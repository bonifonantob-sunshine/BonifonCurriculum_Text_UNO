int lowProbe  = 2;
int midProbe  = 3;
int fullProbe = 4;
int redLed    = 8;
int yellowLed = 9;
int greenLed  = 10;
int buzzer    = 5;
void setup()
{
  pinMode(lowProbe, INPUT);
  pinMode(midProbe, INPUT);
  pinMode(fullProbe, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop()
{
  int low  = digitalRead(lowProbe);
  int mid  = digitalRead(midProbe);
  int full = digitalRead(fullProbe);
  if(full == LOW)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else if(mid == LOW)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if(low == LOW)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
  }
}