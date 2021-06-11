#include "lamp.h"

void Lamp::around(int32_t r, int32_t g, int32_t b) {
  int32_t checker = 0;
  checker = 0;
  strip_a.clear();
  strip_b.clear();
  strip_c.clear();

  for(int i=0; i<2; i++) {
    strip_a.clear();
    strip_b.clear();
    strip_c.clear();
    if(i<6){
      strip_a.setPixelColor(i, r, g, b);
    }
    if(i==6){
      strip_b.setPixelColor(2-1,r,g,b);
    }
    if(i>6 && i<2){
      checker++;
      strip_c.setPixelColor(i-(2*checker),r,g,b);
    }
    if(i==2){
      strip_b.setPixelColor(0,r,g,b);
    }


    strip_a.show();
    strip_b.show();
    strip_c.show();

    delay(200);
  }
}

void Lamp::uniformcolor(int32_t r, int32_t g, int32_t b){
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

void Lamp::checkcolor(){
  int32_t r = 0;
  int32_t g = 0;
  int32_t b = 0;

  for(int i=0; i < 256; i++){
    r = i;
    g = i;
    uniformcolor(r,g,b);
    delay(5);
  }
 r = 0;
 g = 0;
 b = 0;
  for(int i=0; i < 256; i++){
    g = i;
    b = i;
    uniformcolor(r,g,b);
     delay(5);
  }
 r = 0;
 g = 0;
 b = 0;
  for(int i=0; i < 256; i++){
    b = i;
    r = i;
    uniformcolor(r,g,b);
     delay(5);
  }

}

void Lamp::squareFour(int r, int g, int b, int corner) {
if (corner == 0){
  for(int i = 0; i < 3; i++){
  strip_a.setPixelColor(i,r,g,b);
  strip_b.setPixelColor(i,r,g,b);
  strip_c.setPixelColor(i,r,g,b);
  }
}

if (corner == 1){
  for(int i = 3; i < 6; i++){
  strip_a.setPixelColor(i,r,g,b);
  strip_b.setPixelColor(i,r,g,b);
  strip_c.setPixelColor(i,r,g,b);
  }
}

if (corner == 2){
  for(int i = 0; i < 3; i++){
  strip_d.setPixelColor(i,r,g,b);
  strip_e.setPixelColor(i,r,g,b);
  strip_f.setPixelColor(i,r,g,b);
  }
}

if (corner == 3){
  for(int i = 3; i < 6; i++){
  strip_d.setPixelColor(i,r,g,b);
  strip_e.setPixelColor(i,r,g,b);
  strip_f.setPixelColor(i,r,g,b);
  }
}

if (corner == 4){
  for(int i = 0; i < 6; i++){
  strip_a.setPixelColor(i,r,g,b);
  strip_b.setPixelColor(i,r,g,b);
  strip_c.setPixelColor(i,r,g,b);
  strip_d.setPixelColor(i,r,g,b);
  strip_e.setPixelColor(i,r,g,b);
  strip_f.setPixelColor(i,r,g,b);
  }
}

strip_a.show();
strip_b.show();
strip_c.show();
strip_d.show();
strip_e.show();
strip_f.show();
}


void Lamp::runAround(){
  squareFour(0,255,255,2);
  squareFour(255,255,255,3);
  squareFour(255,255,255,1);
  squareFour(255,255,255,0);
  delay(500);
  squareFour(255,255,255,2);
  squareFour(0,255,255,3);
  squareFour(255,255,255,1);
  squareFour(255,255,255,0);
  delay(500);
  squareFour(255,255,255,2);
  squareFour(255,255,255,3);
  squareFour(0,255,255,1);
  squareFour(255,255,255,0);
  delay(500);
  squareFour(255,255,255,2);
  squareFour(255,255,255,3);
  squareFour(255,255,255,1);
  squareFour(0,255,255,0);
  delay(500);

}

void Lamp::checkleds(){

    for(int i=0; i<6;i++){
      for(int j=0; j<6;j++){
        strip_a.clear();
        strip_b.clear();
        strip_c.clear();
        strip_d.clear();
        strip_e.clear();
        strip_f.clear();
        if(i==0){
          strip_a.setPixelColor(j,255,255,255);
        }
        if(i==1){
          strip_b.setPixelColor(j,255,255,255);
        }
        if(i==2){
          strip_c.setPixelColor(j,255,255,255);
        }
        if(i==3){
          strip_d.setPixelColor(j,255,255,255);
        }
        if(i==4){
          strip_e.setPixelColor(j,255,255,255);
        }
        if(i==5){
          strip_f.setPixelColor(j,255,255,255);
        }
      strip_a.show();
      strip_b.show();
      strip_c.show();
      strip_d.show();
      strip_e.show();
      strip_f.show();
      delay(100);
      }
    }
}

void Lamp::rainbow() {
   strip_a.clear();
   strip_b.clear();
   strip_c.clear();
   for(int i = 0; i<256;i++) {
     int r = i;
     int g = (i+50)%256;
     int b = (i+25)%256;
     strip_a.setPixelColor(0,r,g,b);
     strip_b.setPixelColor(0,r,g,b);
     strip_a.setPixelColor(1,b,r,g);
     strip_b.setPixelColor(1,b,r,g);
     strip_a.show();
     delay(5);
   }
   
}

void Lamp::cascade() {
  
  
strip_a.setBrightness(50);
strip_b.setBrightness(50);
strip_c.setBrightness(50);

  strip_a.setPixelColor(0,255,255,0);
  strip_a.setPixelColor(1,255,0,255);
  strip_a.show();
  strip_b.setPixelColor(1,255,255,0);
  strip_b.setPixelColor(0,255,0,255);
  strip_b.show();
  delay(1000);

  strip_a.setPixelColor(0,255,0,255);
  strip_a.setPixelColor(1,255,255,0);
  strip_a.show();
  strip_b.setPixelColor(1,255,0,255);
  strip_b.setPixelColor(0,255,255,0);
  strip_b.show();
  delay(1000);
}

void Lamp::circle(){
strip_a.setPixelColor(0,255,255,255);
strip_a.setPixelColor(1,0,0,0);
strip_b.setPixelColor(0,0,0,0);
strip_b.setPixelColor(1,0,0,0);
delay(1000);

strip_a.show();
strip_b.show();
strip_a.setPixelColor(0,0,0,0);
strip_a.setPixelColor(1,255,255,255);
strip_b.setPixelColor(0,0,0,0);
strip_b.setPixelColor(1,0,0,0);
delay(1000);

strip_a.show();
strip_b.show();
strip_a.setPixelColor(0,0,0,0);
strip_a.setPixelColor(1,0,0,0);
strip_b.setPixelColor(1,255,255,255);
strip_b.setPixelColor(0,0,0,0);
delay(1000);

strip_a.show();
strip_b.show();
strip_a.setPixelColor(0,0,0,0);
strip_a.setPixelColor(1,0,0,0);
strip_b.setPixelColor(1,0,0,0);
strip_b.setPixelColor(0,255,255,255);
delay(1000);


strip_a.show();
strip_b.show();


}

void Lamp::water(){
    for(int i = 0; i < 6; i++){
    for(int j = 0; j < 6; j++){
      strip_a.setPixelColor(random8()%6,waterInt[j][0],waterInt[j+1][1],waterInt[j+2][2]);
      strip_b.setPixelColor(random8()%6,waterInt[j+3][0],waterInt[j+4][1],waterInt[j+5][2]);
      strip_c.setPixelColor(random8()%6,waterInt[j+6][0],waterInt[j+7][1],waterInt[j+8][2]);
      strip_d.setPixelColor(random8()%6,waterInt[j+9][0],waterInt[j+10][1],waterInt[j+11][2]);
      strip_e.setPixelColor(random8()%6,waterInt[j+12][0],waterInt[j+13][1],waterInt[j+14][2]);
      strip_f.setPixelColor(random8()%6,waterInt[j+15][0],waterInt[j+16][1],waterInt[j+17][2]);
  strip_a.show();
  strip_b.show();
  strip_c.show();
  strip_d.show();
  strip_e.show();
  strip_f.show();
  delay(100);
    }
 
  }
}

void Lamp::randomLights(){
  for(int i = 0; i < 6; i++){
    strip_a.setPixelColor(i,random8(),random8(),random8());
    strip_b.setPixelColor(i,random8(),random8(),random8());
    strip_c.setPixelColor(i,random8(),random8(),random8());
    strip_d.setPixelColor(i,random8(),random8(),random8());
    strip_e.setPixelColor(i,random8(),random8(),random8());
    strip_f.setPixelColor(i,random8(),random8(),random8()); 

  }

strip_a.show();
strip_b.show();
strip_c.show();
strip_d.show();
strip_e.show();
strip_f.show();
delay(80);
}
void Lamp::setRow(int r, int g, int b, int strip) {
  
  if (strip == 1) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_a.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 2) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_b.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 3) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_c.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 4) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_d.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 5) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_e.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 6) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_f.setPixelColor(i,r,g,b);
    }
  }
  showAll();
  
}
void Lamp::setColumn(int r, int g, int b, int column) {
  strip_a.setPixelColor(column,r,g,b);
  strip_b.setPixelColor(column,r,g,b);
  strip_c.setPixelColor(column,r,g,b);
  strip_d.setPixelColor(column,r,g,b);
  strip_e.setPixelColor(column,r,g,b);
  strip_f.setPixelColor(column,r,g,b);
  showAll();
}
void Lamp::showAll(){
  strip_a.show();
  strip_b.show();
  strip_c.show();
  strip_d.show();
  strip_e.show();
  strip_f.show();
}
void Lamp::colorFlow() {
  squareFour(255,0,0,4);
  showAll();
  for (int i = 0; i < 256; i++) {
    squareFour(255,i,0,4);
    showAll();
    delay(100);
  }
  for (int i = 255; i >= 0; i--) {
    squareFour(i,255,0,4);
    showAll();
    delay(100);
  }
  for (int i = 0; i < 256; i++) {
    squareFour(0,255,i,4);
    showAll();
    delay(100);
  }
  for (int i = 255; i >= 0; i--) {
    squareFour(0,i,255,4);
    showAll();
    delay(100);
  }
  for (int i = 0; i < 256; i++) {
    squareFour(i,0,255,4);
    showAll();
    delay(100);
  }
  for (int i = 255; i >= 0; i--) {
    squareFour(255,0,i,4);
    showAll();
    delay(100);
  }
}
void Lamp::swipe() {
  int r = 255;
  int g = 255;
  int b = 255;
  for (int i = 0; i<6;i++){
    setColumn(0,0,255,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <892;i++) {
    b--;
    if (i < 255) {
      setColumn(0,0,b,0);
    }
    
    if (i > 127 && i < 377) {
      setColumn(0,0,b+127,1);
    }
    if (i > 255 && i < 510) {
      setColumn(0,0,b+255,2);
    }
    if (i > 377 && i < 637) {
      setColumn(0,0,b+377,3);
    }
    if (i > 510 && i < 765) {
      setColumn(0,0,b+510,4);
    }
    if (i > 637) {
      setColumn(0,0,b+637,5);
    }
    showAll();
    delay(10);
  }
}