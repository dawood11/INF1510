#include <stdbool.h>
#include <Servo.h> 


int mic_pin = 0;
int mic_input = -1;

Servo servo_phase_1;
Servo servo_phase_2;
Servo servo_phase_3;

int servo_pin_phase_1 = 3;
int servo_pin_phase_2 = 5;
int servo_pin_phase_3 = 10;

int led_phase_1 = 13;
int led_phase_2 = 12;
int led_phase_3 = 11;

int phase_1_position[2] = {0, 100};
int phase_2_position[2] = {0, 100};
int phase_3_position[2] = {0, 100};


int phase_1_interval[2] = {0,   100};
int phase_2_interval[2] = {101, 200};
int phase_3_interval[2] = {201, 300};
int phase_4_interval[2] = {301, 1024};

void setup(){
  Serial.begin(9600);

  servo_phase_1.attach(servo_pin_phase_1); 
  servo_phase_2.attach(servo_pin_phase_2); 
  servo_phase_3.attach(servo_pin_phase_3); 

  pinMode(led_phase_1, OUTPUT);
  pinMode(led_phase_2, OUTPUT);
  pinMode(led_phase_3, OUTPUT);
  pinMode(mic_pin, INPUT);
}

void loop(){
  mic_input = analogRead(mic_pin);
  Serial.print(mic_input);
  
  if((mic_input >= phase_1_interval[0]) && (mic_input <= phase_1_interval[1])){
    Serial.write("\n Status of phase_1 execution: ");
    boolean state = phase_1_init();
    Serial.write(state);
    
  }else if((mic_input >= phase_2_interval[0]) && (mic_input <= phase_2_interval[1])){
    Serial.write("\n Status of phase_2 execution: ");
    boolean state = phase_2_init();
    Serial.write(state);
    
  }else if((mic_input >= phase_3_interval[0]) && (mic_input <= phase_3_interval[1])){
    Serial.write("\n Status of phase_3 execution: ");
    boolean state = phase_3_init();
    Serial.write(state);
    
  }else if((mic_input >= phase_4_interval[0]) && (mic_input <= phase_4_interval[1])){
    Serial.write("\n Status of phase_4 execution: ");
    boolean state = phase_4_init();
    Serial.write(state);
    
  }else{
    Serial.write("Invalid value from microphone input \n");
  }
  
  delay(100);
}

// structure
// idle phase 1
boolean phase_1_init(){
  moveServo(servo_phase_1, phase_1_position[0], phase_1_position[1]);
  digitalWrite(led_phase_1, HIGH);
  digitalWrite(led_phase_2, LOW);
  digitalWrite(led_phase_3, LOW);
}

// idle phase 2
boolean phase_2_init(){
  moveServo(servo_phase_2, phase_2_position[0], phase_2_position[1]);
  digitalWrite(led_phase_1, LOW);
  digitalWrite(led_phase_2, HIGH);
  digitalWrite(led_phase_3, LOW);
}

// idle phase 3
boolean phase_3_init(){
  moveServo(servo_phase_3, phase_3_position[0], phase_3_position[1]);
  digitalWrite(led_phase_1, LOW);
  digitalWrite(led_phase_2, LOW);
  digitalWrite(led_phase_3, HIGH);
}

// idle phase 4
boolean phase_4_init(){
  
}

void moveServo(Servo myServo, int startPos, int stopPos){
  int pos = startPos;
  myServo.write(random(0, 180)); 
  delay(300);
//  for(pos = startPos; pos < stopPos; pos++){    // goes from 180 degrees to 0 degrees                           
//    myServo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(5);                       // waits 15ms for the servo to reach the position 
//  } 
}



