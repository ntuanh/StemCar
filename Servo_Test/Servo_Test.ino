#include <Servo.h>     
Servo myservo; 

const int servo = 10;

void setup() { 
  myservo.attach(servo);
} 

void SERVO(int n ){
  myservo.write(n);
}

void loop() { 
  SERVO(90) ;
  //delay(5000);
  //SERVO(180);
  delay(2000);
  SERVO(45);
  //SERVO(0);
  delay(2000);
}