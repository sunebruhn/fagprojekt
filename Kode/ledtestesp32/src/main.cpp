#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#include "lamp.h"

Lamp myLamp;

void setup() {
}


void loop(){
  myLamp.randomLights();
}

