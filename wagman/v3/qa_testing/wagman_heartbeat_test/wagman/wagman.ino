#include "config.cpp"

#include <Wire.h>
#include <avr/wdt.h>

#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"


unsigned char WagID[8];

int question_no = 1;

void setup()
{
    delay(1000);
    set_up_pinmodes();
    delay(1000);
    Serial.begin(115200);
    Wire.begin();
    delay(1000);
}




void loop()

{
    Serial.println("------Wagman board test------");
    WagID_print ();
    delay(2000);
    Serial.println("");
    Serial.print(question_no++); Serial.print(". ");
    Serial.println("Heartbeat test:");
    delay(2000);
    Serial.println("Reading heartbeat values for PORT1, PORT2, PORT3, PORT4 and PORT5 every 500ms:");
    Serial.println(" ");
    while(1)
    {
        turnON_POW5(); // Simulating heartbeat for Port 4 and 5 for testing in the absence of Function Generator.
        turnON_POW4();
        delay(370);
        hbt_read();
        delay(470);
        hbt_read();
        delay(100);
        turnOFF_POW5();
        turnOFF_POW4();
        delay(370);
        hbt_read();
        delay(470);
        hbt_read();
        delay(100);
    }
}


