#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h
const int BT_RX = 2;   // Connected to HC-05 TX
const int BT_TX = 3;   // Connected to HC-05 RX
SoftwareSerial BT(BT_RX, BT_TX);
LiquidCrystal_I2C lcd(0x27, 16, 2);
String command = "";
int relay1 = 7;
int relay2 = 8;
bool relay1Status = false;
bool relay2Status = false;
void updateLCD()
{
  lcd.setCursor(0, 0);
  lcd.print("R1: ");
  lcd.print(relay1Status ? "ON " : "OFF");
  lcd.setCursor(0, 1);
  lcd.print("R2: ");
  lcd.print(relay2Status ? "ON " : "OFF");
}
void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  BT.begin(9600);
  lcd.init();
  lcd.backlight();
  updateLCD();
}
void loop()
{
  if (BT.available())
  {
    command = BT.readStringUntil('\n');
    command.trim();
    if (command == "ON1")
    {
      digitalWrite(relay1, HIGH);
      relay1Status = true;
      updateLCD();
    }
    else if (command == "OFF1")
    {
      digitalWrite(relay1, LOW);
      relay1Status = false;
      updateLCD();
    }
    else if (command == "ON2")
    {
      digitalWrite(relay2, HIGH);
      relay2Status = true;
      updateLCD();
    }
    else if (command == "OFF2")
    {
      digitalWrite(relay2, LOW);
      relay2Status = false;
      updateLCD();
    }
  }
}