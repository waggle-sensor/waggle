void airsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring AirSense Data.");
    #endif

    #ifdef TMP112_include
    TMP112_read();


    TMP112[0] = ID_TMP112;
    TMP112[1] = (1 << 7) | LENGTH_FORMAT6;

    format6(Temp_float[0]);  // Put it into format 1
    TMP112[2] = formatted_data_buffer[0];
    TMP112[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TMP112:");
    SerialUSB.println(Temp_float[0]);
    #endif

    #endif

    #ifdef HTU21D_include
    Temp_float[1] = myHumidity.readHumidity();
    Temp_float[0] = myHumidity.readTemperature();

    HTU21D[0] = ID_HTU21D;
    HTU21D[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

    format6(Temp_float[0]);  // Put it into format 1
    HTU21D[2] = formatted_data_buffer[0];
    HTU21D[3] = formatted_data_buffer[1];

    format6(Temp_float[1]);  // Put it into format 1
    HTU21D[4] = formatted_data_buffer[0];
    HTU21D[5] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("HTU21D Temperature:");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print("C");
    SerialUSB.print(" Humidity:");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print("%");
    SerialUSB.println();
    #endif

    #endif

    #ifdef BMP180_include
    BMP180[0] = ID_BMP180;
    bmp.getEvent(&event);
    /* Display the results (barometric pressure is measure in Pascals) */
    if (event.pressure)
    {
        BMP180[1] = (1 << 7) | (LENGTH_FORMAT6 + LENGTH_FORMAT5);
        Temp_long = long(event.pressure);
        bmp.getTemperature(&Temp_float[0]);
        format6(Temp_float[0]);
        BMP180[2] = formatted_data_buffer[0];
        BMP180[3] = formatted_data_buffer[1];
        format5(Temp_long);
        BMP180[4] = formatted_data_buffer[0];
        BMP180[5] = formatted_data_buffer[1];
        BMP180[6] = formatted_data_buffer[2];

    }
    else
    {
        BMP180[1] = (0 << 7) | (LENGTH_FORMAT6 + LENGTH_FORMAT5);
    }

    #ifdef SERIAL_DEBUG
    SerialUSB.print("BMP180 temp: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print("C pressure: ");
    SerialUSB.print(Temp_long);
    SerialUSB.println("hPa");
    #endif


    #endif

    #ifdef PR103J2_include
    PR103J2[0] = ID_PR103J2;
    PR103J2[1] = (1 << 7) | LENGTH_FORMAT1;
    Temp_uint16 = analogRead(A2D_PRJ103J2);
    format1(Temp_uint16);
    PR103J2[2] = formatted_data_buffer[0];
    PR103J2[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("PR103J2: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef TSL250RD_1_include

    TSL250RD_1[0] = ID_TSL250RD_1;
    TSL250RD_1[1] = (1 << 7) | LENGTH_FORMAT1;

    Temp_uint16 = analogRead(A2D_TSL250RD_1);
    format1(Temp_uint16);
    TSL250RD_1[2] = formatted_data_buffer[0];
    TSL250RD_1[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef MMA8452Q_include
    MMA8452_read();

    MMA8452Q[0] = ID_MMA8452Q;
    MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT6 * 4);

    format6(Temp_float[0]);  // Put it into format 1
    MMA8452Q[2] = formatted_data_buffer[0];
    MMA8452Q[3] = formatted_data_buffer[1];

    format6(Temp_float[1]);  // Put it into format 1
    MMA8452Q[4] = formatted_data_buffer[0];
    MMA8452Q[5] = formatted_data_buffer[1];


    format6(Temp_float[2]);  // Put it into format 1
    MMA8452Q[6] = formatted_data_buffer[0];
    MMA8452Q[7] = formatted_data_buffer[1];


    format6(0);  // Put it into format 1
    MMA8452Q[8] = formatted_data_buffer[0];
    MMA8452Q[9] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("MMA8452Q x: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print(" y: ");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print(" z: ");
    SerialUSB.print(Temp_float[2]);
    SerialUSB.print(" rms: ");
    SerialUSB.println(0);
    #endif

    #endif

    #ifdef TSYS01_include
    TSYS01_read();
    TSYS01[0] = ID_TSYS01;
    TSYS01[1] = (1 << 7) | LENGTH_FORMAT6;
    format6(Temp_float[0]);  // Put it into format 2
    TSYS01[2] = formatted_data_buffer[0];
    TSYS01[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSYS01: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif


    #ifdef SPV1840LR5HB_1_include
    long SPV_1_AMPV[100];
    double SPV_1_AMPV_AVG = 0;

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV[i] = 512 - analogRead(SPV_1_AMP);
        if (SPV_1_AMPV[i] < 0)
        {
            SPV_1_AMPV[i] = SPV_1_AMPV[i] * -1;
        }
        delay(1);
    }

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * i) + SPV_1_AMPV[i]) / (i+1);
    }

    SPV1840LR5HB_1[0] = ID_SPV1840LR5HB_1;
    SPV1840LR5HB_1[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(int(SPV_1_AMPV_AVG * 10));

    SPV1840LR5HB_1[2] = formatted_data_buffer[0];
    SPV1840LR5HB_1[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
    Serial.print("SPV1840LR5HB: ");
    Serial.println(Temp_uint16);
    #endif
    #endif



}

