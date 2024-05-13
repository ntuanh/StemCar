#include<Servo.h>
// Khai báo 
int time  = 100 ;
const int max_distance = 25 ;
Servo myservo; 
const int servo = 10 ;

const int trig = A1;     // chân trig của HC-SR04
const int echo = A2;     // chân echo của HC-SR04

int left_up = 4 ;
int left_down = 5 ;
int right_up = 6 ;
int right_down  = 7 ;

int f = 1  ;
int *ptr = &f ;


// setup 
void setup() { 
    Serial.begin(9600);

    myservo.attach(servo);

    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu

    pinMode(left_down, OUTPUT);
    pinMode(left_up , OUTPUT);
    pinMode(right_down , OUTPUT);
    pinMode(right_up , OUTPUT);
} 



// loop
void loop() {
  SERVO(90);
  if (distance() > max_distance )GO(0,1);
  else {
    stop() ;
    *ptr = 0;
    check(ptr);
    while ( *ptr == 0){
      GO(0,-1);
      delay(200);
      stop();
      check(ptr);
    }
}
}

// function

void SERVO(int n ){
  myservo.write(n);
  //Serial.println(distance());
  //delay(450);
}

int distance(){
  unsigned long duration; // biến đo thời gian
  int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
  digitalWrite(trig,0);   // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig,1);   // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
  duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
  distance = int(duration/2/29.412);

  return distance;
    /* In kết quả ra Serial Monitor */
    //Serial.print(distance);
    //Serial.println("cm");
    //delay(200);
}

void stop(){
    digitalWrite(right_up , 0);
    digitalWrite(right_down , 0);
    digitalWrite(left_down, 0);
    digitalWrite(left_up, 0);
    //delay(time);

}

void right( int n ){
    if ( n == -1 ){
        digitalWrite(right_down , 1 );
        digitalWrite(right_up , 0); 
    }else {
        digitalWrite(right_down , 0 );
        digitalWrite(right_up , 1); 
    }
} 

void left( int n ){
    if ( n == -1 ){
        digitalWrite(left_down , 1 );
        digitalWrite(left_up , 0); 
    }else {
        digitalWrite(left_down , 0 );
        digitalWrite(left_up , 1); 
    }
} 
// function premium 

void GO(int x , int y  ){
  int time = 250 ;
    if (x == 0 ){
        if ( y == 1 ){
            right(1);
            left(1);
            //delay(time);
        }
        else{
            right(-1);
            left(-1);
            //delay(time);
        }
    }else {
        if (x == 1){
            right(-1);
            left(1);
            delay(time);
            stop();
        }else {
            right(1);
            left(-1);
            delay(time);
            stop();
        }
    }
}

void check( int *ptr ){
  int d = 0; 
  SERVO(0);
  if(distance() > max_distance + 5){
    GO(1,0);
    SERVO(90);
    d = 1 ;
  }else {
    SERVO(180);
    if( distance() > max_distance +5){
      GO(-1, 0);
      SERVO(90);
      d = 1 ;
    }
  }
  *ptr = d ;
  delay(100);
}

// test 

void test_hc05(){
  Serial.print("Khoảng cách : ");
  Serial.print(distance());
  Serial.print(" cm ");
  delay(250);
}

void test_motor(){
  Serial.println("Tiến về phía trước ");
  GO(0,1);
}

void test_servo(){
  Serial.println("Quay góc 0 độ ");
  SERVO(0);
  delay(250);
  Serial.println("Quay góc 90 độ ");
  SERVO(90);
  delay(250);
  Serial.println("Quay góc 180 độ ");
  SERVO(180);
  delay(250);
}