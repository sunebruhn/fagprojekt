#ifndef webprotocols_h
#define webprotocols_h

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include "files.h"

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len);

#endif