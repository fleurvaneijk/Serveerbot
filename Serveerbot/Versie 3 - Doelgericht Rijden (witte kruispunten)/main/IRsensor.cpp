#include "IRsensor.h"
#include <IRremote.h>

IRrecv irrecv(2);
decode_results result;

IRsensor::IRsensor() {
}

void IRsensor::init() {
  irrecv.enableIRIn();
}

int IRsensor::readSignal() {
  if (irrecv.decode(&result)){
    int tableNumber = convertSignal(result.value);
//    Serial.println(tableNumber);
    irrecv.resume();
    return tableNumber;
  } else {
    return 0;
  }
}

int IRsensor::convertSignal(int value) {
  int tableNumber;
  switch (value) {
    case 134775421: tableNumber = 1; break;
    case 134759101: tableNumber = 2; break;
    case 134791741: tableNumber = 3; break;
    case 134750941: tableNumber = 4; break;
    case 134783581: tableNumber = 5; break;
    case 134767261: tableNumber = 6; break;
    case 134799901: tableNumber = 7; break;
    case 134746861: tableNumber = 8; break;
    case 134779501: tableNumber = 9; break;
    default: Serial.println("default");
  }
  return tableNumber;
}
