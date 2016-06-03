#include "config.cpp"

void setup()
{
    delay(500);
    set_up_pinmodes();
    delay(1000);
    Serial.begin(115200);
    delay(1500);
}




void loop()

{
    test_debugLeds();
    delay(25000);
    analogWrite(PIN_Debug_L,0x00);
    analogWrite(PIN_Debug_L1,0x00);
    delay(1000);
    power_off_all();
    analogWrite(PIN_Debug_L,0xff);
    analogWrite(PIN_Debug_L1,0xff);
    delay(1000);
    analogWrite(PIN_Debug_L,0x00);
    analogWrite(PIN_Debug_L1,0x00);
    delay(1000);
    test_debugLeds();
    delay(1000);
    analogWrite(PIN_Debug_L,0xff);
    analogWrite(PIN_Debug_L1,0xff);
    delay(2000);
    turnON_POW1();
    test_debugLeds();
    analogWrite(PIN_Debug_L,0xff);
    analogWrite(PIN_Debug_L1,0x00);
    delay(60000);
    turnON_POW2();
    test_debugLeds();
    analogWrite(PIN_Debug_L,0x00);
    analogWrite(PIN_Debug_L1,0xff);
    delay(2000);
    while(1)
    {
        delay(100); // OFF OFF
        analogWrite(PIN_Debug_L,0x00);
        analogWrite(PIN_Debug_L1,0x00);
        delay(100); // OFF ON
        analogWrite(PIN_Debug_L,0x00);
        analogWrite(PIN_Debug_L1,0xff);
        delay(100); // ON ON
        analogWrite(PIN_Debug_L,0xff);
        analogWrite(PIN_Debug_L1,0xff);
        delay(100); // ON OFF
        analogWrite(PIN_Debug_L,0xff);
        analogWrite(PIN_Debug_L1,0x00);
    }
}


