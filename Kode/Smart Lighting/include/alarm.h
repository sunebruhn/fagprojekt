#ifndef alarm_h
#define alarm_h

#include <Arduino.h>
#include <sys/time.h>
#include <time.h>

#define ntpServer "pool.ntp.org"
#define gmtOffset_sec 3600
#define daylightOffset_sec 3600

class Alarm
{
    public:
    
        struct tm timeinfo;

        Alarm()
        {
            configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        }
        
        void task();
        static void startTaskImpl(void*);
        void startTask(TaskHandle_t taskHandle);

        void printLocalTimeLoop();

};


#endif