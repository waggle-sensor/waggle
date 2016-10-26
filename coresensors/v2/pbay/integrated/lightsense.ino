/*
 * /coresensors/v2/pbay/integrated
 * integrated.ino V2 (including NEW INTEL CHEMSENSE BOARD)
 */

#ifdef LIGHTSENSE_INCLUDE
 void lightsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring LightSense Data");
    #endif

    #ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    HMC5883L[1] = (1 << 7) | (LENGTH_FORMAT8 * 3);
    format8(event.magnetic.x);
    HMC5883L[2] = formatted_data_buffer[0];
    HMC5883L[3] = formatted_data_buffer[1];
    format8(event.magnetic.y);
    HMC5883L[4] = formatted_data_buffer[0];
    HMC5883L[5] = formatted_data_buffer[1];
    format8(event.magnetic.z);
    HMC5883L[6] = formatted_data_buffer[0];
    HMC5883L[7] = formatted_data_buffer[1];

    if (event.magnetic.x > 127 && event.magnetic.y > 127 && event.magnetic.z > 127)
        HMC5883L[1] = (0 << 7) | (LENGTH_FORMAT8 * 3);

    #ifdef SERIAL_DEBUG
    SerialUSB.print("HMC5883L X:");
    SerialUSB.println(event.magnetic.x);
    SerialUSB.print("HMC5883L Y:");
    SerialUSB.println(event.magnetic.y);
    SerialUSB.print("HMC5883L Z:");
    SerialUSB.println(event.magnetic.z);
    #endif
    #endif

    #ifdef HIH6130_include
    HIH_fetch_humidity_temperature();

    HIH6130[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);
    format6(Temp_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];
    format6(Temp_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];

    if (Temp_float[0] > 124 && Temp_float[1] > 99)
        HIH6130[1] = (0 << 7) | (LENGTH_FORMAT6 * 2);


    #ifdef SERIAL_DEBUG
    SerialUSB.print("HIH6130 RH%:");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print("  Temperature:");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif



    #ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    if (Temp_uint16 == 65535)
        APDS9006020[1] = (0 << 7) | LENGTH_FORMAT1;
    else
        APDS9006020[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_uint16);
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("APDS9006020: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif

    #ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    if (Temp_uint16 == 65535)
        TSL260RD[1] = (0 << 7) | LENGTH_FORMAT1;
    else
        TSL260RD[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_uint16);
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL260RD: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    if (Temp_uint16 == 65535)
        TSL250RD_2[1] = (0 << 7) | LENGTH_FORMAT1;
    else
        TSL250RD_2[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_uint16);
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD_2: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    if (Temp_uint16 == 65535)
        MLX75305[1] = (0 << 7) | LENGTH_FORMAT1;
    else
        MLX75305[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_uint16);
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("MLX75305: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_1.readADC();

    if (Temp_uint16 == 65535)
        ML8511[1] = (0 << 7) | LENGTH_FORMAT1;
    else
        ML8511[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_uint16);
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("ML8511: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif


    #ifdef TMP421_include
    Temp_float[0] = TMP421_Sensor.GetTemperature();

    if (Temp_float[0] > 127)
        TMP421[1] = (0 << 7) | LENGTH_FORMAT6;
    else
        TMP421[1] = (1 << 7) | LENGTH_FORMAT6;

    format6(Temp_float[0]);
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];


    #ifdef SERIAL_DEBUG
    SerialUSB.print("TMP421: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif


    #ifdef SPV1840LR5HB_2_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    Temp_uint16 = mcp3428_2.readADC();

    if (Temp_uint16 == 65535)
        SPV1840LR5HB_2[1] = (0 << 7) | LENGTH_FORMAT1;
    else
        SPV1840LR5HB_2[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_uint16);
    SPV1840LR5HB_2[2] = formatted_data_buffer[0];
    SPV1840LR5HB_2[3] = formatted_data_buffer[1];
    
    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif
}

#endif