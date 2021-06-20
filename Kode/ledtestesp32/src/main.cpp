#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#include "lamp.h"



Lamp myLamp;

void setup() {
}


void loop(){
 
  myLamp.squareFour(myLamp.r,myLamp.g,myLamp.b,0);
  myLamp.showAll();
  vTaskDelay(1000);
  myLamp.squareFour(myLamp.r,myLamp.g,myLamp.b,1);
  myLamp.showAll();
  vTaskDelay(1000);
  myLamp.runAround();
  vTaskDelay(1000);
  myLamp.randomLights();
  vTaskDelay(1000);
  myLamp.swipe();
  vTaskDelay(1000);
  myLamp.rainbowStrideColumn();
  vTaskDelay(1000);
  myLamp.rainbowStrideRow();
  vTaskDelay(1000);
  myLamp.heart();
  vTaskDelay(1000);
  myLamp.tronRunner();
  vTaskDelay(1000);
  myLamp.circleReal();
  vTaskDelay(1000);
    myLamp.colorFlow();
  vTaskDelay(1000);
  //myLamp.squareFour(myLamp.r,myLamp.g,myLamp.b,0);
}

