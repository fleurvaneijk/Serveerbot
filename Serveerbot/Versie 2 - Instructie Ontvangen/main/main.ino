#include "IRsensor.h"
#include "Motors.h"

IRsensor irSensor = IRsensor(2);
Motors motors = Motors();

boolean driving = false;
int target;

void setup() {
  Serial.begin(9600);
  afstandsbediening.init();
  motors.init();
}

void loop() {
  if(driving == false){
    target = irSensor.readSignal();
    Serial.println(target);
    delay(50);

    if(target >= 0 && target <= 9){
      driving = true;
    }
  } else if(driving == true){
    drive(target);
  }
}

void drive(int target){
  //do stuff
}
