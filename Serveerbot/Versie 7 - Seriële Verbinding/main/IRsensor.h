#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <Arduino.h>
 
class IRsensor {
  
  private:
    int convertSignal(int value);

  public:
    IRsensor();
    void init();
    int readSignal();
};
#endif
