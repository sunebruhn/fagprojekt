#include <Adafruit_NeoPixel.h>

#define NUMPIXELS  6


Adafruit_NeoPixel strip_a(NUMPIXELS, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_b(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_c(NUMPIXELS, 7, NEO_GRB + NEO_KHZ800);


int32_t r = 0;
int32_t g = 0;
int32_t b = 0;

void setup() {
  strip_a.begin();
  strip_b.begin();
  strip_c.begin();
}


void loop(){



}


//functions:
void around(int32_t r, int32_t g, int32_t b) {
  int32_t checker = 0;
  checker = 0;
  strip_a.clear();
  strip_b.clear();
  strip_c.clear();

  for(int i=0; i<14; i++) {
    strip_a.clear();
    strip_b.clear();
    strip_c.clear();
    if(i<6){
      strip_a.setPixelColor(i, r, g, b);
    }
    if(i==6){
      strip_b.setPixelColor(6-1,r,g,b);
    }
    if(i>6 && i<13){
      checker++;
      strip_c.setPixelColor(i-(2*checker),r,g,b);
    }
    if(i==13){
      strip_b.setPixelColor(0,r,g,b);
    }


    strip_a.show();
    strip_b.show();
    strip_c.show();

    delay(200);
  }
}

void uniformcolor(int32_t r, int32_t g, int32_t b){
  int32_t r_in = r;
  int32_t g_in = g;
  int32_t b_in = b;


  for(int i=0; i<3;i++){
    for(int j=0; j<6;j++){
      if(i==0){
        strip_a.setPixelColor(j,r_in,g_in,b_in);
      }
      if(i==1){
        strip_b.setPixelColor(j,r_in,g_in,b_in);
      }
      if(i==2){
        strip_c.setPixelColor(j,r_in,g_in,b_in);
      }
    }
    }
    strip_a.show();
    strip_b.show();
    strip_c.show();
}

void checkcolor(){
  int32_t r = 0;
  int32_t g = 0;
  int32_t b = 0;

  for(int i=0; i < 256; i++){
    r = i;
    uniformcolor(r,g,b);
    delay(50);
  }
 r = 0;
 g = 0;
 b = 0;
  for(int i=0; i < 256; i++){
    g = i;
    uniformcolor(r,g,b);
     delay(50);
  }
 r = 0;
 g = 0;
 b = 0;
  for(int i=0; i < 256; i++){
    b = i;
    uniformcolor(r,g,b);
     delay(50);
  }

}

void checkleds(){

    for(int i=0; i<3;i++){
    for(int j=0; j<6;j++){
      strip_a.clear();
      strip_b.clear();
      strip_c.clear();
      if(i==0){
        strip_a.setPixelColor(j,255,255,255);
      }
      if(i==1){
        strip_b.setPixelColor(j,255,255,255);
      }
      if(i==2){
        strip_c.setPixelColor(j,255,255,255);
      }
    strip_a.show();
    strip_b.show();
    strip_c.show();
    delay(200);
    }
    }
}