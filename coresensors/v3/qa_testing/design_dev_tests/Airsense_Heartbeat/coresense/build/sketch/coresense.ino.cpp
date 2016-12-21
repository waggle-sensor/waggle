#include <Arduino.h>
#line 1
#line 1 "/home/rajesh/WaggleGIT/waggle/coresensors/v3/qa_testing/Airsense_Heartbeat/coresense/coresense.ino"
// This code only generates a simple heartbeat, 2 second  timeperiod and 50% duty cycle
#define HBEAT_PIN 8
#line 3 "/home/rajesh/WaggleGIT/waggle/coresensors/v3/qa_testing/Airsense_Heartbeat/coresense/coresense.ino"
void setup();
#line 12 "/home/rajesh/WaggleGIT/waggle/coresensors/v3/qa_testing/Airsense_Heartbeat/coresense/coresense.ino"
void loop();
#line 3
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






