#define MAX_UNSIGNED_LONG 4294967295
#define DHT11ReadDelay 5000

// GLOBAL VARIABLES
char jsonOut[256]; 
float Temperature = -1, Humidity = -1, HeatIndex = -1; 
int Light = -1; 

void setup() {
  Serial.begin(115200);

  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  
  SetupWifi();
  CheckWifi();
  SetupSensors();
 }

void loop() {
  static unsigned long previousTime = 0;
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= DHT11ReadDelay || currentTime >= MAX_UNSIGNED_LONG - DHT11ReadDelay) {
    Serial.println("\nReading sensors...");
    ReadSensors();
    
    Serial.println("Creating JSON...");
    CreateJSON();
        
    Serial.println("Sending POST...");
    SendPOST(jsonOut);
    previousTime = millis();
  }

  CheckWifi();
  delay(50);
}
