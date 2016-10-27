
#ifdef RAIN_GAUGER_INCLUDE

void acquire_rain()
{
	// pack data into a subpacket

	// SerialUSB.print("pin_signal");
	// SerialUSB.print("\t");
	// SerialUSB.println(pin_signal);

	// SerialUSB.print("count_num");
	// SerialUSB.print("\t");
	// SerialUSB.println(count_num);


	if (count_num != 0 && tip_count == count_num)
	{
		no_rain_check++;
		// SerialUSB.println("no_rain_check++;");
	}
	else if (no_rain_check != 0)
	{
		no_rain_check = 0;
		// SerialUSB.println("no_rain_check = 0;");
	}


	if (no_rain_check == 3 && count_num == 1) // possible count error
		rain_initialization();
	if (no_rain_check == 24 && count_num != 0) // 10 mins (25 sec * 24), 30 mins (25 sec * 72)
		rain_initialization();

	tip_count = count_num;


	rain_monitor = analogRead(RAIN_MONITOR_PIN);

	SerialUSB.print("analogRead rain monitor");
	SerialUSB.print("\t");
	SerialUSB.println(rain_monitor);

	if (rain_monitor == 0)
	{
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
	no_rain_check = 0;

	// SerialUSB.println("!!!!!!!!RESET_RAIN_GAUGER_VARIABLES!!!!!!!!");

	// SerialUSB.print("pin_signal");
	// SerialUSB.print("\t");
	// SerialUSB.println(pin_signal);	

	// SerialUSB.print("count_num");
	// SerialUSB.print("\t");
	// SerialUSB.println(count_num);
}
#endif