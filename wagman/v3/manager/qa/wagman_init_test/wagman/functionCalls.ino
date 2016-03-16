
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

void boot_pow_check()
{
//     Serial.println("NC and GM set to eEMMC mode.");
//     boot_nc_emmc();
//     boot_gm_emmc();
//     analogWrite(PIN_Debug_L,0xff);
//     analogWrite(PIN_Debug_L1,0x00);

    Serial.println("We will power ON all ports one by one. You should hear 5 seperate clicks, and see the current usage increase.");
    currentusage_report();

    Serial.print("Click 1 ");
    turnON_POW1();
    delay(2000);

    Serial.print("Click 2 ");
    turnON_POW2();
    delay(2000);

    Serial.print("Click 3 ");
    turnON_POW3();
    delay(2000);

    Serial.print("Click 4 ");
    turnON_POW4();
    delay(2000);

    Serial.println("Click 5");
    turnON_POW5();
    delay(2000);

    currentusage_report();
    delay(2000);

    Serial.println("Powering off all relays. The current usage reported now should all be under 120.");
    power_off_all();
    delay(1000);
    currentusage_report();
    delay(1000);
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


void HBT_output_pulsetest (void)
{
    //switching to output mode.
    pinMode(PIN_HBT1, OUTPUT);   // Heartbeat 1
    pinMode(PIN_HBT2, OUTPUT);   // Heartbeat 2
    pinMode(PIN_HBT3, OUTPUT);   // Heartbeat 3
    pinMode(PIN_HBT4, OUTPUT);   // Heartbeat 4
    pinMode(PIN_HBT5, OUTPUT);   // Heartbeat 5

    Serial.println("The Heartbeat pins will be pulsed 3 times.");
    for (byte i = 0x00; i<0x03; i++)
    {
        Serial.println("Setting HBT Pins to high.");
        digitalWrite(PIN_HBT1,HIGH);
        digitalWrite(PIN_HBT2,HIGH);
        digitalWrite(PIN_HBT3,HIGH);
        digitalWrite(PIN_HBT4,HIGH);
        digitalWrite(PIN_HBT5,HIGH);
        delay(1000);
        Serial.println("Setting HBT Pins to Low.");
        digitalWrite(PIN_HBT1,LOW);
        digitalWrite(PIN_HBT2,LOW);
        digitalWrite(PIN_HBT3,LOW);
        digitalWrite(PIN_HBT4,LOW);
        digitalWrite(PIN_HBT5,LOW);
        delay(1000);


    }



    //switching back to input mode.
    pinMode(PIN_HBT1, INPUT);   // Heartbeat 1
    pinMode(PIN_HBT2, INPUT);   // Heartbeat 2
    pinMode(PIN_HBT3, INPUT);   // Heartbeat 3
    pinMode(PIN_HBT4, INPUT);   // Heartbeat 4
    pinMode(PIN_HBT5, INPUT);   // Heartbeat 5

}

void heartbeat_test()
{
    Serial.println("Reading heartbeat values for PORT1:");

    for (loop_count = 0; loop_count < 10; loop_count++)
    {
        Serial.print(digitalRead(PIN_HBT1));
        Serial.print(" ");
        delay(500);
    }
    Serial.println("");
    Serial.println("Reading heartbeat values for PORT2:");

    for (loop_count = 0; loop_count < 10; loop_count++)
    {
        Serial.print(digitalRead(PIN_HBT2));
        Serial.print(" ");
        delay(500);
    }

    Serial.println("");
    Serial.println("Reading heartbeat values for PORT3:");


    for (loop_count = 0; loop_count < 10; loop_count++)
    {
        Serial.print(digitalRead(PIN_HBT3));
        Serial.print(" ");
        delay(500);
    }

    Serial.println("");
    Serial.println("Reading heartbeat values for PORT4:");



    for (loop_count = 0; loop_count < 10; loop_count++)
    {
        Serial.print(digitalRead(PIN_HBT4));
        Serial.print(" ");
        delay(500);
    }

    Serial.println("");
    Serial.println("Reading heartbeat values for PORT5:");


    for (loop_count = 0; loop_count < 10; loop_count++)
    {
        Serial.print(digitalRead(PIN_HBT5));
        Serial.print(" ");
        delay(500);
    }

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

void hbt_read()
{
    Serial.print(digitalRead(PIN_HBT1));
    Serial.print(',');
    delay(1);
    Serial.print(digitalRead(PIN_HBT2));
    Serial.print(',');
    delay(1);
    Serial.print(digitalRead(PIN_HBT3));
    Serial.print(',');
    delay(1);
    Serial.print(digitalRead(PIN_HBT4));
    Serial.print(',');
    delay(1);
    Serial.println(digitalRead(PIN_HBT5));
    delay(1);
    return;
}


int read_current(int addr)
{
    byte msb,csb,lsb, logged;
    // Start I2C transaction with current sensor

    logged = 0;
    do{

        Wire.beginTransmission(addr);
        // Tell sensor we want to read "data" register
        Wire.write(0);
        // Sensor expects restart condition, so end I2C transaction (no stop bit)
        Wire.endTransmission(0);
        // Ask sensor for data
        Wire.requestFrom(addr, 3);

        // Read the 3 bytes that the sensor returns
        if(Wire.available())
        {
            msb = Wire.read();
            // We only care about the data, so the mask hides the SYNC flag
            csb = Wire.read() & 0x01;
            lsb = Wire.read();
            logged = 1;
        }
        else
        {
            delay(500);
        }
    }while(logged == 0);

    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);

    // Calculate milliamps from raw sensor data
    unsigned int milliamps = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;
    return milliamps;
}

void RTC_time_report (void)
{
    Serial.print("Current time since epoch: ");
    Serial.println(RTC.get());
    return;
}


void currentusage_report(void)
{
    Serial.print("Current consumption:");
    Serial.print(read_current(ADDR_CURRENT_SYS));
    Serial.print(';');
    delay(5);
    Serial.print(read_current(ADDR_CURRENT_POW1));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(ADDR_CURRENT_POW2));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(ADDR_CURRENT_POW3));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(ADDR_CURRENT_POW4));
    Serial.print(',');
    delay(5);
    Serial.println(read_current(ADDR_CURRENT_POW5));
    return;
}

void xu4_boot_selector_test()
{

    Serial.println("XU4 boot selector test - please check the continuity between PIN 1 and 2 of J4.");
    delay(5000);
    Serial.println("The board will alternate the modes for next 5 seconds and you should hear beeps.");
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
    Serial.println("");
    Serial.println("Now check continuity between PINS 2 and 3 of J4.");
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
    Serial.println("");
    Serial.println("XU4 bootpin J4 test complete.");
    return;

}


void c1p_boot_selector_test()
{
    Serial.println("Please set the multimeter in continuity check with beeper ON mode.");
    delay(5000);
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
    return;
}
