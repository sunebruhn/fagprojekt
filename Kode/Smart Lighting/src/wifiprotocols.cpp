#include "wifiprotocols.h"

#define WIFI_TIMEOUT_MS 20000      // 20 second WiFi connection timeout
#define WIFI_RECOVER_TIME_MS 30000 // Wait 30 seconds after a failed connection attempt
#define MAX_ATTEMPTS 3
#define CONFIG_FILE "/config.txt"

Config WIFI_CREDENTIALS;

DNSServer dnsServer;
TaskHandle_t dnsHandle;

boolean beginSTA()
{
  Serial.print("[WIFI beginSTA] Beginning wifi station");
  WiFi.mode(WIFI_STA);
  // Configures static IP address
  if (!WiFi.config(IPAddress(192,168,2,69), IPAddress(192,168,2,1), IPAddress(255,255,255,0))) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin(WIFI_CREDENTIALS.ssid, WIFI_CREDENTIALS.pass);

  unsigned long startAttemptTime = millis();

  // Keep looping while we're not connected and haven't reached the timeout
  while (WiFi.status() != WL_CONNECTED &&
         millis() - startAttemptTime < WIFI_TIMEOUT_MS)
  {
    vTaskDelay(500);
    Serial.print(".");
  }

  // When we couldn't make a WiFi connection (or the timeout expired)
  // sleep for a while and then retry.
  if (WiFi.status() != WL_CONNECTED)
  {   
    Serial.println("\n[WIFI beginSTA] Connection failed.");
    return false;
  }
  Serial.print("\n[WIFI beginSTA] Connected: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  return true;
}

boolean beginAP()
{
  Serial.print("[WIFI beginAP] Beginning wifi AP");
  //Setup captive portal
  WiFi.mode(WIFI_AP);
  if(!WiFi.softAP("ESP Config")){
    Serial.println("[WIFI beginAP] Error starting AP");
    return false;
  }
  WiFi.softAPConfig(IPAddress(192,168,1,69),IPAddress(192,168,1,69),IPAddress(255,255,255,0));
  Serial.print("ESP32 IP as soft AP: ");
  Serial.println(WiFi.softAPIP());

  // TODO : Setup captive portal
  dnsServer.start(53, "*", WiFi.softAPIP());
  xTaskCreate(
      handleDNS,   // Task function
      "handleDNS", // Task name
      5000,            // Stack size (bytes)
      NULL,            // Parameter
      1,               // Task priority
      &dnsHandle       // Task handle
      );
      
  return true;  
}

void handleDNS(void * parameters)
{
  while(1)
  {
    dnsServer.processNextRequest();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void autoConnect()
{
  //WiFi.mode(WIFI_OFF);
  
  if (loadConfiguration(SPIFFS, CONFIG_FILE, WIFI_CREDENTIALS))
  {
    Serial.println("[WIFI autoConnect] Using existing credentials");
    beginSTA();
    xTaskCreate(
      keepWiFiAlive,   // Task function
      "keepWiFiAlive", // Task name
      5000,            // Stack size (bytes)
      NULL,            // Parameter
      1,               // Task priority
      NULL             // Task handle
      );
      return;
  }
  // Opening AP
  while(!beginAP())
  {
    Serial.println("Failed to open AP. Retrying in ");
    Serial.print(WIFI_RECOVER_TIME_MS / 1000);
    Serial.print(" seconds\n");
    vTaskDelay(WIFI_RECOVER_TIME_MS / portTICK_PERIOD_MS);
  }
}

void keepWiFiAlive(void *parameter)
{
  while (1)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("[WIFI] Succesful Check");
      vTaskDelay(6 * 10000 / portTICK_PERIOD_MS); //check every minute
      continue;
    }

    // Load config
    loadConfiguration(SPIFFS, CONFIG_FILE, WIFI_CREDENTIALS);

    // Attempt to reconnect with MAX_ATTEMPTS
    for(int i = MAX_ATTEMPTS; i; i--)
    {
      if (beginSTA())
      {
        vTaskDelete(dnsHandle);
        break;
      }
      Serial.print("\n[WIFI] Connection failed. Retrying in ");
      Serial.print(WIFI_RECOVER_TIME_MS / 1000);
      Serial.print(" seconds\n");
      vTaskDelay(WIFI_RECOVER_TIME_MS / portTICK_PERIOD_MS);
    }

    // if connection succeeded, continue
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("[WIFI] Succesful Check");
      vTaskDelay(6 * 10000 / portTICK_PERIOD_MS); //check every minute
      continue;
    }

    // else, end WiFi and clear config
    Serial.println("[WIFI] WiFi unavailable with current credentials. Clearing config.");
    WiFi.disconnect();
    strlcpy(WIFI_CREDENTIALS.ssid,          // <- destination
          "",                               // <- source
          sizeof(WIFI_CREDENTIALS.ssid));   // <- destination's capacity
    strlcpy(WIFI_CREDENTIALS.pass,          // <- destination
          "",                               // <- source
          sizeof(WIFI_CREDENTIALS.pass));   // <- destination's capacity
    saveConfiguration(SPIFFS, "/config.txt", WIFI_CREDENTIALS);
    // reopen AP and delete this task
    // Opening AP
    for(int i = MAX_ATTEMPTS; i; i--)
    {
      if (beginAP())
      {
        Serial.println("AP opening. Deleting task keepWiFiAlive");
        vTaskDelete(NULL);
      }
      Serial.print("\n[WIFI] Failed to open AP. Retrying in ");
      Serial.print(WIFI_RECOVER_TIME_MS / 1000);
      Serial.print(" seconds\n");
      vTaskDelay(WIFI_RECOVER_TIME_MS / portTICK_PERIOD_MS);
    }
    Serial.println("Failed to open AP. Reattempting station mode");
  }
}
