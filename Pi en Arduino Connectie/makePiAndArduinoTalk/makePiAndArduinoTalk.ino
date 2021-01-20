int fromPi = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
}

void loop() {

  if(Serial.available() > 0){
    fromPi = Serial.read();
  
    Serial.print("Received: ");
    Serial.println(fromPi, DEC);
    
    if(fromPi = 'E'){
      digitalWrite(A0, HIGH);
      delay(500);
      digitalWrite(A0, LOW);
      delay(500);
    }
  }
}
