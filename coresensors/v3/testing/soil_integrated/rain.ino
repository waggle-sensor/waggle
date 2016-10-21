
#ifdef RAIN_GAUGER_INCLUDE

void acquire_rain()
{
	// pack data into a subpacket

	if (state == HIGH)
	{
		// SerialUSB.print("count_num");
		// SerialUSB.print("\t");
		// SerialUSB.println(count_num);

		// SerialUSB.print("pin_signal");
		// SerialUSB.print("\t");
		// SerialUSB.println(pin_signal);
		state = LOW;

		tip_count = count_num;

		format1(tip_count);

		RAIN_GAUGER[1] = (1 << 7) | LENGTH_FORMAT1;
		RAIN_GAUGER[2] = formatted_data_buffer[0];
		RAIN_GAUGER[3] = formatted_data_buffer[1];
	}
}

void rain_initialization()
{
	pin_signal = 0;
	count_num = 0;
	count = 0;
	no_rain_check = 0;

	// SerialUSB.println("!!!!!!!!RESET_RAIN_GAUGER_VARIABLES!!!!!!!!");

	// SerialUSB.print("count_num");
	// SerialUSB.print("\t");
	// SerialUSB.println(count_num);

	// SerialUSB.print("pin_signal");
	// SerialUSB.print("\t");
	// SerialUSB.println(pin_signal);	
}
#endif