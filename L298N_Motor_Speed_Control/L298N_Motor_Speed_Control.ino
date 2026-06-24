int ENA = 5;
int IN1 = 8;
int IN2 = 9;
void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void loop()
{
  analogWrite(ENA, 64);
  delay(2000);
  analogWrite(ENA, 128);
  delay(2000);
  analogWrite(ENA, 192);
  delay(2000);
  analogWrite(ENA, 255);
  delay(2000);
}