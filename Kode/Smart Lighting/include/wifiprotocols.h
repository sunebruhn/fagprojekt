#ifndef wifiprotocols_h
#define wifiprotocols_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>
#include "wificonfig.h"

boolean beginSTA();

boolean beginAP();

void autoConnect();

//void keepAPAlive(void * parameter);

//void waitForConfig(void * parameters);

//boolean beginWiFi();

void keepWiFiAlive(void * parameter);

#endif