
void airsense_acquire (void)
{
// #ifdef SERIAL_DEBUG
//     SerialUSB.print("\n");
//     SerialUSB.println("Acquiring AirSense Data.");
// #endif

#ifdef TMP112_include
    TMP112_read();           //************ From TMP112.ino
    format6(Temp_float[0]); 

    TMP112[1] = (1 << 7) | LENGTH_FORMAT6;
    TMP112[2] = formatted_data_buffer[0];
    TMP112[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TMP112: ");
    // SerialUSB.println(Temp_float[0]);


    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef HTU21D_include
    Temp_float[1] = myHumidity.readHumidity();
    Temp_float[0] = myHumidity.readTemperature();

    HTU21D_array[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

    format6(Temp_float[0]);
    HTU21D_array[2] = formatted_data_buffer[0];
    HTU21D_array[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format6(Temp_float[1]);
    HTU21D_array[4] = formatted_data_buffer[0];
    HTU21D_array[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("HTU21D Temperature:");
//     SerialUSB.print(Temp_float[0]);
//     SerialUSB.print("C");
//     SerialUSB.print(" Humidity:");
//     SerialUSB.print(Temp_float[1]);
//     SerialUSB.print("%");
//     SerialUSB.println();
// #endif
#endif


#ifdef HIH4030_include      // NOT IN THE PACKET, DO NOT KNOW WHAT IS HAPPENING
    Temp_uint16 = analogRead(PIN_HIH4030);
    format1(Temp_uint16);

    HIH4030[1] = (1 << 7) | LENGTH_FORMAT1;
    HIH4030[2] = formatted_data_buffer[0];
    HIH4030[3] = formatted_data_buffer[1];
#ifdef SERIAL_DEBUG
    // SerialUSB.print("HIH4030: ");
    // SerialUSB.println(Temp_uint16);

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif



#ifdef BMP180_include
    
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

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
        
        format5(Temp_long);
        BMP180[4] = formatted_data_buffer[0];
        BMP180[5] = formatted_data_buffer[1];
        BMP180[6] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT5; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    }

    else { BMP180[1] = (0 << 7) | (LENGTH_FORMAT6 + LENGTH_FORMAT5); }

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("BMP180 temp: ");
//     SerialUSB.print(Temp_float[0]);
//     SerialUSB.print("C pressure: ");
//     SerialUSB.print(Temp_long);
//     SerialUSB.println("hPa");
// #endif
#endif

#ifdef PR103J2_include

    PR103J2[1] = (1 << 7) | LENGTH_FORMAT1;
    
    Temp_uint16 = analogRead(A2D_PRJ103J2);
    format1(Temp_uint16);
    PR103J2[2] = formatted_data_buffer[0];
    PR103J2[3] = formatted_data_buffer[1];
    
#ifdef SERIAL_DEBUG
    // SerialUSB.print("PR103J2: ");
    // SerialUSB.println(Temp_uint16);

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef TSL250RD_1_include

    TSL250RD_1[1] = (1 << 7) | LENGTH_FORMAT1;

    Temp_uint16 = analogRead(A2D_TSL250RD_1);
    format1(Temp_uint16);
    TSL250RD_1[2] = formatted_data_buffer[0];
    TSL250RD_1[3] = formatted_data_buffer[1];
    
#ifdef SERIAL_DEBUG
    // SerialUSB.print("TSL250RD: ");
    // SerialUSB.println(Temp_uint16);

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef MMA8452Q_include
    MMA8452_read();           //************ From mma84521.ino

    MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT6 * 4);

    format6(Temp_float[0]);  // Put it into format 1
    MMA8452Q[2] = formatted_data_buffer[0];
    MMA8452Q[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format6(Temp_float[1]);  // Put it into format 1
    MMA8452Q[4] = formatted_data_buffer[0];
    MMA8452Q[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif


    format6(Temp_float[2]);  // Put it into format 1
    MMA8452Q[6] = formatted_data_buffer[0];
    MMA8452Q[7] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif


    format6(Temp_float[3]);  // Put it into format 1
    MMA8452Q[8] = formatted_data_buffer[0];
    MMA8452Q[9] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("MMA8452Q x: ");
//     SerialUSB.print(Temp_float[0]);
//     SerialUSB.print(" y: ");
//     SerialUSB.print(Temp_float[1]);
//     SerialUSB.print(" z: ");
//     SerialUSB.print(Temp_float[2]);
//     SerialUSB.print(" rms: ");
//     SerialUSB.println(0);
// #endif
#endif



#ifdef SPV1840LR5HB_include
    Temp_uint16 = analogRead(PIN_SPV_AMP);
    format1(Temp_uint16);

    SPV1840LR5HB[1] = (1 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB[2] = formatted_data_buffer[0];
    SPV1840LR5HB[3] = formatted_data_buffer[1];


    // long SPV_1_AMPV[100];
    // double SPV_1_AMPV_AVG = 0;

    // for(int i = 0; i < 100; i++)
    // {
    //     SPV_1_AMPV[i] = 512 - analogRead(SPV_1_AMP);
    //     if (SPV_1_AMPV[i] < 0)
    //     {
    //         SPV_1_AMPV[i] = SPV_1_AMPV[i] * -1;
    //     }
    //     delay(1);
    // }

    // for(int i = 0; i < 100; i++)
    // {
    //     SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * i) + SPV_1_AMPV[i]) / (i+1);
    // }

    // SPV1840LR5HB[1] = (1 << 7) | LENGTH_FORMAT1;

    // format1(int(SPV_1_AMPV_AVG * 10));

    // SPV1840LR5HB[2] = formatted_data_buffer[0];
    // SPV1840LR5HB[3] = formatted_data_buffer[1];

    // #ifdef SERIAL_DEBUG
    // // SerialUSB.print("SPV1840LR5HB: ");
    // // SerialUSB.println(Temp_uint16);

    // for (i = 0; i < LENGTH_FORMAT1; i++)
    //     SerialUSB.print(formatted_data_buffer[i],HEX);
    // #endif
#endif


#ifdef TSYS01_include
    TSYS01_read();
    format6(Temp_float[0]);  // Put it into format 2

    TSYS01[1] = (1 << 7) | LENGTH_FORMAT6;
    TSYS01[2] = formatted_data_buffer[0];
    TSYS01[3] = formatted_data_buffer[1];
#ifdef SERIAL_DEBUG
    // SerialUSB.print("TSYS01: ");
    // SerialUSB.println(Temp_float[0]);

    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


}

