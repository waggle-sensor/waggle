#include "config.cpp"
#include "rtc_conf.cpp"

#include <Wire.h>
#include <avr/wdt.h>

#include "./libs/MCP342X/MCP342X.h"
#include "./libs/HTU21D/HTU21D.h"
#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"


MCP342X mcp3428_1;
unsigned char WagID[8];
float htu21d_humd, htu21d_temp;
HTU21D myHumidity;
unsigned char TIME_DURATION = 100;

int loop_count = 0;
int question_no = 1;
int temp;

void setup()
{
    delay(1000);
    set_up_pinmodes();
    delay(1000);
    Serial.begin(115200);
    Wire.begin();
    delay(1000);

    mcp3428_1.init(MCP342X::H, MCP342X::H);
    myHumidity.begin();

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

    Serial.println("------Wagman thermal envelope and power test------");

    Serial.print(question_no++); Serial.print(". ");
    WagID_print ();
    Serial.println("");
    power_on_all();

    while(1)
    {
        RTC_time_report();
        Serial.println("");
        thermistor_report();
        Serial.println("");
        currentusage_report();
        Serial.println("-------------");
        Serial.println("");
        delay(10000);
    }
}


