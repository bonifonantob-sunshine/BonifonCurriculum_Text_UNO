const int ldrPin = A0;
const int buzzer = 10;
int leds[] = {2,3,4,5,6,7,8,9};
void setup()
{
  Serial.begin(9600);
  for(int i=0; i<8; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
}
void loop()
{
  int adcValue = analogRead(ldrPin);
  int lightPercent = map(adcValue, 0, 1000, 0, 100);
  Serial.print("Light Intensity: ");
  Serial.print(lightPercent);
  Serial.println("%");
  int ledCount = map(lightPercent, 0, 100, 0, 8);
  for(int i=0; i<8; i++)
  {
    if(i < ledCount)
      digitalWrite(leds[i], HIGH);
    else
      digitalWrite(leds[i], LOW);
  }
  if(lightPercent >= 100)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}