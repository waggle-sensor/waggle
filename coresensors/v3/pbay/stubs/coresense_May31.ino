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
int pre_idx = 0;
int SQ_num = 0;
	
int key_id = 0;
int val_id = 0;

bool flag_KEY = false;

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
	Serial3.begin(19200);       //getData, communicate with the sensor
	while(!SerialUSB) {;}
	SerialUSB.begin(115200);    //sendData, communicate with computer
	while(!Serial) {;}

	        //turn ON chemsense.
    digitalWrite(PIN_CHEMSENSE_POW, LOW);
    
//     //turn OFF chemsense.
//     digitalWrite(PIN_CHEMSENSE_POW, HIGH);
    
}

void loop()
{
    Read_value();
}

void Read_value()
{
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
                Add_carrier();
                flag_KEY = false;
                key_id = 0;
                val_id = 0;
                break;
            }/*
            case '\r':
                Send_CARR();
                break;*/
            default:
            break;
        }
    }
}

void Add_carrier()
{
	if (!flag_KEY)
		return;

	if (strncmp(KEY, "BAD", 3) == 0) 
	{
        int valid = 1;
        Hex_BAD();
		carrier[0] = ID_CHEMSENSE_MAC;
        carrier[1] = (valid << 7) | LENGTH_FORMAT3;
        carrier[2] = formatted_data_buffer[0];
        carrier[3] = formatted_data_buffer[1];
        carrier[4] = formatted_data_buffer[2];
        carrier[5] = formatted_data_buffer[3];
        carrier[6] = formatted_data_buffer[4];
        carrier[7] = formatted_data_buffer[5];
		SerialUSB.write(carrier, 8);           // send carrier
        SerialUSB.print("");
	}
	else if (strncmp(KEY, "SHT", 3) == 0)  // wait SHH
	{
        int idx = 0;
        int valid = 1;
        
        int form2;
        form2 = (int)atoi(VAL);
        format2(form2);
        
		carrier[0] = ID_SHT25;
		carrier[1] = (valid << 7) | LENGTH_FORMAT2;
		carrier[2] = formatted_data_buffer[0];
		carrier[3] = formatted_data_buffer[1];
		idx = 4;
		
		Read_value();
        if (strncmp(KEY, "SHH", 3) == 0)
        {
            unsigned int form1;
            form1 = (unsigned int)atoi(VAL);       //char to int
            format1(form1); 
            
            carrier[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
            carrier[4] = formatted_data_buffer[0];
            carrier[5] = formatted_data_buffer[1];
            idx = 6;
        }
        SerialUSB.write(carrier, idx);           // send carrier
        SerialUSB.print("");
	}
	else if (strncmp(KEY, "LPT", 3) == 0)  // wait LPP
	{
		int valid = 1;
		
        int form2;
        form2 = (int)atoi(VAL);
        format2(form2);
        
        carrier[0] = ID_LPS25H;
        carrier[1] = (valid << 7) | LENGTH_FORMAT2;
        carrier[2] = formatted_data_buffer[0];
        carrier[3] = formatted_data_buffer[1];
        idx = 4;
        
        Read_value();
        if (strncmp(KEY, "LPP", 3) == 0)
        {
            unsigned int form1;
            form1 = (unsigned int)atoi(VAL);       //char to int
            format1(form1); 
        
            carrier[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
            carrier[4] = formatted_data_buffer[0];
            carrier[5] = formatted_data_buffer[1];
            idx = 6;
        }
        SerialUSB.write(carrier, idx);           // send carrier
        SerialUSB.print("");
	}
	else if (strncmp(KEY, "SUV", 3) == 0)  // wait SVL and SIR
	{
        int valid = 1;
        int idx = 0;
        
        unsigned int hex;
        hex = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
        format1(hex);
        
		carrier[0] = ID_Si1145;
		carrier[1] = (valid << 7) | LENGTH_FORMAT1;
		carrier[2] = formatted_data_buffer[0];
		carrier[3] = formatted_data_buffer[1];
		idx = 4;
		
        Read_value();
        if (strncmp(KEY, "SVL", 3) == 0)
        {
            unsigned int hex;
            hex = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
            format1(hex);
        
            carrier[1] = (valid << 7) | (LENGTH_FORMAT1 * 2);
            carrier[4] = formatted_data_buffer[0];
            carrier[5] = formatted_data_buffer[1];
            idx = 6;
        }
        
        Read_value();
        if (strncmp(KEY, "SIR", 3) == 0)
        {
            unsigned int hex;
            hex = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
            format1(hex);
        
            carrier[1] = (valid << 7) | (LENGTH_FORMAT1 * 3);
            carrier[6] = formatted_data_buffer[0];
            carrier[7] = formatted_data_buffer[1];
            idx = 8;
        }        
        
        SerialUSB.write(carrier, idx);           // send carrier
        SerialUSB.print("");
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
		carrier[0] = ID_THREE_ACCEL_AND_VIB;
	else if (strncmp(KEY, "GYX", 3) == 0)  //wait GYY, GYZ, and OIX
		carrier[0] = ID_THREE_MAG_AND_ORIENTATION;

    flag_KEY = false;
    key_id = 0;
    val_id = 0;
}

void Hex_BAD()
{
    SerialUSB.println(VAL);
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
    
    SerialUSB.write(carrier, 4);
    SerialUSB.print("");
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
    carrier[4] = formatted_data_buffer[2];
    
    SerialUSB.write(carrier, 5);
    SerialUSB.print("");
}

void Formatting(char* KEY)
{
	int type = 9;

	if (strncmp(KEY, "BAD", 3) == 0)			//string
		type = 0;
	else if (strncmp(KEY, "SQN", 3) == 0)		//uint8 --> not in data Formatting ino, but use shift?????
		type = 1;
	else if (strncmp(KEY, "SHH", 3) == 0)	//uint16 from string: format1
		type = 2;
	else if (strncmp(KEY, "SUV", 3) == 0 | strncmp(KEY, "SVL", 3) == 0 | strncmp(KEY, "SIR", 3) == 0)	//uint16 from hex deciamal from string: format1
		type = 3;			
	else if (strncmp(KEY, "VIX", 3) == 0 | strncmp(KEY, "OIX", 3) == 0 | strncmp(KEY, "LPP", 3) == 0)	//uint24 from string: format4
		type = 4;
	else if (SQ_num == 1)			//the last for if else, int24: format5
		type = 5;
	else							//for default, int16: format2
		type = 9;

	char copy_val[12];
	strncpy(copy_val, VAL, val_id);		//Since the VAL is a pointer, copy value to a char arr
	copy_val[val_id] = '\0';

	switch(type)
	{
		case 0:	//string "BAD", form3
		{
			char first[6], second[6];
			strncpy(first, copy_val, 6);
			char *i = copy_val;
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
			break;
		}
		case 1:	//uint8 "SQN"
		{
			unsigned int form1;
			form1 = (int)strtol(copy_val, NULL, 16);   //hex string to int
			SQ_num = form1 % 4;
			format1(form1);	
			carrier[idx] = formatted_data_buffer[1];
			idx++;
			break;
		}

		case 2: 	//uint16 from string: format1 "SHH" and "LPP"
		{
			unsigned int form1;
			form1 = (unsigned int)atoi(copy_val);		//char to int
			format1(form1);		
			break;
		}
		case 3: 	//uint16 from hex deciamal from string: format1 "SUV" "SVL" "SIR"
		{
			unsigned int hex;
			hex = (unsigned int)strtol(copy_val, NULL, 16);   //hex string to int
			format1(hex);
			break;
		}
		case 4:	//uint32: format4 "VIX" "OIX"
		{
			unsigned long form4;
			form4 = (unsigned long)atol(copy_val);				//char to int
			format4(form4);
			break;
		}
		case 5:	//int24: format5 sqn == 1
		{
			long form5;
			form5 = (long) strtol(copy_val, NULL, 10);
			format5(form5);
			break;
		}
		default:  //form2
		{
			int form2;
			form2 = (int)atoi(copy_val);
			format2(form2);
			break;
		}
    }
	flag_KEY = false;
}


