#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); //0X3F
void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();
}
void loop()
{
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum :");
  lcd.print(hum);
  lcd.print("%");
  delay(2000);
}