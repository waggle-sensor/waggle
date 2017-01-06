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

void turnON_POW3()
{
    digitalWrite(PIN_POW_3, HIGH);
    return;
}

void turnOFF_POW3()
{
    digitalWrite(PIN_POW_3, LOW);
    return;
}