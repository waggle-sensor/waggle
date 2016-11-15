#ifdef LIGHTSENSE_INCLUDE
#ifdef I2C_SENSORS

void lightsense_initial (void)
{
#ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    HMC_float[0] = event.magnetic.x;
    HMC_float[1] = event.magnetic.y;
    HMC_float[2] = event.magnetic.z;
#endif


#ifdef HIH6130_include
    HIH_fetch_humidity_temperature();
    HIH6130_float[0] = Temp_float[0];
    HIH6130_float[1] = Temp_float[1];
#endif


#ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    APDS_uint16 = mcp3428_2.readADC();
#endif

#ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    TSL260_uint16 = mcp3428_1.readADC();
#endif

#ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    TSL250_2_uint16 = mcp3428_1.readADC();
#endif


#ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    MLX753_uint16 = mcp3428_1.readADC();
#endif

#ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    ML8511_uint16 = mcp3428_1.readADC();
#endif


#ifdef TMP421_include
    TMP421_float = TMP421_Sensor.GetTemperature();
#endif
}



void lightsense_acquire (void)
{
#ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring LightSense Data");
#endif


#ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    HMC_float[0] = (HMC_float[0] + event.magnetic.x) / 2;
    HMC_float[1] = (HMC_float[1] + event.magnetic.y) / 2;
    HMC_float[2] = (HMC_float[2] + event.magnetic.z) / 2;

    if (event.magnetic.z > 127 || event.magnetic.z > 30)
    {
        HMC5883L[1] = (0 << 7) | (LENGTH_FORMAT8 * 3);
        SerialUSB.println("HMC5883L: I2C not available");
    }
    else
        HMC5883L[1] = (1 << 7) | (LENGTH_FORMAT8 * 3);

    format8(HMC_float[0]);
    HMC5883L[2] = formatted_data_buffer[0];
    HMC5883L[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT8; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format8(HMC_float[1]);
    HMC5883L[4] = formatted_data_buffer[0];
    HMC5883L[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT8; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format8(HMC_float[2]);
    HMC5883L[6] = formatted_data_buffer[0];
    HMC5883L[7] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT8; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

#endif


#ifdef HIH6130_include
    HIH_fetch_humidity_temperature();

    HIH6130_float[0] = (HIH6130_float[0] + Temp_float[0]) / 2;
    HIH6130_float[1] = (HIH6130_float[0] + Temp_float[1]) / 2;

    if (Temp_float[0] > 255 || Temp_float[1] < 0)
    {
        HIH6130[1] = (0 << 7) | (LENGTH_FORMAT6 * 2);
        SerialUSB.println("HIH6130: I2C not available");
    }
    else
        HIH6130[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

    format6(HIH6130_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format6(HIH6130_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("HIH6130");
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_2.readADC();

    APDS_uint16 = (APDS_uint16 + Temp_uint16) / 2;

    if (Temp_uint16 == 65535)
    {
        APDS9006020[1] = (0 << 7) | LENGTH_FORMAT1;
        SerialUSB.println("APDS9006020: I2C not available");
    }
    else
        APDS9006020[1] = (1 << 7) | LENGTH_FORMAT1;
    

    format1(APDS_uint16);
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("APDS9006020");
    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    TSL260_uint16 = (TSL260_uint16 + Temp_uint16) / 2;

    if (Temp_uint16 == 65535)
    {
        TSL260RD[1] = (0 << 7) | LENGTH_FORMAT1;
        SerialUSB.println("TSL260RD: I2C not available");
    }
    else
        TSL260RD[1] = (1 << 7) | LENGTH_FORMAT1;
    

    format1(TSL260_uint16);
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("TSL260RD");
    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    TSL250_2_uint16 = (TSL250_2_uint16 + Temp_uint16) / 2;
    
    if (Temp_uint16 == 65535)
    {
        TSL250RD_2[1] = (0 << 7) | LENGTH_FORMAT1;
        SerialUSB.println("TSL250RD_2: I2C not available");
    }
    else
        TSL250RD_2[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(TSL250_2_uint16);
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD_2");
    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    MLX753_uint16 = (MLX753_uint16 + Temp_uint16) / 2;
    
    if (Temp_uint16 == 65535)
    {
        MLX75305[1] = (0 << 7) | LENGTH_FORMAT1;
        SerialUSB.println("MLX75305: I2C not available");
    }
    else
        MLX75305[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(MLX753_uint16);
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("MLX75305");
    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    ML8511_uint16 = (ML8511_uint16 + Temp_uint16) / 2;
    
    if (Temp_uint16 == 65535)
    {
        ML8511[1] = (0 << 7) | LENGTH_FORMAT1;
        SerialUSB.println("ML8511: I2C not available");
    }
    else
        ML8511[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(ML8511_uint16);
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("ML8511");
    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef TMP421_include
    Temp_float[0] = TMP421_Sensor.GetTemperature();
    TMP421_float = (TMP421_float + Temp_float[0]) / 2;

    if (abs(Temp_float[0]) > 127)
    {
        TMP421[1] = (0 << 7) | LENGTH_FORMAT6;
        SerialUSB.println("TMP421: I2C not available");
    }
    else
        TMP421[1] = (1 << 7) | LENGTH_FORMAT6;
    
    format6(TMP421_float);
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    SerialUSB.print("TMP421");
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif
}


#endif
#endif