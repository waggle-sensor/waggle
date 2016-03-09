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
    power_off_all ();
    mcp3428_1.init(MCP342X::H, MCP342X::H);
    myHumidity.begin();
    boot_nc_emmc();
}




void loop()

{
    Serial.println("------Wagman board test------");

    Serial.print(question_no++); Serial.print(". ");

    Serial.println("Powering up Wagman, please verify that the power LED is ON...");
    delay(5000);
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    WagID_print ();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    test_debugLeds ();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    RTC_time_report();
    Serial.println("Waiting for second and printing time again...");
    delay(970);
//     Serial.print(question_no++); Serial.print(". ");
    RTC_time_report();
    Serial.println("");


    Serial.print(question_no++); Serial.print(". ");
    hih4030_report();
    Serial.println("For the next 10 seconds, please touch the HIH4030 sensor with your finger.");
    Serial.print("Counting down...");
    for (loop_count = 11; loop_count > 0; loop_count--)
    {
        Serial.print(loop_count-1);
        Serial.print(" ");
        delay(990);
    }
    Serial.print("\n");
    delay(500);
    hih4030_report();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    lightsensor_report();
    Serial.println("For the next 10 seconds, please cover the lighsensor with you thumb.");
    Serial.print("Counting down...");
    for (loop_count = 10; loop_count > 0; loop_count--)
    {
        Serial.print(loop_count-1);
        Serial.print(" ");
        delay(990);
        if (loop_count == 6)
        {
            temp=analogRead(PIN_Light_Sensor);
        }
    }
    Serial.print("\n");
    Serial.print("Light Sensor reading (0-1024):");
    Serial.println(temp);
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    thermistor_report();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    currentusage_report();
    Serial.println("Now, we will turn the on-board relays ON and see if the current sensors pick them up.");
    power_on_all();
    currentusage_report();
    Serial.println("");
    power_off_all();

    Serial.print(question_no++); Serial.print(". ");
    htu21D_report();
    Serial.println("For the next 10 seconds, please touch the HTU21D sensor with your finger.");
    Serial.print("Counting down...");
    for (loop_count = 11; loop_count > 0; loop_count--)
    {
        Serial.print(loop_count-1);
        Serial.print(" ");
        delay(990);
    }
    Serial.print("\n");
    delay(500);
    htu21D_report();
    Serial.print("\n");

    Serial.print(question_no++); Serial.print(". ");
    boot_pow_check();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    Serial.println("Boot selector tests:");
    Serial.println("Please set the multimeter in continuity check with beeper ON mode.");
    Serial.println("C1P boot selector test - please check the continuity between the two pins of JP9. The board will alternate the modes for next 5 seconds and you should hear beeps.");
    delay(2000);
    Serial.print("beep..");
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    Serial.println("C1+ bootpin JP9 test complete.");

    Serial.println("XU4 boot selector test - please check the continuity between PIN 1 and 2 of J4. The board will alternate the modes for next 5 seconds and you should hear beeps.");
    delay(5000);
    Serial.print("beep..");
    boot_gm_usd();
    delay(1000);
    boot_gm_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_gm_usd();
    delay(1000);
    boot_gm_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_gm_usd();
    delay(1000);
    boot_gm_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_gm_usd();
    delay(1000);
    boot_gm_emmc();
    delay(1000);
    Serial.print("beep..");
    boot_gm_usd();
    delay(1000);
    boot_gm_emmc();
    delay(1000);


    Serial.println("Now check continuity between PINS 2 and 3 of J4.");
    delay(5000);
    boot_gm_usd();
    delay(1000);
    Serial.print("beep..");
    boot_gm_emmc();
    delay(1000);
    boot_gm_usd();
    delay(1000);
    Serial.print("beep..");
    boot_gm_emmc();
    delay(1000);
    boot_gm_usd();
    delay(1000);
    Serial.print("beep..");
    boot_gm_emmc();
    delay(1000);
    boot_gm_usd();
    delay(1000);
    Serial.print("beep..");
    boot_gm_emmc();
    delay(1000);
    boot_gm_usd();
    delay(1000);
    Serial.print("beep..");
    boot_gm_emmc();
    delay(1000);

    Serial.println("XU4 bootpin J4 test complete.");

    Serial.println("------End of board test------");

    while(1)
    {
        delay(1);
    }
}


