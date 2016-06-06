//#include <Wire.h>
//extern TwoWire Wire1;
//#include <OneWire.h>
#include "config.cpp"

#define MAX_FMT_SIZE 6
byte formatted_data_buffer[MAX_FMT_SIZE];

char one;
char KEY[3];
char VAL[12];

int key_id = 0;
int val_id = 0;

bool flag_KEY = false;
/*
#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  3
#define LENGTH_FORMAT5  3
#define LENGTH_FORMAT6  2
#define LENGTH_FORMAT7  4
#define LENGTH_FORMAT8  2
*/

//chemsense board
byte chemsense_MAC_ID[LENGTH_FORMAT3 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of chemsense board

byte SHT25[LENGTH_FORMAT2 + LENGTH_FORMAT1 + 2]; // ambient temp and RH
byte LPS25H[LENGTH_FORMAT2 + LENGTH_FORMAT4 + 2]; // atmospheric temperature and pressure
byte Si1145[(LENGTH_FORMAT1 * 3) + 2]; // UV

byte total_reducing_gases[LENGTH_FORMAT5 + 2]; // ambient concentration
byte total_oxidizing_gases[LENGTH_FORMAT5 + 2]; // ambient concentration
byte sulfur_dioxide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte hydrogen_sulphide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte ozone[LENGTH_FORMAT5 + 2]; // ambient concentration
byte nitrogen_dioxide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte carbon_monoxide[LENGTH_FORMAT5 + 2]; // ambient concentration

byte CO_ADC_temp[LENGTH_FORMAT2 + 2];
byte IAQ_IRR_ADC_temp[LENGTH_FORMAT2 + 2];
byte O3_NO2_ADC_temp[LENGTH_FORMAT2 + 2];
byte SO2_H2S_ADC_temp[LENGTH_FORMAT2 + 2];
byte CO_LMP_temp[LENGTH_FORMAT2 + 2];

byte three_accel_and_vib[(LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4 + 2];
byte three_gyro_and_orientation[(LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4 + 2];


void setup()
{
    //Wire.begin();
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
//    // read from port 1, send to port 0:
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
                    KEY[key_id] = '\0';
                }
                else
                {
                    VAL[val_id] = one;
                    val_id++;
                    VAL[val_id] = '\0';
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
            case '\r':
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
    
#ifdef SERIAL_DEBUG
    // to confirm output data
    SerialUSB.print(KEY);
    SerialUSB.print(" ");
    SerialUSB.print(VAL);
    SerialUSB.print(" ");
#endif
    
    int valid = 1;
    
	if (strncmp(KEY, "BAD", 3) == 0) 
	{
        Hex_BAD();
        
        chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;
        chemsense_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
        
        for (int j = 0; j < LENGTH_FORMAT3; j++)
            chemsense_MAC_ID[2 + j] = formatted_data_buffer[j];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT3; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
	}
	else if (strncmp(KEY, "SHT", 3) == 0)  // wait SHH
	{
        Int_form2();

        SHT25[0] = ID_SHT25;
        SHT25[1] = (valid << 7) | LENGTH_FORMAT2;
        SHT25[2] = formatted_data_buffer[0];
        SHT25[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check the values
        for (int j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "SHH", 3) == 0)
    {
        unsigned int form1;
        form1 = (unsigned int)atoi(VAL);       //char to int
        format1(form1); 
        
        SHT25[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
        SHT25[4] = formatted_data_buffer[0];
        SHT25[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check the values
        for (int j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "LPT", 3) == 0)  // wait LPP
	{
        Int_form2();
        
        LPS25H[0] = ID_LPS25H;
        LPS25H[1] = (valid << 7) | LENGTH_FORMAT2;
        LPS25H[2] = formatted_data_buffer[0];
        LPS25H[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "LPP", 3) == 0)
    {
        Int_form4();
        
        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
        LPS25H[4] = formatted_data_buffer[0];
        LPS25H[5] = formatted_data_buffer[1];
        LPS25H[6] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT4; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
	}
	else if (strncmp(KEY, "SUV", 3) == 0)  // wait SVL and SIR
	{
        Hex_form1();
		
        Si1145[0] = ID_Si1145;
	Si1145[1] = (valid << 7) | LENGTH_FORMAT1;
        Si1145[2] = formatted_data_buffer[0];
        Si1145[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "SVL", 3) == 0)
    {
        Hex_form1();
        
        Si1145[1] = (valid << 7) | (LENGTH_FORMAT1 * 2);
        Si1145[4] = formatted_data_buffer[0];
        Si1145[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "SIR", 3) == 0)
    {
        Hex_form1();
        
        Si1145[1] = (valid << 7) | (LENGTH_FORMAT1 * 3);
        Si1145[6] = formatted_data_buffer[0];
        Si1145[7] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "IRR", 3) == 0)
	{
        Int_form5();
        
        total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
        total_reducing_gases[1] = (valid << 7) | LENGTH_FORMAT5;
        total_reducing_gases[2] = formatted_data_buffer[0];
        total_reducing_gases[3] = formatted_data_buffer[1];
        total_reducing_gases[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "IAQ", 3) == 0)
    {
        Int_form5();
        
        total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
        total_oxidizing_gases[1] = (valid << 7) | LENGTH_FORMAT5;
        total_oxidizing_gases[2] = formatted_data_buffer[0];
        total_oxidizing_gases[3] = formatted_data_buffer[1];
        total_oxidizing_gases[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "SO2", 3) == 0)
    {
        Int_form5();
        
        sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
        sulfur_dioxide[1] = (valid << 7) | LENGTH_FORMAT5;
        sulfur_dioxide[2] = formatted_data_buffer[0];
        sulfur_dioxide[3] = formatted_data_buffer[1];
        sulfur_dioxide[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "H2S", 3) == 0)
	{
        Int_form5();
        
        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
        hydrogen_sulphide[1] = (valid << 7) | LENGTH_FORMAT5;
        hydrogen_sulphide[2] = formatted_data_buffer[0];
        hydrogen_sulphide[3] = formatted_data_buffer[1];
        hydrogen_sulphide[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "OZO", 3) == 0)
	{
        Int_form5();
        
        ozone[0] = ID_OZONE;
        ozone[1] = (valid << 7) | LENGTH_FORMAT5;
        ozone[2] = formatted_data_buffer[0];
        ozone[3] = formatted_data_buffer[1];
        ozone[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "NO2", 3) == 0)
	{
        Int_form5();
        
        nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
        nitrogen_dioxide[1] = (valid << 7) | LENGTH_FORMAT5;
        nitrogen_dioxide[2] = formatted_data_buffer[0];
        nitrogen_dioxide[3] = formatted_data_buffer[1];
        nitrogen_dioxide[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "CMO", 3) == 0)
	{
        Int_form5();
        
        carbon_monoxide[0] = ID_CARBON_MONOXIDE;
        carbon_monoxide[1] = (valid << 7) | LENGTH_FORMAT5;
        carbon_monoxide[2] = formatted_data_buffer[0];
        carbon_monoxide[3] = formatted_data_buffer[1];
        carbon_monoxide[4] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT5; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
	}
	else if (strncmp(KEY, "AT0", 3) == 0)
	{
        Int_form2();
        
        CO_ADC_temp[0] = ID_CO_ADC_TEMP;
        CO_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        CO_ADC_temp[2] = formatted_data_buffer[0];
        CO_ADC_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "AT1", 3) == 0)
	{
		Int_form2();
        
        IAQ_IRR_ADC_temp[0] = ID_IAQ_IRR_ADC_TEMP;
        IAQ_IRR_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        IAQ_IRR_ADC_temp[2] = formatted_data_buffer[0];
        IAQ_IRR_ADC_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "AT2", 3) == 0)
	{
		Int_form2();
        
        O3_NO2_ADC_temp[0] = ID_O3_NO2_ADC_TEMP;
        O3_NO2_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        O3_NO2_ADC_temp[2] = formatted_data_buffer[0];
        O3_NO2_ADC_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "AT3", 3) == 0)
	{
        Int_form2();
        
        SO2_H2S_ADC_temp[0] = ID_SO2_H2S_ADC_TEMP;
        SO2_H2S_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        SO2_H2S_ADC_temp[2] = formatted_data_buffer[0];
        SO2_H2S_ADC_temp[3] = formatted_data_buffer[1];
    
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "LTM", 3) == 0)
	{
		Int_form2();
        
        CO_LMP_temp[0] = ID_CO_LMP_TEMP;
        CO_LMP_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        CO_LMP_temp[2] = formatted_data_buffer[0];
        CO_LMP_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "ACX", 3) == 0)  //wait ACY, ACZ, and VIX
    {
        Int_form2();
        
        three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
        three_accel_and_vib[1] = (valid << 7) | LENGTH_FORMAT2;
        three_accel_and_vib[2] = formatted_data_buffer[0];
        three_accel_and_vib[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "ACY", 3) == 0)
    {
        Int_form2();
        
        three_accel_and_vib[1] = (valid << 7) | (LENGTH_FORMAT2 * 2);
        three_accel_and_vib[4] = formatted_data_buffer[0];
        three_accel_and_vib[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "ACZ", 3) == 0)
    {
        Int_form2();
        
        three_accel_and_vib[1] = (valid << 7) | (LENGTH_FORMAT2 * 3);
        three_accel_and_vib[6] = formatted_data_buffer[0];
        three_accel_and_vib[7] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "VIX", 3) == 0)
    {
        Int_form4();
        
        three_accel_and_vib[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        three_accel_and_vib[8] = formatted_data_buffer[0];
        three_accel_and_vib[9] = formatted_data_buffer[1];
        three_accel_and_vib[10] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT4; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "GYX", 3) == 0)  //wait GYY, GYZ, and OIX
    {
        Int_form2();
        
        three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;
        three_gyro_and_orientation[1] = (valid << 7) | LENGTH_FORMAT2;
        three_gyro_and_orientation[2] = formatted_data_buffer[0];
        three_gyro_and_orientation[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "GYY", 3) == 0)
    {
        Int_form2();
        
        three_gyro_and_orientation[1] = (valid << 7) | (LENGTH_FORMAT2 * 2);
        three_gyro_and_orientation[4] = formatted_data_buffer[0];
        three_gyro_and_orientation[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "GYZ", 3) == 0)
    {
        Int_form2();
        
        three_gyro_and_orientation[1] = (valid << 7) | (LENGTH_FORMAT2 * 3);
        three_gyro_and_orientation[6] = formatted_data_buffer[0];
        three_gyro_and_orientation[7] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "OIX", 3) == 0)
    {
        Int_form4();
        
        three_gyro_and_orientation[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        three_gyro_and_orientation[8] = formatted_data_buffer[0];
        three_gyro_and_orientation[9] = formatted_data_buffer[1];
        three_gyro_and_orientation[10] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (int j = 0; j < LENGTH_FORMAT4; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    
#ifdef SERIAL_DEBUG
    SerialUSB.print("\r\n");
#endif
    
    flag_KEY = false;
    key_id = 0;
    val_id = 0;
}

void Hex_BAD()          // format3
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

void Hex_form1()
{
    unsigned int hex;
    hex = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
    format1(hex);
}

void Int_form2()
{
    int form2;
    form2 = (int)atoi(VAL);
    format2(form2);
}

void Int_form4()
{
    unsigned long form4;
    form4 = (unsigned long)atol(VAL);              //char to int
    format4(form4);
}

void Int_form5()
{
    long form5;
    form5 = (long) strtol(VAL, NULL, 10);
    format5(form5);
}


