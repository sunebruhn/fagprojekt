#ifndef wificonfig_h
#define wificonfig_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

struct Config {
  char ssid[32];
  char pass[32];
};

boolean loadConfiguration(fs::FS &fs, const char *path, Config &config);

void saveConfiguration(fs::FS &fs, const char * path, const Config &config);

#endif