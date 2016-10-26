#ifdef AIRSENSE_INCLUDE


void airsense_initial (void)
{
#ifdef I2C_SENSORS
    #ifdef TMP112_include
        TMP112_read();           //************ From TMP112.ino
        TMP112_float = Temp_float[0];
    #endif

    #ifdef HTU21D_include
        HTU21D_float[1] = myHumidity.readHumidity();
        HTU21D_float[0] = myHumidity.readTemperature();
    #endif


    #ifdef BMP180_include
        
        bmp.getEvent(&event);
        /* Display the results (barometric pressure is measure in Pascals) */
        if (event.pressure)
        {
            BMP180_long = long(event.pressure);
            bmp.getTemperature(&Temp_float[0]);
            BMP180_float = Temp_float[0];
        }
    #endif

    #ifdef MMA8452Q_include
        MMA8452_read();           //************ From mma84521.ino

        MMA_float[0] = Temp_float[0];  // Put it into format 1
        MMA_float[1] = Temp_float[1];  // Put it into format 1
        MMA_float[2] = Temp_float[2];  // Put it into format 1
        MMA_float[3] = Temp_float[3];  // Put it into format 1
    #endif


    #ifdef TSYS01_include
        TSYS01_read();
        TSYS_float = Temp_float[0];  // Put it into format 2
    #endif
#endif    

#ifdef ANALOG_SENSORS
    #ifdef HIH4030_include      // NOT IN THE PACKET, DO NOT KNOW WHAT IS HAPPENING
        HIH4030_uint16 = analogRead(PIN_HIH4030);
    #endif

    #ifdef PR103J2_include
        PR_uint16 = analogRead(A2D_PRJ103J2);
    #endif

    #ifdef TSL250RD_1_include
        TSL250_1_uint16 = analogRead(A2D_TSL250RD_1);
    #endif


    #ifdef SPV1840LR5HB_include
        SPV_uint16 = analogRead(PIN_SPV_AMP);
    #endif
#endif
}


void airsense_acquire (void)
{
#ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring AirSense Data.");
#endif

#ifdef I2C_SENSORS

    #ifdef TMP112_include
        TMP112_read();           //************ From TMP112.ino

        TMP112_float = (Temp_float[0] + TMP112_float) / 2;

        format6(TMP112_float); 

        TMP112[1] = (1 << 7) | LENGTH_FORMAT6;
        TMP112[2] = formatted_data_buffer[0];
        TMP112[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
    #endif

    #ifdef HTU21D_include
        Temp_float[1] = myHumidity.readHumidity();
        Temp_float[0] = myHumidity.readTemperature();

        HTU21D_float[1] = (Temp_float[1] + HTU21D_float[1]) / 2;
        HTU21D_float[0] = (Temp_float[0] + HTU21D_float[0]) / 2;

        HTU21D_array[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

        format6(HTU21D_float[0]);
        HTU21D_array[2] = formatted_data_buffer[0];
        HTU21D_array[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif

        format6(HTU21D_float[1]);
        HTU21D_array[4] = formatted_data_buffer[0];
        HTU21D_array[5] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
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

            BMP180_long = (Temp_long + BMP180_long) / 2;
            BMP180_float = (Temp_float[0] + BMP180_float) / 2;


            format6(BMP180_float);
            BMP180[2] = formatted_data_buffer[0];
            BMP180[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
            
            format5(BMP180_long);
            BMP180[4] = formatted_data_buffer[0];
            BMP180[5] = formatted_data_buffer[1];
            BMP180[6] = formatted_data_buffer[2];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
        }
        else { BMP180[1] = (0 << 7) | (LENGTH_FORMAT6 + LENGTH_FORMAT5); }
    #endif


    #ifdef MMA8452Q_include
        MMA8452_read();           //************ From mma84521.ino

        MMA_float[0] = (Temp_float[0] + MMA_float[0]) / 2;
        MMA_float[1] = (Temp_float[1] + MMA_float[1]) / 2;
        MMA_float[2] = (Temp_float[2] + MMA_float[2]) / 2;
        MMA_float[3] = (Temp_float[3] + MMA_float[3]) / 2;


        MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT6 * 4);

        format6(MMA_float[0]);  // Put it into format 1
        MMA8452Q[2] = formatted_data_buffer[0];
        MMA8452Q[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif

        format6(MMA_float[1]);  // Put it into format 1
        MMA8452Q[4] = formatted_data_buffer[0];
        MMA8452Q[5] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif


        format6(MMA_float[2]);  // Put it into format 1
        MMA8452Q[6] = formatted_data_buffer[0];
        MMA8452Q[7] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif


        format6(MMA_float[3]);  // Put it into format 1
        MMA8452Q[8] = formatted_data_buffer[0];
        MMA8452Q[9] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
    #endif


    #ifdef TSYS01_include
        TSYS01_read();

        TSYS_float = (Temp_float[0] + TSYS_float) / 2;

        format6(TSYS_float);  // Put it into format 2
        TSYS01[1] = (1 << 7) | LENGTH_FORMAT6;
        TSYS01[2] = formatted_data_buffer[0];
        TSYS01[3] = formatted_data_buffer[1];
    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT6; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
    #endif
#endif    

#ifdef ANALOG_SENSORS

    #ifdef HIH4030_include      // NOT IN THE PACKET, DO NOT KNOW WHAT IS HAPPENING
        Temp_uint16 = analogRead(PIN_HIH4030);

        HIH4030_uint16 = (Temp_uint16 + HIH4030_uint16) / 2;

        format1(HIH4030_uint16);
        HIH4030[1] = (1 << 7) | LENGTH_FORMAT1;
        HIH4030[2] = formatted_data_buffer[0];
        HIH4030[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
    #endif

    #ifdef PR103J2_include

        PR103J2[1] = (1 << 7) | LENGTH_FORMAT1;
        
        Temp_uint16 = analogRead(A2D_PRJ103J2);

        PR_uint16 = (Temp_uint16 + PR_uint16) / 2;

        format1(PR_uint16);
        PR103J2[2] = formatted_data_buffer[0];
        PR103J2[3] = formatted_data_buffer[1];
        
    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
    #endif

    #ifdef TSL250RD_1_include

        TSL250RD_1[1] = (1 << 7) | LENGTH_FORMAT1;

        Temp_uint16 = analogRead(A2D_TSL250RD_1);

        TSL250_1_uint16 = (Temp_uint16 + TSL250_1_uint16) / 2;

        format1(TSL250_1_uint16);
        TSL250RD_1[2] = formatted_data_buffer[0];
        TSL250RD_1[3] = formatted_data_buffer[1];
        
    #ifdef SERIAL_DEBUG
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
    #endif


    #ifdef SPV1840LR5HB_include
        Temp_uint16 = analogRead(PIN_SPV_AMP);

        SPV_uint16 = (Temp_uint16 + SPV_uint16) / 2;

        format1(SPV_uint16);

        SPV1840LR5HB[1] = (1 << 7) | LENGTH_FORMAT1;
        SPV1840LR5HB[2] = formatted_data_buffer[0];
        SPV1840LR5HB[3] = formatted_data_buffer[1];
    #endif
#endif

    #ifdef SERIAL_DEBUG
        SerialUSB.print("\n");
        SerialUSB.println("Finished Acquiring AirSense Data.");
    #endif
}

#endif