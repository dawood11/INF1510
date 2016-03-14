//lydbildet
#include <stdbool.h>
#include <Servo.h> 

int servo1Pin = 3;
int servo2Pin = 5;
int servo3Pin = 6;

Servo servo1;
Servo servo2;
Servo servo3;


void setup(){
  Serial.begin(9600);
  Serial.print("Nulling servos... \n");
  moveServo(servo1, 0, 0);
  servo1.attach(servo1Pin); 
  delay(50);
  moveServo(servo2, 0, 0);
  servo2.attach(servo2Pin); 
  delay(50);
  moveServo(servo3, 0, 0);
  servo3.attach(servo3Pin); 
  delay(50);
 }


void loop(){
  delay(3000);
  Serial.print("Phase 1 running.. \n");
  phase_1();
  Serial.print("Waiting 5 sec.. \n");
  delay(6000);
  Serial.print("Phase 2 running.. \n");
  phase_2();
  Serial.print("Waiting 5 sec.. \n");
  delay(10000);
  Serial.print("Phase 3 running.. \n");
  phase_3();
  
  Serial.print("Waiting.. \n");
  delay(20000);
  Serial.print("Everything goes back.. \n");
  moveAllBack();
  Serial.print("Loop complete... \n");
}


void phase_1(){
  moveServoSlow(servo1, 85, 20);
}


void phase_2(){
  moveServoSlow(servo2, 90, 80);
}


void phase_3(){
  moveServoSlow(servo3, 80, 150);
}


void moveAllBack(){
  // all servos back to the initial point
  Serial.print("Phase 1 going back.. \n");
  moveServo(servo1, 0, 0);
  delay(250);
  Serial.print("Phase 2 going back.. \n");
  moveServo(servo2, 0, 0);
  delay(250);
  Serial.print("Phase 3 going back.. \n");
  moveServo(servo3, 0, 0);
  delay(250);
}


void moveServo(Servo myServo, int stopPos, int dummyVar){
  myServo.write(stopPos);  
  delay(50); 
}


void moveServoSlow(Servo myServo, int stopPos, int servoDelay){
 int pos = myServo.read();
 for(pos; pos < stopPos; pos++){
  myServo.write(pos);
  delay(servoDelay);
 } 
}