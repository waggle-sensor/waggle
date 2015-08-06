#include <Wire.h>
#include "config.cpp"

// #define CR_ENABLE 0
#define CR_ENABLE 1
#define BUFFER_SIZE_INTEL 150
#define PARAM_SIZE_INTEL 15
#define DEBUG_INTEL

// #define ID_TOTAL_REDUCING_GASES  0x15
// #define ID_ETHANOL  0x16
// #define ID_NITROGEN_DIOXIDE  0x17
// #define ID_OZONE  0x18
// #define ID_HYDROGEN_SULPHIDE  0x19
// #define ID_TOTAL_OXIDIZING_GASES  0x1A
// #define ID_CARBON_MONOXIDE  0x1B
// #define ID_SULFUR_DIOXIDE  0x1C

// #define total_reducing_gases_include 0x01
// #define ethanol_include 0x01
// #define nitrogen_dioxide_include 0x01
// #define ozone_include 0x01
// #define hydrogen_sulphide_include 0x01
// #define total_oxidizing_gases_include 0x01
// #define carbon_monoxide_include 0x01
// #define sulfur_dioxide_include 0x01


// Main board
byte MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address
byte TMP112[LENGTH_FORMAT1 + 2]; // ambient temp
byte HTU21D[(LENGTH_FORMAT1 * 2) + 2]; // ambient RH & temp
byte GP2Y1010AU0F[LENGTH_FORMAT2 + 2]; // dust density
byte BMP180[LENGTH_FORMAT1 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte PR103J2[LENGTH_FORMAT2 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT2 + 2]; // ambient light (400-950nm)
byte MMA8452Q[(LENGTH_FORMAT1 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB_1[LENGTH_FORMAT2 + 2]; // sound pressure
byte TSYS01[LENGTH_FORMAT2 + 2]; // ambient temp

// Aux board
byte HMC5883L[(LENGTH_FORMAT4 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT1 * 2) + 2]; // temp and RH inside transparent box
byte APDS9006020[LENGTH_FORMAT2 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT2 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT2 + 2]; // solar visible light
byte MLX75305[LENGTH_FORMAT2 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT2 + 2]; // solar UV
byte D6T[(LENGTH_FORMAT1 * 17) + 2]; // temp of surrounding objects
byte MLX90614[LENGTH_FORMAT1 + 2]; // temp of pavement
byte TMP421[LENGTH_FORMAT1 + 2]; // temp inside transparent box
byte SPV1840LR5HB_2[LENGTH_FORMAT2 + 2]; // sound pressure

// Intel board
byte total_reducing_gases[LENGTH_FORMAT6 + 2]; // ambient concentration
byte ethanol[LENGTH_FORMAT6 + 2]; // ambient concentration
byte nitrogen_dioxide[LENGTH_FORMAT6 + 2]; // ambient concentration
byte ozone[LENGTH_FORMAT6 + 2]; // ambient concentration
byte hydrogen_sulphide[LENGTH_FORMAT6 + 2]; // ambient concentration
byte total_oxidizing_gases[LENGTH_FORMAT6 + 2]; // ambient concentration
byte carbon_monoxide[LENGTH_FORMAT6 + 2]; // ambient concentration
byte sulfur_dioxide[LENGTH_FORMAT6 + 2]; // ambient concentration

byte SHT25[(LENGTH_FORMAT5 * 2) + 2]; // ambient temp and RH
byte LPS25H[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric temperature and pressure
byte Si1145[LENGTH_FORMAT2 + 2]; // UV

byte intel_MAC_ID[LENGTH_FORMAT3 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of Intel board



// Whole packet
byte packet_whole[LENGTH_WHOLE];
byte sensor_health[SENSOR_HEALTH_SIZE+2];
// Data sub-packet
byte packet_data[LENGTH_DATA];
// Sub-packets for each format
byte packet_format1[LENGTH_FORMAT1];
byte packet_format2[LENGTH_FORMAT2];
byte packet_format3[LENGTH_FORMAT3];
byte packet_format4[LENGTH_FORMAT4];
byte packet_format5[LENGTH_FORMAT5];
byte packet_format6[LENGTH_FORMAT6];

// These lengths are calculated at packet assembly
byte length_whole_actual;
byte length_data_actual;


unsigned char buffer [BUFFER_SIZE_INTEL];
unsigned char parameter[PARAM_SIZE_INTEL];
unsigned char cnt = 0;
boolean ready = false;
float param_value;
unsigned char attenuate = 0;



// CRC-8
byte crc = 0x00;
/**************************************************************************************/

/** I2C request interrupt *************************************************************/
void requestEvent()
{
    // Send it!
    Wire.write(packet_whole, packet_whole[0x02]+0x05);
    // Generate fake sensor data
    generate_data();
    // Put whole packet together
    assemble_packet_whole();
    Serial.print("Request rcvd\n");
    for(int i = 0; i < packet_whole[0x02]+0x05; i++)
    {
        Serial.print(packet_whole[i], HEX);
        Serial.print(" ");
    }
    Serial.print("\n");
}
/**************************************************************************************/



/** Arduino: setup ********************************************************************/
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(2000);
    Serial.begin(115200);
    Serial1.begin(115200);
    //     Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
    {
        packet_whole[i] = 0x00;
    }
    packet_whole[0x00] = START_BYTE;
    packet_whole[0x01] = HEADER_RESERVED | HEADER_VERSION;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = END_BYTE;
//     Serial.print("This is the emulator...");
    // Join I2C bus as slave
//     Wire.begin(I2C_SLAVE_ADDRESS);
    // Register interrupt
//     Wire.onRequest(requestEvent);
}
/**************************************************************************************/

void get_value (unsigned char pidx)
{
    param_value = 0;
    for (unsigned char idx = 0; idx < pidx; idx ++)
    {
        if (parameter[idx] != 0x2d)
        {
            parameter[idx] = parameter[idx] - 48;
            param_value = (param_value * 10) + parameter[idx];
        }
    }

    if (parameter[0] == 0x2d)
    {
        param_value = param_value * (-1);
    }

    if (attenuate == 1)
    {
        param_value = param_value / 256;
        attenuate = 0;
    }

    return;
}

void intel_aquire ()
{

    while (Serial1.available())
    {
        char inByte = Serial1.read();
        #ifdef DEBUG_INTEL
            Serial.write(inByte);
        #endif
        if (( inByte != '\n') && (cnt < BUFFER_SIZE_INTEL))
        {
            buffer[cnt] = inByte;
            cnt = cnt + 1;
        }
        else
        {
            ready = true;
            cnt = cnt + 1;
        }
    }
    return;
}


void loop() {
    byte valid;
    byte integer1, integer2, integer3;
    int fractional;
    byte neg;
    int value_i;
    float value_f;
    long value_l;
    int valid_index = 0;

    intel_aquire();

    if (ready == true)
    {
        ready = false;
        unsigned char count = 0, pidx = 0;
        for (unsigned char index = CR_ENABLE; index < cnt; index ++)
        {
            if (buffer[index] != ',')
            {
                if ((count == 0) && (pidx < PARAM_SIZE_INTEL))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }
            }
            else
            {
                count = count + 1;
            }
        }

        if ((count == 15) && (pidx == 12))
        {
            #ifdef DEBUG_INTEL
            Serial.println("Received full packet");
            #endif
            unsigned char count = 0, pidx = 0;
            for (unsigned char index = CR_ENABLE; index < cnt; index ++)
            {
                if ((buffer[index] != ',') && (pidx < PARAM_SIZE_INTEL))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }

                else
                {
                    if (count == 0)
                    {
                        #ifdef intel_MAC_ID_include
                        // Intel MAC address (format 3)
                        valid = 1;
                        intel_MAC_ID[0] = ID_INTEL_MAC;
                        intel_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
                        for (unsigned char idx = 0; idx < pidx; idx ++)
                        {
                            if ((parameter[idx] > 96) && (parameter[idx] < 103))
                            {
                                parameter[idx] = parameter[idx] - 87;
                            }
                            else
                            {
                                parameter[idx] = parameter[idx] - 48;
                            }

                            if (idx % 2 == 0)
                            {
                                parameter[idx] = parameter[idx] << 4;
                            }
                            intel_MAC_ID[(idx/2)+2] = intel_MAC_ID[(idx/2)+2] | parameter[idx];
                        }
                        #ifdef SERIAL_DEBUG
                        Serial.print("Intel MAC ID: ");
                        for (int i = 2; i < (LENGTH_FORMAT3 + 2); i++)
                            Serial.print(intel_MAC_ID[i], HEX);
                        Serial.println("");
                        #endif
                        #endif
                    }

                    else if (count == 1)
                    {
                    #ifdef HDC_1000_include
                        //Serial.println("HDC_Temp");
                        get_value(pidx);
                        Serial.println(param_value);
                    #endif
                    }
                    else if (count == 2)
                    {
                        #ifdef HDC_1000_include
                        //Serial.println("HDC_RH");
                        get_value(pidx);
                        Serial.println(param_value);
                        #endif
                    }
                    else if (count == 3)
                    {
                        #ifdef SHT25_include
                        //SHT25 temperature value
                        valid = 1;
                        get_value(pidx);
                        format5(int(param_value));
                        SHT25[0] = ID_SHT25;
                        SHT25[1] = (valid << 7) | ((LENGTH_FORMAT5) * 2);
                        SHT25[2] = packet_format5[0];
                        SHT25[3] = packet_format5[1];
                        #ifdef SERIAL_DEBUG
                        Serial.print("SHT25 Temperature: ");
                        Serial.println(int(param_value));
                        #endif
                        #endif
                    }
                    else if (count == 4)
                    {
                        #ifdef SHT25_include
                        //SHT25 RH value
                        valid = 1;
                        get_value(pidx);
                        format5(int(param_value));
                        SHT25[0] = ID_SHT25;
                        SHT25[1] = (valid << 7) | ((LENGTH_FORMAT5) * 2);
                        SHT25[4] = packet_format5[0];
                        SHT25[5] = packet_format5[1];
                        #ifdef SERIAL_DEBUG
                        Serial.print("SHT25 RH: ");
                        Serial.println(int(param_value));
                        #endif
                        #endif

                    }
                    else if (count == 5)
                    {
                        #ifdef LPS25H_include
                        //LPS Temp Value
                        valid = 1;
                        get_value(pidx);
//                         The raw value is 15 bits + a sign bit - we will amek it 14 bits + a sign bit, loosing
//                         the LSB in the process
                        format5(int(param_value) >> 1);
                        LPS25H[0] = ID_LPS25H;
                        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
                        LPS25H[2] = packet_format5[0];
                        LPS25H[3] = packet_format5[1];
                        #ifdef SERIAL_DEBUG
                        Serial.print("LPS25H Temp: ");
                        Serial.println(int(param_value));
                        #endif
                        #endif

                    }
                    else if (count == 6)
                    {
                        #ifdef Si1145_include
                        //LPS Temp Value
                        valid = 1;
                        get_value(pidx);
                        //                         The raw value is 16 bits - we will make it 15 bits, loosing
                        //                         the LSB in the process
                        format2(int(param_value) >> 1);
                        Si1145[0] = ID_Si1145;
                        Si1145[1] = (valid << 7) | (LENGTH_FORMAT2);
                        Si1145[2] = packet_format2[0];
                        Si1145[3] = packet_format2[1];
                        #ifdef SERIAL_DEBUG
                        Serial.print("Si1145 UV: ");
                        Serial.println(int(param_value) >> 1);
                        #endif
                        #endif
                        get_value(pidx);
                        Serial.println(param_value);
                    }
                    else if (count == 7)
                    {
                        #ifdef LPS25H_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 2);
                        LPS25H[0] = ID_LPS25H;
                        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
                        LPS25H[4] = packet_format6[0];
                        LPS25H[5] = packet_format6[1];
                        LPS25H[6] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("LPS25H Pressure: ");
                        Serial.println(long(param_value) >> 2);
                        #endif
                        #endif
                    }
                    else if (count == 8)
                    {
                        #ifdef hydrogen_sulphide_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        hydrogen_sulphide[2] = packet_format6[0];
                        hydrogen_sulphide[3] = packet_format6[1];
                        hydrogen_sulphide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("H2S: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 9)
                    {
                        #ifdef ozone_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        ozone[0] = ID_OZONE;
                        ozone[1] = (valid << 7) | (LENGTH_FORMAT6);
                        ozone[2] = packet_format6[0];
                        ozone[3] = packet_format6[1];
                        ozone[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("O3: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    else if (count == 10)
                    {
                        #ifdef nitrogen_dioxide_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
                        nitrogen_dioxide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        nitrogen_dioxide[2] = packet_format6[0];
                        nitrogen_dioxide[3] = packet_format6[1];
                        nitrogen_dioxide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("NO2: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 11)
                    {
                        //Serial.println("CO");
                        #ifdef hydrogen_sulphide_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        hydrogen_sulphide[2] = packet_format6[0];
                        hydrogen_sulphide[3] = packet_format6[1];
                        hydrogen_sulphide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("H2S: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 12)
                    {
                        //Serial.println("SO2");
                        #ifdef hydrogen_sulphide_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        hydrogen_sulphide[2] = packet_format6[0];
                        hydrogen_sulphide[3] = packet_format6[1];
                        hydrogen_sulphide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("H2S: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }

                    else if (count == 13)
                    {
                        //Serial.println("TotalOX");
                        #ifdef hydrogen_sulphide_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        hydrogen_sulphide[2] = packet_format6[0];
                        hydrogen_sulphide[3] = packet_format6[1];
                        hydrogen_sulphide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("H2S: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 14)
                    {
                        //Serial.println("TotalRed");
                        #ifdef hydrogen_sulphide_include
                        //LPS Pressure Value
                        valid = 1;
                        get_value(pidx);
                        // The raw value is 24 bits - we will make it 22 bits loosing
                        // the 2 LSB bits in the process
                        format6(long(param_value) >> 1);
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        hydrogen_sulphide[2] = packet_format6[0];
                        hydrogen_sulphide[3] = packet_format6[1];
                        hydrogen_sulphide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        Serial.print("H2S: ");
                        Serial.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    count = count + 1;
                    pidx = 0;
                }
            }
            get_value(pidx-1);
        }

        cnt = 0;
    }
}
