#include <stdbool.h>
#include <Servo.h> 

int fade_delay = 150;

Servo servo_phase_1;
int servo_pin_phase_1 = 3;
int initial_phase_1 = 55;                   // TODO
int final_phase_1 = 10;                     // TODO

Servo servo_phase_2;
int servo_pin_phase_2 = 5;
int initial_phase_2 = 25;                   // TODO
int final_phase_2 = 90;                     // TODO

Servo servo_phase_3;
int servo_pin_phase_3 = 6;
int initial_phase_3 = 150;                  // TODO
int final_phase_3 = 80;                     // TODO


void setup(){
  Serial.begin(9600);
  servo_phase_1.attach(servo_pin_phase_1); 
  delay(50);
  servo_phase_2.attach(servo_pin_phase_2); 
  delay(50);
  servo_phase_3.attach(servo_pin_phase_3); 
  delay(50);
  Serial.print("initial servos... \n");
  moveServo(servo_phase_1, initial_phase_1);
  delay(250);
  moveServo(servo_phase_2, initial_phase_2);
  delay(250);
  moveServo(servo_phase_3, initial_phase_3);
  delay(250);
  Serial.print("Starting... \n");
 
//  // CODE
//  // START
  Serial.print("Phase 1 runing.. \n");
  phase_1();
  Serial.print("Waiting 5 sec.. \n");
  delay(5000);
  Serial.print("Phase 2 runing.. \n");
  phase_2();
  Serial.print("Waiting 5 sec.. \n");
  delay(5000);
  Serial.print("Phase 3 runing.. \n");
  phase_3();
  
  Serial.print("Waiting 10 sec.. \n");
  delay(5000);
  Serial.print("Everything goes back.. \n");
  moveAllBack();
  Serial.print("done... \n");
}

void loop(){
}

void phase_1(){
  moveServoNeg(servo_phase_1, initial_phase_1, final_phase_1);
}

void phase_2(){
  moveServoPos(servo_phase_2, initial_phase_2, final_phase_2);
}

void phase_3(){
  moveServoNeg(servo_phase_3, initial_phase_3, final_phase_3);
}

void moveAllBack(){
  // all servos back to the initial point
  Serial.print("Phase 1 going back.. \n");
  moveServo(servo_phase_1, initial_phase_1);
  delay(250);
  Serial.print("Phase 2 going back.. \n");
  moveServo(servo_phase_2, initial_phase_2);
  delay(250);
  Serial.print("Phase 3 going back.. \n");
  moveServo(servo_phase_3, initial_phase_3);
  delay(250);
}

void moveServo(Servo myServo, int stopPos){
  // move servo with out any fading
  myServo.write(stopPos);  
  delay(50); 
}

void moveServoPos(Servo myServo, int startPos, int stopPos){
  // move servo with fading
  int pos = startPos;
  myServo.write(startPos); 
  delay(fade_delay);
  for(pos = startPos; pos < stopPos; pos++){    // goes from 180 degrees to 0 degrees                           
    myServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(fade_delay);                       // waits 15ms for the servo to reach the position 
  } 
}

void moveServoNeg(Servo myServo, int startPos, int stopPos){
  // move servo with fading
  int pos = startPos;
  myServo.write(startPos); 
  delay(fade_delay);
  for(pos = startPos; pos > stopPos; pos--){    // goes from 180 degrees to 0 degrees                           
    myServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(fade_delay);                       // waits 15ms for the servo to reach the position 
  } 
}
