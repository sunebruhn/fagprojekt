#ifndef webprotocols_h
#define webprotocols_h

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include "wificonfig.h"
#include "wifiprotocols.h"
#include "files.h"
#include "lamp.h"
#include "alarm.h"

enum identifiers{NO_ID, WIFI_CONFIG, ON_OFF_SWITCH, SET_COLOUR, SET_TO_UNIFORM, SET_TO_SWIPE, SET_TO_6, SET_TO_7, SET_TO_8, SET_TO_9, SET_TO_10, SET_TO_11, SET_ALARM_ON, SET_ALARM_OFF};

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len);

void handleClientConnections(void * ws);

void handleData(char* data, size_t len);

#endif