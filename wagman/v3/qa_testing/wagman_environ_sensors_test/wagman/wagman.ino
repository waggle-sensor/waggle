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
    Serial.println("------Wagman Environmental Sensors Test------");
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


