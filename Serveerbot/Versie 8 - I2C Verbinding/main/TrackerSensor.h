#ifndef TRACKERSENSOR_H
#define TRACKERSENSOR_H

#include <Arduino.h>

class TrackerSensor {

  private:
    const byte leftSensorPin = A3; //brown
    const byte centerSensorPin = A4; //orange
    const byte rightSensorPin = A5; //yellow

  public:
    TrackerSensor();
    void init();
    String followLine();
};
#endif
