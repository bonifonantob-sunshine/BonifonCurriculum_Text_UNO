const int leftIR = 2;
const int rightIR = 3;
const int ENA = 5;
const int ENB = 6;
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
int speedValue = 180;
void setup()
{
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void forward()
{
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void stopRobot()
{
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}
void turnLeft()
{
  analogWrite(ENA, 80);
  analogWrite(ENB, speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void turnRight()
{
  analogWrite(ENA, speedValue);
  analogWrite(ENB, 80);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void loop()
{
  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);
  if(left == LOW && right == LOW)
  {
    forward();
  }
  else if(left == HIGH && right == LOW)
  {
    turnRight();
  }
  else if(left == LOW && right == HIGH)
  {
    turnLeft();
  }
  else
  {
    stopRobot();
  }
}