void airsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring AirSense Data.");
    #endif

    #ifdef TMP112_include
    TMP112_read();


    TMP112[0] = ID_TMP112;
    TMP112[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(Temp_float[0]);  // Put it into format 1
    TMP112[2] = packet_format1[0];
    TMP112[3] = packet_format1[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TMP112:");
    SerialUSB.println(Temp_float[0]);
    #endif

    #endif

    #ifdef HTU21D_include
    Temp_float[1] = myHumidity.readHumidity();
    Temp_float[0] = myHumidity.readTemperature();

    HTU21D[0] = ID_HTU21D;
    HTU21D[1] = (1 << 7) | (LENGTH_FORMAT1 * 2);

    format1(Temp_float[0]);  // Put it into format 1
    HTU21D[2] = packet_format1[0];
    HTU21D[3] = packet_format1[1];

    format1(Temp_float[1]);  // Put it into format 1
    HTU21D[4] = packet_format1[0];
    HTU21D[5] = packet_format1[1];

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

    /* Display the results (barometric pressure is measure in hPa) */
    if (event.pressure)
    {

        BMP180[1] = (1 << 7) | (LENGTH_FORMAT1 + LENGTH_FORMAT6);

        Temp_long = long(event.pressure);
        bmp.getTemperature(&Temp_float[0]);
        format1(Temp_float[0]);  // Put it into format 1
        BMP180[2] = packet_format1[0];
        BMP180[3] = packet_format1[1];
        format6(Temp_long);
        BMP180[4] = packet_format6[0];
        BMP180[5] = packet_format6[1];
        BMP180[6] = packet_format6[2];

    }
    else
    {
        BMP180[1] = (0 << 7) | (LENGTH_FORMAT1 + LENGTH_FORMAT6);
        BMP180[2] = 0xff;
        BMP180[3] = 0xff;
        BMP180[4] = 0xff;
        BMP180[5] = 0xff;
        BMP180[6] = 0xff;
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
    PR103J2[1] = (1 << 7) | LENGTH_FORMAT2;
    Temp_uint16 = analogRead(A2D_PRJ103J2);
    format2(Temp_uint16);
    PR103J2[2] = packet_format2[0];
    PR103J2[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("PR103J2: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef TSL250RD_1_include

    TSL250RD_1[0] = ID_TSL250RD_1;
    TSL250RD_1[1] = (1 << 7) | LENGTH_FORMAT2;

    Temp_uint16 = analogRead(A2D_TSL250RD_1);
    format2(Temp_uint16);
    TSL250RD_1[2] = packet_format2[0];
    TSL250RD_1[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef MMA8452Q_include
    MMA8452_read();

    MMA8452Q[0] = ID_MMA8452Q;
    MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT1 * 4);

    format1(Temp_float[0]);  // Put it into format 1
    MMA8452Q[2] = packet_format1[0];
    MMA8452Q[3] = packet_format1[1];

    format1(Temp_float[1]);  // Put it into format 1
    MMA8452Q[4] = packet_format1[0];
    MMA8452Q[5] = packet_format1[1];


    format1(Temp_float[2]);  // Put it into format 1
    MMA8452Q[6] = packet_format1[0];
    MMA8452Q[7] = packet_format1[1];


    format1(0);  // Put it into format 1
    MMA8452Q[8] = packet_format1[0];
    MMA8452Q[9] = packet_format1[1];

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
    TSYS01[1] = (1 << 7) | LENGTH_FORMAT2;
    format2(Temp_float[0]);  // Put it into format 2
    TSYS01[2] = packet_format2[0];
    TSYS01[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSYS01: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif


    #ifdef SPV1840LR5HB_1_include

    SPV1840LR5HB_1[0] = ID_SPV1840LR5HB_1;
    SPV1840LR5HB_1[1] = (1 << 7) | LENGTH_FORMAT2;

    Temp_uint16 = analogRead(SPV_1_AMP);
    format2(Temp_uint16);

    SPV1840LR5HB_1[2] = packet_format2[0];
    SPV1840LR5HB_1[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("SPV1840LR5HB: ");
    Serial.println(Temp_uint16);
    #endif
    #endif



}

