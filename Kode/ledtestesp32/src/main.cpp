#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#include "lamp.h"
//hejwilliam

Lamp myLamp;

void setup() {
}


void loop(){
  myLamp.randomLights();
}

