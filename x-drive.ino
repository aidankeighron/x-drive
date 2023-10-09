#include <AFMotor.h>

AF_DCMotor FR_Motor(1);
AF_DCMotor FL_Motor(2);
AF_DCMotor BR_Motor(3);
AF_DCMotor BL_Motor(4);

void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  
  BR_Motor.setSpeed(100);
  BR_Motor.run(RELEASE);
}

void loop() 
{
  uint8_t i;
  
//Motor spinning clockwise
  FR_Motor.run(FORWARD);
  FL_Motor.run(FORWARD);
  BR_Motor.run(FORWARD);
  BL_Motor.run(FORWARD);
  //Speed up
  for (i=0; i<255; i++) 
  {
    FR_Motor.setSpeed(i);  
    FL_Motor.setSpeed(i);  
    BR_Motor.setSpeed(i);  
    BL_Motor.setSpeed(i);  
    delay(10);
  }
  
  // Speed down
  for (i=255; i!=0; i--) 
  {
    FR_Motor.setSpeed(i);  
    FL_Motor.setSpeed(i);  
    BR_Motor.setSpeed(i);  
    BL_Motor.setSpeed(i); 
    delay(10);
  }

//Motor spinning anti-clockwise
  FR_Motor.run(BACKWARD);
  FL_Motor.run(BACKWARD);
  BR_Motor.run(BACKWARD);
  BL_Motor.run(BACKWARD);
  
  // Speed up
  for (i=0; i<255; i++) 
  {
    FR_Motor.setSpeed(i);  
    FL_Motor.setSpeed(i);  
    BR_Motor.setSpeed(i);  
    BL_Motor.setSpeed(i);
    delay(10);
  }

  // Speed down
  for (i=255; i!=0; i--) 
  {
    FR_Motor.setSpeed(i);  
    FL_Motor.setSpeed(i);  
    BR_Motor.setSpeed(i);  
    BL_Motor.setSpeed(i);
    delay(10);
  }

  // Now turn off motor
  FR_Motor.run(RELEASE);
  FL_Motor.run(RELEASE);
  BR_Motor.run(RELEASE);
  BR_Motor.run(RELEASE);
  delay(1000);
}