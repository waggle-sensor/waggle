void airsense_acquire (void)
{
#ifdef SPV1840LR5HB_include   ////was  SPV1840LR5HB_2_include
    Temp_uint16 = analogRead(PIN_RAW_MIC);

    comm.subpacketBegin(ID_SPV1840LR5HB);
    comm.subpacketFormat1(Temp_uint16);
    comm.subpacketEnd();
#endif

#ifdef TMP112_include
    TMP112_read();

    comm.subpacketBegin(ID_TMP112);
    comm.subpacketFormat6(Temp_float[0]);
    comm.subpacketEnd();
#endif

#ifdef HTU21D_include
    Temp_float[1] = myHumidity.readHumidity();
    Temp_float[0] = myHumidity.readTemperature();

    comm.subpacketBegin(ID_HTU21D);
    comm.subpacketFormat6(Temp_float[0]);
    comm.subpacketFormat6(Temp_float[1]);
    comm.subpacketEnd();
#endif

#ifdef BMP180_include
    bmp.getEvent(&event);

    /* Display the results (barometric pressure is measure in Pascals) */
    if (event.pressure)
    {
        Temp_long = long(event.pressure);
        bmp.getTemperature(&Temp_float[0]);

        comm.subpacketBegin(ID_HTU21D);
        comm.subpacketFormat6(Temp_float[0]);
        comm.subpacketFormat5(Temp_long);
        comm.subpacketEnd();
    }
#endif

#ifdef PR103J2_include
    Temp_uint16 = analogRead(A2D_PRJ103J2);

    comm.subpacketBegin(ID_PR103J2);
    comm.subpacketFormat1(Temp_uint16);
    comm.subpacketEnd();
#endif

#ifdef TSL250RD_1_include
    Temp_uint16 = analogRead(A2D_TSL250RD_1);

    comm.subpacketBegin(ID_TSL250RD_1);
    comm.subpacketFormat1(Temp_uint16);
    comm.subpacketEnd();
#endif

#ifdef MMA8452Q_include
    MMA8452_read();           //************ From mma84521.ino

    comm.subpacketBegin(ID_MMA8452Q);
    comm.subpacketFormat6(Temp_float[0]);
    comm.subpacketFormat6(Temp_float[1]);
    comm.subpacketFormat6(Temp_float[2]);
    comm.subpacketFormat6(0);
    comm.subpacketEnd();
#endif

#ifdef TSYS01_include
    TSYS01_read();

    comm.subpacketBegin(ID_TSYS01);
    comm.subpacketFormat6(Temp_float[0]);
    comm.subpacketEnd();
#endif

#ifdef HIH4030_include      // NOT IN THE PACKET, DO NOT KNOW WHAT IS HAPPENING
    Temp_uint16 = analogRead(PIN_HIH4030);

    comm.subpacketBegin(ID_HIH4030);
    comm.subpacketFormat1(Temp_uint16);
    comm.subpacketEnd();
#endif
}
