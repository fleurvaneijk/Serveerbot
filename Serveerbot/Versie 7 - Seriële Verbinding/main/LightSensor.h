#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Arduino.h>
 
class LightSensor {
  
  private:
    const byte pin = A1;

  public:
    LightSensor();
    void init();
    boolean checkIfDark();
};
#endif
