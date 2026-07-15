const int trigPin = 2;
const int echoPin = 3;
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
long duration;
int distance;
void forward()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
void backward()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
void left()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
void right()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
void stopRobot()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
int getDistance()
{
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    return duration * 0.034 / 2;
}
void setup()
{
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    randomSeed(analogRead(A0));   // Random left/right turns
}

void loop()
{
    distance = getDistance();
    if(distance > 15)
    {
        forward();
    }
    else
    {
        stopRobot();
        delay(200);
        backward();
        delay(2000);
        stopRobot();
        delay(200);
        if(random(2)==0)
            left();
        else
            right();
        delay(700);
        stopRobot();
        delay(200);
    }
}