#include <Servo.h> 
 
Servo myservo;
 
void setup() 
{ 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  myservo.attach(5);
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  Serial.println("Servo 2 off. Servo 3 on."); 
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(5000);
  
    Serial.println("Servo 3 off. Servo 2 on."); 
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);

  
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(5000);
} 
