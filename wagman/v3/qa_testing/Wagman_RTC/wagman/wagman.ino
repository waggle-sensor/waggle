#include "config.cpp"
#include "rtc_conf.cpp"

#include <Wire.h>
#include <avr/wdt.h>

#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"


unsigned char WagID[8];
int question_no = 1;
unsigned long time_this;

void setup()
{
    delay(1000);
    set_up_pinmodes();
    delay(1000);
    Serial.begin(115200);
    Wire.begin();
    delay(1000);

    #ifdef SET_RTC_TIME
    RTC.set(CURRENT_TIME);
    while(1)
    {
        delay(1000);
        analogWrite(PIN_Debug_L,0x00);
        analogWrite(PIN_Debug_L1,0x00);
        delay(1000);
        analogWrite(PIN_Debug_L,0x00);
        analogWrite(PIN_Debug_L1,0xff);
        delay(1000);
        analogWrite(PIN_Debug_L,0xff);
        analogWrite(PIN_Debug_L1,0xff);
        delay(1000);
        analogWrite(PIN_Debug_L,0xff);
        analogWrite(PIN_Debug_L1,0x00);
    };
    #endif
    delay(4000);
}




void loop()

{
    Serial.println("------Wagman RTC Timekeep Test------");
    WagID_print ();
    Serial.print("1. Wagman RTC Test: ");
    time_this = RTC.get();
    delay(1000);
    if ((RTC.get() - time_this) > 0)
    {
        Serial.println("PASS.");
    }

    else
    {
        Serial.println("FAIL.");
    }

    Serial.println("------End of board test------");

    while(1)
    {
        delay(10);
    }
}


