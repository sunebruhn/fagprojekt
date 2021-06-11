#include "webprotocols.h"

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){

  switch (type)
  {
    case WS_EVT_CONNECT:
      Serial.println("Websocket client connection received");
      break;

    case WS_EVT_DISCONNECT:
      Serial.println("Websocket client connection finished");
      break;

    case WS_EVT_DATA:
      //testing
      Serial.print("Data received: ");
      for(int i=0; i < len; i++) {
        Serial.print((char) data[i]);
      }
      Serial.println();
      //testing done

      handleData((char*)data, len);
      break;

    default:
      break;
  }
}

void handleClientConnections(void * ws){

  while(1){
    // Disable client connections if it was activated
    if ( static_cast<AsyncWebSocket *>(ws)->enabled() )
      static_cast<AsyncWebSocket *>(ws)->enable(false);

    // enable client connections if it was disabled
    if ( !static_cast<AsyncWebSocket *>(ws)->enabled() )
      static_cast<AsyncWebSocket *>(ws)->enable(true);

    // wait 1 sec
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void handleData(char* data, size_t len){
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, data);
  enum identifiers identifier; 
  identifier = doc["id"];

  switch (identifier)
  {
  case NO_ID:
    Serial.println("Data had no ID");
    break;
  case WIFI_CONFIG:
    Config config;
    // Copy values from the JsonDocument to the Config
    strlcpy(config.ssid,          // <- destination
            doc["ssid"] | "",     // <- source
            sizeof(config.ssid)); // <- destination's capacity
    strlcpy(config.pass,          // <- destination
            doc["pass"] | "",     // <- source
            sizeof(config.pass)); // <- destination's capacity
    saveConfiguration(SPIFFS, "/config.txt", config);

    // delete AP
    WiFi.softAPdisconnect();
    
    // begin station
    xTaskCreate(
      keepWiFiAlive,   // Task function
      "keepWiFiAlive", // Task name
      5000,            // Stack size (bytes)
      NULL,            // Parameter
      1,               // Task priority
      NULL             // Task handle
      );
    break;
  case ON_OFF_SWITCH:
  {
    Lamp tmpLamp;
    tmpLamp.state = doc["state"];
    Serial.print("the test ");
    Serial.println(tmpLamp.state);
  }  
    break;
  
  case SET_COLOUR:
    Serial.println();
    break;
  default:
    break;
  }

}
