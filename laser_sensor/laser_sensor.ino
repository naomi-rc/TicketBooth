/* Laser transmitter module test project
*/
char val;
void setup()
{
  Serial.begin(9600); 
  pinMode(13, OUTPUT);  
}
void loop() {
   val=Serial.read();
   if(val=='1')
  {
     digitalWrite(13, HIGH);  
     Serial.print(" on");
   }
  if(val=='0')
  {
    digitalWrite(13, LOW);  
    Serial.print(" off");
   }
  
}
