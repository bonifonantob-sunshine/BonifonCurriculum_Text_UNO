const int frontIR = 2;
const int rightIR = 3;
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
void setup()
{
  pinMode(frontIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop()
{
  bool frontBlocked = (digitalRead(frontIR) == LOW);
  bool wallPresent  = (digitalRead(rightIR) == LOW);

  if(frontBlocked)
  {
    turnLeft();
  }
  else
  {
    if(wallPresent)
    {
      forward();
    }
    else
    {
      turnRight();
    }
  }
}

void forward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void turnLeft()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void turnRight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}