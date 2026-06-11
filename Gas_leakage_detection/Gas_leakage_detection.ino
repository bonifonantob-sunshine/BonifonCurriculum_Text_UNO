#define SENSOR_PIN    A0
#define BUZZER_PIN    9
#define WARN_THRESHOLD    30   
#define DANGER_THRESHOLD  60  
#define TONE_WARNING   500  
#define TONE_DANGER    2800 
void buzzerSafe() {
  noTone(BUZZER_PIN);
}
void buzzerWarning() {
  tone(BUZZER_PIN, TONE_WARNING, 300);
  delay(400);                         
  noTone(BUZZER_PIN);
}
void buzzerDanger() {
  tone(BUZZER_PIN, TONE_DANGER);
}
void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);
  Serial.println("Ready — monitoring gas levels");
  Serial.println("──────────────────────────────");
}
void loop() {
  int adcValue = analogRead(SENSOR_PIN);
  int gasPct = map(adcValue, 0, 1023, 0, 100);
  gasPct = constrain(gasPct, 0, 100);
  if (gasPct > DANGER_THRESHOLD) {
    buzzerDanger();
    Serial.print("[DANGER!]  Gas: ");
  }
  else if (gasPct > WARN_THRESHOLD) {
    buzzerWarning();
    Serial.print("[WARNING]  Gas: ");
  }
  else {
    buzzerSafe();
    Serial.print("[SAFE]     Gas: ");
  }
  Serial.print(gasPct);
  Serial.print(" %  (ADC: ");
  Serial.print(adcValue);
  Serial.println(")");
  delay(1000);
}
