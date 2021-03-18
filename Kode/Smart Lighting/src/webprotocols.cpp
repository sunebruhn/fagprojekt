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


