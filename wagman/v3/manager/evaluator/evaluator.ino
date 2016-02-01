#include "config.cpp"
#include "rtc_conf.cpp"

#include <Wire.h>
#include <avr/wdt.h>

#include "./libs/MCP342X/MCP342X.h"
#include "./libs/HTU21D/HTU21D.h"
#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"


// ***This is a PCB bug, There is a line that connects K2 to GND - need to fix this.
// ***Missed R37 in BOM
// Check Temp Controlled Power Circuit - something funny here.


MCP342X mcp3428_1;
unsigned char WagID[8];
float htu21d_humd, htu21d_temp;
HTU21D myHumidity;

void setup()
{
    delay(1000);    //Initial boot up settling delay
    set_up_pinmodes();
    power_off_all();
    delay(2000);
    Serial.begin(115200);
    Wire.begin();

    #ifdef SET_RTC_TIME
    RTC.set(CURRENT_TIME);
    Serial.println("Setting Wagman RTC Time to system time, will reflash in 2 seconds.");
    while(1);
    #endif

    Serial.println("");
    Serial.println("Powering up Wagman...");



    mcp3428_1.init(MCP342X::H, MCP342X::H);
    myHumidity.begin();
    test_debugLeds ();
    power_on_all ();
    WagID_print ();

}




void loop()
{
    Serial.println("");

//     RTC_time_report();
//     Serial.print(";");
    hih4030_report();
    Serial.println("");
//     Serial.print(";");
//     lightsensor_report();
    thermistor_report();
    Serial.println("");
//     Serial.print(";");
//     RTC_report();
    currentusage_report();
    htu21D_report();
//     boot_pow_check();
    Serial.println("");
    HBT_output_pulsetest();
//     Serial.println("--------------------");
    delay(480);
}

