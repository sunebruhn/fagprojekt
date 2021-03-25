#ifndef webprotocols_h
#define webprotocols_h

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include "wificonfig.h"
#include "wifiprotocols.h"
#include "files.h"

enum identifiers{NO_ID, WIFI_CONFIG};

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len);

void handleClientConnections(void * ws);

void handleData(char* data, size_t len);

#endif