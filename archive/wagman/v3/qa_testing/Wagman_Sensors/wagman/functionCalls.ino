
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

    Serial.println("We will power ON all ports one by one. You should hear 5 seperate clicks.");

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
    Serial.println("Powering off all relays.");
    power_off_all();
    delay(1000);
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




