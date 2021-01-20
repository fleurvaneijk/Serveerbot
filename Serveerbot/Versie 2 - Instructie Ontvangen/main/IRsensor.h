#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <Arduino.h>
 
class IRsensor {
  
  private:
    byte pin;
    int convertSignal(int value);

  public:
    IRsensor(byte pin);
    void init();
    int readSignal();
};
#endif
