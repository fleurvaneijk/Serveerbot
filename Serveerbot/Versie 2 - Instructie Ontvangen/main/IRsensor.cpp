#include "IRsensor.h"
#include <IRremote.h>

byte IRPIN = 0;
IRrecv irrecv(IRPIN);
decode_results result;

IRsensor::IRsensor(byte pin) {
  this->pin = pin;
  IRPIN = this->pin;
}

void IRsensor::init() {
  Serial.println("Enabling IR sensor");
  irrecv.enableIRIn();
  Serial.println("Enabled IR sensor");
}

int IRsensor::readSignal() {
  if (irrecv.decode(&result)){
    int target = convertSignal(result.value);
    irrecv.resume();
    return(target);
  }
}

int IRsensor::convertSignal(int value) {
  int target;
  switch (value) {
    case 134775421: target = 1; break;
    case 134759101: target = 2; break;
    case 134791741: target = 3; break;
    case 134750941: target = 4; break;
    case 134783581: target = 5; break;
    case 134767261: target = 6; break;
    case 134799901: target = 7; break;
    case 134746861: target = 8; break;
    case 134779501: target = 9; break;
    case 134795821: target = 0; break;
    default: Serial.println("default");
  }
  return target;
}
