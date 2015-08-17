void airsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
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



}

