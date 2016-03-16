#include "config.cpp"
#include "rtc_conf.cpp"

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

    #ifdef SET_RTC_TIME
    RTC.set(CURRENT_TIME);
    while(1)
    {
        delay(100);
        analogWrite(PIN_Debug_L,0x00);
        analogWrite(PIN_Debug_L1,0x00);
        delay(100);
        analogWrite(PIN_Debug_L,0x00);
        analogWrite(PIN_Debug_L1,0xff);
        delay(100);
        analogWrite(PIN_Debug_L,0xff);
        analogWrite(PIN_Debug_L1,0xff);
        delay(100);
        analogWrite(PIN_Debug_L,0xff);
        analogWrite(PIN_Debug_L1,0x00);
    };
    #endif
}




void loop()

{
    Serial.println("------Wagman RTC Timekeep Test------");
    WagID_print ();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    RTC_time_report();

    Serial.println("Waiting for a second and printing time again...");
    delay(970);
    RTC_time_report();
    Serial.println("");

    Serial.println("Waiting for a second and printing time again...");
    delay(970);
    RTC_time_report();
    Serial.println("");

    Serial.println("Waiting for a second and printing time again...");
    delay(970);
    RTC_time_report();
    Serial.println("");

    Serial.println("Waiting for a second and printing time again...");
    delay(970);
    RTC_time_report();
    Serial.println("");

    Serial.println(" ");
    Serial.println("------End of board test------");

    while(1)
    {
        delay(1);
    }
}


