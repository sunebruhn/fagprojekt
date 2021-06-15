#include "files.h"

bool checkFile(fs::FS &fs, const char * path){
  Serial.printf("Checking file: %s\r\n", path);

  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    Serial.println("- empty file or failed to open file");
    return 0;
  } else {
    Serial.println("- File exists");
    return 1;
  }
}

/* virker ikke hvis der er noget andet før kodeordet. I øvrigt er det nok bedre bare at bruge readFile og lave nogle funktioner til at kigge på Strings.
String readFileCode(fs::FS &fs, const char * path, const char * code){
  Serial.printf("Reading file %s for code %s\r\n", path, code);

  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    Serial.println("- empty file or failed to open file");
    return String();
  }
  
  Serial.println("- read from file:");
  String fileContent;
  String compareCode = "";
  char appendChar;
  while(file.available()) {
    appendChar = (char)file.read();

    if(appendChar == (' ' || '\n')){
        Serial.println("compare reset");
        Serial.println(compareCode);
        compareCode = "";
    } else {
        compareCode += String(appendChar);
    }

    if(compareCode == code){
        Serial.println("break");
        Serial.println(compareCode);
        break;
    }
  }
    
  while(file.available()){   
    appendChar = (char)file.read();
    if(appendChar == '\n'){
        break;
    }
    fileContent += appendChar;
  }
  
  Serial.println("Success");
  Serial.println(fileContent);
  return fileContent;
}
*/

const char * readFile(fs::FS &fs, const char * path){
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    Serial.println("- empty file or failed to open file");
    return {};
  }

  Serial.println("- read from file:");
  String fileContent;
  while(file.available()){
    fileContent+=String((char)file.read());
  }
  Serial.println(fileContent);
  const char * data = fileContent.c_str();
  return data;
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}


/* UMIDDELBART IKKE NOGET VI SKAL BRUGE
void appendFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}
*/
/* UMIDDELBART IKKE NOGET VI SKAL BRUGE
void renameFile(fs::FS &fs, const char * path1, const char * path2){
    Serial.printf("Renaming file %s to %s\n", path1, path2);
    if (fs.rename(path1, path2)) {
        Serial.println("File renamed");
    } else {
        Serial.println("Rename failed");
    }
}
*/
/*
void deleteFile(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\n", path);
    if(fs.remove(path)){
        Serial.println("File deleted");
    } else {
        Serial.println("Delete failed");
    }
}
*/