#include "PiConnection.h"

PiConnection::PiConnection() {

}

void PiConnection::init() {
//  pinMode(A0, OUTPUT);
}

boolean PiConnection::detectObstacle() {
  if(Serial.available() > 0){
    int fromPi = Serial.read();    
    if(fromPi){

      return true;
    }
  }
  return false;
}
