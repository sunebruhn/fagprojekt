#ifndef alarm_h
#define alarm_h

#include <Arduino.h>
#include <sys/time.h>
#include <time.h>
#include <lamp.h>

#define ntpServer "pool.ntp.org"
#define gmtOffset_sec 3600
#define daylightOffset_sec 3600

struct Clk
{
  int	clk_min;
  int	clk_hour;    
};

class Alarm
{
    public:
    
        struct tm timeinfo;
        static bool enable;
        static struct Clk turnOn, turnOff;

        Alarm()
        {
            configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        }
        
        void task();
        static void startTaskImpl(void*);
        void startTask(TaskHandle_t taskHandle);
        void printLocalTimeLoop();

        void task2();
        static void startTaskImpl2(void*);
        void startTask2(TaskHandle_t taskHandle);
        void checkTime();
        bool compareTime(struct Clk clk);
};


#endif