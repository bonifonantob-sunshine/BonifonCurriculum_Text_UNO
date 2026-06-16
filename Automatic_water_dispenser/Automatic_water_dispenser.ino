#define IR_PIN      7
#define RELAY_PIN   8
void setup()
{
    pinMode(IR_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
}
void loop()
{
    int irState = digitalRead(IR_PIN);
    if (irState == LOW)
    {
        digitalWrite(RELAY_PIN, LOW);
    }
    else
    {
        digitalWrite(RELAY_PIN, HIGH);
    }
    delay(200);
}