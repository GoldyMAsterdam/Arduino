#include <ArduinoJson.h>
StaticJsonDocument<256> doc; 

const char* password2 = "duurzaamhuisBO"; 

void CreateJSON() {
  doc["ldr"] = String(Light);
  doc["dht11"]["Temperature"] = String(Temperature);
  doc["dht11"]["Humidity"] = String(Humidity);
  doc["dht11"]["HeatIndex"] = String(HeatIndex);
  doc["password"] = password2;
  serializeJson(doc, jsonOut);
}

void ReadJSON(String resJSON) {
  resJSON.remove(0,9);
  StaticJsonDocument<200> resDoc;
  deserializeJson(resDoc, resJSON);
  digitalWrite(D3, bool(resDoc["lights"][0]));
  digitalWrite(D5, bool(resDoc["lights"][1]));
  digitalWrite(D6, bool(resDoc["lights"][2]));
}

void SendJSONToSerial() {
  serializeJson(doc, Serial);
  Serial.println();
}
