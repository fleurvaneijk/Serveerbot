#include "LightSensor.h"

int ldrValue; 

LightSensor::LightSensor() {
}

void LightSensor::init() {
}

boolean LightSensor::checkIfDark() {
  ldrValue = analogRead(this->pin);
    
  if(ldrValue < 50){
    return true;
  } else {
    return false;
  }  
}
