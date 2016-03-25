
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

void boot_nc_usd()
{
    digitalWrite(PIN_BootSelect_NC, LOW);
    return;
}


void c1p_boot_selector_test()
{
    Serial.println("Please set the multimeter in continuity check mode with beeper enabled.");
    delay(5000);
    Serial.println("C1P boot selector test - please check the continuity between the two pins of JP9. The board will alternate the modes and you should hear beeps.");
    delay(1000);
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
    boot_nc_usd();
    delay(1000);
    boot_nc_emmc();
    delay(1000);
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

