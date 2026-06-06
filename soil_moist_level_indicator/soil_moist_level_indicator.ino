int soilPin = A0;
int redLed    = 8;
int yellowLed = 9;
int greenLed  = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  int adcValue = analogRead(soilPin);
  int moisture = map(adcValue, 1023, 0, 0, 100);
  moisture = constrain(moisture, 0, 100);
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print("  Moisture: ");
  Serial.print(moisture);
  Serial.println("%");
  if(moisture <= 30)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  else if(moisture <= 70)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
  delay(500);
}