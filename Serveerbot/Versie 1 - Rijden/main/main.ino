#include <AccelStepper.h>

#define dirPin1 8
#define stepPin1 9
#define dirPin2 10
#define stepPin2 11
#define stepsPerRevolution 200
#define motorInterfaceType 1

AccelStepper motor1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper motor2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);

void setup() {
  motor1.setMaxSpeed(600);
  motor2.setMaxSpeed(600);
  Serial.begin(9600);
}

void loop() {
  drive();
}

void drive(){
    motor1.setSpeed(500);
    motor1.runSpeed();
    motor2.setSpeed(-500);
    motor2.runSpeed();
}
