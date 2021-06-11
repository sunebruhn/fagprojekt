#include "lamp.h"

void Lamp::squareFour(int r, int g, int b, int corner) { //tænder en af fire blokke, eller alle blokke
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

void Lamp::runAround(){ //bevæger sig rundt i 4 blokke
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

void Lamp::water(){
  int randA = random8()%111;
  int randB= random8()%111;
  int randC = random8()%111;
  int randD = random8()%111;
  int randE = random8()%111;
  int randF = random8()%111;
    for(int i = 0; i < 500; i++){
      for(int j = 0; j < 6; j++){
        strip_a.setPixelColor(j,waterInt[i+(randA%(10*j))][0],waterInt[i+(randA%(10*j))][1],waterInt[i+(randA%(10*j))][2]);
        strip_b.setPixelColor(j,waterInt[i+(randB%(10*j))][0],waterInt[i+(randB%(10*j))][1],waterInt[i+(randB%(10*j))][2]);
        strip_c.setPixelColor(j,waterInt[i+(randC%(10*j))][0],waterInt[i+(randC%(10*j))][1],waterInt[i+(randC%(10*j))][2]);
        strip_d.setPixelColor(j,waterInt[i+(randD%(10*j))][0],waterInt[i+(randD%(10*j))][1],waterInt[i+(randD%(10*j))][2]);
        strip_e.setPixelColor(j,waterInt[i+(randE%(10*j))][0],waterInt[i+(randE%(10*j))][1],waterInt[i+(randE%(10*j))][2]);
        strip_f.setPixelColor(j,waterInt[i+(randF%(10*j))][0],waterInt[i+(randF%(10*j))][1],waterInt[i+(randF%(10*j))][2]);
        showAll();
        delay(25);
      }
    }

}

void Lamp::randomLights(){ // Tilfældige lys blinker hurtigt

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

void Lamp::setRow(int r, int g, int b, int strip) { //tænder for en række med en rgb farve
  
  if (strip == 0) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_a.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 1) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_b.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 2) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_c.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 3) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_d.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 4) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_e.setPixelColor(i,r,g,b);
    }
  }
   if (strip == 5) {
    for (int i = 0; i<NUMPIXELS; i++) {
      strip_f.setPixelColor(i,r,g,b);
    }
  }
  showAll();
  
}

void Lamp::setColumn(int r, int g, int b, int column) {  //tænder en kollonne med rgb farve
  strip_a.setPixelColor(column,r,g,b);
  strip_b.setPixelColor(column,r,g,b);
  strip_c.setPixelColor(column,r,g,b);
  strip_d.setPixelColor(column,r,g,b);
  strip_e.setPixelColor(column,r,g,b);
  strip_f.setPixelColor(column,r,g,b);
  showAll();
}

void Lamp::showAll(){ //Shows all LED's
  strip_a.show();
  strip_b.show();
  strip_c.show();
  strip_d.show();
  strip_e.show();
  strip_f.show();
}

void Lamp::colorFlow() { //Går langsomt igennem all farver
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

void Lamp::rainbowStrideColumn(){
  for(int i = 0; i < 20; i++){
    setColumn(9, 235, 5,(i%6));
    delay(10);
    setColumn(235, 231, 5,(i+1)%6);
    delay(10);
    setColumn(5, 235, 224,(i+2)%6);
    delay(10);
    setColumn(5, 81, 245,(i+3)%6);
    delay(10);
    setColumn(177, 5, 245,(i+4)%6);
    delay(10);
    setColumn(245, 5, 17,(i+5)%6);
    delay(10);
    setColumn(245, 93, 5,(i+6)%6);
    delay(10);
    
  }
  


}


void Lamp::rainbowStrideRow(){

  int colors[][3] = {{9, 235, 5},{235, 231, 5},{5, 235, 224},{5, 81, 245},{177, 5, 245},{245, 5, 17}};

  for(int i = 0; i < 20; i++){
    setRow(9, 235, 5,(i%6));
    delay(10);
    setRow(235, 231, 5,(i+1)%6);
    delay(10);
    setRow(5, 235, 224,(i+2)%6);
    delay(10);
    setRow(5, 81, 245,(i+3)%6);
    delay(10);
    setRow(177, 5, 245,(i+4)%6);
    delay(10);
    setRow(245, 5, 17,(i+5)%6);
    delay(10);
    setRow(245, 93, 5,(i+6)%6);
    delay(10);
    
  }
  


}