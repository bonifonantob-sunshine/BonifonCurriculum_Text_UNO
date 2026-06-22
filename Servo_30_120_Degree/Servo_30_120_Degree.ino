#include <Servo.h>
Servo myServo;
void setup()
{
  myServo.attach(9);
}
void loop()
{
  for(int angle = 30; angle <= 120; angle++)
  {
    myServo.write(angle);
    delay(20);
  }
  for(int angle = 120; angle >= 30; angle--)
  {
    myServo.write(angle);
    delay(20);
  }
}