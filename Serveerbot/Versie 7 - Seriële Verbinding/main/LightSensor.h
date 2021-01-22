#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Arduino.h>
 
class LightSensor {
  
  private:
    const byte pin = A0;

  public:
    LightSensor();
    void init();
    boolean checkIfDark();
};
#endif
