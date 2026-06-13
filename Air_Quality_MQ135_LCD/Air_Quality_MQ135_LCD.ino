#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define SENSOR_PIN   A0
#define BUZZER_PIN   8
#define POOR_THRESHOLD    70
#define DANGER_THRESHOLD  40  
LiquidCrystal_I2C lcd(0x27, 16, 2);
int readAirQuality() 
{
  int adc = analogRead(SENSOR_PIN);
  int quality = map(adc, 0, 1023, 100, 0);
  return constrain(quality, 0, 100);
}
void updateLCD(int quality, String status) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air: ");
  lcd.print(quality);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);
}
void buzzerGood() {
  noTone(BUZZER_PIN);
}
void buzzerPoor() {
  tone(BUZZER_PIN, 1000, 200);
  delay(400);
  noTone(BUZZER_PIN);
}
void buzzerDanger() {
  tone(BUZZER_PIN, 2500);
}
void setup()
 {
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("Air Quality");
  lcd.setCursor(0, 1); 
  lcd.print("Monitor...");
}
void loop() {
  int quality = readAirQuality();
  if (quality <= DANGER_THRESHOLD) {
    updateLCD(quality, "DANGER");
    buzzerDanger();
  }
  else if (quality <= POOR_THRESHOLD) {
    updateLCD(quality, "POOR");
    buzzerPoor();
  }
  else {
    updateLCD(quality, "GOOD");
    buzzerGood();
  }
  delay(300);
}