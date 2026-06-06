const int ledPins[] = {2, 3, 4, 5, 6, 7};
const int buttonPin = 8;
void setup() 
{
  for (int i = 0; i < 6; i++)
    {
      pinMode(ledPins[i], OUTPUT);
    }
    pinMode(buttonPin, INPUT_PULLUP);
}
void loop() 
{
  if (digitalRead(buttonPin) == LOW) 
  {
    delay(50);                        
    int value = random(1, 7);        
    for (int i = 0; i < 6; i++)
    {digitalWrite(ledPins[i], i < value ? HIGH : LOW);}
    while (digitalRead(buttonPin) == LOW); 
  }
}