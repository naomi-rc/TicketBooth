// Include the Servo library 
#include <Servo.h> 


// Declare the Servo pin, Servo variables 
int servoPin = 13; 
char servo_degree;
// Create a servo object 
Servo Servo1; 


//Photo resistor variables
int photo_sensor_pin = A0; 
const int lightPin = 8;
int photo_value; 

//Close Button variables
const int close_button_pin= 12;
int close_button_state;


void setup() { 
   // We need to attach the servo to the used pin number
   //Servo setup 
   Servo1.attach(servoPin); 
   Serial.begin(9600); 
   closeGate();

  //Setup for photoresistor
  pinMode(photo_sensor_pin, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600); 

  //Setup for close button
  pinMode(close_button_pin, INPUT);
  Serial.begin(9600); 
}
void loop(){ 
  servo_degree  = Serial.read();
  if(servo_degree == '1'){
    openGate();
  }else if(servo_degree == '0'){
    closeGate();
  }
  
   //photo code
   photo_value = analogRead(photo_sensor_pin); 
 Serial.println(photo_value); 
 delay(200); 
 if(photo_value > 700){
  turnOnLight();
  openGate();
 }
 else{
  turnOffLight();  
 }

 //close button code
 close_button_state = digitalRead(12);
 if(close_button_state==HIGH){
  Serial.println("Button pressed");
  closeGate(); 
 }
 
}


//SERVO FUNCTIONS
void openGate(){
  Servo1.write(90); 
  
}


void closeGate(){
  Servo1.write(0); 
  
}

//PHOTORESISTOIR FUNCTIONS
void turnOnLight(){
  digitalWrite(lightPin, HIGH);
  Serial.println("LIGHT ON"); 
}

void turnOffLight(){
  digitalWrite(lightPin, LOW);
}
