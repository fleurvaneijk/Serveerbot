#include "LightSensor.h"

int ldrValue; 

LightSensor::LightSensor() {
}

void LightSensor::init() {
  pinMode(this->pin, INPUT);
}

boolean LightSensor::checkIfDark() {
  ldrValue = analogRead(this->pin);
  
//  Serial.print("LDR value is : ");
//  Serial.println(ldrValue);
  
  if(ldrValue < 50){
    return true;
  }
  else {
    return false;
  }  
}
