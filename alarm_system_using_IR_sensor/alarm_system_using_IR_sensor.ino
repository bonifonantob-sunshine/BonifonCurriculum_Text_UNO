int irPin     = 7;
int buzzerPin = 9; 
void setup() 
{
  pinMode(irPin,     INPUT); 
  pinMode(buzzerPin, OUTPUT); 
}
void loop() {
int irValue = digitalRead(irPin); 
  if (irValue == LOW) 
  {           
    digitalWrite(buzzerPin, HIGH);  
  } 
  else 
  {                           
    digitalWrite(buzzerPin, LOW);   
  }
}
