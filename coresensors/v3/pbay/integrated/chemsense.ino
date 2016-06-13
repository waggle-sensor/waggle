unsigned char INPUT_BYTE;
char KEY[5];
char VAL[14];

char first[6], second[6];
char *i = VAL;

byte formatted_byte_temp[8];

int KEY_NUM_ID = 0;
int VAL_NUM_ID = 0;

int j = 0;

bool flag_KEY = false;

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
                KEY[KEY_NUM_ID] = INPUT_BYTE;
                KEY_NUM_ID++;
            }
            else
            {
                VAL[VAL_NUM_ID] = INPUT_BYTE;
                VAL_NUM_ID++;
            }
        }
        else if (INPUT_BYTE == '=')
        {
            flag_KEY = true;
        }
        else if (INPUT_BYTE == '\r' || INPUT_BYTE == ' ')
        {
            KEY[KEY_NUM_ID] = '\0';
            VAL[VAL_NUM_ID] = '\0';
            KEY_NUM_ID = 0;
            VAL_NUM_ID = 0;
            Carrier();
        }
//         switch(INPUT_BYTE)
//         {
//             case 48 ... 57: // numbers
//             case 65 ... 90: // Upper case letter
//             case 97 ... 122: // Lower case letter
//             case '-': //negative sign
//             {
//                 if (!flag_KEY)
//                 {
//                     KEY[KEY_NUM_ID] = INPUT_BYTE;
//                     KEY_NUM_ID++;
//                 }
//                 else
//                 {
//                     VAL[VAL_NUM_ID] = INPUT_BYTE;
//                     VAL_NUM_ID++;
//                 }
//                 break;
//             } 
//             
//             case '=':
//             {
//                 flag_KEY = true;
//                 break;
//             }
//             case '\r':
//             case ' ':
//             {
//                 KEY[KEY_NUM_ID] = '\0';
//                 VAL[VAL_NUM_ID] = '\0';
//                 KEY_NUM_ID = 0;
//                 VAL_NUM_ID = 0;
//                 //Carrier();
//                 break;
//             }
//             default:
//             break;
//         }
    }
}

void Carrier()
{
    // transform the data format as it defined
    
	if (!flag_KEY)
		return;
    
    flag_KEY = false;
    #ifdef SERIAL_DEBUG
        // to confirm output data
        SerialUSB.print(KEY);
        SerialUSB.print(" ");
        SerialUSB.print(VAL);
        SerialUSB.print(" ");
    #endif
    
	if (strncmp(KEY, "BAD", 3) == 0) 
	{
        Hex_BAD();
        
        chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;
        chemsense_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
        
        for (j = 0; j < LENGTH_FORMAT3; j++)
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

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check the values
        for (j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "SHH", 3) == 0)
    {
        Temp_uint16 = (unsigned int)atoi(VAL);       //char to int
        format1(Temp_uint16); 
        
        SHT25[0] = ID_SHT25;
        SHT25[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
        SHT25[2] = formatted_byte_temp[0];
        SHT25[3] = formatted_byte_temp[1];
        SHT25[4] = formatted_data_buffer[0];
        SHT25[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check the values
        for (j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "LPT", 3) == 0)  // wait LPP
	{
        Int_form2();
        
        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "LPP", 3) == 0)
    {
        Int_form4();
        
        LPS25H[0] = ID_LPS25H;
        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
        LPS25H[2] = formatted_byte_temp[0];
        LPS25H[3] = formatted_byte_temp[1];
        LPS25H[4] = formatted_data_buffer[0];
        LPS25H[5] = formatted_data_buffer[1];
        LPS25H[6] = formatted_data_buffer[2];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT4; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
	}
	else if (strncmp(KEY, "SUV", 3) == 0)  // wait SVL and SIR
	{
        Hex_form1();
        
        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "SVL", 3) == 0)
    {
        Hex_form1();
        
        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT1; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "SIR", 3) == 0)
    {
        Hex_form1();
        
        Si1145[0] = ID_Si1145;
        Si1145[1] = (valid << 7) | (LENGTH_FORMAT1 * 3);
        Si1145[2] = formatted_byte_temp[0];
        Si1145[3] = formatted_byte_temp[1];
        Si1145[4] = formatted_byte_temp[2];
        Si1145[5] = formatted_byte_temp[3];
        Si1145[6] = formatted_data_buffer[0];
        Si1145[7] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT1; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT5; j++)
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
        for (j = 0; j < LENGTH_FORMAT2; j++)
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
        for (j = 0; j < LENGTH_FORMAT2; j++)
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
        for (j = 0; j < LENGTH_FORMAT2; j++)
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
        for (j = 0; j < LENGTH_FORMAT2; j++)
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
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "ACX", 3) == 0)  //wait ACY, ACZ, and VIX
    {
        Int_form2();
        
        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "ACY", 3) == 0)
    {
        Int_form2();
        
        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "ACZ", 3) == 0)
    {
        Int_form2();
        
        formatted_byte_temp[4] = formatted_data_buffer[0];
        formatted_byte_temp[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "VIX", 3) == 0)
    {
        Int_form4();
        
        three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
        three_accel_and_vib[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
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
        for (j = 0; j < LENGTH_FORMAT4; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
	else if (strncmp(KEY, "GYX", 3) == 0)  //wait GYY, GYZ, and OIX
    {
        Int_form2();
        
        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "GYY", 3) == 0)
    {
        Int_form2();
        
        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "GYZ", 3) == 0)
    {
        Int_form2();
        
        formatted_byte_temp[4] = formatted_data_buffer[0];
        formatted_byte_temp[5] = formatted_data_buffer[1];
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    else if (strncmp(KEY, "OIX", 3) == 0)
    {
        Int_form4();
        
        three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;
        three_gyro_and_orientation[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
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
        
#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT4; j++)
        {
            SerialUSB.print(formatted_data_buffer[j],HEX);
            SerialUSB.print(" ");
        }
#endif
    }
    
#ifdef SERIAL_DEBUG
    SerialUSB.print("\r\n");
#endif
}

// formatting data
void Hex_BAD()          // format3
{
    //SerialUSB.println(VAL);
	strncpy(first, VAL, 6);
	i += 6;
	strncpy(second, i, 6);
	Temp_ulong[0]= (unsigned long) strtol(first, NULL, 16);      //too short to contain the whole value of 'BAD'
	Temp_ulong[1] = (unsigned long) strtol(second, NULL, 16);
	byte result[6];
	result[0] = (Temp_ulong[0] & 0xFF0000) >> 16;
	result[1] = (Temp_ulong[0] & 0x00FF00) >> 8;
	result[2] = (Temp_ulong[0] & 0x0000FF);
	result[3] = (Temp_ulong[1] & 0xFF0000) >> 16;
	result[4] = (Temp_ulong[1] & 0x00FF00) >> 8;
	result[5] = (Temp_ulong[1] & 0x0000FF);
	format3(result);
}

void Hex_form1()
{
    Temp_uint16 = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
    format1(Temp_uint16);
}

void Int_form2()
{
    
    Temp_int[0] = (int)atoi(VAL);
    format2(Temp_int[0]);
}

void Int_form4()
{
    Temp_ulong[0] = (unsigned long)atol(VAL);              //char to int
    format4(Temp_ulong[0]);
}

void Int_form5()
{
    Temp_long = (long) strtol(VAL, NULL, 10);
    format5(Temp_long);
}


