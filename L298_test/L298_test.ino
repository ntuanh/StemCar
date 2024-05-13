
// Khai báo 
const int time = 350 ;

int left_up = 4 ;
int left_down = 5 ;

int right_up = 6 ;
int right_down  = 7 ;


// setup 
void setup(){
    pinMode(left_down, OUTPUT);
    pinMode(left_up , OUTPUT);
    pinMode(right_down , OUTPUT);
    pinMode(right_up , OUTPUT);
}

// loop

void loop(){
  GO(0,1);
  delay(10000);
  //stop()

}
// function basic
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

void GO(int x , int y ){
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
        }else {
            right(1);
            left(-1);
            delay(time);
        }
    }
}


