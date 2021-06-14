#include "wificonfig.h"

// Loads the configuration from a file *************************************************************************************

boolean loadConfiguration(fs::FS &fs, const char *path, Config &config)
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
    strlcpy(config.ssid,          // <- destination
            doc["ssid"] | "",     // <- source
            sizeof(config.ssid)); // <- destination's capacity
    strlcpy(config.pass,          // <- destination
            doc["pass"] | "",     // <- source
            sizeof(config.pass)); // <- destination's capacity

    // Close the file (Curiously, File's destructor doesn't close the file)
    file.close();
    return true;
}

// Saves the configuration to a file *************************************************************************************

void saveConfiguration(fs::FS &fs, const char *path, const Config &config)
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
    doc["ssid"] = config.ssid;
    doc["pass"] = config.pass;

    // Serialize JSON to file
    if (serializeJson(doc, file) == 0)
    {
        Serial.println(F("Failed to write to file"));
    }

    // Close the file
    file.close();
}