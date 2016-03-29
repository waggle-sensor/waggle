#include "config.cpp"
#include <Wire.h>

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
    Serial.println("------Wagman Board Initialization Test Part II------");
    Serial.println("");
    Serial.print(question_no++); Serial.print(". ");
    Serial.println("Testing Debug LEDs - They should pulse now for 5 seconds...");
    Serial.flush();
    delay(2000);
    test_debugLeds ();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    WagID_print ();
    Serial.println("");
    Serial.println("------End of board test------");

    while(1)
    {
        delay(1);
    }
}


