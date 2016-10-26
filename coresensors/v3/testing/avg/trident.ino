
#ifdef DECAGON_INCLUDE

void init_trident()
{
	count_trident = 0;

	data_char = 0;
	data_int = 0;

	for (int i = 0; i < 25; i++)
		data_string[i] = char(32);
	input_num = 0;

	checksum = 0;

	crc_int = 0;
	crc_char = 0;

	data_int = 0;

	checkZ = true;
	crc_byte = false;

	param = 0;
	last = 0;
}

void calc_crc()
{
	crc_int = checksum % 64 + 32;
	crc_char = char(crc_int);
}

void parameters()
{
	int Temp_uint16 = 0;

	for (int i = last; i < (input_num - 1); i++)
	{
		if (data_string[i] < '0' || data_string[i] > '9')
			continue;

		// SerialUSB.print(data_string[i]);
		// SerialUSB.print("\t");

		data_string[i] = data_string[i] - '0';
		Temp_uint16 = (Temp_uint16 * 10) + data_string[i];
	}
	// SerialUSB.println(" ");

	// SerialUSB.print("converted");
	// SerialUSB.print("\t");
	// SerialUSB.println(Temp_uint16);

	if (param == 0)
	{
		dielectric = float(Temp_uint16) / 50.000000;

		// SerialUSB.print("dielectric");
		// SerialUSB.print("\t");
		// SerialUSB.println(dielectric);
	}
	else if (param == 1)
	{
		if (Temp_uint16 < 700)
			conductivity = float(Temp_uint16) / 100.0;
		else
			conductivity = (float(Temp_uint16) - 700.0) * 5.0 + 700.0;

		// SerialUSB.print("conductivity");
		// SerialUSB.print("\t");
		// SerialUSB.println(conductivity);
	}
	else if (param == 2)
	{
		if (Temp_uint16 < 900)
			temperature = (float(Temp_uint16) - 400.0) / 10.0;
		else
			temperature = (float(Temp_uint16) - 900.0) * 5.0 + 900.0;

		// SerialUSB.print("temperature");
		// SerialUSB.print("\t");
		// SerialUSB.println(temperature);
	}

	last = input_num;
	param++;
}

void fill_subpacket()
{
	format6(dielectric);

	DECAGON[2] = formatted_data_buffer[0];
	DECAGON[3] = formatted_data_buffer[1];

	format6(conductivity);

	DECAGON[4] = formatted_data_buffer[0];
	DECAGON[5] = formatted_data_buffer[1];

	format6(temperature);

	DECAGON[1] = (1 << 7) | (LENGTH_FORMAT6 * 3);
	DECAGON[6] = formatted_data_buffer[0];
	DECAGON[7] = formatted_data_buffer[1];
}

void acquire_trident()
{
	count_trident = count;

	PWR_UP_DOWN = true;
	digitalWrite(TRIDENT_POWER, PWR_UP_DOWN);
	delay(100);

	while (count_trident == count) // Theoratically, work below will be done in 16ms
	{
		if (Serial1.available() > 0)
		{
			data_int = Serial1.read();
			data_char = char(data_int);

			data_string[input_num] = data_char;
			input_num++;

			SerialUSB.println(data_string);
			

			if (data_int == 32)
				parameters();

			if (crc_byte == true)
			{
				crc_from = data_char;
				crc_byte = false;
			}

			if (data_int == 122)
			{
				parameters();

				checksum += data_int;
				checkZ = false;
				crc_byte = true;
			}

			if (checkZ == true)
				checksum += data_int;
		}
	}


	calc_crc();

	if (crc_char == crc_from)
	{
		// Then send this as a subpacket
		fill_subpacket();

		// SerialUSB.println("MATCH");
		// SerialUSB.println(" ");
	}


	PWR_UP_DOWN = false;
	digitalWrite(TRIDENT_POWER, PWR_UP_DOWN);

	init_trident();
}

// unsigned int reverse(register unsigned int x)
// {
// 	x = (((x & 0xaa) >> 1) | ((x & 0x55) << 1));
// 	x = (((x & 0xcc) >> 2) | ((x & 0x33) << 2));
// 	x = (((x & 0xf0) >> 4) | ((x & 0x0f) << 4));
// 	return x;
// }
#endif