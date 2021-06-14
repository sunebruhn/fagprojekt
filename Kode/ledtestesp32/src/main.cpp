#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#include "lamp.h"



Lamp myLamp;

void setup() {
}


void loop(){
 
  myLamp.circleReal();
  myLamp.rainbowStrideColumn();
  myLamp.rainbowStrideRow();
  myLamp.heart();
  
  //myLamp.squareFour(myLamp.r,myLamp.g,myLamp.b,0);
}

