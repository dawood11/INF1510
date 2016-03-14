#include <stdbool.h>
#include <Servo.h> 

Servo servo_phase_1;
int servo_pin_phase_1 = 3;


void setup(){
  Serial.begin(9600);
  servo_phase_1.attach(servo_pin_phase_1); 
  Serial.print("starting... \n");
  moveServo(servo_phase_1, 0, 120);
}

void loop(){
}

void moveServo(Servo myServo, int startPos, int stopPos){
  int pos = startPos;
  myServo.write(startPos); 
  delay(300);
  for(pos = startPos; pos < stopPos; pos++){    // goes from 180 degrees to 0 degrees                           
    myServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(300);                       // waits 15ms for the servo to reach the position 
  } 
}
