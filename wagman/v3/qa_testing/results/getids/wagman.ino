#include "config.cpp"
#include <Wire.h>

#include "./libs/MCP79412RTC/MCP79412RTC.h"    //http://github.com/JChristensen/MCP79412RTC
#include "./libs/Time/Time.h"


unsigned char WagID[8];
int question_no = 1;

void setup()
{
    Serial.begin(115200);
    delay(1000);
}

void loop() {
    WagID_print();
    delay(1000);
}

