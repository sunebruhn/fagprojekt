#ifndef wifiprotocols_h
#define wifiprotocols_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include "wificonfig.h"

class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    request->send(SPIFFS, "/config_page.html");
    return true;
  }
};

boolean beginSTA();

boolean beginAP();

void autoConnect();

void handleDNS(void * parameters);

void keepWiFiAlive(void * parameter);

#endif