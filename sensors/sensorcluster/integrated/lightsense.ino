void lightsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring LightSense Data");
    #endif

    #ifdef HIH6130_include
    HIH_fetch_humidity_temperature();
    HIH6130[0] = ID_HIH6130;
    HIH6130[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);
    format6(Temp_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];
    format6(Temp_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("HIH6130 RH%:");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print("  Temperature:");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif

    #ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);


    HMC5883L[0] = ID_HMC5883L;
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

    #ifdef SERIAL_DEBUG
    SerialUSB.print("HMC5883L X:");
    SerialUSB.print(event.magnetic.x);
    SerialUSB.print("HMC5883L Y:");
    SerialUSB.print(event.magnetic.y);
    SerialUSB.print("HMC5883L Z:");
    SerialUSB.print(event.magnetic.z);
    #endif

    #endif

    #ifdef TMP421_include
    Temp_float[0] = TMP421_Sensor.GetTemperature();
    TMP421[0] = ID_TMP421;
    TMP421[1] = (1 << 7) | LENGTH_FORMAT6;
    format6(Temp_float[0]);
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TMP421: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif

    #ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());
    APDS9006020[0] = ID_APDS9006020;
    APDS9006020[1] = (valid << 7) | LENGTH_FORMAT1;
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("APDS9006020: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif

    #ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    TSL260RD[0] = ID_TSL260RD;
    TSL260RD[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL260RD: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    TSL250RD_2[0] = ID_TSL250RD_2;
    TSL250RD_2[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD_2: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    MLX75305[0] = ID_MLX75305;
    MLX75305[1] = (1 << 7) | LENGTH_FORMAT1;
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("MLX75305: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());
    ML8511[0] = ID_ML8511;
    ML8511[1] = (valid << 7) | LENGTH_FORMAT1;
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("ML8511: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef SPV1840LR5HB_2_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());
    SPV1840LR5HB_2[0] = ID_SPV1840LR5HB_2;
    SPV1840LR5HB_2[1] = (1 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB_2[2] = formatted_data_buffer[0];
    SPV1840LR5HB_2[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif

}

