#include <Servo.h> 

int soundPin = A0;

int soundLevel = 0;

 
Servo servo1;
Servo servo2;
Servo servo3;

int phase1Threshold = 20;
int phase2Threshold = 13;
int phase3Threshold = 10;

unsigned long phase1Time = 0;
unsigned long phase2Time = 0;
unsigned long phase3Time = 0;

unsigned long phase1StartTime = 0;
unsigned long phase2StartTime = 0;
unsigned long phase3StartTime = 0;

unsigned long phase1Delay = 5000;
unsigned long phase2Delay = 12000;
unsigned long phase3Delay = 20000;

int phase1Started = 0;
int phase2Started = 0;
int phase3Started = 0;

int phase1Active = 0;
int phase2Active = 0;
int phase3Active = 0;




unsigned long start;


void setup()
{
  Serial.begin(9600);
  
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  

  
  Serial.println("Initialized...");
}

void loop()
{
 soundLevel = analogRead(soundPin);
 Serial.print("Sound level: ");
 Serial.println(soundLevel);
 
 //Calculating status of phase 1...
 if (soundLevel < phase1Threshold){
   if (phase1Started == 0){
     phase1Started = 1;
     phase1StartTime = millis();
   }
  phase1Time = millis() - phase1StartTime; //This is how long the sound level has been lower than the threshold
  if ((phase1Time > phase1Delay) && (phase1Active == 0)){ //Fire phase!
    Serial.println("Phase 1 active!");
    phase1Active = 1;
    servo1.write(50);
  }
 } else { 
   if (phase1Active == 1){
    Serial.println("Phase 1 deactivated...");
    phase1Time = 0;    //Reset elapsed time in phase //Vars could probably be merged
    phase1Started = 0; //No longer counting in phase
    phase1Active = 0;
    servo1.write(0);
   }
 }

 //Calculating status of phase 2...
 if (soundLevel < phase2Threshold){
   if (phase2Started == 0){
     phase2Started = 1;
     phase2StartTime = millis();
   }
  phase2Time = millis() - phase2StartTime; //This is how long the sound level has been lower than the threshold
  if ((phase2Time > phase2Delay) && (phase2Active == 0)){ //Fire phase!{ //Fire phase!
    Serial.println("Phase 2 active!");
    phase2Time = 0;
    phase2Active = 1;
    servo2.write(100);
  }
 } else { 
   if (phase2Active == 1){
    Serial.println("Phase 2 deactivated...");
    phase2Time = 0;    //Reset elapsed time in phase //Vars could probably be merged
    phase2Started = 0; //No longer counting in phase
    phase2Active = 0;
    servo2.write(0);
   }
 }

 //Calculating status of phase 3...
 if (soundLevel < phase3Threshold){
   if (phase3Started == 0){
     phase3Started = 1;
     phase3StartTime = millis();
   }
  phase3Time = millis() - phase3StartTime; //This is how long the sound level has been lower than the threshold
  if ((phase3Time > phase3Delay) && (phase3Active == 0)){ //Fire phase!
    Serial.println("Phase 3 active!");
    phase1Time = 0;
    phase3Active = 1;
    servo3.write(85);
  }
 } else { 
   if (phase3Active == 1){
    Serial.println("Phase 3 deactivated...");
    phase3Time = 0;    //Reset elapsed time in phase //Vars could probably be merged
    phase3Started = 0; //No longer counting in phase
    phase3Active = 0;
    servo3.write(0);
   }
 }
 delay(1000);
}

