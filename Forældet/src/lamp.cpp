#include "lamp.h"

bool Lamp::state = 0;
int32_t Lamp::r = 64;
int32_t Lamp::g = 64;
int32_t Lamp::b = 64;

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
/*
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
*/

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
  
}

void Lamp::setColumn(int r, int g, int b, int column) {  //tænder en kollonne med rgb farve
  strip_a.setPixelColor(column,r,g,b);
  strip_b.setPixelColor(column,r,g,b);
  strip_c.setPixelColor(column,r,g,b);
  strip_d.setPixelColor(column,r,g,b);
  strip_e.setPixelColor(column,r,g,b);
  strip_f.setPixelColor(column,r,g,b);
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
    showAll();
    delay(10);
    setColumn(235, 231, 5,(i+1)%6);
    showAll();
    delay(10);
    setColumn(5, 235, 224,(i+2)%6);
    showAll();
    delay(10);
    setColumn(5, 81, 245,(i+3)%6);
    showAll();
    delay(10);
    setColumn(177, 5, 245,(i+4)%6);
    showAll();
    delay(10);
    setColumn(245, 5, 17,(i+5)%6);
    showAll();
    delay(10);
    setColumn(245, 93, 5,(i+6)%6);
    showAll();
    delay(10);
    
  }
  


}


void Lamp::rainbowStrideRow(){

  

  for(int i = 0; i < 20; i++){
    setRow(9, 235, 5,(i%6));
    showAll();
    delay(10);
    setRow(235, 231, 5,(i+1)%6);
    showAll();
    delay(10);
    setRow(5, 235, 224,(i+2)%6);
    showAll();
    delay(10);
    setRow(5, 81, 245,(i+3)%6);
    showAll();
    delay(10);
    setRow(177, 5, 245,(i+4)%6);
    showAll();
    delay(10);
    setRow(245, 5, 17,(i+5)%6);
    showAll();
    delay(10);
    setRow(245, 93, 5,(i+6)%6);
    showAll();
    delay(10);
    
  }
  


}
void Lamp::swipe() {
  swipeRightBlue();
  swipeLeftRed();
  swipeUpGreen();
  swipeDownPurple();
  swipeRightCyan();
  swipeLeftYellow();
  swipeUpBlue();
  swipeDownRed();
  swipeRightGreen();
  swipeLeftPurple();
  swipeUpCyan();
  swipeDownYellow();

}
void Lamp::swipeRightBlue() {
  int s = 255;
  for (int i = 0; i<6;i++){
    setColumn(0,0,s,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setColumn(0,0,s,0);
    }
    
    if (i > 64 && i < 319) {
      setColumn(0,0,s+64,1);
    }
    if (i > 128 && i < 383) {
      setColumn(0,0,s+128,2);
    }
    if (i > 192 && i < 447) {
      setColumn(0,0,s+192,3);
    }
    if (i > 256 && i < 511) {
      setColumn(0,0,s+256,4);
    }
    if (i > 320) {
      setColumn(0,0,s+320,5);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeLeftRed() {
  int s = 255;
  for (int i = 6; i>=0;i--){
    setColumn(s,0,0,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setColumn(s,0,0,5);
    }
    
    if (i > 64 && i < 319) {
      setColumn(s+64,0,0,4);
    }
    if (i > 128 && i < 383) {
      setColumn(s+128,0,0,3);
    }
    if (i > 192 && i < 447) {
      setColumn(s+192,0,0,2);
    }
    if (i > 256 && i < 511) {
      setColumn(s+256,0,0,1);
    }
    if (i > 320) {
      setColumn(s+320,0,0,0);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeUpGreen() {
  int s = 255;
  for (int i = 0; i<6;i++){
    setRow(0,s,0,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setRow(0,s,0,0);
    }
    
    if (i > 64 && i < 319) {
      setRow(0,s+64,0,1);
    }
    if (i > 128 && i < 383) {
      setRow(0,s+128,0,2);
    }
    if (i > 192 && i < 447) {
      setRow(0,s+192,0,3);
    }
    if (i > 256 && i < 511) {
      setRow(0,s+256,0,4);
    }
    if (i > 320) {
      setRow(0,s+320,0,5);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeDownPurple() {
  int s = 255;
  for (int i = 5; i>=0;i--){
    setRow(s,0,s,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setRow(s,0,s,5);
    }
    
    if (i > 64 && i < 319) {
      setRow(s+64,0,s+64,4);
    }
    if (i > 128 && i < 383) {
      setRow(s+128,0,s+128,3);
    }
    if (i > 192 && i < 447) {
      setRow(s+192,0,s+192,2);
    }
    if (i > 256 && i < 511) {
      setRow(s+256,0,s+256,1);
    }
    if (i > 320) {
      setRow(s+320,0,s+320,0);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeRightCyan() {
  int s = 255;
  for (int i = 0; i<6;i++){
    setColumn(0,s,s,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setColumn(0,s,s,0);
    }
    
    if (i > 64 && i < 319) {
      setColumn(0,s+64,s+64,1);
    }
    if (i > 128 && i < 383) {
      setColumn(0,s+128,s+128,2);
    }
    if (i > 192 && i < 447) {
      setColumn(0,s+192,s+192,3);
    }
    if (i > 256 && i < 511) {
      setColumn(0,s+256,s+256,4);
    }
    if (i > 320) {
      setColumn(0,s+320,s+320,5);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeLeftYellow() {
  int s = 255;
  for (int i = 6; i>=0;i--){
    setColumn(s,s,0,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setColumn(s,s,0,5);
    }
    
    if (i > 64 && i < 319) {
      setColumn(s+64,s+64,0,4);
    }
    if (i > 128 && i < 383) {
      setColumn(s+128,s+128,0,3);
    }
    if (i > 192 && i < 447) {
      setColumn(s+192,s+192,0,2);
    }
    if (i > 256 && i < 511) {
      setColumn(s+256,s+256,0,1);
    }
    if (i > 320) {
      setColumn(s+320,s+320,0,0);
    }
    showAll();
    delay(2);
  }
}

void Lamp::swipeUpBlue() {
  int s = 255;
  for (int i = 0; i<6;i++){
    setRow(0,0,s,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setRow(0,0,s,0);
    }
    
    if (i > 64 && i < 319) {
      setRow(0,0,s+64,1);
    }
    if (i > 128 && i < 383) {
      setRow(0,0,s+128,2);
    }
    if (i > 192 && i < 447) {
      setRow(0,0,s+192,3);
    }
    if (i > 256 && i < 511) {
      setRow(0,0,s+256,4);
    }
    if (i > 320) {
      setRow(0,0,s+320,5);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeDownRed() {
  int s = 255;
  for (int i = 5; i>=0;i--){
    setRow(s,0,0,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setRow(s,0,0,5);
    }
    
    if (i > 64 && i < 319) {
      setRow(s+64,0,0,4);
    }
    if (i > 128 && i < 383) {
      setRow(s+128,0,0,3);
    }
    if (i > 192 && i < 447) {
      setRow(s+192,0,0,2);
    }
    if (i > 256 && i < 511) {
      setRow(s+256,0,0,1);
    }
    if (i > 320) {
      setRow(s+320,0,0,0);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeRightGreen() {
  int s = 255;
  for (int i = 0; i<6;i++){
    setColumn(0,s,0,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setColumn(0,s,0,0);
    }
    
    if (i > 64 && i < 319) {
      setColumn(0,s+64,0,1);
    }
    if (i > 128 && i < 383) {
      setColumn(0,s+128,0,2);
    }
    if (i > 192 && i < 447) {
      setColumn(0,s+192,0,3);
    }
    if (i > 256 && i < 511) {
      setColumn(0,s+256,0,4);
    }
    if (i > 320) {
      setColumn(0,s+320,0,5);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeLeftPurple() {
  int s = 255;
  for (int i = 6; i>=0;i--){
    setColumn(s,0,s,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setColumn(s,0,s,5);
    }
    
    if (i > 64 && i < 319) {
      setColumn(s+64,0,s+64,4);
    }
    if (i > 128 && i < 383) {
      setColumn(s+128,0,s+128,3);
    }
    if (i > 192 && i < 447) {
      setColumn(s+192,0,s+192,2);
    }
    if (i > 256 && i < 511) {
      setColumn(s+256,0,s+256,1);
    }
    if (i > 320) {
      setColumn(s+320,0,s+320,0);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeUpCyan() {
  int s = 255;
  for (int i = 0; i<6;i++){
    setRow(0,s,s,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setRow(0,s,s,0);
    }
    
    if (i > 64 && i < 319) {
      setRow(0,s+64,s+64,1);
    }
    if (i > 128 && i < 383) {
      setRow(0,s+128,s+128,2);
    }
    if (i > 192 && i < 447) {
      setRow(0,s+192,s+192,3);
    }
    if (i > 256 && i < 511) {
      setRow(0,s+256,s+256,4);
    }
    if (i > 320) {
      setRow(0,s+320,s+320,5);
    }
    showAll();
    delay(2);
  }
}
void Lamp::swipeDownYellow() {
  int s = 255;
  for (int i = 5; i>=0;i--){
    setRow(s,s,0,i);
    showAll();
    delay(100);
  }
  for (int i = 0; i <575;i++) {
    s--;
    if (i < 255) {
      setRow(s,s,0,5);
    }
    
    if (i > 64 && i < 319) {
      setRow(s+64,s+64,0,4);
    }
    if (i > 128 && i < 383) {
      setRow(s+128,s+128,0,3);
    }
    if (i > 192 && i < 447) {
      setRow(s+192,s+192,0,2);
    }
    if (i > 256 && i < 511) {
      setRow(s+256,s+256,0,1);
    }
    if (i > 320) {
      setRow(s+320,s+320,0,0);
    }
    showAll();
    delay(2);
  }
}

void Lamp::heart() {
  int pulse = 50;
  strip_a.setPixelColor(2,255,105,180);
  strip_a.setPixelColor(3,255,105,180);
  strip_b.setPixelColor(1,255,105,180);
  strip_b.setPixelColor(2,255,105,180);
  strip_b.setPixelColor(3,255,105,180);
  strip_b.setPixelColor(4,255,105,180);
  setRow(255,105,180,2);
  setRow(255,105,180,3);
  setRow(255,105,180,4);
  strip_f.setPixelColor(4,255,105,180);
  strip_f.setPixelColor(1,255,105,180);
  showAll();
  delay(2500);
  squareFour(0,0,0,4);
  strip_b.setPixelColor(2,255,105,180);
  strip_b.setPixelColor(3,255,105,180);
  strip_c.setPixelColor(1,255,105,180);
  strip_c.setPixelColor(2,255,105,180);
  strip_c.setPixelColor(3,255,105,180);
  strip_c.setPixelColor(4,255,105,180);
  setRow(255,105,180,3);
  strip_e.setPixelColor(4,255,105,180);
  strip_e.setPixelColor(3,255,105,180);
  strip_e.setPixelColor(2,255,105,180);
  strip_e.setPixelColor(1,255,105,180);
  showAll();
  delay(pulse);
  strip_d.setPixelColor(0,0,0,0);
  strip_d.setPixelColor(5,0,0,0);
  strip_e.setPixelColor(1,0,0,0);
  strip_e.setPixelColor(4,0,0,0);
  showAll();
  delay(pulse);
  setRow(0,0,0,1);
  setRow(0,0,0,4);
  setColumn(0,0,0,1);
  setColumn(0,0,0,4);
  showAll();
  delay(600);
  strip_b.setPixelColor(3,255,105,180);
  strip_b.setPixelColor(2,255,105,180);
  strip_c.setPixelColor(4,255,105,180);
  strip_c.setPixelColor(1,255,105,180);
  strip_d.setPixelColor(1,255,105,180);
  strip_d.setPixelColor(4,255,105,180);
  strip_e.setPixelColor(3,255,105,180);
  strip_e.setPixelColor(2,255,105,180);
  showAll();
  delay(pulse);
  strip_d.setPixelColor(0,255,105,180);
  strip_d.setPixelColor(5,255,105,180);
  strip_e.setPixelColor(1,255,105,180);
  strip_e.setPixelColor(4,255,105,180);
  showAll();
  delay(pulse);

}

void Lamp::tronRunner(){

  for(int j = 0; j < 6; j++){
    int r = random8()%50;
    int g = random8()%50;
    int b = random8()%210 + 40;

    if(j == 0){
      for(int i = 0; i < 6; i++){
        strip_a.setPixelColor(i,r,g,b);
        showAll();
      delay(100);
      }
    }
        if(j == 3){
      for(int i = 0; i < 6; i++){
        strip_b.setPixelColor(i,r,g,b);
        showAll();
        delay(100);
      }
    }
        if(j == 5){
      for(int i = 0; i < 6; i++){
        strip_c.setPixelColor(i,r,g,b);
        showAll();
        delay(100);
      }
    }
    if(j == 1){
      for(int i = 0; i < 6; i++){
        strip_d.setPixelColor(i,r,g,b);
        showAll();
        delay(100);
      }
    }
        if(j == 2){
      for(int i = 0; i < 6; i++){
        strip_e.setPixelColor(i,r,g,b);
        showAll();
        delay(100);
      }
    }
        if(j == 5){
      for(int i = 0; i < 6; i++){
        strip_f.setPixelColor(i,r,g,b);
        showAll();
        delay(100);
      }
    }
  }


}

void Lamp::individual(int r, int g, int b, int x, int y){
  if(x == 0){
    strip_a.setPixelColor(y,r,g,b);
  }

   if(x == 1){
    strip_b.setPixelColor(y,r,g,b);
  }

   if(x == 2){
    strip_c.setPixelColor(y,r,g,b);
  }

   if(x == 3){
    strip_d.setPixelColor(y,r,g,b);
  }

   if(x == 4){
    strip_e.setPixelColor(y,r,g,b);
  }

   if(x == 5){
    strip_f.setPixelColor(y,r,g,b);
  }


}

void Lamp::circle(int r, int g, int b, int x, int y){
  individual(r,g,b,x,y);
  showAll();
  delay(150);

  squareFour(0,0,0,4);
  showAll();
  for(int i = -1; i < 0; i++){
        individual(r,g,b,x+i,y);
        individual(r,g,b,x,y+i);
        individual(r,g,b,x+i,y+i); 
        individual(r,g,b,x-i,y);
        individual(r,g,b,x,y-i);
        individual(r,g,b,x-i,y-i); 
        individual(r,g,b,x+i,y-i);
        individual(r,g,b,x-i,y+i);             
  }
    for(int i = 1; i < 2; i++){
        individual(r,g,b,x+i,y);
        individual(r,g,b,x,y+i);
        individual(r,g,b,x+i,y+i); 
        individual(r,g,b,x-i,y);
        individual(r,g,b,x,y-i);
        individual(r,g,b,x-i,y-i); 
        individual(r,g,b,x+i,y-i);
        individual(r,g,b,x-i,y+i);             
  }
    showAll();
  delay(150);
  squareFour(0,0,0,4);
  showAll();


  setRow(r,g,b,x+2);
  setRow(r,g,b,x-2);
  setColumn(r,g,b,y-2);
  setColumn(r,g,b,y+2);

  setRow(0,0,0,x+3);
  setRow(0,0,0,x-3);
  setColumn(0,0,0,y+3);
  setColumn(0,0,0,y-3);

  individual(0,0,0,x+2,y+2);
  individual(0,0,0,x-2,y-2);
  individual(0,0,0,x+2,y-2);
  individual(0,0,0,x-2,y+2);

  showAll();
  delay(150);
  squareFour(0,0,0,4);
  showAll();

  setRow(r,g,b,x+3);
  setRow(r,g,b,x-3);
  setColumn(r,g,b,y+3);
  setColumn(r,g,b,y-3);
  individual(0,0,0,x+3,y+3);
  individual(0,0,0,x-3,y-3);
  individual(0,0,0,x+3,y-3);
  individual(0,0,0,x-3,y+3);

  showAll();
  delay(150);
  squareFour(0,0,0,4);
  showAll();





}