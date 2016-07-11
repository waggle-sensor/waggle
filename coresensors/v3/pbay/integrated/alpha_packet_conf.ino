
/** Assemble whole packet *************************************************************/
void alpha_packet_config()
{
    packet_whole_index = 3; // start at 3 to account for header
    

#ifdef ALPHASENSE_INCLUDE
    if (flag_alpha == true)
    {
        if ((alpha_config_b[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_b); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_b[i];
                packet_whole_index++;
            }
            alpha_config_b[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_B;
        }

        if ((alpha_config_c[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_c); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_c[i];
                packet_whole_index++;
            }
            alpha_config_c[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_C;
        }

        if ((alpha_config_d[1] & 0x80) == 0x80)
        {
            for (i = 0; i <  sizeof(alpha_config_d); i++)
            {
                packet_whole[packet_whole_index] = alpha_config_d[i];
                packet_whole_index++;
            }
            alpha_config_d[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_D;
        }


        flag_alpha = false;
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
