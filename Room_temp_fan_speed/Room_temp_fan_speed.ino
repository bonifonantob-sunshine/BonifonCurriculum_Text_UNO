#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int fanPin = 9;
void setup()
{
  Serial.begin(9600);
  dht.begin();
}
void loop()
{
  float temp = dht.readTemperature();
  int pwm = 0;
  if(temp < 25)
    pwm = 0;
  else if(temp < 30)
    pwm = 80;
  else if(temp < 35)
    pwm = 150;
  else if(temp < 40)
    pwm = 220;
  else
    pwm = 255;
  analogWrite(fanPin, pwm);
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C  PWM: ");
  Serial.println(pwm);
  delay(1000);
}