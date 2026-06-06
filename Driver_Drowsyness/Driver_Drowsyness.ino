#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int irSensor = 2;
const int buzzer   = 8;
const int relayPin = 9;
void setup()
{
  pinMode(irSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relayPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  digitalWrite(relayPin, LOW);
}
void loop()
{
  int eyeStatus = digitalRead(irSensor);
  if(eyeStatus == LOW) // Eye Closed
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(relayPin, HIGH);// Relay OFF
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DROWSINESS!");
    lcd.setCursor(0,1);
    lcd.print("WAKE UP!");
  }
  else // Eye Open
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(relayPin, LOW);// Relay ON
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DRIVER ALERT");
    lcd.setCursor(0,1);
    lcd.print("SYSTEM OK");
  }
  delay(200);
}