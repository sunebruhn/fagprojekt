#include "wifiprotocols.h"

#define WIFI_TIMEOUT_MS 20000      // 20 second WiFi connection timeout
#define WIFI_RECOVER_TIME_MS 30000 // Wait 30 seconds after a failed connection attempt
#define CONFIG_FILE "/config.txt"

Config WIFI_CREDENTIALS;

void autoConnect()
{
  
  if (loadConfiguration(SPIFFS, CONFIG_FILE, WIFI_CREDENTIALS))
  {
    Serial.println("[WIFI] Using existing credentials");
  }

  //Setup captive portal
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("ESP Config");
  Serial.print("ESP32 IP as soft AP: ");
  Serial.println(WiFi.softAPIP());

  xTaskCreate(
      waitForConfig,   // Task function
      "waitForConfig", // Task name
      5000,            // Stack size (bytes)
      NULL,            // Parameter
      1,               // Task priority
      NULL             // Task handle
  );

}

void waitForConfig(void * parameters){

  while(1){
    if(!loadConfiguration(SPIFFS, CONFIG_FILE, WIFI_CREDENTIALS)){
      Serial.println("Awaiting wifi config");
      vTaskDelay(WIFI_TIMEOUT_MS / portTICK_PERIOD_MS);
      continue;
    }
    
    if(beginWiFi()){

      xTaskCreate(
      keepWiFiAlive,   // Task function
      "keepWiFiAlive", // Task name
      5000,            // Stack size (bytes)
      NULL,            // Parameter
      1,               // Task priority
      NULL             // Task handle
      );

      // delete waitForConfig
      vTaskDelete(NULL);

      continue;
    }
    vTaskDelay(WIFI_TIMEOUT_MS / portTICK_PERIOD_MS);
  }
}

boolean beginWiFi()
{

  Serial.print("[WIFI] Connecting");
  //WiFi.mode(WIFI_AP_STA);
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
    Serial.println("\n[WIFI] Connection failed.");
    return false;
  }
  Serial.print("\n[WIFI] Connected: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  return true;
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

    if (beginWiFi()){
      vTaskDelay(6 * 10000 / portTICK_PERIOD_MS); //check in a minute
      continue;
    }
    Serial.print("\n[WIFI] Connection failed. Retrying in ");
    Serial.print(WIFI_RECOVER_TIME_MS / 1000);
    Serial.print(" seconds\n");
    vTaskDelay(WIFI_RECOVER_TIME_MS / portTICK_PERIOD_MS);
  }
}