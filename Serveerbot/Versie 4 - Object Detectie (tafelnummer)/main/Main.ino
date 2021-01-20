#include "IRsensor.h"
#include "Motors.h"
#include "TrackerSensor.h"
#include "PiConnection.h"

IRsensor irSensor = IRsensor();
PiConnection pi = PiConnection();
Motors motors = Motors();
TrackerSensor trackerSensor = TrackerSensor();

boolean driving = false;
int tableNumber;
int intersectionCounter = 0;
int stopCounter = 0;
boolean coffeeLight;

void setup() {
  Serial.begin(9600);
  irSensor.init();
  motors.init();
  trackerSensor.init();
}

void loop() {
  if(driving == false){
    tableNumber = irSensor.readSignal();
    delay(100);
    if(tableNumber >= 1 && tableNumber <= 9){
      pi.sendTableNumber(tableNumber);
      driving = true;
    }
  } else if(driving == true){
    drive(tableNumber);
  }
}

void drive(int tableNumber){
  String drivingDirection = trackerSensor.followLine();

//  Serial.print("drivind direction: ");
//  Serial.println(drivingDirection);

  if(drivingDirection == "STRAIGHT"){
    motors.drive();
  } else if(drivingDirection == "INTERSECTION"){
    intersectionCounter ++;
//    Serial.println(intersectionCounter);
    if(intersectionCounter == tableNumber || intersectionCounter == tableNumber + 1) {
      motors.intersection("RIGHT"); //TODO: hij gaat nu alleen rechts bij kruispunten
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
//    coffeeLight = false;
//    if(coffeeLight == false){ //check if coffee is not on robot
//      motors.turnAround();
//    }
    
    if(stopCounter == 2) { //kitchen reached
      intersectionCounter = 0;
      stopCounter = 0;
      driving = false;
    }    
  }
  
}
