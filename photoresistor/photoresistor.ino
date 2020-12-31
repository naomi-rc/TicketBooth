int sensorPin = A0; 
const int lightPin = 8;
int value = 0; 
void setup() {
 pinMode(sensorPin, INPUT);
 pinMode(lightPin, OUTPUT);
 Serial.begin(9600); 
} 
void loop() { 
 value = analogRead(sensorPin); 
 Serial.println(value); 
 delay(200); 
 if(value > 700){
  turnOnLight();
  //openGate();
 }
 else{
  turnOffLight();  
 }
 
} 

void turnOnLight(){
  digitalWrite(lightPin, HIGH);
  Serial.println("LIGHT ON"); 
}

void turnOffLight(){
  digitalWrite(lightPin, LOW);
}
