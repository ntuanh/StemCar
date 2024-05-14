#include <Servo.h>     
Servo myservo; 

const int servo = 10;

void setup() { 
  myservo.attach(servo);
  Serial.begin(9600);
} 

void SERVO(int n ){
  myservo.write(n);
}

void loop() { 
  SERVO(180) ;
  Serial.println(180);
  //delay(5000);
  //SERVO(180);
  delay(500);
  SERVO(0);
  //SERVO(0);
  Serial.println(0);
  delay(2000);
}