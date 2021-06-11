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

//  Definitions and globals

Lamp lamp;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/test");

//   SSSSSS   EEEEEEEE  TTTTTTTT  UU    UU  PPPPPPP
//  SS    SS  EE           TT     UU    UU  PP    PP
//  SS        EE           TT     UU    UU  PP    PP
//   SSSSS    EEEEEE       TT     UU    UU  PPPPPPP
//        SS  EE           TT     UU    UU  PP
//  SS    SS  EE           TT     UU    UU  PP
//   SSSSSS   EEEEEEEE     TT      UUUUUU   PP

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

  // Route for root / web page

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

}

//  LL         OOOOOO    OOOOOO   PPPPPPP
//  LL        OO    OO  OO    OO  PP    PP
//  LL        OO    OO  OO    OO  PP    PP
//  LL        OO    OO  OO    OO  PPPPPPP
//  LL        OO    OO  OO    OO  PP
//  LL        OO    OO  OO    OO  PP
//  LLLLLLLL   OOOOOO    OOOOOO   PP

void loop() {
  while(lamp.state)
  {
    lamp.checkleds();
  }
}
