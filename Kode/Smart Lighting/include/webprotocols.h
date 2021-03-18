#ifndef webprotocols_h
#define webprotocols_h

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include "files.h"

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len);

void handleClientConnections(void * ws);

void beginWiFi();

void keepWiFiAlive(void * parameter);

void setupWiFi();

#endif