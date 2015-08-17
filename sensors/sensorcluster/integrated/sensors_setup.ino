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

return;
}