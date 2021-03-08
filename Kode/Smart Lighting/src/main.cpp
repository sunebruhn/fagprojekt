#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "time.h"
#include "files.h"

//  Definitions and globals

#define ssid "Sunet"
#define password "sunesune"

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

void setup() {
  Serial.begin(115200);

  //  initialise file system
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  //read from config
  if(!checkFile(SPIFFS, "/config.txt")){
    writeFile(SPIFFS, "/config.txt","test SSID: Sunet\nPassword: sunesune\n");
  }

  //  connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  Serial.println(WiFi.localIP());

  //  Web server protocols
    
 /* ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  */
   // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
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
 
void loop() {}