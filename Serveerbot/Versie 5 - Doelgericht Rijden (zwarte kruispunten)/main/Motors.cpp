#include "Motors.h"
#include <AccelStepper.h>

AccelStepper motor1;
AccelStepper motor2;

Motors::Motors() {
  
}

void Motors::init() {
  motor1 = AccelStepper(this->motorInterfaceType, this->stepPin1, this->dirPin1);
  motor2 = AccelStepper(this->motorInterfaceType, this->stepPin2, this->dirPin2);
  motor1.setMaxSpeed(600);
  motor2.setMaxSpeed(600);
}

void Motors::drive() {
  motor1.setSpeed(100);
  motor1.runSpeed();
  motor2.setSpeed(-100);
  motor2.runSpeed();
}

void Motors::intersection(String side) {
  motor1.setSpeed(100);
  motor1.setAcceleration(100);
  motor2.setSpeed(-100);
  motor2.setAcceleration(100);
  motor1.move(50);
  motor2.move(-50);
  while (motor1.currentPosition() != motor1.targetPosition()){
    motor1.run();
    motor2.run();
  }

  if(side == "STRAIGHT"){
    motor1.move(100);
    motor2.move(-100);
    while (motor1.currentPosition() != motor1.targetPosition()){
      motor1.run();
      motor2.run();
    }       
  }
            
  else if(side == "LEFT"){
      motor1.move(660);
      motor2.move(160);
      while (motor1.currentPosition() != motor1.targetPosition()){
        motor1.run();
        motor2.run();
      }
      
  } else if(side == "RIGHT"){
      motor1.move(-130);
      motor2.move(-630);
      while (motor2.currentPosition() != motor2.targetPosition()){
        motor1.run();
        motor2.run();
      }        
  }
}

void Motors::turnLeft() {
  motor1.setSpeed(100);
  motor1.runSpeed();
  motor2.setSpeed(100);
  motor2.runSpeed();
}

void Motors::turnRight() {
  motor1.setSpeed(-100);
  motor1.runSpeed();
  motor2.setSpeed(-100);
  motor2.runSpeed();
}

void Motors::stopDriving() {
  motor1.setSpeed(0);
  motor1.runSpeed();
  motor2.setSpeed(0);
  motor2.runSpeed();
}

void Motors::turnAround() {
  motor1.setSpeed(100);
  motor1.setAcceleration(100);
  motor2.setSpeed(-100);
  motor2.setAcceleration(100);
  motor1.move(800);
  motor2.move(800);
  while (motor1.currentPosition() != motor1.targetPosition()){
    motor1.run();
    motor2.run();
  }
}
