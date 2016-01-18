#include <Wire.h>
extern TwoWire Wire1;
#define I2C_TMP112 0x48

byte readBuffer[2];
uint16_t pTemperatureRaw;

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
    readBuffer[0] = Wire1.read(); // receive DATA
    readBuffer[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission
}

void setup() {
    delay(5000);
    Wire1.begin();
    SerialUSB.begin(115200);
    TMP112_CONFIG();

}

void loop() {
    SerialUSB.print("TMP112_Temperature:");
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_TEMP_REG); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);

    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    readBuffer[0] = Wire1.read(); // receive DATA
    readBuffer[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission

    if ((readBuffer[0] & 0x80) == 0x00)
    {
    // it is a positive temperature
        pTemperatureRaw = readBuffer[0];
        pTemperatureRaw = pTemperatureRaw << 5;
        pTemperatureRaw = pTemperatureRaw | (readBuffer[1] >> 3);
        SerialUSB.println((pTemperatureRaw & 0x0FFF)*0.0625);
    }
    else
    {
        readBuffer[0] = ~readBuffer[0];
        readBuffer[1] = ~readBuffer[1];
        pTemperatureRaw = readBuffer[0];
        pTemperatureRaw = pTemperatureRaw << 5;
        pTemperatureRaw = pTemperatureRaw | (readBuffer[1] >> 3);
        SerialUSB.println((pTemperatureRaw & 0x0FFF)*-0.0625);
    }
    delay(1000);

}
