#include "Motors.h"
#include <AccelStepper.h>

AccelStepper motor1;
AccelStepper motor2;

Motors::Motors() {
  
}

void Motors::init() {
  Serial.println("Enabling Motor");
  
  motor1 = AccelStepper(this->motorInterfaceType, this->stepPin1, this->dirPin1);
  motor2 = AccelStepper(this->motorInterfaceType, this->stepPin2, this->dirPin2);
  motor1.setMaxSpeed(600);
  motor2.setMaxSpeed(600);

  Serial.println("Enabled Motor");
}

void Motors::drive() {
  motor1.setSpeed(500);
  motor1.runSpeed();
  motor2.setSpeed(-500);
  motor2.runSpeed();
}
