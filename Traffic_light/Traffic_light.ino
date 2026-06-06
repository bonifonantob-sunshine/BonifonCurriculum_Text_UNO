int aRed = 2, aYel = 3, aGrn = 4;
int bRed = 5, bYel = 6, bGrn = 7;

void setup() {
  int pins[] = {2,3,4,5,6,7};
  for (int i = 0; i < 6; i++)
    {
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], LOW);
    }
  digitalWrite(aRed, HIGH); 
  digitalWrite(bRed, HIGH);
  delay(5000);    
}
void loop() 
{
  digitalWrite(aGrn, HIGH); digitalWrite(bRed, HIGH);
  delay(5000);
  digitalWrite(aGrn, LOW);  digitalWrite(aYel, HIGH);
  delay(2000);
  digitalWrite(aYel, LOW);  digitalWrite(aRed, HIGH);
  delay(1000);
  digitalWrite(bRed, LOW);  digitalWrite(bGrn, HIGH);
  delay(5000);
  digitalWrite(bGrn, LOW);  digitalWrite(bYel, HIGH);
  delay(2000);
  digitalWrite(bYel, LOW);  digitalWrite(bRed, HIGH);
  delay(1000);
  digitalWrite(aRed, LOW);
}