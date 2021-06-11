#ifndef settings_h
#define settings_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

struct Settings {
  char state[32];
  char colour[32];
};

boolean loadSettings(fs::FS &fs, const char *path, Settings &settings);

void saveSettings(fs::FS &fs, const char * path, const Settings &settings);



#endif