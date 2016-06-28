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
    while (Serial3.available() > 0)
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

#ifdef SERIAL_DEBUG
        // to check output
        for (i = 0; i < LENGTH_FORMAT4; i++)
            SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
    }

}
