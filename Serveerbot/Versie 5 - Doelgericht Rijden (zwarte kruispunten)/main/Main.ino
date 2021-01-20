#include "IRsensor.h"
#include "Motors.h"
#include "TrackerSensor.h"

IRsensor irSensor = IRsensor();
Motors motors = Motors();
TrackerSensor trackerSensor = TrackerSensor();

boolean driving = false;
int tableNumber;
int intersectionCounter = 0;
int stopCounter = 0;

void setup() {
  Serial.begin(9600);
  irSensor.init();
  motors.init();
  trackerSensor.init();
  Serial.println("Init complete");
}

void loop() {
  if(driving == false){
    tableNumber = irSensor.readSignal();
    delay(100);

    if(tableNumber >= 1 && tableNumber <= 9){
      driving = true;
    }
  } else if(driving == true){
    drive(tableNumber);
  }
}

void drive(int tableNumber){
  String drivingDirection = trackerSensor.followLine();

  if(drivingDirection == "STRAIGHT"){
    motors.drive();
  } else if(drivingDirection == "INTERSECTION"){
    intersectionCounter ++;
    if(intersectionCounter == tableNumber) {
      motors.intersection("RIGHT");
    } else if(intersectionCounter == tableNumber + 1){
      motors.intersection("LEFT");
    } else {
      motors.intersection("STRAIGHT");
    }
  } else if(drivingDirection == "LEFT"){
    motors.turnLeft();
  } else if(drivingDirection == "RIGHT"){
    motors.turnRight();
  } else if(drivingDirection == "STOP"){
    stopCounter ++;
    motors.stopDriving();
    
    //TODO make LightSensor class that checks if coffee is picked up from robot
    
    if(stopCounter == 2) { //kitchen reached
      intersectionCounter = 0;
      stopCounter = 0;
      driving = false;
    }    
  }
  
}
