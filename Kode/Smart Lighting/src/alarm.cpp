#include "alarm.h"

void Alarm::printLocalTimeLoop()
{
  while(!getLocalTime(&timeinfo)){
    Serial.println("printLocalTimeLoop: Failed to obtain time");
    
  }
  Serial.println(&timeinfo, "printLocalTimeLoop: %A, %B %d %Y %H:%M:%S");
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