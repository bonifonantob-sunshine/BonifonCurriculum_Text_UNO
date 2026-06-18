#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int mq135 = A0;
const int buzzer = 8;
const int AIR_THRESHOLD = 40; // Percentage
void setup()
{
    dht.begin();
    lcd.init();
    lcd.backlight();
    pinMode(buzzer, OUTPUT);
}
void loop()
{
    float temp = dht.readTemperature();
    float hum  = dht.readHumidity();
    int adcValue = analogRead(mq135);
    int quality = map(adcValue, 0, 1023, 100, 0);
    quality = constrain(quality, 0, 100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp, 0);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Hum : ");
    lcd.print(hum, 0);
    lcd.print("%");
    delay(1500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Air Quality:");
    lcd.print(quality);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Status: ");
    if (quality < AIR_THRESHOLD)
    {
        lcd.print("BAD");
        digitalWrite(buzzer, HIGH);
    }
    else
    {
        lcd.print("GOOD");
        digitalWrite(buzzer, LOW);
    }
    delay(2000);
}