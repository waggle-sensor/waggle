#include "RCM_TMP112.h"

RCM_TMP112 tmp112;

#define LED_PIN P1_0 // (Arduino is 13, Teensy is 6)
bool blinkState = false;
void setup() {
   
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, blinkState);
    bool check = tmp112.begin();
    if (!check) {
        Serial.println("TMP112 Not found.");
        while (1);
    }
    else 
    {
       Serial.println("TMP112 found.");
    }
}

void loop() {
    
    tmp112.readTemperature();
    Serial.println(tmp112.pTemperatureRaw);
    delay(500);
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
