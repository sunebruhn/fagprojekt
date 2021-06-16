#include "alarm.h"

bool Alarm::enable = 0;
struct Clk Alarm::turnOn;
struct Clk Alarm::turnOff;

// gets time
void Alarm::printLocalTimeLoop()
{
  while(!getLocalTime(&timeinfo)){
    Serial.println("printLocalTimeLoop: Failed to obtain time");
    
  }
  Serial.println(&timeinfo, "printLocalTimeLoop: %A, %B %d %Y %H:%M:%S");
  startTask2(NULL);
  vTaskDelete(NULL);
}

void Alarm::task(){
     while(1){
         this->printLocalTimeLoop();
     }
}

void Alarm::startTaskImpl(void* parm){
    static_cast<Alarm*>(parm)->task();
}
void Alarm::startTask(TaskHandle_t taskHandle){
    xTaskCreate(this->startTaskImpl, "Task", 2048, this, 0, &taskHandle);
}

// checks time to turn on and off
bool Alarm::compareTime(struct Clk clk)
{
  if (clk.clk_hour == timeinfo.tm_hour && clk.clk_min == timeinfo.tm_min && timeinfo.tm_sec == (0 || 1))
  {
    Serial.println("compareTime true");
    return 1;
  }
  return 0;
}

void Alarm::checkTime()
{
  getLocalTime(&timeinfo);
  if(compareTime(turnOff))
  {
    Lamp tmpLamp;
    tmpLamp.state = 0;
    Serial.println("lamp off");
    return;
  }
  if(compareTime(turnOn))
  {
    Lamp tmpLamp;
    tmpLamp.state = 1;
    Serial.println("lamp on");
    return;
  }
}

void Alarm::task2(){
     while(1){
       if(enable){
         this->checkTime();
       }
      vTaskDelay(1000);
     }
}

void Alarm::startTaskImpl2(void* parm){
    static_cast<Alarm*>(parm)->task2();
}
void Alarm::startTask2(TaskHandle_t taskHandle){
    xTaskCreate(this->startTaskImpl2, "Task2", 2048, this, 0, &taskHandle);
}