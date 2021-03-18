#include "wifiprotocols.h"

#define WIFI_NETWORK "Sunet"
#define WIFI_PASSWORD "sunesune"
#define WIFI_TIMEOUT_MS 20000 // 20 second WiFi connection timeout
#define WIFI_RECOVER_TIME_MS 30000 // Wait 30 seconds after a failed connection attempt

void beginWiFi(){

  Serial.print("[WIFI] Connecting");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

    unsigned long startAttemptTime = millis();

    // Keep looping while we're not connected and haven't reached the timeout
    while (WiFi.status() != WL_CONNECTED && 
            millis() - startAttemptTime < WIFI_TIMEOUT_MS){
      vTaskDelay(500);
      Serial.print(".");
    }

    // When we couldn't make a WiFi connection (or the timeout expired)
    // sleep for a while and then retry.
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("\n[WIFI] Connection failed. Retrying in ");
      Serial.print(WIFI_RECOVER_TIME_MS / 1000);
      Serial.print(" seconds\n");
      vTaskDelay(WIFI_RECOVER_TIME_MS / portTICK_PERIOD_MS);
    return;
    }

    Serial.print("\n[WIFI] Connected: ");
    Serial.print(WiFi.localIP());
    Serial.println();
}

void keepWiFiAlive(void * parameter){
  
  while(1){
    if(WiFi.status() == WL_CONNECTED){
      Serial.println("[WIFI] Succesful Check");
      vTaskDelay(6*10000 / portTICK_PERIOD_MS); //check every minute
      continue;
    }

    beginWiFi();    
  }
}

void setupWiFi(){

  beginWiFi();

  xTaskCreate(
    keepWiFiAlive,    // Task function
    "keepWiFiAlive",  // Task name
    5000,             // Stack size (bytes)
    NULL,             // Parameter
    1,                // Task priority
    NULL              // Task handle
  );
}