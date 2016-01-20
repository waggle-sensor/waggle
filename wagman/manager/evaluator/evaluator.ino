#include "config.cpp"
#include "rtc_conf.cpp"

#include <Wire.h>
#include <avr/wdt.h>

#include "./libs/MCP342X/MCP342X.h"
#include "./libs/HTU21D/HTU21D.h"
#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"



MCP342X mcp3428_1;
float htu21d_humd, htu21d_temp;
HTU21D myHumidity;

void setup()
{
    delay(1000);    //Initial boot up settling delay
    set_up_pinmodes();
    delay(2000);
    Serial.begin(115200);
    Wire.begin();

    #ifdef SET_RTC_TIME
    RTC.set(CURRENT_TIME);
    Serial.println("Setting Wagman RTC Time to system time, will reflash in 2 seconds.");
    while(1);
    #endif

    Serial.println("Powering up Wagman...");
    mcp3428_1.init(MCP342X::H, MCP342X::H);
    myHumidity.begin();
    test_debugLeds ();
}




void loop()
{

    hih4030_report();
    lightsensor_report();
    thermistor_report();
    RTC_report();
    currentusage_report();
    htu21D_report();
    Serial.println("");
    delay(1900);
}

