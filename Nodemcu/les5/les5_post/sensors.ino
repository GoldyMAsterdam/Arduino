#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define LDRPIN A0

void SetupSensors() {
  dht.begin();
  delay(2000);
}

void ReadSensors() {
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  HeatIndex = dht.computeHeatIndex(Temperature, Humidity, false);
  Light = analogRead(LDRPIN);
  Serial.print("Temperature: "); Serial.println(Temperature);
  Serial.print("Humidity: "); Serial.println(Humidity);
  Serial.print("Heat Index: "); Serial.println(HeatIndex);
  Serial.print("Light: "); Serial.println(Light);
}
