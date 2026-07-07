#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int slot1 = 2;
const int slot2 = 3;
void setup()
{
    pinMode(slot1, INPUT);
    pinMode(slot2, INPUT);
    lcd.init();
    lcd.backlight();
}
void loop()
{
    int s1 = digitalRead(slot1);
    int s2 = digitalRead(slot2);
    int freeSlots = 0;
    if(s1 == HIGH) freeSlots++;
    if(s2 == HIGH) freeSlots++;
    lcd.clear();
    if(s1 == LOW && s2 == LOW)
    {
        lcd.setCursor(0,0);
        lcd.print("PARKING FULL");
        lcd.setCursor(0,1);
        lcd.print("Free Slot: 0");
    }
    else
    {
        lcd.setCursor(0,0);
        lcd.print("Parking Slots");
        lcd.setCursor(0,1);
        lcd.print("Available: ");
        lcd.print(freeSlots);
    }
    delay(300);
}