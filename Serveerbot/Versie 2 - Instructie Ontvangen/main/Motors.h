#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

class Motors {
  
  private:
    const byte dirPin1 = 8;
    const byte stepPin1 = 9;
    const byte dirPin2 = 10;
    const byte stepPin2 = 11;
    const int stepsPerRevolution = 200;
    const byte motorInterfaceType = 1;
    
  public:
    Motors();
    void init();
    void drive();
};
#endif
