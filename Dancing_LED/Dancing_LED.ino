// Dancing LEDs — Chaser Pattern
int pins[] = {8, 9, 10, 11};
int spd   = 150;
void setup() {
  for (int i = 0; i < 4; i++) 
  pinMode(pins[i], OUTPUT);
}
void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], HIGH);
    delay(spd);
    digitalWrite(pins[i], LOW);
  }
}