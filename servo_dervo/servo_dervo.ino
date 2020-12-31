// Include the Servo library 
#include <Servo.h> 


// Declare the Servo pin 
int servoPin = 13; 
char val;
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   Serial.begin(9600); 
}
void loop(){ 
  val  = Serial.read();
  if(val == '1'){
    openGate();
  }else if(val == '0'){
    closeGate();
  }
  /* // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); */
}

void openGate(){
  Servo1.write(90); 
  
}


void closeGate(){
  Servo1.write(0); 
  
}
