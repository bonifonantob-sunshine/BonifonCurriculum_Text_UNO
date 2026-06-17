const int soilSensor = A0;
const int relayPin   = 8;
void setup()
{
    Serial.begin(9600);
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH);
}
void loop()
{
    int adcValue = analogRead(soilSensor);
    int moisture = map(adcValue, 900, 300, 0, 100);
    moisture = constrain(moisture, 0, 100);
    Serial.print("Moisture: ");
    Serial.print(moisture);
    Serial.println("%");
    if(moisture < 30)
        digitalWrite(relayPin, LOW);
    else
        digitalWrite(relayPin, HIGH);
    delay(1000);
}