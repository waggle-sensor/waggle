#ifdef HIH6130_include
void HIH_fetch_humidity_temperature()
{
    Wire1.beginTransmission(HIH_ADDRESS);
    Wire1.endTransmission();
    delay(100);

    Wire1.requestFrom((int)HIH_ADDRESS, (int) 4);


    bool able = true;
    if (Wire1.available() <= 0)
        able = false;

    Temp_byte[1] = Wire.read();
    Temp_byte[2] = Wire.read();
    Temp_byte[3] = Wire.read();
    Temp_byte[4] = Wire.read();
    
    Wire1.endTransmission();

    Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

    Temp_byte[1] = Temp_byte[1] & 0x3f;
    Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

    Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
    Temp_int[1] = Temp_int[1] / 4;

    Temp_float[1] = (float) Temp_int[0] * 6.10e-3;
    Temp_float[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;

    if (able == false)
    {
        Temp_float[0] = 255.9;
        Temp_float[1] = 255.9;
    }
}
#endif
