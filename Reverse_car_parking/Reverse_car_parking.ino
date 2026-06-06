const int trigPin = 9;
const int echoPin = 10;
const int greenLED  = 2;
const int yellowLED = 3;
const int redLED    = 4;
const int buzzer = 8;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance > 45)
  {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if(distance > 30)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);          // Long beep
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  else if(distance > 15)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, HIGH);
    delay(250);          // Medium beep
    digitalWrite(buzzer, LOW);
    delay(250);
  }
  else
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);          // Fast beep
    digitalWrite(buzzer, LOW);
    delay(100);
  }
}