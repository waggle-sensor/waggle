void lightsense_acquire (void)
{


    #ifdef SERIAL_DEBUG
    SerialUSB.print("***");
    SerialUSB.println("Acquiring LightSense Data.");
    #endif
    #ifdef HIH6130_include
    HIH_fetch_humidity_temperature();
    HIH6130[0] = ID_HIH6130;
    HIH6130[1] = (1 << 7) | (LENGTH_FORMAT1 * 2);
    format1(Temp_float[0]);  // Put it into format 1
    HIH6130[2] = packet_format1[0];
    HIH6130[3] = packet_format1[1];
    format1(Temp_float[1]);  // Put it into format 1
    HIH6130[4] = packet_format1[0];
    HIH6130[5] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    SerialUSB.print("HIH6130 RH%:");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print("  Temperature:");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif

}

