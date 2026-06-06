const int LED_PIN  = 13;
const int DELAY_MS = 1000;  
void setup() 
{
  pinMode(LED_PIN, OUTPUT);   
}

void loop() 
{
  digitalWrite(LED_PIN, HIGH);  
  delay(DELAY_MS);              
  digitalWrite(LED_PIN, LOW);   
  delay(DELAY_MS);              
}