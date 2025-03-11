#include <ArduinoJson.h>

// JSON document
StaticJsonDocument<128> doc;

void CreateJSON() {
  static int attempt = 0;
  
  doc["attempt"] = ++attempt;
  doc["temperature"] = Temperature;
  doc["humidity"] = Humidity;
  doc["heat_index"] = HeatIndex;
  doc["light"] = Light;

  serializeJson(doc, jsonOut);
}

// JSON debug naar Serial Monitor
void SendJSONToSerial() {
  serializeJson(doc, Serial);
  Serial.println();
}
