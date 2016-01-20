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
    Serial.println("NC and GM set to eEMMC mode.");
    boot_nc_emmc();
    boot_gm_emmc();
    analogWrite(PIN_Debug_L,0xff);
    analogWrite(PIN_Debug_L1,0x00);
    Serial.println("Powering ON all Boards.");
    power_on_all();
    delay(500);
    currentusage_report();
    delay(2000);
    Serial.println("Powering OFF all Boards.");
    power_off_all();
    delay(500);
    currentusage_report();
    delay(1000);
    Serial.println("NC and GM set to uSD mode.");
    boot_nc_usd();
    boot_gm_usd();
    analogWrite(PIN_Debug_L,0x00);
    analogWrite(PIN_Debug_L1,0xff);
    Serial.println("Powering ON all Boards.");
    power_on_all();
    delay(500);
    currentusage_report();
    delay(2000);
    Serial.println("Powering OFF all Boards.");
    power_off_all();
    delay(500);
    currentusage_report();
    return;
}


void test_debugLeds ()

{

    Serial.println("Testing Debug LEDs - They should pulse now for 5 seconds...");
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

    Serial.println("LED pulsing finished.");
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
    delay(1);
    // giving raising clock edge
    digitalWrite(PIN_NC_POW_State_Latch, HIGH);
    delay(1);
    // lowering clock edge
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    delay(1);
    return;
}

void turnON_POW2()
{
    digitalWrite(PIN_POW_2, HIGH);
    return;
}

void turnON_POW3()
{
    digitalWrite(PIN_POW_3, HIGH);
    return;
}
void turnON_POW4()
{
    digitalWrite(PIN_POW_4, HIGH);
    return;
}
void turnON_POW5()
{
    digitalWrite(PIN_POW_5, HIGH);
    return;
}

void turnOFF_POW1 () {
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    //Setting state to ON
    digitalWrite(PIN_NC_POW_State, LOW);
    delay(1);
    // giving raising clock edge
    digitalWrite(PIN_NC_POW_State_Latch, HIGH);
    delay(1);
    // lowering clock edge
    digitalWrite(PIN_NC_POW_State_Latch, LOW);
    delay(5);
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

void RTC_report()
{
    Serial.print("Time in seconds reported by RTC:");
    Serial.println(RTC.get());
    return;
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
