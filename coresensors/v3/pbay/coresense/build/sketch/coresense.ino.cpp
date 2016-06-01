#include <Arduino.h>
#line 1
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
#include <Wire.h>
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

#define MAX_FMT_SIZE 6
byte formatted_data_buffer[MAX_FMT_SIZE];

char one;
char KEY[3];
char VAL[12];
char carrier[100];
//char *KEY;
//char *VAL;
//char *carrier;

int idx = 0;
	
int key_id = 0;
int val_id = 0;

bool flag_KEY = false;
bool SEND = true;
/*
#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  3
#define LENGTH_FORMAT5  3
#define LENGTH_FORMAT6  2
#define LENGTH_FORMAT7  4
#define LENGTH_FORMAT8  2


#define ID_TOTAL_REDUCING_GASES  0x15 // 0x03
#define ID_ETHANOL  0x16
#define ID_NITROGEN_DIOXIDE  0x17
#define ID_OZONE  0x18
#define ID_HYDROGEN_SULPHIDE  0x19
#define ID_TOTAL_OXIDIZING_GASES  0x1A
#define ID_CARBON_MONOXIDE  0x1B
#define ID_SULFUR_DIOXIDE  0x1C
#define ID_SHT25 0x1D
#define ID_LPS25H 0x1E
#define ID_Si1145 0x1F
#define ID_CHEMSENSE_MAC  0x20
#define ID_CO_ADC_TEMP  0x21
#define ID_IAQ_IRR_ADC_TEMP 0x22
#define ID_O3_NO2_ADC_TEMP  0x23
#define ID_SO2_H2S_ADC_TEMP 0x24
#define ID_CO_LMP_TEMP  0x25
#define ID_THREE_ACCEL_AND_VIB  0x26
#define ID_THREE_MAG_AND_ORIENTATION    0x27
*/


//chemsense board
/*
byte total_reducing_gases[LENGTH_FORMAT5 + 2]; // ambient concentration
byte nitrogen_dioxide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte ozone[LENGTH_FORMAT5 + 2]; // ambient concentration
byte hydrogen_sulphide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte total_oxidizing_gases[LENGTH_FORMAT5 + 2]; // ambient concentration
byte carbon_monoxide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte sulfur_dioxide[LENGTH_FORMAT5 + 2]; // ambient concentration

byte SHT25[LENGTH_FORMAT2 + LENGTH_FORMAT1 + 2]; // ambient temp and RH
byte LPS25H[LENGTH_FORMAT2 + LENGTH_FORMAT4 + 2]; // atmospheric temperature and pressure
byte Si1145[(LENGTH_FORMAT1 * 3) + 2]; // UV

byte 


byte chemsense_MAC_ID[LENGTH_FORMAT3 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of chemsense board*/


#line 77 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void setup();
#line 95 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void loop();
#line 166 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void Carrier();
#line 449 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void Hex_BAD();
#line 469 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void Int_form2();
#line 484 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void Int_form5();
#line 500 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/coresense.ino"
void Hex_form1();
#line 14 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format1(unsigned int input);
#line 26 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format2(int input);
#line 48 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format3(byte *input);
#line 62 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format4(unsigned long input);
#line 75 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format5(long input);
#line 101 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format6(float input);
#line 129 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format7(byte *input);
#line 141 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
void format8(float input);
#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/sensors_setup.ino"
void initializeSensorBoard();
#line 60 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/sensors_setup.ino"
void writeEEPROM(unsigned int memory_address, byte data_byte );
#line 70 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/sensors_setup.ino"
byte readEEPROM(unsigned int memory_address );
#line 91 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/sensors_setup.ino"
void Sensors_Setup(void);
#line 77
void setup()
{
    Wire.begin();
	Serial3.begin(19200);       //getData, communicate with the sensor
	while(!Serial3) {;}
	SerialUSB.begin(115200);    //sendData, communicate with computer
	while(!SerialUSB) {;}

    initializeSensorBoard();
	
    //turn ON chemsense.
    digitalWrite(PIN_CHEMSENSE_POW, LOW);
    
     //turn OFF chemsense.
    //digitalWrite(PIN_CHEMSENSE_POW, HIGH);
    
}

void loop()
{
    
//     // read from port 1, send to port 0:
//   if (Serial3.available()) {
//     int inByte = Serial3.read();
//     SerialUSB.write(inByte);
//   }
// 
//   // read from port 0, send to port 1:
//   if (SerialUSB.available()) {
//     int inByte = SerialUSB.read();
//     Serial3.write(inByte);
//   }
//   
    while (Serial3.available() > 0) 
    {
        one = Serial3.read();     //read the incoming byte

        switch(one)
        {
            case 48 ... 57: // numbers
            case 65 ... 90: // Upper case letter
            case 97 ... 122: // Lower case letter
            case '-': //negative sign
            {
                if (!flag_KEY)
                {
                    KEY[key_id] = one;
                    key_id++;
                }
                else
                {
                    VAL[val_id] = one;
                    val_id++;
                }
                break;
            } 
            case '=':
            {
                flag_KEY = true;
                break;
            }
            case ' ':
            {
                KEY[key_id] = '\0';
                VAL[val_id] = '\0';
                Carrier();
                flag_KEY = false;
                key_id = 0;
                val_id = 0;
                break;
            }
            case '\r':
            {
                KEY[key_id] = '\0';
                VAL[val_id] = '\0';
                Carrier();
                flag_KEY = false;
                key_id = 0;
                val_id = 0;
                break;
            }
            default:
            break;
        }
    }
    
    
}

void Carrier()
{
	if (!flag_KEY)
		return;

    SerialUSB.print(KEY);
    SerialUSB.print(" ");
    SerialUSB.print(VAL);
    SerialUSB.print(" ");

	if (strncmp(KEY, "BAD", 3) == 0) 
	{
        int valid = 1;
        Hex_BAD();
        
		carrier[0] = ID_CHEMSENSE_MAC;
        carrier[1] = (valid << 7) | LENGTH_FORMAT3;
        
        for (int j = 0; j < LENGTH_FORMAT3; j++)
            carrier[2 + j] = formatted_data_buffer[j];
        
        idx = LENGTH_FORMAT3 + 2;
        
        for (int j = 0; j < LENGTH_FORMAT3; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
        
	}
	else if (strncmp(KEY, "SHT", 3) == 0)  // wait SHH
	{
        carrier[0] = ID_SHT25;
        Int_form2();
        SEND = false;
    }
    else if (strncmp(KEY, "SHH", 3) == 0)
    {
        int valid = 1;
        unsigned int form1;
        form1 = (unsigned int)atoi(VAL);       //char to int
        format1(form1); 
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        
        for (int j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
        
        idx = idx + LENGTH_FORMAT1;
    }
	else if (strncmp(KEY, "LPT", 3) == 0)  // wait LPP
	{
        carrier[0] = ID_LPS25H;
        Int_form2();
        SEND = false;
    }
    else if (strncmp(KEY, "LPP", 3) == 0)
    {
        int valid = 1;
        unsigned int form1;
        form1 = (unsigned int)atoi(VAL);       //char to int
        format1(form1); 
    
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        
        idx = idx + LENGTH_FORMAT1;
	}
	else if (strncmp(KEY, "SUV", 3) == 0)  // wait SVL and SIR
	{
        int valid = 1;
        Hex_form1();
		
        carrier[0] = ID_Si1145;
		carrier[1] = (valid << 7) | LENGTH_FORMAT1;
        carrier[2] = formatted_data_buffer[0];
        carrier[3] = formatted_data_buffer[1];
        
		idx = 2 + LENGTH_FORMAT1;
        SEND = false;
    }
	else if (strncmp(KEY, "SVL", 3) == 0)
    {
        int valid = 1;
        Hex_form1();
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT1 * 2);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];

        idx = idx + LENGTH_FORMAT1;
        SEND = false;
    }
    else if (strncmp(KEY, "SIR", 3) == 0)
    {
        int valid = 1;
        Hex_form1();
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT1 * 3);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];

        idx = idx + LENGTH_FORMAT1;
    }
	else if (strncmp(KEY, "IRR", 3) == 0)
	{
        carrier[0] = ID_TOTAL_REDUCING_GASES;
        Int_form5();
    }
	else if (strncmp(KEY, "IAQ", 3) == 0)
    {
        carrier[0] = ID_TOTAL_OXIDIZING_GASES;
        Int_form5();
    }
	else if (strncmp(KEY, "SO2", 3) == 0)
    {
		carrier[0] = ID_SULFUR_DIOXIDE;
        Int_form5();
    }
	else if (strncmp(KEY, "H2S", 3) == 0)
	{
		carrier[0] = ID_HYDROGEN_SULPHIDE;
        Int_form5();
    }
	else if (strncmp(KEY, "OZO", 3) == 0)
	{
		carrier[0] = ID_OZONE;
        Int_form5();
    }
	else if (strncmp(KEY, "NO2", 3) == 0)
	{
		carrier[0] = ID_NITROGEN_DIOXIDE;
        Int_form5();
    }
	else if (strncmp(KEY, "CMO", 3) == 0)
	{
		carrier[0] = ID_CARBON_MONOXIDE;
        Int_form5();
	}
	else if (strncmp(KEY, "AT0", 3) == 0)
	{
		carrier[0] = ID_CO_ADC_TEMP;
        Int_form2();
    }
	else if (strncmp(KEY, "AT1", 3) == 0)
	{
		carrier[0] = ID_IAQ_IRR_ADC_TEMP;
		Int_form2();
    }
	else if (strncmp(KEY, "AT2", 3) == 0)
	{
		carrier[0] = ID_O3_NO2_ADC_TEMP;
		Int_form2();
    }
	else if (strncmp(KEY, "AT3", 3) == 0)
	{
		carrier[0] = ID_SO2_H2S_ADC_TEMP;
        Int_form2();
    }
	else if (strncmp(KEY, "LTM", 3) == 0)
	{
		carrier[0] = ID_CO_LMP_TEMP;
		Int_form2();
    }
	else if (strncmp(KEY, "ACX", 3) == 0)  //wait ACY, ACZ, and VIX
    {
		carrier[0] = ID_THREE_ACCEL_AND_VIB;
        Int_form2();
        SEND = false;
    }
    else if (strncmp(KEY, "ACY", 3) == 0)
    {
        int valid = 1;
        int form2;
        form2 = (int)atoi(VAL);
        format2(form2);
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 * 2);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        
        idx = idx + LENGTH_FORMAT2;
        SEND = false;
    }
    else if (strncmp(KEY, "ACZ", 3) == 0)
    {
        int valid = 1;
        int form2;
        form2 = (int)atoi(VAL);
        format2(form2);
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 * 3);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];

        idx = idx + LENGTH_FORMAT2;
        SEND = false;
    }
    else if (strncmp(KEY, "VIX", 3) == 0)
    {
        int valid = 1;
        unsigned long form4;
        form4 = (unsigned long)atol(VAL);              //char to int
        format4(form4);
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        carrier[idx + 2] = formatted_data_buffer[2];

        idx = idx + LENGTH_FORMAT4;
    }
	else if (strncmp(KEY, "GYX", 3) == 0)  //wait GYY, GYZ, and OIX
    {
		carrier[0] = ID_THREE_MAG_AND_ORIENTATION;
        Int_form2();
        SEND = false;
    }
    else if (strncmp(KEY, "GYY", 3) == 0)
    {
        int valid = 1;
        int form2;
        form2 = (int)atoi(VAL);
        format2(form2);
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 * 2);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        
        idx = idx + LENGTH_FORMAT2;
        SEND = false;
    }
    else if (strncmp(KEY, "GYZ", 3) == 0)
    {
        int valid = 1;
        int form2;
        form2 = (int)atoi(VAL);
        format2(form2);
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT1 * 3);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        
        idx = idx + LENGTH_FORMAT2;
        SEND = false;
    }
    else if (strncmp(KEY, "OIX", 3) == 0)
    {
        int valid = 1;
        unsigned long form4;
        form4 = (unsigned long)atol(VAL);              //char to int
        format4(form4);
        
        carrier[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        carrier[idx] = formatted_data_buffer[0];
        carrier[idx + 1] = formatted_data_buffer[1];
        carrier[idx + 2] = formatted_data_buffer[2];
        carrier[idx + 3] = formatted_data_buffer[3];
        
        idx = idx + LENGTH_FORMAT4;
    }
    
    SerialUSB.print("\r\n");

//     if (SEND)
//     {
//         SerialUSB.write(carrier, idx);
//         SerialUSB.print("");
//         idx = 0;
//         SEND = false;
//     }
//     
    flag_KEY = false;
    key_id = 0;
    val_id = 0;
}

void Hex_BAD()
{
    //SerialUSB.println(VAL);
	char first[6], second[6];
	strncpy(first, VAL, 6);
	char *i = VAL;
	i += 6;
	strncpy(second, i, 6);
	unsigned long case0 = (unsigned long) strtol(first, NULL, 16);      //too short to contain the whole value of 'BAD'
	unsigned long case1 = (unsigned long) strtol(second, NULL, 16);
	byte result[6];
	result[0] = (case0 & 0xFF0000) >> 16;
	result[1] = (case0 & 0x00FF00) >> 8;
	result[2] = (case0 & 0x0000FF);
	result[3] = (case1 & 0xFF0000) >> 16;
	result[4] = (case1 & 0x00FF00) >> 8;
	result[5] = (case1 & 0x0000FF);
	format3(result);
}

void Int_form2()
{
    int form2;
    form2 = (int)atoi(VAL);
    format2(form2);
    
    int valid = 1;
    carrier[1] = (valid << 7) | LENGTH_FORMAT2;
    carrier[2] = formatted_data_buffer[0];
    carrier[3] = formatted_data_buffer[1];
        
    idx = LENGTH_FORMAT2 + 2;
    SEND = true;
}

void Int_form5()
{
    long form5;
    form5 = (long) strtol(VAL, NULL, 10);
    format5(form5);
    
    int valid = 1;
    carrier[1] = (valid << 7) | LENGTH_FORMAT5;
    
    carrier[2] = formatted_data_buffer[0];
    carrier[3] = formatted_data_buffer[1];
        
    idx = LENGTH_FORMAT5 + 2;
    SEND = true;
}

void Hex_form1()
{
    unsigned int hex;
    hex = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
    format1(hex);
}


#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/dataFormats.ino"
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

#line 1 "/home/spark/repos/waggle/coresensors/v3/pbay/coresense/sensors_setup.ino"
void initializeSensorBoard()
{
    byte i;

    pinMode(PIN_SPV_AMP,INPUT);
    pinMode(PIN_SVP_SPL,INPUT);
    pinMode(PIN_RAW_MIC,INPUT);
    pinMode(PIN_HIH4030,INPUT);
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
/*
    if (ds2401.reset() == TRUE)
    {
        ds2401.write(0x33);
        for (i = 0; i < 8; i++)
        {
            Temp_byte[i] = ds2401.read();
        }

        if (OneWire::crc8(Temp_byte, 8) == 0)
        {
            for (i=1; i<7; i++)
            {
                MAC_ID[i + 1] = Temp_byte[i];
            }

        }

        else
        {

            MAC_ID[3] = 0xff;

        }
    }
    else //Nothing is connected in the bus
    {
        MAC_ID[3] = 0xaa;
    }

    #ifdef SERIAL_DEBUG
    for (i=0; i<8; i++)
    {
        SerialUSB.print(MAC_ID[i],HEX);

        if (i < 7)
        {
            SerialUSB.print(":");
        }
        else
        {
            SerialUSB.print("\n");
        }
    }
    #endif
*/
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
    {
        recv_data = Wire.read();
    }
    return recv_data;
}





void Sensors_Setup(void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.println("Setting up sensors...");
    #endif
/*
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

    #ifdef HIH6130_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("HIH6130.");
    #endif
    #endif

    #ifdef TMP421_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TMP421.");
    #endif
    #endif

    #ifdef APDS9006020_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("APDS9006020.");
    #endif
    #endif

    #ifdef TSL260RD_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL260RD.");
    #endif
    #endif

    #ifdef TSL250RD_2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL250RD_2.");
    #endif
    #endif

    #ifdef MLX75305_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("MLX75305.");
    #endif
    #endif

    #ifdef ML8511_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("ML8511.");
    #endif
    #endif

    #ifdef SPV1840LR5HB_1_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("SPV1840LR5HB_1.");
    #endif
    #endif

    #ifdef SPV1840LR5HB_2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("SPV1840LR5HB_2.");
    #endif
    #endif

    #ifdef LIGHTSENSE_INCLUDE
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);
    #endif

    #ifdef HMC5883L_include
    HMC5883_Magnetometer.begin();
    #endif*/
    return;
}

