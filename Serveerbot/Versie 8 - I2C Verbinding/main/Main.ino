#include <Wire.h>
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
boolean objectDetected = false;

void setup() {
  Serial.begin(9600);
  irSensor.init();
  motors.init();
  Wire.begin(0x8);
  Wire.onReceive(detectObstacle);
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

  if(objectDetected == true){
    digitalWrite(4, HIGH);
    motors.stopDriving();
    delay(5000);
  } else {
    digitalWrite(4, LOW);
  }

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
  } 
  else if(drivingDirection == "STOP"){
    motors.turnAround();
    do{
      coffeeOnRobot = lightSensor.checkIfDark();
      motors.stopDriving();
    }while(coffeeOnRobot == true);
   
    if(coffeeOnRobot == false){
      stopCounter ++;
    }    
    if(stopCounter == 2) { //kitchen reached
      Serial.println("kitchen reached");    
      intersectionCounter = 0;
      stopCounter = 0;
      tableNumber = 0;
      driving = false;
    }    
  } 
}

void detectObstacle(int howMany) {
  if (Wire.available()) {
    char c = Wire.read();
    if(c){
      objectDetected = true;
    } else {
      objectDetected = false; 
    }
  }
}
