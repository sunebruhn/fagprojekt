#ifndef wifiprotocols_h
#define wifiprotocols_h

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

void beginWiFi();

void keepWiFiAlive(void * parameter);

void setupWiFi();

#endif