#include "webprotocols.h"

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){
 
  if(type == WS_EVT_DATA){ 
    //testing
    Serial.print("Data received: ");
    for(int i=0; i < len; i++) {
      Serial.print((char) data[i]);
    }
    Serial.println();
    //testing done


  }
}