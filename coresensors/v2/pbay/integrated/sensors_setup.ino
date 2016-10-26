void Sensors_Setup(void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.println("Setting up sensors...");
    #endif

#ifdef AIRSENSE_INCLUDE
    #ifdef TMP112_include
    TMP112_CONFIG();
    #endif

    #ifdef  BMP180_include
    bmp.begin();
    #endif

    #ifdef MMA8452Q_include
    MMA8452_CONFIG();
    #endif

    #ifdef TSYS01_include
    TSYS01_CONFIG();
    #endif
#endif



#ifdef LIGHTSENSE_INCLUDE
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);

    #ifdef HMC5883L_include
    HMC5883_Magnetometer.begin();
    #endif
#endif

    return;
}
