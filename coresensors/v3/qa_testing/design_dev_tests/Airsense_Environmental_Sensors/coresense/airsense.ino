void airsense_acquire (void)
{

    #ifdef TMP112_include
    TMP112_read();


    TMP112[0] = ID_TMP112;
    TMP112[1] = (1 << 7) | LENGTH_FORMAT6;

    format6(Temp_float[0]);  // Put it into format 1
    TMP112[2] = formatted_data_buffer[0];
    TMP112[3] = formatted_data_buffer[1];

    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("1. TMP112: ");
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

    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("2. HTU21D: ");
    SerialUSB.print(" I. Temperature:");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print("C");
    SerialUSB.print(" II. Humidity:");
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

    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("3. BMP180: ");
    SerialUSB.print("I. Temperature: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print("C");
    SerialUSB.print(" II. Pressure: ");
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
    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("4. PR103J2: ");
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
    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("5. TSL250RD: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif

    #ifdef TSYS01_include
    TSYS01_read();
    TSYS01[0] = ID_TSYS01;
    TSYS01[1] = (1 << 7) | LENGTH_FORMAT6;
    format6(Temp_float[0]);  // Put it into format 2
    TSYS01[2] = formatted_data_buffer[0];
    TSYS01[3] = formatted_data_buffer[1];
    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("7. TSYS01: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif

    #ifdef HIH4030_include
    HIH4030[0] = ID_HIH4030;
    HIH4030[1] = (1 << 7) | LENGTH_FORMAT1;
    Temp_uint16 = analogRead(PIN_HIH4030);
    format1(Temp_uint16);
    HIH4030[2] = formatted_data_buffer[0];
    HIH4030[3] = formatted_data_buffer[1];
    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("8. HIH4030: ");
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

    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("6. MMA8452Q: I. x: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print(" II. y: ");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print(" III. z: ");
    SerialUSB.println(Temp_float[2]);
    #endif
    #endif


    #ifdef SPV1840LR5HB_include
    SPV1840LR5HB[0] = ID_SPV1840LR5HB;
    SPV1840LR5HB[1] = (1 << 7) | LENGTH_FORMAT1;

    Temp_float[0] = 0.0;

    for (byte times = 0x01; times<0x10; times++)
    {
        Temp_uint16 = analogRead(PIN_RAW_MIC);
        Temp_float[0] = ((Temp_float[0] / times) * (times-1)) + (Temp_uint16 / times);
        delay(1);
    }

    Temp_uint16 = Temp_float[0];
    format1(Temp_uint16);
    SPV1840LR5HB[2] = formatted_data_buffer[0];
    SPV1840LR5HB[3] = formatted_data_buffer[1];

    #ifdef SERIAL_HUMAN_READABLE_ENABLE
    SerialUSB.print("9. SPV1840LR5HB: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif
}

