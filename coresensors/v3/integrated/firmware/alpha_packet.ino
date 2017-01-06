
/** Assemble whole packet *************************************************************/
void alpha_packet_whole()
{
    packet_whole_index = 3; // start at 3 to account for header
    

#ifdef ALPHASENSE_INCLUDE
    if ((alpha_histogram[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(alpha_histogram); i++)
        {
            packet_whole[packet_whole_index] = alpha_histogram[i];
            packet_whole_index++;
        }
        alpha_histogram[1] = (0 << 7) | LENGTH_ALPHA_HISTOGRAM;
    }

    if ((alpha_serial[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(alpha_serial); i++)
        {
            packet_whole[packet_whole_index] = alpha_serial[i];
            packet_whole_index++;
        }
        alpha_serial[1] = (0 << 7) | LENGTH_ALPHA_SERIAL;
    }

    if (flag_alpha == true)
    {
        if ((alpha_firmware[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_firmware); i++)
            {
                packet_whole[packet_whole_index] = alpha_firmware[i];
                packet_whole_index++;
            }
            alpha_firmware[1] = (0 << 7) | LENGTH_ALPHA_FIRMWARE;
        }
    }

    if (flag_alpha == true)
    {
        if ((alpha_config_a[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_a); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_a[i];
                packet_whole_index++;
            }
            alpha_config_a[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_A;
        }
    }
#endif
   

    // #ifdef system_health_include
    // // Append health
    // for (int i = 0; i < sizeof(sensor_health); i++)
    // {
    //     packet_whole[packet_whole_index] = sensor_health[i];
    //     // Increment index for whole packet
    //     packet_whole_index++;
    // }
    // #endif


    // Length
    packet_whole[0x02] = packet_whole_index - 0x03;
    packet_seq_number++;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;

    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = END_BYTE;

//     #ifdef SERIAL_DEBUG
//     SerialUSB.println(packet_whole_index, DEC);
//     #endif
}
/**************************************************************************************/
