#ifndef PICONNECTION_H
#define PICONNECTION_H

#include <Arduino.h>

class PiConnection {

  private:
    boolean objectDetected = false;
    String drivingDirection;

  public:
    PiConnection();
    void init();
    String checkForSignal();
    void sendTableNumber(int tableNumber);
};
#endif
