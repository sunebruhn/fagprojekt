#ifndef lamp_h
#define lamp_h

#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

#define NUMPIXELS  6
#define BRIGNTNESS 255

enum lampMode{OFF, UNIFORM, SWIPE};

class Lamp
{
    public:

        static bool state;
        static int32_t r, g, b;
        static enum lampMode mode;

        Adafruit_NeoPixel strip_a;
        Adafruit_NeoPixel strip_b;
        Adafruit_NeoPixel strip_c;
        Adafruit_NeoPixel strip_d;
        Adafruit_NeoPixel strip_e;
        Adafruit_NeoPixel strip_f;
        Lamp() : 
            strip_a(NUMPIXELS, 16, NEO_GRB + NEO_KHZ800), 
            strip_b(NUMPIXELS, 17, NEO_GRB + NEO_KHZ800),
            strip_c(NUMPIXELS, 18, NEO_GRB + NEO_KHZ800),
            strip_d(NUMPIXELS, 19, NEO_GRB + NEO_KHZ800),
            strip_e(NUMPIXELS, 21, NEO_GRB + NEO_KHZ800),
            strip_f(NUMPIXELS, 22, NEO_GRB + NEO_KHZ800)
        {
            strip_a.begin();
            strip_b.begin();
            strip_c.begin();
            strip_d.begin();
            strip_e.begin();
            strip_f.begin();
            strip_a.setBrightness(BRIGNTNESS);
            strip_b.setBrightness(BRIGNTNESS);
            strip_c.setBrightness(BRIGNTNESS);
            strip_d.setBrightness(BRIGNTNESS);
            strip_e.setBrightness(BRIGNTNESS);
            strip_f.setBrightness(BRIGNTNESS);
        }
        
        void task();
        static void startTaskImpl(void*);
        void startTask(TaskHandle_t taskHandle);
        

        void update();

        // member functions
        void squareFour(int r, int g, int b, int corner);
        void runAround();
       // void water();
        void randomLights();
        void colorFlow();
        void setRow(int r, int g, int b, int strip);
        void setColumn(int r, int g, int b, int column);
        void showAll();
        void swipeRightBlue();
        void swipeLeftRed();
        void swipeUpGreen();
        void swipeDownPurple();
        void swipeRightCyan();
        void swipeLeftYellow();
        void swipeUpBlue();
        void swipeDownRed();
        void swipeRightGreen();
        void swipeLeftPurple();
        void swipeUpCyan();
        void swipeDownYellow();
        void swipe();
        void rainbowStrideColumn();
        void rainbowStrideRow();
        void heart();
        void tronRunner();
        void individual(int r, int g, int b, int x, int y);
        void circle(int r, int g, int b, int x, int y);
        void uniform();
        void clearAll();
        void circleReal();
};

#endif