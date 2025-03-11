int ledPin = D3;
int val = 0;


void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
}

void loop() {
  // T
  digitalWrite(D3, HIGH); 
  delay(1500); 
  digitalWrite(D3, LOW);
  delay(250);

  // Y
  digitalWrite(D5, HIGH);
  delay (1500);
  digitalWrite(D5, LOW);
  delay(250);
   digitalWrite(D5, HIGH);
  delay (500);
  digitalWrite(D5, LOW);
  delay(1500);
  digitalWrite(D5, HIGH);
  delay (1500);
  digitalWrite(D5, LOW);
  delay(250);

  // C
  digitalWrite(D6, HIGH);
  delay(1500);
  digitalWrite(D6, LOW);
  delay(250);
  digitalWrite(D6, HIGH);
  delay(500);
  digitalWrite(D6, LOW);
  delay(250);
  digitalWrite(D6, HIGH);
  delay(1500);
  digitalWrite(D6, LOW);
  delay(250);
  digitalWrite(D6, HIGH);
  delay(500);
  digitalWrite(D6, LOW);
  delay(250);

  // H
  digitalWrite(D3, HIGH); 
  delay(500); 
  digitalWrite(D3, LOW);
  delay(250);
  digitalWrite(D3, HIGH); 
  delay(500); 
  digitalWrite(D3, LOW);
  delay(250);
  digitalWrite(D3, HIGH); 
  delay(500); 
  digitalWrite(D3, LOW);
  delay(250);
  digitalWrite(D3, HIGH); 
  delay(500); 
  digitalWrite(D3, LOW);
  delay(250);
  
  
  // O
  digitalWrite(D5, HIGH); 
  delay(1500); 
  digitalWrite(D5, LOW);
  delay(250);
  digitalWrite(D5, HIGH); 
  delay(1500); 
  digitalWrite(D5, LOW);
  delay(250);
  digitalWrite(D5, HIGH); 
  delay(1500); 
  digitalWrite(D5, LOW);
  delay(250);
}
