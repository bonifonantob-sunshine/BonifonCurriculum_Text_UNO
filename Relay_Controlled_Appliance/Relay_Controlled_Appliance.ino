#define RELAY_PIN  8
void setup()
{
    Serial.begin(9600);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Serial Relay Control ready");
    Serial.println("Type ON or OFF and press Enter");
}
void loop()
{
    if (Serial.available() > 0)
    {
        String command = Serial.readStringUntil('\n');
        command.trim();
        if (command == "ON")
        {
            digitalWrite(RELAY_PIN, LOW);
            Serial.println("Relay ON — appliance switched on");
        }
        else if (command == "OFF")
        {
            digitalWrite(RELAY_PIN, HIGH);
            Serial.println("Relay OFF — appliance switched off");
        }
        else
        {
            Serial.print("Unknown command: \"");
            Serial.print(command);
            Serial.println("\" — type ON or OFF.");
        }
    }
}