#ifndef lamp_h
#define lamp_h

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS  36

class Lamp
{
    public:

        static bool state;

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
            strip_a.setBrightness(64);
            strip_b.setBrightness(64);
            strip_c.setBrightness(64);
            strip_d.setBrightness(64);
            strip_e.setBrightness(64);
            strip_f.setBrightness(64);
        }
        void around(int32_t r, int32_t g, int32_t b);
        void uniformcolor(int32_t r, int32_t g, int32_t b);
        void squareFour(int r, int g, int b, int corner);
        void checkleds();
        void checkcolor();
        void rainbow();
        void cascade();
        void circle();
        void runAround();
};

#endif