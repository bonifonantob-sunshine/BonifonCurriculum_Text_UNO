#include <Servo.h>
Servo clothServo;
const int rainSensor = 2;
int currentAngle = 90;
int targetAngle = 90;
void moveServoSmooth(int fromAngle, int toAngle)
{
  if(fromAngle < toAngle)
  {
    for(int angle = fromAngle; angle <= toAngle; angle++)
    {
      clothServo.write(angle);
      delay(15);
    }
  }
  else
  {
    for(int angle = fromAngle; angle >= toAngle; angle--)
    {
      clothServo.write(angle);
      delay(15);
    }
  }
}
void setup()
{
  pinMode(rainSensor, INPUT);
  clothServo.attach(9);
  clothServo.write(90);
}
void loop()
{
  int rain = digitalRead(rainSensor);
  if(rain == LOW && currentAngle != 180)
  {
    moveServoSmooth(currentAngle,180);
    currentAngle = 180;
  }
  else if(rain == HIGH && currentAngle != 90)
  {
    moveServoSmooth(currentAngle,90);
    currentAngle = 90;
  }
  delay(100);
}