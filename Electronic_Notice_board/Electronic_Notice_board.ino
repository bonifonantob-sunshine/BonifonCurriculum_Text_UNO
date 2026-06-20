#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#define BT_RX  2   // connects to HC-05 TXD
#define BT_TX  3   // connects to HC-05 RXD
SoftwareSerial bluetooth(BT_RX, BT_TX);
LiquidCrystal_I2C lcd(0x27, 16, 2);
void showMessage(String msg)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Notice:");
    lcd.setCursor(0, 1);
    lcd.print(msg);
}
void setup()
{
    bluetooth.begin(9600);  
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Notice Board");
    lcd.setCursor(0, 1);
    lcd.print("Waiting...");
}
void loop()
{
    if (bluetooth.available() > 0)
    {
        String message = bluetooth.readStringUntil('\n');
        message.trim();
        if (message.length() > 0)
        {
            showMessage(message);
        }
    }
}