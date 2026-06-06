#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // or (0x3F)
void setup()
{
  lcd.init();                      
  lcd.init();
  lcd.backlight();
}
void loop()
{
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("I am Bonifon");
}
