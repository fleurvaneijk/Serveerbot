#include "IRsensor.h"
#include "Motors.h"
#include "TrackerSensor.h"
#include "LightSensor.h"

IRsensor irSensor = IRsensor();
Motors motors = Motors();
TrackerSensor trackerSensor = TrackerSensor();
LightSensor lightSensor = LightSensor();

boolean driving = false;
int tableNumber;
int intersectionCounter = 0;
int stopCounter = 0;
boolean coffeeOnRobot;

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

    if(tableNumber >= 1 && tableNumber <= 9 && lightSensor.checkIfDark()){
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
    motors.turnAround();
    do{
      coffeeOnRobot = lightSensor.checkIfDark();
      motors.stopDriving();
    }while(coffeeOnRobot == true);
   
    if(coffeeOnRobot == false){
      stopCounter ++;
    }    
    if(stopCounter == 2) { //kitchen reached      
      intersectionCounter = 0;
      stopCounter = 0;
      driving = false;
      tableNumber = 0;
    }    
  }
  
}
