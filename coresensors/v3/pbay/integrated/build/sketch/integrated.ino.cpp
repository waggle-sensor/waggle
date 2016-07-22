#include <Arduino.h>
#line 1
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/integrated.ino"
/**
 ** /coresensors/v3/pbay/v3.1/integrated
 ** integrated.ino V3 (pbay)
 **/

#include <SPI.h>
#include <Wire.h> 
#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

#include "./variable.h"     //** byte arrays, variables for all sensors and integrated.ino
#include "./setsensor.h"    //** add variables for sensors on airsense and lightsense boards depening on its availability 

#line 16 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/integrated.ino"
void setup();
#line 65 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/integrated.ino"
void loop();
#line 166 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/integrated.ino"
void handler();
#line 2 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/CRC_8_Waggle.ino"
byte CRC_calc(byte length_data);
#line 15 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/CRC_8_Waggle.ino"
byte CRC_8_Waggle(byte data, byte crc);
#line 2 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/HIH.ino"
void HIH_fetch_humidity_temperature();
#line 3 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TMP112.ino"
void TMP112_CONFIG();
#line 22 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TMP112.ino"
void TMP112_read();
#line 5 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
void TSYS01_CONFIG();
#line 11 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
void TSYS01_read();
#line 16 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
void TSYS01INIT();
#line 25 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
void TSYS_Get_Coeff();
#line 42 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
float TSYS_ScaleTemp_C(uint16_t rawAdc);
#line 56 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
void TSYS01GetTemp();
#line 2 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/airsense.ino"
void airsense_acquire(void);
#line 3 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alpha_packet.ino"
void alpha_packet_whole();
#line 3 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alpha_packet_conf.ino"
void alpha_packet_config();
#line 23 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alphasense.ino"
void alphasense_on();
#line 44 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alphasense.ino"
void alphasense_off();
#line 65 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alphasense.ino"
void alphasense_firmware();
#line 92 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alphasense.ino"
void alphasense_histo();
#line 118 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alphasense.ino"
void alphasense_config();
#line 6 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void form3_hex_string_to_hex();
#line 33 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void form1_hex_string_to_unsigned_int();
#line 48 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void form1_int_string_to_unsigned_int();
#line 62 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void form4_int_string_to_unsigned_long(int shift_needed);
#line 79 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void form2_int_string_to_int();
#line 95 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void form5_int_string_to_long();
#line 111 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
int compareKey(char k1, char k2, char k3);
#line 119 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void chemsense_acquire();
#line 170 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
void Carrier();
#line 14 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format1(unsigned int input);
#line 26 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format2(int input);
#line 48 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format3(byte *input);
#line 62 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format4(unsigned long input);
#line 75 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format5(long input);
#line 101 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format6(float input);
#line 129 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format7(byte *input);
#line 141 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
void format8(float input);
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/initialization.ino"
void sensor_buff_initialization();
#line 2 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/lightsense.ino"
void lightsense_acquire(void);
#line 6 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void MMA8452_read();
#line 14 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void readAccelData(int *destination);
#line 37 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void MMA8452_CONFIG();
#line 52 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void MMA8452Standby();
#line 59 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void MMA8452Active();
#line 66 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void MMA8452readRegisters(byte addressToRead, int bytesToRead, byte *dest);
#line 75 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
byte MMA8452readRegister(byte addressToRead);
#line 83 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
void MMA8452writeRegister(byte addressToWrite, byte dataToWrite);
#line 3 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/packet_assembler.ino"
void assemble_packet_empty();
#line 14 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/packet_assembler.ino"
void assemble_packet_whole();
#line 2 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/sensors_setup.ino"
void initializeSensorBoard();
#line 33 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/sensors_setup.ino"
void Sensors_Setup(void);
#line 63 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/sensors_setup.ino"
void writeEEPROM(unsigned int memory_address, byte data_byte );
#line 73 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/sensors_setup.ino"
byte readEEPROM(unsigned int memory_address );
#line 16
void setup()
{
    //** Let us wait for the processor and the sensors to settle down
    delay(2000);

    //** initialize the super-packet
    //** and sub-packets
    //** sensors_setup.ino, set pinMode and put MACID of airsense
    assemble_packet_empty();
    sensor_buff_initialization();
    initializeSensorBoard();

    //** begin communication lines
    Wire.begin(); // Sensors are on the first I2C Bus, air and light sensor boards
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.
    SPI.begin(); // data from the ****************************************************** alphasensor

    #ifdef CHEMSENSE_INCLUDE
    digitalWrite(PIN_CHEMSENSE_POW, LOW);  //** Power on the Chemsense board
    #endif

    //** sensors_setup.ino, initialize sensors in airsense and lightsense boards
    Sensors_Setup();    // TMP112 config(); Chemsense turned off, This has to come later than chemsense digital write

    //** begin I2C interface
    #ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire1.begin(I2C_SLAVE_ADDRESS);
    Wire1.onRequest(requestEvent);
    #endif

    #ifdef ALPHASENSE_INCLUDE
    delay(15000);
    alphasense_on();
    SerialUSB.print("on");
    delay(10000);

    alphasense_firmware();
    alphasense_config();
    // Serial.print("configuration");
    delay(1000);

    flag_alpha = true;
    #endif

    Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();
}

void loop()
{
    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif
    
    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif

    while (count < 15)       // every 24 sec
    {
        #ifdef CHEMSENSE_INCLUDE
        chemsense_acquire();
        #endif

#ifdef ALPHASENSE_INCLUDE
        alphasense_histo();
        delay(100);

        if (count == 14)        //every 23 sec
        {
            count_conf++;
            if (count_conf == 26)       // every 598 secs, about 10 min
            {
                alphasense_config();
                delay(100);
                alphasense_firmware();
                delay(100);

                flag_alpha = true;
                count_conf = 0;
            }
        }
#endif
    }

    // #ifdef ALPHASENSE_INCLUDE
    // alphasense_off();
    // SerialUSB.print("off");
    // delay(1000);
    // #endif

    assemble_packet_whole();        //******** packetize air/light/chem
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
        SerialUSB.write(packet_whole[i]);

#ifdef ALPHASENSE_INCLUDE
    alpha_packet_whole();           //******** packetize histo/firmware/config(part)
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
        SerialUSB.write(packet_whole[i]);

    if (flag_alpha == true)
    {
        alpha_packet_config();       //******** packetize config(part)

        for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
            SerialUSB.write(packet_whole[i]);
    }

    flag_alpha = false;
#endif
    
    count = 0;

    //************************** test OIX sub-packet
    // SerialUSB.print("OIX_count ");
    // SerialUSB.print(OIX_count);
    // SerialUSB.print(" OIX_packet_count ");
    // SerialUSB.println(OIX_packet_count);

    // for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
    // {
    //     SerialUSB.print(packet_whole[i], HEX);
    //     if (i < packet_whole[0x02] + 0x04)
    //         SerialUSB.print(":");
    // }
    // SerialUSB.print("\n");

    // OIX_count = 0;
    // OIX_packet_count = 0;
    //************************** test OIX sub-packet
}

#ifdef I2C_INTERFACE
void requestEvent()
{
    #ifdef I2C_INTERFACE_CONST_SIZE
    Wire1.write(packet_whole, I2C_PACKET_SIZE);

    #else
    char bytes_to_send;
    bytes_to_send = packet_whole[0x02] + 0x05;
    Wire1.write(packet_whole, bytes_to_send );
    #endif

    I2C_READ_COMPLETE = true;
    assemble_packet_empty();
}
#endif

void handler()
{
    //TIMER = false;
    count++;
    UP_DOWN =! UP_DOWN;
    digitalWrite(PIN_HBT, UP_DOWN);
}



#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/CRC_8_Waggle.ino"
/** Calculate CRC8 ********************************************************************/
byte CRC_calc(byte length_data)
{
    byte crc = 0x00;
    
    for (int i = 0x03; i < (length_data + 0x03); i++) // 0x03 accounts for header
        crc = CRC_8_Waggle(packet_whole[i], crc);

    return crc;
}
/**************************************************************************************/


/** Calculate CRC, byte by byte *******************************************************/
byte CRC_8_Waggle(byte data, byte crc)
{
    byte i;
    crc ^= data;

    for (i = 0x00; i < 0x08; i++)
    {
        if (crc & 0x01)
            crc = (crc >> 0x01) ^ 0x8C;
        else
            crc =  crc >> 0x01;
    }

    return(crc);
}
/**************************************************************************************/


#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/HIH.ino"
#ifdef HIH6130_include
void HIH_fetch_humidity_temperature()
{
    Wire.beginTransmission(HIH_ADDRESS);
    Wire.endTransmission();
    delay(100);

    Wire.requestFrom((int)HIH_ADDRESS, (int) 4);

    Temp_byte[1] = Wire.read();
    Temp_byte[2] = Wire.read();
    Temp_byte[3] = Wire.read();
    Temp_byte[4] = Wire.read();
    
    Wire.endTransmission();

    Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

    Temp_byte[1] = Temp_byte[1] & 0x3f;
    Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

    Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
    Temp_int[1] = Temp_int[1] / 4;

    Temp_float[1] = (float) Temp_int[0] * 6.10e-3;
    Temp_float[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;
}
#endif

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TMP112.ino"
#ifdef TMP112_include

void TMP112_CONFIG()
{
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire.write(0x60);  // write data
    Wire.write(0xB0);  // write data
    Wire.endTransmission(); // end transmission
    delay(100);
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire.endTransmission(); // end transmission
    delay(100);
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    Temp_byte[0] = Wire.read(); // receive DATA
    Temp_byte[1] = Wire.read();// receive DATA
    Wire.endTransmission(); // end transmission
}

void TMP112_read()
{
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.write(TMP112_TEMP_REG); // sends register address to read from
    Wire.endTransmission(); // end transmission
    delay(100);
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    Temp_byte[0] = Wire.read(); // receive DATA
    Temp_byte[1] = Wire.read();// receive DATA
    Wire.endTransmission(); // end transmission

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
}

#endif
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/TSYS01.ino"
#ifdef TSYS01_include

float retVal = 0.0;

void TSYS01_CONFIG()
{
    TSYS01INIT();
    TSYS_Get_Coeff();
}

void TSYS01_read()
{
    TSYS01GetTemp();
}

void TSYS01INIT()
{
    Wire.beginTransmission(TSYS01Address);
    Wire.write(0x1E);
    Wire.endTransmission();
    delay(50);
}


void TSYS_Get_Coeff()  //gathers calibration coefficients to array
{
    for (uint8_t n = 0; n < 5; n++)
    {
        Wire.beginTransmission(TSYS01Address);
        Wire.write(0xA2 + (n * 2));
        Wire.endTransmission();
        Wire.requestFrom(TSYS01Address, 2);
        uint8_t Ai = Wire.read();
        uint8_t Bi = Wire.read();
        uint16_t x = (uint16_t)Ai << 8;
        x += Bi;
        TSYS_coefficents[n] = x;
    }
}


float TSYS_ScaleTemp_C(uint16_t rawAdc)
{

    retVal =
    (-2) * (float)TSYS_coefficents[TSYS_K4] * (float)pow(10, -21) * pow(rawAdc, 4) +
    4 * (float)TSYS_coefficents[TSYS_K3] * (float)pow(10, -16) * pow(rawAdc, 3) +
    (-2) * (float)TSYS_coefficents[TSYS_K2] * (float)pow(10, -11) * pow(rawAdc, 2) +
    1 * (float)TSYS_coefficents[TSYS_K1] * (float)pow(10, -6) * rawAdc +
    (-1.5) * (float)TSYS_coefficents[TSYS_K0] * (float)pow(10, -2);

    return retVal;

}

void TSYS01GetTemp()
{
    Wire.beginTransmission(TSYS01Address);
    Wire.write(TSYS01StartReg); //Start measurement process
    Wire.endTransmission();
    delay(10);

    Wire.beginTransmission(TSYS01Address);
    Wire.write(TSYS01TempReg); //Request measurement
    Wire.endTransmission();

    Wire.requestFrom(TSYS01Address,3); //read in 24 bit output
    Temp_byte[0] = Wire.read();
    Temp_byte[1] = Wire.read();
    Temp_byte[2] = Wire.read(); //not used but necessary if 24bit conversion method is found (shifts below return 24bit output / 256 per TSYS01 datasheet conversion equations

    Temp_float[0] = TSYS_ScaleTemp_C((((unsigned long)Temp_byte[0] << 8) | ((unsigned long)Temp_byte[1]))); //convert and cast to Temp with scaling equation
}

#endif
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/airsense.ino"

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
    long SPV_1_AMPV[100];
    double SPV_1_AMPV_AVG = 0;

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV[i] = 512 - analogRead(SPV_1_AMP);
        if (SPV_1_AMPV[i] < 0)
        {
            SPV_1_AMPV[i] = SPV_1_AMPV[i] * -1;
        }
        delay(1);
    }

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * i) + SPV_1_AMPV[i]) / (i+1);
    }

    SPV1840LR5HB[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(int(SPV_1_AMPV_AVG * 10));

    SPV1840LR5HB[2] = formatted_data_buffer[0];
    SPV1840LR5HB[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    // SerialUSB.print("SPV1840LR5HB: ");
    // SerialUSB.println(Temp_uint16);

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
    #endif
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


#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alpha_packet.ino"

/** Assemble whole packet *************************************************************/
void alpha_packet_whole()
{
    packet_whole_index = 3; // start at 3 to account for header
    

#ifdef ALPHASENSE_INCLUDE
    if ((alpha_histogram[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(alpha_histogram); i++)
        {
            packet_whole[packet_whole_index] = alpha_histogram[i];
            packet_whole_index++;
        }
        alpha_histogram[1] = (0 << 7) | LENGTH_ALPHA_HISTOGRAM;
    }

    if (flag_alpha == true)
    {
        if ((alpha_firmware[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_firmware); i++)
            {
                packet_whole[packet_whole_index] = alpha_firmware[i];
                packet_whole_index++;
            }
            alpha_firmware[1] = (0 << 7) | LENGTH_ALPHA_FIRMWARE;
        }
    }

    if (flag_alpha == true)
    {
        if ((alpha_config_a[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_a); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_a[i];
                packet_whole_index++;
            }
            alpha_config_a[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_A;
        }
    }
#endif
   

    // #ifdef system_health_include
    // // Append health
    // for (int i = 0; i < sizeof(sensor_health); i++)
    // {
    //     packet_whole[packet_whole_index] = sensor_health[i];
    //     // Increment index for whole packet
    //     packet_whole_index++;
    // }
    // #endif


    // Length
    packet_whole[0x02] = packet_whole_index - 0x03;
    packet_seq_number++;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;

    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = END_BYTE;

//     #ifdef SERIAL_DEBUG
//     SerialUSB.println(packet_whole_index, DEC);
//     #endif
}
/**************************************************************************************/

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alpha_packet_conf.ino"

/** Assemble whole packet *************************************************************/
void alpha_packet_config()
{
    packet_whole_index = 3; // start at 3 to account for header
    

#ifdef ALPHASENSE_INCLUDE
    if (flag_alpha == true)
    {
        if ((alpha_config_b[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_b); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_b[i];
                packet_whole_index++;
            }
            alpha_config_b[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_B;
        }

        if ((alpha_config_c[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_c); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_c[i];
                packet_whole_index++;
            }
            alpha_config_c[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_C;
        }

        if ((alpha_config_d[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_d); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_d[i];
                packet_whole_index++;
            }
            alpha_config_d[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_D;
        }


        flag_alpha = false;
    }
#endif
   

    // #ifdef system_health_include
    // // Append health
    // for (int i = 0; i < sizeof(sensor_health); i++)
    // {
    //     packet_whole[packet_whole_index] = sensor_health[i];
    //     // Increment index for whole packet
    //     packet_whole_index++;
    // }
    // #endif


    // Length
    packet_whole[0x02] = packet_whole_index - 0x03;
    packet_seq_number++;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;

    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = END_BYTE;

//     #ifdef SERIAL_DEBUG
//     SerialUSB.println(packet_whole_index, DEC);
//     #endif
}
/**************************************************************************************/

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/alphasense.ino"
// the sensor communicates using SPI, so include the library:
// #include <SPI.h>

// // will use digital pin 33 instead of pin 10 
// // because of the cirsumstnace of the airsense boards
// const int select_slave = 33;
// const int SPI_MAX_speed = 500000;   //2000000;  //250000;

// uint8_t stat1, val1, val2, result;

// byte buff[62];
// byte SPI_read_byte = 0;

// SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);

// void setup() {
//     SerialUSB.begin(115200);

//     pinMode(select_slave, OUTPUT);
//     SPI.begin();
// }

void alphasense_on() 
{
	//** POWER ON
	SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    val1 = SPI.transfer(0x03);
    delay(100);
    val2 = SPI.transfer(0x00);
    delay(100);
    
    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPAH_DEBUG
    SerialUSB.print(val1, HEX);
    SerialUSB.print(val2, HEX);
#endif
}

void alphasense_off()
{
    //** POWER OFF
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

	val1 = SPI.transfer(0x03);
	delay(100);
    val2 = SPI.transfer(0x01);
    delay(100);

	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPAH_DEBUG
    SerialUSB.print(val1, HEX);
    SerialUSB.print(val2, HEX);
#endif
}

void alphasense_firmware()
{
    alpha_firmware[1] = (1 << 7) | LENGTH_ALPHA_FIRMWARE;

	//** Get firmware    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SPI.transfer(0x12);    // 0xF3
    delay(100);

    alpha_firmware[2] = SPI.transfer(0x12);
    delay(100);
    alpha_firmware[3] = SPI.transfer(0x12);
    delay(100);

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    SerialUSB.write(alpha_firmware[0]);
    SerialUSB.write(alpha_firmware[1]);
#endif
}


void alphasense_histo()
{
    alpha_histogram[1] = (1 << 7) | LENGTH_ALPHA_HISTOGRAM;

    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x30);   // 0xF3
    delay(100);
    
    for (i = 0; i < 62; i++)
    {
	    alpha_histogram[i + 2] = SPI.transfer(0x30);
	    delay(100);
	}

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();	

#ifdef ALPHA_DEBUG
    for (i = 0; i < 62; i++)
    	SerialUSB.write(alpha_histogram[i]);
#endif
}

void alphasense_config()
{
    alpha_config_a[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_A;
    alpha_config_b[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_B;
    alpha_config_c[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_C;
    alpha_config_d[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_D;

    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x3C);   // 0xF3
    delay(100);
    
    for (i = 0; i < 64; i++)
    {
	    alpha_config_a[i + 2] = SPI.transfer(0x3C);
	    delay(100);
	}

    for (i = 0; i < 64; i++)
    {
        alpha_config_b[i + 2] = SPI.transfer(0x3C);
        delay(100);
    }

    for (i = 0; i < 64; i++)
    {
        alpha_config_c[i + 2] = SPI.transfer(0x3C);
        delay(100);
    }

    for (i = 0; i < 64; i++)
    {
        alpha_config_d[i + 2] = SPI.transfer(0x3C);
        delay(100);
    }

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    for (i = 0; i < 64; i++)
	    SerialUSB.print(alpha_config_a[i], HEX);
    for (i = 0; i < 64; i++)
        SerialUSB.print(alpha_config_b[i], HEX);
    for (i = 0; i < 64; i++)
        SerialUSB.print(alpha_config_c[i], HEX);
    for (i = 0; i < 64; i++)
        SerialUSB.print(alpha_config_d[i], HEX);
#endif
}



#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/chemsense.ino"
/* Chemsesne reader using the Serial "Serial3".
 * Suppose that the Chemsense is device /dev/ttyACM0 when you connect the board with light and airsense.
 */


void form3_hex_string_to_hex()                     // Hex to hex: form3
{
    Temp_ulong[0] = 0x000000;
    Temp_ulong[1] = 0x000000;

    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] > '9')                   // letters
            VAL[i] = VAL[i] - 'a' + 0x0a;
        else                                // numbers
            VAL[i] = VAL[i] - '0';

        if (i < VAL_NUM_ID / 2)
            Temp_ulong[0] = Temp_ulong[0] | (VAL[i] << (VAL_NUM_ID / 2 - i - 1) * 4);
        else
            Temp_ulong[1] = Temp_ulong[1] | (VAL[i] << (VAL_NUM_ID - i - 1) * 4);
    }

    Temp_byte[0] = (Temp_ulong[0] & 0xFF0000) >> 16;
    Temp_byte[1] = (Temp_ulong[0] & 0x00FF00) >> 8;
    Temp_byte[2] = (Temp_ulong[0] & 0x0000FF);
    Temp_byte[3] = (Temp_ulong[1] & 0xFF0000) >> 16;
    Temp_byte[4] = (Temp_ulong[1] & 0x00FF00) >> 8;
    Temp_byte[5] = (Temp_ulong[1] & 0x0000FF);
    format3(Temp_byte);
}

void form1_hex_string_to_unsigned_int()            //hex to uint: form1
{
    Temp_uint16 = 0x0000;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] > '9')                   // letters
            VAL[i] = VAL[i] - 'a' + 0x0a;
        else                                // numbers
            VAL[i] = VAL[i] - '0';

        Temp_uint16 = Temp_uint16 | (VAL[i] << (VAL_NUM_ID - i - 1) * 4);
    }
    format1(Temp_uint16);
}

void form1_int_string_to_unsigned_int()                //form1
{
    Temp_uint16 = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_uint16 = (Temp_uint16 * 10) + VAL[i];
    }
    format1(Temp_uint16);
}

void form4_int_string_to_unsigned_long(int shift_needed)                //form4
{
    Temp_ulong[0] = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_ulong[0] = (Temp_ulong[0] * 10) + VAL[i];
    }
    if (shift_needed == 1)
        Temp_ulong[0] = (Temp_ulong[0] & 0xffffff00) >> 8;

    format4(Temp_ulong[0] & 0xffffff);
}

void form2_int_string_to_int()                   // form2
{
    Temp_int[0] = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_int[0] = (Temp_int[0] * 10) + VAL[i];
    }
    if (VAL[0] == '-')
        Temp_int[0] *= -1;
    format2(Temp_int[0]);
}

void form5_int_string_to_long()    // form5
{
    Temp_long = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_long = (Temp_long * 10) + VAL[i];
    }
    if (VAL[0] == '-')
        Temp_long *= -1;
    format5(Temp_long);
}

int compareKey(char k1, char k2, char k3)
{
    if (KEY[0] != k1) return -1;
    if (KEY[1] != k2) return -1;
    if (KEY[2] != k3) return -1;
    return 0;
}

void chemsense_acquire()
{
    if (Serial3.available() > 0)
    {
        INPUT_BYTE = Serial3.read();     //read the incoming byte

        if (INPUT_BYTE >= 'a' && INPUT_BYTE <= 'z' ||
            INPUT_BYTE >= 'A' && INPUT_BYTE <= 'Z' ||
            INPUT_BYTE >= '0' && INPUT_BYTE <= '9' ||
            INPUT_BYTE == '-')
        {
            if (!flag_KEY)
            {
                if (KEY_NUM_ID < 3)
                {
                    KEY[KEY_NUM_ID] = INPUT_BYTE;
                    KEY_NUM_ID++;
                }
                else
                    KEY_NUM_ID = 0;
            }
            else
            {
                if (VAL_NUM_ID < 12)
                {
                    VAL[VAL_NUM_ID] = INPUT_BYTE;
                    VAL_NUM_ID++;
                }
                else
                {
                    KEY_NUM_ID = 0;
                    VAL_NUM_ID = 0;
                    flag_KEY = false;
                }
            }
        }
        else if (INPUT_BYTE == '=')
        {
            flag_KEY = true;
        }
        else if (INPUT_BYTE == '\r' || INPUT_BYTE == ' ' || INPUT_BYTE == '\n')
        {
            //KEY[KEY_NUM_ID] = '\0';
            //VAL[VAL_NUM_ID] = '\0';
            Carrier();
            KEY_NUM_ID = 0;
            VAL_NUM_ID = 0;
        }
    }
}

void Carrier()
{
    // transform the data format as it defined

	if (!flag_KEY)
		return;

    flag_KEY = false;
    // #ifdef SERIAL_DEBUG
    //     // to confirm output data
    //     SerialUSB.print(KEY);
    //     SerialUSB.print(" ");
    //     SerialUSB.print(VAL);
    //     SerialUSB.print(" ");
    // #endif

	if (compareKey('B', 'A', 'D') == 0)
	{
        //Hex_BAD();
        form3_hex_string_to_hex();

        chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;
        chemsense_MAC_ID[1] = (1 << 7) | LENGTH_FORMAT3;

        for (i = 0; i < LENGTH_FORMAT3; i++)
            chemsense_MAC_ID[2 + i] = formatted_data_buffer[i];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT3; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
	}

	else if (compareKey('S', 'H', 'T') == 0)  // wait SHH
	{
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check the values
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('S', 'H', 'H') == 0)
    {
        //Temp_uint16 = (unsigned int)atoi(VAL);       //char to int
        //format1(Temp_uint16);
        form1_int_string_to_unsigned_int();

        SHT25[0] = ID_SHT25;
        SHT25[1] = (1 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
        SHT25[2] = formatted_byte_temp[0];
        SHT25[3] = formatted_byte_temp[1];
        SHT25[4] = formatted_data_buffer[0];
        SHT25[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check the values
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('L', 'P', 'T') == 0)  // wait LPP
	{
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('L', 'P', 'P') == 0)
    {
        //Int_form4();
        form4_int_string_to_unsigned_long(0);

        LPS25H[0] = ID_LPS25H;
        LPS25H[1] = (1 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
        LPS25H[2] = formatted_byte_temp[0];
        LPS25H[3] = formatted_byte_temp[1];
        LPS25H[4] = formatted_data_buffer[0];
        LPS25H[5] = formatted_data_buffer[1];
        LPS25H[6] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT4; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
	}

	else if (compareKey('S', 'U', 'V') == 0)  // wait SVL and SIR
	{
        //Hex_form1();
        form1_hex_string_to_unsigned_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('S', 'V', 'L') == 0)
    {
        //Hex_form1();
        form1_hex_string_to_unsigned_int();

        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('S', 'I', 'R') == 0)
    {
        //Hex_form1();
        form1_hex_string_to_unsigned_int();

        Si1145[0] = ID_Si1145;
        Si1145[1] = (1 << 7) | (LENGTH_FORMAT1 * 3);
        Si1145[2] = formatted_byte_temp[0];
        Si1145[3] = formatted_byte_temp[1];
        Si1145[4] = formatted_byte_temp[2];
        Si1145[5] = formatted_byte_temp[3];
        Si1145[6] = formatted_data_buffer[0];
        Si1145[7] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT1; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('I', 'R', 'R') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
        total_reducing_gases[1] = (1 << 7) | LENGTH_FORMAT5;
        total_reducing_gases[2] = formatted_data_buffer[0];
        total_reducing_gases[3] = formatted_data_buffer[1];
        total_reducing_gases[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('I', 'A', 'Q') == 0)
    {
        //Int_form5();
        form5_int_string_to_long();

        total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
        total_oxidizing_gases[1] = (1 << 7) | LENGTH_FORMAT5;
        total_oxidizing_gases[2] = formatted_data_buffer[0];
        total_oxidizing_gases[3] = formatted_data_buffer[1];
        total_oxidizing_gases[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('S', 'O', '2') == 0)
    {
        //Int_form5();
        form5_int_string_to_long();

        sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
        sulfur_dioxide[1] = (1 << 7) | LENGTH_FORMAT5;
        sulfur_dioxide[2] = formatted_data_buffer[0];
        sulfur_dioxide[3] = formatted_data_buffer[1];
        sulfur_dioxide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('H', '2', 'S') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
        hydrogen_sulphide[1] = (1 << 7) | LENGTH_FORMAT5;
        hydrogen_sulphide[2] = formatted_data_buffer[0];
        hydrogen_sulphide[3] = formatted_data_buffer[1];
        hydrogen_sulphide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('O', 'Z', 'O') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        ozone[0] = ID_OZONE;
        ozone[1] = (1 << 7) | LENGTH_FORMAT5;
        ozone[2] = formatted_data_buffer[0];
        ozone[3] = formatted_data_buffer[1];
        ozone[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('N', 'O', '2') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
        nitrogen_dioxide[1] = (1 << 7) | LENGTH_FORMAT5;
        nitrogen_dioxide[2] = formatted_data_buffer[0];
        nitrogen_dioxide[3] = formatted_data_buffer[1];
        nitrogen_dioxide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('C', 'M', 'O') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        carbon_monoxide[0] = ID_CARBON_MONOXIDE;
        carbon_monoxide[1] = (1 << 7) | LENGTH_FORMAT5;
        carbon_monoxide[2] = formatted_data_buffer[0];
        carbon_monoxide[3] = formatted_data_buffer[1];
        carbon_monoxide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT5; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
	}

	else if (compareKey('A', 'T', '0') == 0)
	{
        //Int_form2();
        form2_int_string_to_int();

        CO_ADC_temp[0] = ID_CO_ADC_TEMP;
        CO_ADC_temp[1] = (1 << 7) | LENGTH_FORMAT2;
        CO_ADC_temp[2] = formatted_data_buffer[0];
        CO_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('A', 'T', '1') == 0)
	{
		//Int_form2();
        form2_int_string_to_int();

        IAQ_IRR_ADC_temp[0] = ID_IAQ_IRR_ADC_TEMP;
        IAQ_IRR_ADC_temp[1] = (1 << 7) | LENGTH_FORMAT2;
        IAQ_IRR_ADC_temp[2] = formatted_data_buffer[0];
        IAQ_IRR_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('A', 'T', '2') == 0)
	{
		//Int_form2();
        form2_int_string_to_int();

        O3_NO2_ADC_temp[0] = ID_O3_NO2_ADC_TEMP;
        O3_NO2_ADC_temp[1] = (1 << 7) | LENGTH_FORMAT2;
        O3_NO2_ADC_temp[2] = formatted_data_buffer[0];
        O3_NO2_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('A', 'T', '3') == 0)
	{
        //Int_form2();
        form2_int_string_to_int();

        SO2_H2S_ADC_temp[0] = ID_SO2_H2S_ADC_TEMP;
        SO2_H2S_ADC_temp[1] = (1 << 7) | LENGTH_FORMAT2;
        SO2_H2S_ADC_temp[2] = formatted_data_buffer[0];
        SO2_H2S_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('L', 'T', 'M') == 0)
	{
		//Int_form2();
        form2_int_string_to_int();

        CO_LMP_temp[0] = ID_CO_LMP_TEMP;
        CO_LMP_temp[1] = (1 << 7) | LENGTH_FORMAT2;
        CO_LMP_temp[2] = formatted_data_buffer[0];
        CO_LMP_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('A', 'C', 'X') == 0)  //wait ACY, ACZ, and VIX
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('A', 'C', 'Y') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('A', 'C', 'Z') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[4] = formatted_data_buffer[0];
        formatted_byte_temp[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('V', 'I', 'X') == 0)
    {
        //Int_form4();
        form4_int_string_to_unsigned_long(1);

        three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
        three_accel_and_vib[1] = (1 << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        three_accel_and_vib[2] = formatted_byte_temp[0];
        three_accel_and_vib[3] = formatted_byte_temp[1];
        three_accel_and_vib[4] = formatted_byte_temp[2];
        three_accel_and_vib[5] = formatted_byte_temp[3];
        three_accel_and_vib[6] = formatted_byte_temp[4];
        three_accel_and_vib[7] = formatted_byte_temp[5];
        three_accel_and_vib[8] = formatted_data_buffer[0];
        three_accel_and_vib[9] = formatted_data_buffer[1];
        three_accel_and_vib[10] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT4; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

	else if (compareKey('G', 'Y', 'X') == 0)  //wait GYY, GYZ, and OIX
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('G', 'Y', 'Y') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('G', 'Y', 'Z') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[4] = formatted_data_buffer[0];
        formatted_byte_temp[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT2; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

    else if (compareKey('O', 'I', 'X') == 0)
    {
        //Int_form4();
        form4_int_string_to_unsigned_long(1);

        three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;
        three_gyro_and_orientation[1] = (1 << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        three_gyro_and_orientation[2] = formatted_byte_temp[0];
        three_gyro_and_orientation[3] = formatted_byte_temp[1];
        three_gyro_and_orientation[4] = formatted_byte_temp[2];
        three_gyro_and_orientation[5] = formatted_byte_temp[3];
        three_gyro_and_orientation[6] = formatted_byte_temp[4];
        three_gyro_and_orientation[7] = formatted_byte_temp[5];
        three_gyro_and_orientation[8] = formatted_byte_temp[6];
        three_gyro_and_orientation[8] = formatted_data_buffer[0];
        three_gyro_and_orientation[9] = formatted_data_buffer[1];
        three_gyro_and_orientation[10] = formatted_data_buffer[2];

        OIX_count++;

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT4; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

}

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/dataFormats.ino"
// Packet formatters -
// F1 - unsigned int_16 input, {0-0xffff} - Byte1 Byte2 (16 bit number)
// F2 - int_16 input , +-{0-0x7fff} - 1S|7Bits Byte2
// F3 - byte input[6], {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
// F4 - unsigned long_24 input, {0-0xffffff} - Byte1 Byte2 Byte3
// F5 - long_24 input, +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
// F6 - float input, +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}
// F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
// F8 - float input, +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac


/** Format 1 assembler ****************************************************************/
// F1 - {0-0xffff} - Byte1 Byte2 (16 bit number)
void format1(unsigned int input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff00) >> 8;
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/



/** Format 2 assembler ****************************************************************/
// F2 - +-{0-0x7fff} - 1S|7Bits Byte2
void format2(int input)
{

    byte _negative;
    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }
    // Get abs. value of input
    input = abs(input);
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f00) >> 8);
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/


/** Format 3 assembler ****************************************************************/
// F3 - {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
void format3(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
    formatted_data_buffer[4] = input[4];
    formatted_data_buffer[5] = input[5];
}
/**************************************************************************************/

/** Format 4 assembler ****************************************************************/
// F4 - {0-0xffffff} - Byte1 Byte2 Byte3
void format4(unsigned long input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff0000) >> 16;
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/



/** Format 5 assembler ****************************************************************/
// F5 - +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
void format5(long input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f0000) >> 16);
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/


/** Format 6 assembler ****************************************************************/
// F6 - +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}

void format6(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Extract integer component
    unsigned int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    unsigned int fractional = ((int)(input*100) - integer*100);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | integer;
    formatted_data_buffer[1] = (fractional & 0x7F);
}
/**************************************************************************************/

/** Format 7 assembler ****************************************************************/
// F7 - {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
void format7(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
}
/**************************************************************************************/

/** Format 8 assembler ****************************************************************/
// F8 - +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac
void format8(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Extract integer component
    int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    int fractional = int((input - integer) * 1000);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((integer & 0x1F) << 2) | ((fractional & 0x0300) >> 8);
    formatted_data_buffer[1] = (fractional & 0x00FF);;
}
/**************************************************************************************/

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/initialization.ino"
void sensor_buff_initialization()
{
	//***************************** FIRST BYTE of the array
	MAC_ID[0] = ID_MAC;	MAC_ID[0] = ID_MAC;

	// airsense board
    TMP112[0] = ID_TMP112;
    HTU21D_array[0] = ID_HTU21D;

    HIH4030[0] = ID_HIH4030;

    BMP180[0] = ID_BMP180;
    PR103J2[0] = ID_PR103J2;
    TSL250RD_1[0] = ID_TSL250RD_1;

    MMA8452Q[0] = ID_MMA8452Q;
    SPV1840LR5HB[0] = ID_SPV1840LR5HB;
    TSYS01[0] = ID_TSYS01;



    // lightsense board
    HMC5883L[0] = ID_HMC5883L;
    HIH6130[0] = ID_HIH6130;

    APDS9006020[0] = ID_APDS9006020;
    TSL260RD[0] = ID_TSL260RD;
    TSL250RD_2[0] = ID_TSL250RD_2;

    MLX75305[0] = ID_MLX75305;
    ML8511[0] = ID_ML8511;
    TMP421[0] = ID_TMP421;



	//chemsense board
	chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;

	SHT25[0] = ID_SHT25;
	LPS25H[0] = ID_LPS25H;
	Si1145[0] = ID_Si1145;

	total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
	total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
	sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
	hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
	ozone[0] = ID_OZONE;
	nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
	carbon_monoxide[0] = ID_CARBON_MONOXIDE;

	CO_ADC_temp[0] = ID_CO_ADC_TEMP;
	IAQ_IRR_ADC_temp[0] = ID_IAQ_IRR_ADC_TEMP;
	O3_NO2_ADC_temp[0] = ID_O3_NO2_ADC_TEMP;
	SO2_H2S_ADC_temp[0] = ID_SO2_H2S_ADC_TEMP;
	CO_LMP_temp[0] = ID_CO_LMP_TEMP;

	three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
	three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;


	// alpha sensor
	alpha_firmware[0] = ID_ALPHA_FIRMWARE;
	alpha_histogram[0] = ID_ALPHA_HISTOGRAM;

	alpha_config_a[0] = ID_ALPHA_CONFIG_A;
	alpha_config_b[0] = ID_ALPHA_CONFIG_B;
	alpha_config_c[0] = ID_ALPHA_CONFIG_C;
	alpha_config_d[0] = ID_ALPHA_CONFIG_D;



	//***************************** SECOND BYTE of the array
    // airsense initialization
	MAC_ID[1] = (1 << 7) | LENGTH_FORMAT3;

	// airsense initialization
    TMP112[1] = (0 << 7) | LENGTH_FORMAT6;
    HTU21D_array[1] = (0 << 7) | LENGTH_FORMAT6;

    HIH4030[1] = (0 << 7) | LENGTH_FORMAT1;

    BMP180[1] = (0 << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    PR103J2[1] = (0 << 7) | LENGTH_FORMAT1;
    TSL250RD_1[1] = (0 << 7) | LENGTH_FORMAT1;

    MMA8452Q[1] = (0 << 7) | (LENGTH_FORMAT6 * 4);
    SPV1840LR5HB[1] = (0 << 7) | LENGTH_FORMAT1;
    TSYS01[1] = (0 << 7) | LENGTH_FORMAT6;


    // lightsense initialization
    HMC5883L[1] = (0 << 7) | (LENGTH_FORMAT8 * 3);
    HIH6130[1] = (0 << 7) | (LENGTH_FORMAT6 * 2);

    APDS9006020[1] = (0 << 7) | LENGTH_FORMAT1;
    TSL260RD[1] = (0 << 7) | LENGTH_FORMAT1;
    TSL250RD_2[1] = (0 << 7) | LENGTH_FORMAT1;

    MLX75305[1] = (0 << 7) | LENGTH_FORMAT1;
    ML8511[1] = (0 << 7) | LENGTH_FORMAT1;
    TMP421[1] = (0 << 7) | LENGTH_FORMAT6;


	// chemsemse initialization
	chemsense_MAC_ID[1] = (0 << 7) | LENGTH_FORMAT3;

	SHT25[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
	LPS25H[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
	Si1145[1] = (0 << 7) | (LENGTH_FORMAT1 * 3);

	total_reducing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
	total_oxidizing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
	sulfur_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
	hydrogen_sulphide[1] = (0 << 7) | LENGTH_FORMAT5;
	ozone[1] = (0 << 7) | LENGTH_FORMAT5;
	nitrogen_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
	carbon_monoxide[1] = (0 << 7) | LENGTH_FORMAT5;

	CO_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
	IAQ_IRR_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
	O3_NO2_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
	SO2_H2S_ADC_temp[1] = (0 >> 7) | LENGTH_FORMAT2;
	CO_LMP_temp[1] = (0 << 7) | LENGTH_FORMAT2;

	three_accel_and_vib[1] = (0 << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
	three_gyro_and_orientation[1] = (0 << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);


	// alpha sensor
	alpha_firmware[1] = (0 << 7) | LENGTH_ALPHA_FIRMWARE;
	alpha_histogram[1] = (0 << 7) | LENGTH_ALPHA_HISTOGRAM;

	alpha_config_a[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_A;
	alpha_config_b[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_B;
	alpha_config_c[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_C;
	alpha_config_d[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_D;
}
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/lightsense.ino"

void lightsense_acquire (void)
{
// #ifdef SERIAL_DEBUG
//     SerialUSB.print("\n");
//     SerialUSB.println("Acquiring LightSense Data");
// #endif


#ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    HMC5883L[1] = (1 << 7) | (LENGTH_FORMAT8 * 3);

    format8(event.magnetic.x);
    HMC5883L[2] = formatted_data_buffer[0];
    HMC5883L[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (j = 0; j < LENGTH_FORMAT8; j++)
        SerialUSB.print(formatted_data_buffer[j],HEX);
#endif

    format8(event.magnetic.y);
    HMC5883L[4] = formatted_data_buffer[0];
    HMC5883L[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (j = 0; j < LENGTH_FORMAT8; j++)
        SerialUSB.print(formatted_data_buffer[j],HEX);
#endif

    format8(event.magnetic.z);
    HMC5883L[6] = formatted_data_buffer[0];
    HMC5883L[7] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (j = 0; j < LENGTH_FORMAT8; j++)
        SerialUSB.print(formatted_data_buffer[j],HEX);
#endif

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("HMC5883L X:");
//     SerialUSB.print(event.magnetic.x);
//     SerialUSB.print(", Y:");
//     SerialUSB.print(event.magnetic.y);
//     SerialUSB.print(", Z:");
//     SerialUSB.println(event.magnetic.z);
// #endif
#endif


#ifdef HIH6130_include
    HIH_fetch_humidity_temperature();

    HIH6130[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

    format6(Temp_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format6(Temp_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("HIH6130 RH%:");
//     SerialUSB.print(Temp_float[1]);
//     SerialUSB.print("  Temperature:");
//     SerialUSB.println(Temp_float[0]);
// #endif
#endif


#ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());

    APDS9006020[1] = (1 << 7) | LENGTH_FORMAT1;
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("APDS9006020: ");
    // SerialUSB.println(mcp3428_2.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    TSL260RD[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TSL260RD: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    TSL250RD_2[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TSL250RD_2: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    MLX75305[1] = (1 << 7) | LENGTH_FORMAT1;
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("MLX75305: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    ML8511[1] = (1 << 7) | LENGTH_FORMAT1;
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("ML8511: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef TMP421_include
    Temp_float[0] = TMP421_Sensor.GetTemperature();
    format6(Temp_float[0]);

    TMP421[1] = (1 << 7) | LENGTH_FORMAT6;
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TMP421: ");
    // SerialUSB.println(Temp_float[0]);

    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

}


#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/mma84521.ino"
#ifdef MMA8452Q_include

byte fsr;
int gCount = 0;

void MMA8452_read()
{
    readAccelData(Temp_int);

    for (i = 0 ; i < 3 ; i++)
        Temp_float[i] = (float)(Temp_int[i] / ((1 << 12) / (2 * GSCALE)));  // get actual g value, this depends on scale being set
}

void readAccelData(int *destination)
{
    byte rawData[6];  // x/y/z accel register data stored here

    MMA8452readRegisters(OUT_X_MSB, 6, rawData);  // Read the six raw data registers into data array

    // Loop to calculate 12-bit ADC and g value for each axis
    for(i = 0; i < 3 ; i++)
    {
        gCount = (rawData[i * 2] << 8) | rawData[(i * 2) + 1];  //Combine the two 8 bit registers into one 12-bit number
        gCount >>= 4; //The registers are left align, here we right align the 12-bit integer

        // If the number is negative, we have to make it so manually (no 12-bit data type)
        if (rawData[i * 2] > 0x7F)
            gCount -= 0x1000;

        destination[i] = gCount; //Record this gCount into the 3 int array
    }
}

// Initialize the MMA8452 registers
// See the many application notes for more info on setting all of these registers:
// http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=MMA8452Q
void MMA8452_CONFIG()
{
    MMA8452Standby();  // Must be in standby to change registers
    // Set up the full scale range to 2, 4, or 8g.
    fsr = GSCALE;
    if(fsr > 8) 
        fsr = 8; //Easy error check

    fsr >>= 2; // Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
    MMA8452writeRegister(XYZ_DATA_CFG, fsr);
    //The default data rate is 800Hz and we don't modify it in this example code
    MMA8452Active();  // Set to active to start reading
}

// Sets the MMA8452 to standby mode. It must be in standby to change most register settings
void MMA8452Standby()
{
    byte c = MMA8452readRegister(CTRL_REG1);
    MMA8452writeRegister(CTRL_REG1, c & ~(0x01)); //Clear the active bit to go into standby
}

// Sets the MMA8452 to active mode. Needs to be in this mode to output data
void MMA8452Active()
{
    byte c = MMA8452readRegister(CTRL_REG1);
    MMA8452writeRegister(CTRL_REG1, c | 0x01); //Set the active bit to begin detection
}

// Read bytesToRead sequentially, starting at addressToRead into the dest byte array
void MMA8452readRegisters(byte addressToRead, int bytesToRead, byte *dest)
{
    Wire.requestFrom((uint8_t) MMA8452_ADDRESS, (uint8_t) bytesToRead, (uint32_t) addressToRead, (uint8_t) 1, TRUE);
    while(Wire.available() < bytesToRead); //Hang out until we get the # of bytes we expect
    for(int x = 0 ; x < bytesToRead ; x++)
        dest[x] = Wire.read();
}

// Read a single byte from addressToRead and return it as a byte
byte MMA8452readRegister(byte addressToRead)
{
    Wire.requestFrom((uint8_t) MMA8452_ADDRESS, (uint8_t) 1, (uint32_t) addressToRead, (uint8_t) 1, TRUE);
    while(!Wire.available()) ; //Wait for the data to come back
    return Wire.read(); //Return this one byte
}

// Writes a single byte (dataToWrite) into addressToWrite
void MMA8452writeRegister(byte addressToWrite, byte dataToWrite)
{
    Wire.beginTransmission(MMA8452_ADDRESS);
    Wire.write(addressToWrite);
    Wire.write(dataToWrite);
    Wire.endTransmission(); //Stop transmitting
}

#endif
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/packet_assembler.ino"

/** Assemble empty packet *************************************************************/
void assemble_packet_empty()
{
    packet_whole[0x00] = START_BYTE;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = END_BYTE;
}
/**************************************************************************************/

/** Assemble whole packet *************************************************************/
void assemble_packet_whole()
{
    packet_whole_index = 3; // start at 3 to account for header
    
// #ifdef SERIAL_DEBUG
//     SerialUSB.println("Packing.");
// #endif

#ifdef AIRSENSE_INCLUDE

#ifdef MAC_ID_include    // Append MAC_ID

    for (i = 0; i < sizeof(MAC_ID); i++)
    {
        packet_whole[packet_whole_index] = MAC_ID[i];
        // Increment index for whole packet
        packet_whole_index++;
    }

    #ifdef PRINT_ADDRESS
    SerialUSB.print("Airsense-");
   for (unsigned char a = 0x02; a < 0x08; a++)
    {
        if ((MAC_ID[a] & 0xF0) == 0x00)
        {

            SerialUSB.print('0');            
        }

        SerialUSB.print(MAC_ID[a],HEX);

        if (a < 0x07) { SerialUSB.print(":"); }
        else { SerialUSB.println("\r"); }
    }

    SerialUSB.print("Lightsense-");
    for (unsigned char a = 0x02; a < 0x08; a++)
    {
        if ((MAC_ID[a] & 0xF0) == 0x00)
        {

            SerialUSB.print('0');            
        }

        SerialUSB.print(MAC_ID[a],HEX);

        if (a < 0x07) { SerialUSB.print(":"); }
        else { SerialUSB.println("\r"); }
    }
#endif
#endif

#ifdef TMP112_include    // Append TMP112
    if ((TMP112[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TMP112); i++)
        {
            packet_whole[packet_whole_index] = TMP112[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP112[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif

#ifdef HTU21D_include    // Append HTU21D
    if((HTU21D_array[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HTU21D_array); i++)
        {
            packet_whole[packet_whole_index] = HTU21D_array[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HTU21D_array[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif

#ifdef HIH4030_include    // Append HIH4030
    if((HIH4030[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HIH4030); i++)
        {
            packet_whole[packet_whole_index] = HIH4030[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH4030[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef BMP180_include    // Append BMP180
    if ((BMP180[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(BMP180); i++)
        {
            packet_whole[packet_whole_index] = BMP180[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        BMP180[1] = (0 << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    }
#endif

#ifdef PR103J2_include    // Append PR103J2
    if ((PR103J2[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(PR103J2); i++)
        {
            packet_whole[packet_whole_index] = PR103J2[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        PR103J2[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL250RD_1_include    // Append TSL250RD_1
    if ((TSL250RD_1[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSL250RD_1); i++)
        {
            packet_whole[packet_whole_index] = TSL250RD_1[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_1[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef MMA8452Q_include    // Append MMA8452Q
    if ((MMA8452Q[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(MMA8452Q); i++)
        {
            packet_whole[packet_whole_index] = MMA8452Q[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        MMA8452Q[1] = (0 << 7) | (LENGTH_FORMAT6 * 4);
    }
#endif

#ifdef SPV1840LR5HB_include    // Append SPV1840LR5HB_2
    if ((SPV1840LR5HB[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(SPV1840LR5HB); i++)  //********************was SPV1840LR5HB_2
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB[i]; //********************was SPV1840LR5HB_2
            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif
    
#ifdef TSYS01_include    // Append TSYS01
    if ((TSYS01[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSYS01); i++)
        {
            packet_whole[packet_whole_index] = TSYS01[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSYS01[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif
#endif

#ifdef LIGHTSENSE_INCLUDE
#ifdef HMC5883L_include    // Append HMC5883L
    if ((HMC5883L[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HMC5883L); i++)
        {
            packet_whole[packet_whole_index] = HMC5883L[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HMC5883L[1] = (0 << 7) | (LENGTH_FORMAT8 * 3);
    }
#endif

#ifdef HIH6130_include    // Append HIH6130
    if ((HIH6130[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HIH6130); i++)
        {
            packet_whole[packet_whole_index] = HIH6130[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH6130[1] = (0 << 7) | (LENGTH_FORMAT6 * 2);
    }
#endif

#ifdef APDS9006020_include    // Append APDS9006020
    if ((APDS9006020[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(APDS9006020); i++)
        {
            packet_whole[packet_whole_index] = APDS9006020[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        APDS9006020[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL260RD_include    // Append TSL260RD
    if ((TSL250RD_2[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSL260RD); i++)
        {
            packet_whole[packet_whole_index] = TSL260RD[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL260RD[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL250RD_2_include    // Append TSL250RD_2
    if ((TSL250RD_2[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSL250RD_2); i++)
        {
            packet_whole[packet_whole_index] = TSL250RD_2[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_2[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef MLX75305_include    // Append MLX75305
    if ((MLX75305[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(MLX75305); i++)
        {
            packet_whole[packet_whole_index] = MLX75305[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        MLX75305[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef ML8511_include
    // Append ML8511
    if ((ML8511[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(ML8511); i++)
        {
            packet_whole[packet_whole_index] = ML8511[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        ML8511[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TMP421_include    // Append TMP421
    if ((TMP421[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TMP421); i++)
        {
            packet_whole[packet_whole_index] = TMP421[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP421[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif

#endif

#ifdef CHEMSENSE_INCLUDE

#ifdef chemsense_MAC_ID_include
    if ((chemsense_MAC_ID[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(chemsense_MAC_ID); i++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[i];
            packet_whole_index++;
        }
        chemsense_MAC_ID[1] = (0 << 7) | LENGTH_FORMAT3;
    }
    
#ifdef PRINT_ADDRESS
        // to check output
        SerialUSB.print("Chemsense-");
        for (i = 0x02; i < 0x08; i++)
        {
            if ((chemsense_MAC_ID[i] & 0xf0) == 0x00)
                SerialUSB.print('0');
            SerialUSB.print(chemsense_MAC_ID[i],HEX);
            if (i < LENGTH_FORMAT3 + 1) { SerialUSB.print(":"); }
            else { SerialUSB.println("\r"); }
        }
#endif
#endif

#ifdef SHT25_include
    if ((SHT25[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(SHT25); i++)
        {
            packet_whole[packet_whole_index] = SHT25[i];
            packet_whole_index++;
        }
        SHT25[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);

    }
#endif

#ifdef LPS25H_include
    if ((LPS25H[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(LPS25H); i++)
        {
            packet_whole[packet_whole_index] = LPS25H[i];
            packet_whole_index++;
        }
        LPS25H[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
    }
#endif

#ifdef Si1145_include
    if ((Si1145[1] & 0x80) == 0x80)
    { 
        for (i = 0; i <  sizeof(Si1145); i++)
        {
            packet_whole[packet_whole_index] = Si1145[i];
            packet_whole_index++;
        }
        Si1145[1] = (0 << 7) | (LENGTH_FORMAT1 * 3);
    }   
#endif

#ifdef total_reducing_gases_include
    if ((total_reducing_gases[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(total_reducing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[i];
            packet_whole_index++;
        }
        total_reducing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef total_oxidizing_gases_include
    if ((total_oxidizing_gases[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(total_oxidizing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[i];
            packet_whole_index++;
        }
        total_oxidizing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef sulfur_dioxide_include
    if ((sulfur_dioxide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(sulfur_dioxide); i++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[i];
            packet_whole_index++;
        }
        sulfur_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef hydrogen_sulphide_include
    if ((hydrogen_sulphide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(hydrogen_sulphide); i++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[i];
            packet_whole_index++;
        }
        hydrogen_sulphide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef ozone_include
    if ((ozone[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(ozone); i++)
        {
            packet_whole[packet_whole_index] = ozone[i];
            packet_whole_index++;
        }
        ozone[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef nitrogen_dioxide_include
    if ((nitrogen_dioxide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(nitrogen_dioxide); i++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[i];
            packet_whole_index++;
        }
        nitrogen_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef carbon_monoxide_include
    if ((carbon_monoxide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(carbon_monoxide); i++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[i];
            packet_whole_index++;
        }
        carbon_monoxide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef CO_ADC_temp_include
    if ((CO_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(CO_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = CO_ADC_temp[i];
            packet_whole_index++;
        }
        CO_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef IAQ_IRR_ADC_temp_include
    if ((IAQ_IRR_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(IAQ_IRR_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[i];
            packet_whole_index++;
        }
        IAQ_IRR_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef O3_NO2_ADC_temp_include
    if ((O3_NO2_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(O3_NO2_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = O3_NO2_ADC_temp[i];
            packet_whole_index++;
        }
        O3_NO2_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef SO2_H2S_ADC_temp_include
    if ((SO2_H2S_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(SO2_H2S_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[i];
            packet_whole_index++;
        }
        SO2_H2S_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef CO_LMP_temp_include
    if ((CO_LMP_temp[1] & 0x80) == 0x80)
    { 
        for (i = 0; i <  sizeof(CO_LMP_temp); i++)
        {
            packet_whole[packet_whole_index] = CO_LMP_temp[i];
            packet_whole_index++; 
        }
        CO_LMP_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }   
#endif

#ifdef three_accel_and_vib_include
    if ((three_accel_and_vib[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(three_accel_and_vib); i++)
        {
            packet_whole[packet_whole_index] = three_accel_and_vib[i];
            packet_whole_index++;
        }
        three_accel_and_vib[1] = (0 << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
#endif

#ifdef three_gyro_and_orientation_include
    if ((three_gyro_and_orientation[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(three_gyro_and_orientation); i++)
        {
            packet_whole[packet_whole_index] = three_gyro_and_orientation[i];
            packet_whole_index++;
        }
        three_gyro_and_orientation[1] = (0 << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        
        OIX_packet_count++;
    }
#endif

#endif
    

    // #ifdef system_health_include
    // // Append health
    // for (int i = 0; i < sizeof(sensor_health); i++)
    // {
    //     packet_whole[packet_whole_index] = sensor_health[i];
    //     // Increment index for whole packet
    //     packet_whole_index++;
    // }
    // #endif


    // Length
    packet_whole[0x02] = packet_whole_index - 0x03;
    packet_seq_number++;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;

    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = END_BYTE;

//     #ifdef SERIAL_DEBUG
//     SerialUSB.println(packet_whole_index, DEC);
//     #endif
}
/**************************************************************************************/

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/integrated/sensors_setup.ino"

void initializeSensorBoard()
{
    byte i;

    pinMode(PIN_HBT, OUTPUT);
    pinMode(PIN_SPV_AMP,INPUT);         // MODE ON?????????? WHERE????????????? HOW???????????? WHEN???????????
    pinMode(PIN_SVP_SPL,INPUT);
    pinMode(PIN_RAW_MIC,INPUT);
    pinMode(PIN_ALPHASENSE_SLAVE, OUTPUT);
    pinMode(PIN_CHEMSENSE_POW, OUTPUT); // ON/OFF sensor, OUTPUT:LOW = ON
    
    digitalWrite(PIN_CHEMSENSE_POW, HIGH); // Power OFF the Chemsense board
    digitalWrite(PIN_HBT, UP_DOWN); // send signal 0

    if (ds2401.reset() == TRUE)
    {
        ds2401.write(0x33);
        for (i = 0; i < 8; i++)
            Temp_byte[i] = ds2401.read();

        if (OneWire::crc8(Temp_byte, 8) == 0)
        {
            for (i = 0; i < 6; i++)
                MAC_ID[i + 2] = Temp_byte[6 - i];
        }

        else { MAC_ID[3] = 0xff; }
    }
    else { MAC_ID[3] = 0xaa; } //Nothing is connected in the bus
}

void Sensors_Setup(void)      // sensor initialization
{
#ifdef TMP112_include
    TMP112_CONFIG();
#endif

#ifdef  BMP180_include
    bmp.begin();
#endif

#ifdef MMA8452Q_include
    MMA8452_CONFIG(); //Test and intialize the MMA8452
#endif

#ifdef TSYS01_include
    TSYS01_CONFIG();
#endif

#ifdef LIGHTSENSE_INCLUDE
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);
#endif

#ifdef HMC5883L_include
    HMC5883_Magnetometer.begin();
#endif
    return;
}


void writeEEPROM (unsigned int memory_address, byte data_byte )
{
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.write(data_byte);
    Wire.endTransmission();
    delay(5);
}

byte readEEPROM (unsigned int memory_address )
{
    byte recv_data = 0xff;

    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_ADDRESS,1);

    if (Wire.available())
        recv_data = Wire.read();

    return recv_data;
}
