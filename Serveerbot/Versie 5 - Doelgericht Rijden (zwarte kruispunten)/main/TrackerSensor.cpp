#include "TrackerSensor.h"

String drivingDirection;

TrackerSensor::TrackerSensor() {

}

void TrackerSensor::init() {
  pinMode(this->leftSensorPin, INPUT);
  pinMode(this->centerSensorPin, INPUT);
  pinMode(this->rightSensorPin, INPUT);
}

String TrackerSensor::followLine() {
  byte left = digitalRead(this->leftSensorPin);
  byte center = digitalRead(this->centerSensorPin);
  byte right = digitalRead(this->rightSensorPin);
  
  // BLACK = 0        WHITE = 1

  if(left == 1 && center == 0 && right == 1){             // Straight Line
    drivingDirection = "STRAIGHT";
  } else if(left == 0 && center == 0 && right == 0){      // Intersection 
    drivingDirection = "INTERSECTION";
  } else if(left == 0 && center == 1 && right == 1){      // Flauwe bocht links
    drivingDirection = "LEFT";
  } else if(left == 1 && center == 1 && right == 0){      // Flauwe bocht rechts 
    drivingDirection = "RIGHT";
  } else if(left == 0 && center == 0 && right == 1){      // Scherpe bocht links
    drivingDirection = "LEFT";
  } else if(left == 1 && center == 0 && right == 0){      // Scherpe bocht rechts
    drivingDirection = "RIGHT";
  } else if(left == 1 && center == 1 && right == 1){      // 'T' Eindpunt
    drivingDirection = "STOP";
  }
  
  return drivingDirection;
}
