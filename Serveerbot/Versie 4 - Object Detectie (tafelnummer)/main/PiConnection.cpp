#include "PiConnection.h"

PiConnection::PiConnection() {

}

void PiConnection::init() {
  
}

String PiConnection::checkForSignal() {
  if(Serial.available() > 0){
    this->objectDetected = Serial.read();
  
    Serial.print("Received: ");
    Serial.println(this->objectDetected, DEC);   
  }

  if(this->objectDetected == true){
    return "STOP";
  }
}


void PiConnection::sendTableNumber(int tableNumber) {
  Serial.println(tableNumber);
}
