void initializeSensorBoard()
{
    byte i;

    pinMode(PIN_SPV_AMP,INPUT);
    pinMode(PIN_SVP_SPL,INPUT);
    pinMode(PIN_RAW_MIC,INPUT);
    pinMode(PIN_HIH4030,INPUT);
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
/*
    if (ds2401.reset() == TRUE)
    {
        ds2401.write(0x33);
        for (i = 0; i < 8; i++)
        {
            Temp_byte[i] = ds2401.read();
        }

        if (OneWire::crc8(Temp_byte, 8) == 0)
        {
            for (i=1; i<7; i++)
            {
                MAC_ID[i + 1] = Temp_byte[i];
            }

        }

        else
        {

            MAC_ID[3] = 0xff;

        }
    }
    else //Nothing is connected in the bus
    {
        MAC_ID[3] = 0xaa;
    }

    #ifdef SERIAL_DEBUG
    for (i=0; i<8; i++)
    {
        SerialUSB.print(MAC_ID[i],HEX);

        if (i < 7)
        {
            SerialUSB.print(":");
        }
        else
        {
            SerialUSB.print("\n");
        }
    }
    #endif
*/
}



void writeEEPROM (unsigned int memory_address, byte data_byte )
{
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.write(data_byte);
    Wire.endTransmission();
    delay(5);
}

byte readEEPROM (unsigned int memory_address )
{
    byte recv_data = 0xff;

    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_ADDRESS,1);

    if (Wire.available())
    {
        recv_data = Wire.read();
    }
    return recv_data;
}





void Sensors_Setup(void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.println("Setting up sensors...");
    #endif
/*
    #ifdef TMP112_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("TMP112.");
    #endif

    TMP112_CONFIG();
    #endif

    #ifdef HTU21D_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("HTU21.");
    #endif

    #endif


    #ifdef  BMP180_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("BMP180.");
    #endif
    bmp.begin();
    #endif



    #ifdef  PR103J2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("PR103J2.");
    #endif
    #endif

    #ifdef TSL250RD_1_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL250RD_1.");
    #endif
    #endif

    #ifdef MMA8452Q_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("MMA8452Q.");
    #endif
    MMA8452_CONFIG(); //Test and intialize the MMA8452
    #endif

    #ifdef TSYS01_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSYS01.");
    #endif
    TSYS01_CONFIG();
    #endif

    #ifdef HIH6130_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("HIH6130.");
    #endif
    #endif

    #ifdef TMP421_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TMP421.");
    #endif
    #endif

    #ifdef APDS9006020_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("APDS9006020.");
    #endif
    #endif

    #ifdef TSL260RD_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL260RD.");
    #endif
    #endif

    #ifdef TSL250RD_2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL250RD_2.");
    #endif
    #endif

    #ifdef MLX75305_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("MLX75305.");
    #endif
    #endif

    #ifdef ML8511_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("ML8511.");
    #endif
    #endif

    #ifdef SPV1840LR5HB_1_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("SPV1840LR5HB_1.");
    #endif
    #endif

    #ifdef SPV1840LR5HB_2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("SPV1840LR5HB_2.");
    #endif
    #endif

    #ifdef LIGHTSENSE_INCLUDE
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);
    #endif

    #ifdef HMC5883L_include
    HMC5883_Magnetometer.begin();
    #endif*/
    return;
}
