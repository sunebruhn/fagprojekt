#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include <time.h>
#include "files.h"
#include "wificonfig.h"
#include "wifiprotocols.h"
#include "webprotocols.h"
#include "lamp.h"

/* Definitions and globals
{ */
  Lamp lamp;
  TaskHandle_t lampTaskHandle;

  // Create AsyncWebServer object on port 80
  AsyncWebServer server(80);
  AsyncWebSocket ws("/test"); /*
} */
void setup()
{
  Serial.begin(115200);

  //  initialise file system
  if (!SPIFFS.begin())
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  //  connect to WiFi
  autoConnect();
  
  //  Web server protocols

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);

  xTaskCreate(
      handleClientConnections,     // task function
      "Handle Client Connections", // task name
      1024,                        // stack size
      (void *)&ws,                 // parameters passed
      0,                           // priority
      NULL);                       // handler

  // Send data to webpage

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html");
  });

  server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/styles.css");
  });

  server.on("/walter-regular-webfont.woff", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/walter-regular-webfont.woff");
  });

  server.on("/walter-regular-webfont.woff2", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/walter-regular-webfont.woff2");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/script.js");
  });

  server.begin();
  lamp.startTask(lampTaskHandle);

}

void loop() {}
