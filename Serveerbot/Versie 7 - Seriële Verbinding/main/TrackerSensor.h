#ifndef TRACKERSENSOR_H
#define TRACKERSENSOR_H

#include <Arduino.h>

class TrackerSensor {

  private:
    const byte leftSensorPin = A3;
    const byte centerSensorPin = A2;
    const byte rightSensorPin = A1;

  public:
    TrackerSensor();
    void init();
    String followLine();
};
#endif
