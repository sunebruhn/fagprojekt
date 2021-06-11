#include "settings.h"

boolean loadSettings(fs::FS &fs, const char *path, Settings &settings)
{
    // Open file for reading
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path, "r");
    if (!file || file.isDirectory())
    {
        Serial.println("- empty file or failed to open file");
        return false;
    }

    // Allocate a temporary JsonDocument
    // Don't forget to change the capacity to match your requirements.
    // Use arduinojson.org/v6/assistant to compute the capacity.
    StaticJsonDocument<512> doc;

    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, file);
    if (error)
    {
        Serial.println(F("Failed to read file, using default configuration"));
        return false;
    }

    // Copy values from the JsonDocument to the Config
    strlcpy(settings.state,          // <- destination
            doc["state"] | "",     // <- source
            sizeof(settings.state)); // <- destination's capacity
    Serial.println(settings.state);
    // Close the file (Curiously, File's destructor doesn't close the file)
    file.close();
    return true;
}

void saveSettings(fs::FS &fs, const char * path, const Settings &settings)
{
Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        Serial.println("Failed to open file for writing");
        return;
    }

    // Allocate a temporary JsonDocument
    // Don't forget to change the capacity to match your requirements.
    // Use arduinojson.org/assistant to compute the capacity.
    StaticJsonDocument<256> doc;

    // Set the values in the document
    doc["state"] = settings.state;

    // Serialize JSON to file
    if (serializeJson(doc, file) == 0)
    {
        Serial.println(F("Failed to write to file"));
    }

    // Close the file
    file.close();
}