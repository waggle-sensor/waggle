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
    turnON_POW3();
    Serial.begin(115200);
    Wire.begin();
    delay(1000);
}




void loop()

{
    while(1)
    {
        delay(100);
    }
}


