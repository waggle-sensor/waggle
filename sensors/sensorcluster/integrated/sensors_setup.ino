void Sensors_Setup(void)
{

#ifdef SERIAL_DEBUG
SerialUSB.println("Setting up sensors...");
#endif

#ifdef TMP112_include

#ifdef SERIAL_DEBUG
SerialUSB.println("TMP112.");
#endif

TMP112_CONFIG();
#endif

#ifdef HTU21D_include

#ifdef SERIAL_DEBUG
SerialUSB.println("HTU21.");
#endif

#endif


#ifdef  BMP180_include

#ifdef SERIAL_DEBUG
SerialUSB.println("BMP180.");
#endif
bmp.begin();
#endif



#ifdef  PR103J2_include
#ifdef SERIAL_DEBUG
SerialUSB.println("PR103J2.");
#endif
#endif

#ifdef TSL250RD_1_include
#ifdef SERIAL_DEBUG
SerialUSB.println("TSL250RD_1.");
#endif
#endif

#ifdef MMA8452Q_include
#ifdef SERIAL_DEBUG
SerialUSB.println("MMA8452Q.");
#endif
MMA8452_CONFIG(); //Test and intialize the MMA8452
#endif

#ifdef TSYS01_include

#ifdef SERIAL_DEBUG
SerialUSB.println("TSYS01.");
#endif
TSYS01_CONFIG();
#endif


return;
}