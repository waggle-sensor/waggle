#include <Arduino.h>
#line 1
#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/wagman.ino"
#include "config.cpp"

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

int loop_count = 0;
int question_no = 1;
int temp;

#line 21 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/wagman.ino"
void setup();
#line 36 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/wagman.ino"
void loop();
#line 2 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"
void set_up_pinmodes();
#line 27 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"
void htu21D_report();
#line 42 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"
void hih4030_report();
#line 49 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"
void lightsensor_report();
#line 56 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"
void WagID_print();
#line 73 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"
void thermistor_report();
#line 21
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
}




void loop()

{
    Serial.println("------Wagman Sensors Test------");

    WagID_print ();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    thermistor_report();
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    hih4030_report();
    Serial.println("For the next 10 seconds, please touch the HIH4030 sensor with your finger.");
    Serial.print("Counting down...");
    delay(5000);
    for (loop_count = 11; loop_count > 0; loop_count--)
    {
        Serial.print(loop_count-1);
        Serial.print(" ");
        delay(990);
    }
    Serial.println("\n");
    delay(500);
    hih4030_report();
    Serial.println("");


    Serial.print(question_no++); Serial.print(". ");
    lightsensor_report();
    Serial.println("For the next 10 seconds, please cover the lighsensor with you thumb.");
    Serial.print("Counting down...");
    delay(5000);
    for (loop_count = 11; loop_count > 0; loop_count--)
    {
        Serial.print(loop_count-1);
        Serial.print(" ");
        delay(990);
        if (loop_count == 4)
        {
            temp=analogRead(PIN_Light_Sensor);
        }
    }
    Serial.println("\n");
    Serial.print("Light Sensor reading (0-1024):");
    Serial.println(temp);
    Serial.println("");

    Serial.print(question_no++); Serial.print(". ");
    htu21D_report();
    Serial.println("For the next 10 seconds, please touch the HTU21D sensor with your finger.");
    Serial.print("Counting down...");
    delay(5000);
    for (loop_count = 11; loop_count > 0; loop_count--)
    {
        Serial.print(loop_count-1);
        Serial.print(" ");
        delay(990);
    }
    Serial.println("\n");
    delay(500);
    htu21D_report();
    Serial.print("\n");

    Serial.println("------End of board test------");

    while(1)
    {
        delay(1);
    }
}



#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/v3/manager/qa/wagman_environ_sensors_test/wagman/functionCalls.ino"

void set_up_pinmodes ()
{
    //Setup PIN modes
    pinMode(PIN_Debug_L, OUTPUT); // L LED
    pinMode(PIN_Debug_L1, OUTPUT);  // L1 LED

    pinMode(PIN_NC_POW_State_Latch, OUTPUT);    //CLK for the Latch that saves NC power state across Wagman reboots
    pinMode(PIN_BootSelect_NC, OUTPUT);         //High to boot from eMMC, Low to boot from uSD
    pinMode(PIN_NC_POW_State, OUTPUT);          //High to ON, Low to OFF - when the CLK changes from Low to High
    pinMode(PIN_BootSelect_GM, OUTPUT);         //High to boot eMMC, Low to boot uSD

    pinMode(PIN_POW_2, OUTPUT);  // Power Set 2
    pinMode(PIN_POW_3, OUTPUT);  // Power Set 3
    pinMode(PIN_POW_4, OUTPUT);  // Power Set 4
    pinMode(PIN_POW_5, OUTPUT);  // Power Set 5

    pinMode(PIN_HBT1, INPUT);   // Heartbeat 1
    pinMode(PIN_HBT2, INPUT);   // Heartbeat 2
    pinMode(PIN_HBT3, INPUT);   // Heartbeat 3
    pinMode(PIN_HBT4, INPUT);   // Heartbeat 4
    pinMode(PIN_HBT5, INPUT);   // Heartbeat 5
    return;
}


void htu21D_report()
{
    htu21d_humd = myHumidity.readHumidity();
    htu21d_temp = myHumidity.readTemperature();
    Serial.print("HTU21 Sensor: ");
    Serial.print(" Temperature:");
    Serial.print(htu21d_temp, 1);
    Serial.print("C");
    Serial.print(" Humidity:");
    Serial.print(htu21d_humd, 1);
    Serial.println("%");
    delay(10);
    return;
}

void hih4030_report()
{
    Serial.print("HIH4030 Humidity Sensor reading (0-1024):");
    Serial.println(analogRead(PIN_HIH4030_Sensor));
    return;
}

void lightsensor_report()
{
    Serial.print("Light Sensor reading (0-1024):");
    Serial.println(analogRead(PIN_Light_Sensor));
    return;
}

void WagID_print()
{
    byte k;
    RTC.idRead(WagID);
    Serial.print("Unique Board ID # ");
    for (k = 0; k<0x08; k++)
    {
        Serial.print(WagID[k],HEX);
        if (k<0x07)
        {
            Serial.print(":");
        }
    }
    Serial.println("");
}


void thermistor_report()
{
    Serial.print("Thermistor Values:");
    Serial.print(analogRead(PIN_Therm_NC));
    Serial.print(',');
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Serial.print(mcp3428_1.readADC()>>5);
    Serial.print(',');
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    Serial.print(mcp3428_1.readADC()>>5);
    Serial.print(',');
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    Serial.print(mcp3428_1.readADC()>>5);
    Serial.print(',');
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    Serial.println(mcp3428_1.readADC()>>5);
    return;
}

