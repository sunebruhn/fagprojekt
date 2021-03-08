#ifndef files_h
#define files_h

#include <Arduino.h>
#include <SPIFFS.h>

bool checkFile(fs::FS &fs, const char * path);

String readFileCode(fs::FS &fs, const char * path, const char * code);

String readFile(fs::FS &fs, const char * path);

void writeFile(fs::FS &fs, const char * path, const char * message);

#endif