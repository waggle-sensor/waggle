// This code only generates a simple heartbeat, 2 second  timeperiod and 50% duty cycle
#define HBEAT_PIN 8
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(1000);
    pinMode(HBEAT_PIN, OUTPUT);
    delay(1000);
}


void loop()
{
    digitalWrite(HBEAT_PIN, HIGH);
    delay(999);
    digitalWrite(HBEAT_PIN, LOW);
    delay(999);
}





