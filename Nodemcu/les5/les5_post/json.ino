#include <ArduinoJson.h>
// JSON document
StaticJsonDocument<256> doc; // Vergroot voor het wachtwoord

// Wachtwoord voor beveiliging
const char* password = "duurzaamhuisBO"; // Nieuw wachtwoord

void CreateJSON() {
  doc["ldr"] = String(Light);
  doc["dht11"]["Temperature"] = String(Temperature);
  doc["dht11"]["Humidity"] = String(Humidity);
  doc["dht11"]["HeatIndex"] = String(HeatIndex);
  doc["password"] = password; // Voeg het wachtwoord toe aan de JSON
  serializeJson(doc, jsonOut);
}

void ReadJSON(String resJSON) {
  // remove "response: " from resJSON
  resJSON.remove(0,9);
  StaticJsonDocument<200> resDoc;
  deserializeJson(resDoc, resJSON);
  digitalWrite(D3, bool(resDoc["lights"][0]));
  digitalWrite(D5, bool(resDoc["lights"][1]));
  digitalWrite(D6, bool(resDoc["lights"][2]));
}

// JSON debug naar Serial Monitor
void SendJSONToSerial() {
  serializeJson(doc, Serial);
  Serial.println();
}
