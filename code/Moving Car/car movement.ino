  #include "SoftwareSerial.h"// import the serial library\

int IN1 = 2; // IN1 left
int IN2 = 3; // IN2 left
int IN3 = 4 ; // IN3 right 
int IN4 = 5 ; // IN4 right

int BluetoothData; // save data recieved from the bluetooth module
SoftwareSerial HC05 (0,1); // RX, TX
int  Speed=255;

void setup() {
// Start serial for Bluetooth module
HC05.begin(9600);
Serial.begin (9600);
// define the H bridge's IN pins as an OUTPUT
pinMode( IN1,OUTPUT); 
pinMode( IN2 ,OUTPUT); 
pinMode( IN3,OUTPUT); 
pinMode( IN4 ,OUTPUT);

}

// left half is hooked up together to rotate either clockwise or anticlockwise  and the same goes for the right half

void FORWARD(int Speed){

  // move the 
  digitalWrite(IN1,1);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,1);  
  digitalWrite(IN4,0); 
  
}
void BACKWARD(int Speed){
  
 digitalWrite(IN1,0);  
  digitalWrite(IN2,1); 
  digitalWrite(IN3,0);  
  digitalWrite(IN4,1); 
 }
void LEFT(int Speed){
  
  digitalWrite(IN1,0);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,1);  
  digitalWrite(IN4,0); 
}
void RIGHT(int Speed){

  digitalWrite(IN1,1);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,0);  
  digitalWrite(IN4,0); 
}

void Stop(){

    digitalWrite(IN1,0);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,0);  
  digitalWrite(IN4,0); 
}


void FORWARDRIGHT(int Speed){

  digitalWrite(IN1,1);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,0);  
  digitalWrite(IN4,0); 
}


void FORWARDLEFT(int Speed){

  digitalWrite(IN1,0);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,1);  
  digitalWrite(IN4,0); 
}


void BACKWARDRIGHT(int Speed){
  
  digitalWrite(IN1,0);  
  digitalWrite(IN2,1); 
  digitalWrite(IN3,0);  
  digitalWrite(IN4,0); 
}


void BACKWARDLEFT(int Speed){
  
 digitalWrite(IN1,0);  
  digitalWrite(IN2,0); 
  digitalWrite(IN3,0);  
  digitalWrite(IN4,1); 
}



void loop() {

 if (HC05.available()){
 BluetoothData=HC05.read();
 Serial.println(BluetoothData);

/// FORWARD ///
  if(BluetoothData=='F'){   // if Forward direction pressed .... 
   FORWARD(Speed);
   }

/// BACKWWARD ///
  if(BluetoothData=='B'){   // if Back direction pressed .... 
  BACKWARD(Speed);}


/// LEFT ///   
  if(BluetoothData=='L'){   // if Left direction pressed .... 
  LEFT(Speed);}


 /// RIGHT ///
  if(BluetoothData=='R'){   // if Right direction pressed ....
    RIGHT(Speed);}

 /// forward right ///
  if(BluetoothData=='F' && BluetoothData=='L'){   // if F L direction pressed ....
    FORWARDLEFT(Speed);}

 /// forward left ///
  if(BluetoothData=='F' && BluetoothData=='R'){   // if F R direction pressed ....
    FORWARDRIGHT(Speed);}



 /// back right ///
  if(BluetoothData=='B' && BluetoothData=='L'){   // if B L direction pressed ....
    BACKWARDLEFT(Speed);}


 /// back right ///
  if(BluetoothData=='B' && BluetoothData=='R'){   // if B R direction pressed ....
    BACKWARDRIGHT(Speed);}


    
  if(BluetoothData=='S'){   // if nothing pressed ....
  Stop();}

   if(BluetoothData=='0'){  Speed=25 ;} 
   if(BluetoothData=='1'){  Speed=50; }
   if(BluetoothData=='2'){  Speed=75; } 
   if(BluetoothData=='3'){  Speed=100; } 
   if(BluetoothData=='4'){  Speed=125; } 
   if(BluetoothData=='5'){  Speed=150; } 
   if(BluetoothData=='6'){  Speed=175; } 
   if(BluetoothData=='7'){  Speed=200; } 
   if(BluetoothData=='8'){  Speed=225; } 
   if(BluetoothData=='9'){  Speed=255; } 
   if(BluetoothData=='q'){  Speed=255; }  
  }
}




