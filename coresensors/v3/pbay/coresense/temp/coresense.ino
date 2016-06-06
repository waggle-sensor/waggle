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
/*
// chemsense board
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


byte chemsense_MAC_ID[LENGTH_FORMAT3 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of chemsense board
*/

void setup()
{
    Wire.begin();
	SerialUSB.begin(19200);       //getData, communicate with the sensor
	while(!SerialUSB) {;}
	Serial.begin(115200);    //sendData, communicate with computer
	while(!Serial) {;}

    initializeSensorBoard();
	
    //turn ON chemsense.
    digitalWrite(PIN_CHEMSENSE_POW, LOW);
    
     //turn OFF chemsense.
    //digitalWrite(PIN_CHEMSENSE_POW, HIGH);
    
}

void loop()
{
    SEND = true;
    while (SerialUSB.available() > 0) 
    {
        one = SerialUSB.read();     //read the incoming byte

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

	if (strncmp(KEY, "BAD", 3) == 0) 
	{
        int valid = 1;
        Hex_BAD();
		carrier[0] = ID_CHEMSENSE_MAC;
        carrier[1] = (valid << 7) | LENGTH_FORMAT3;
        
        for (int j = 0; j < LENGTH_FORMAT3; j++)
            carrier[2 + j] = formatted_data_buffer[j];
        
        idx = LENGTH_FORMAT3 + 2;
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

    if (SEND)
    {
        Serial.write(carrier, idx);
        Serial.println("");
        idx = 0;
    }
    
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

