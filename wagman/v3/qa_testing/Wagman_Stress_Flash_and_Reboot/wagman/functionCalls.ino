
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

void boot_nc_emmc()
{
    digitalWrite(PIN_BootSelect_NC, HIGH);
    return;
}

void boot_gm_emmc()
{
    digitalWrite(PIN_BootSelect_GM, HIGH);
    return;
}

void boot_nc_usd()
{
    digitalWrite(PIN_BootSelect_NC, LOW);
    return;
}

void boot_gm_usd()
{
    digitalWrite(PIN_BootSelect_GM, LOW);
    return;
}

void power_on_all ()
{
    turnON_POW1();
    delay(200);
    turnON_POW2();
    delay(200);
    turnON_POW3();
    delay(200);
    turnON_POW4();
    delay(200);
    turnON_POW5();
    return;
}

void power_off_all ()
{
    turnOFF_POW1();
    delay(200);
    turnOFF_POW2();
    delay(200);
    turnOFF_POW3();
    delay(200);
    turnOFF_POW4();
    delay(200);
    turnOFF_POW5();
    return;
}

void test_debugLeds ()

{

//     Serial.print("Testing Debug LEDs - They should pulse now for 5 seconds...");
    for (byte j = 0x00; j < 0x07; j++)
    {
        for (byte i = 0x00; i < 0xff; i++)
        {
            analogWrite(PIN_Debug_L,i);
            analogWrite(PIN_Debug_L1,i);
            delay(2);
        }
        for (byte i = 0xff; i > 0x00; i--)
        {
            analogWrite(PIN_Debug_L,i);
            analogWrite(PIN_Debug_L1,i);
            delay(2);
        }
    }
//     Serial.println("LED pulsing finished.");
    return;
}

void turnON_POW1 ()
{
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    //Setting state to ON
    digitalWrite(PIN_NC_POW_State, HIGH);
    delay(2);
    // giving raising clock edge
    digitalWrite(PIN_NC_POW_State_Latch, HIGH);
    delay(2);
    // lowering clock edge
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    delay(2);
    delay(10);
    return;
}

void turnON_POW2()
{
    digitalWrite(PIN_POW_2, HIGH);
    delay(10);
    return;
}

void turnON_POW3()
{
    digitalWrite(PIN_POW_3, HIGH);
    delay(10);
    return;
}
void turnON_POW4()
{
    digitalWrite(PIN_POW_4, HIGH);
    delay(10);
    return;
}
void turnON_POW5()
{
    digitalWrite(PIN_POW_5, HIGH);
    delay(10);
    return;
}

void turnOFF_POW1 () {
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    //Setting state to ON
    digitalWrite(PIN_NC_POW_State, LOW);
    delay(2);
    // giving raising clock edge
    digitalWrite(PIN_NC_POW_State_Latch, HIGH);
    delay(2);
    // lowering clock edge
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    delay(2);
    return;
}

void turnOFF_POW2()
{
    digitalWrite(PIN_POW_2, LOW);
    return;
}

void turnOFF_POW3()
{
    digitalWrite(PIN_POW_3, LOW);
    return;
}
void turnOFF_POW4()
{
    digitalWrite(PIN_POW_4, LOW);
    return;
}
void turnOFF_POW5()
{
    digitalWrite(PIN_POW_5, LOW);
    return;
}

