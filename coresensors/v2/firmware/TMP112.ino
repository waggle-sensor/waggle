#ifdef TMP112_include

#define I2C_TMP112 0x48
#define TMP112_CONFIG_REG 0x01
#define TMP112_TEMP_REG 0x00

void TMP112_CONFIG()
{
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire1.write(0x60);  // write data
    Wire1.write(0xB0);  // write data
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    Temp_byte[0] = Wire1.read(); // receive DATA
    Temp_byte[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission

}

void TMP112_read()
{
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_TEMP_REG); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.requestFrom(I2C_TMP112, 2);// send data n-bytes read

    bool able = true;

    if (Wire1.available() <= 0)
        able = false;

    Temp_byte[0] = Wire1.read(); // receive DATA
    Temp_byte[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission

    if ((Temp_byte[0] & 0x80) == 0x00)
    {
        // it is a positive temperature
        Temp_uint16 = Temp_byte[0];
        Temp_uint16 = Temp_uint16 << 5;
        Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
        Temp_float[0] = (Temp_uint16 & 0x0FFF) * 0.0625;
    }
    else
    {
        Temp_byte[0] = ~Temp_byte[0];
        Temp_byte[1] = ~Temp_byte[1];
        Temp_uint16 = Temp_byte[0];
        Temp_uint16 = Temp_uint16 << 5;
        Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
        Temp_float[0] = (Temp_uint16 & 0x0FFF)*-0.0625;
    }

    if (able == false)
    {
        Temp_float[0] = 255.9;
    }
}

#endif