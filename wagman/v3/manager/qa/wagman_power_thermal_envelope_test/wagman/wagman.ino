#include "config.cpp"

#include <Wire.h>
#include <avr/wdt.h>

#include "./libs/MCP342X/MCP342X.h"
#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"


MCP342X mcp3428_1;
unsigned char WagID[8];

int question_no = 1;

void setup()
{
    delay(1000);
    set_up_pinmodes();
    power_off_all();
    delay(1000);
    Serial.begin(115200);
    Wire.begin();
    delay(1000);
    mcp3428_1.init(MCP342X::H, MCP342X::H);
}




void loop()

{

    Serial.println("------Wagman Power and Thermal Envelope Test------");
    WagID_print ();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    boot_pow_check();
    Serial.println("");


    Serial.print(question_no++); Serial.print(". ");
    Serial.println("Wagman sustained power delivery and temperature sensing test -");
    delay(2000);
    Serial.println("Turning ON all ports and will begin reporting current usage and thermistor values every 10 seconds...");
    turn_on_all();
    Serial.println("");
    delay(3000);
    while(1)
    {
        thermistor_report();
        Serial.println("");
        currentusage_report();
        Serial.println("-------------");
        Serial.println("");
        delay(10000);
    }
}


