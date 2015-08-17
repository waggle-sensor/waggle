void chemsense_parse_value (unsigned char pidx)
{
    param_value = 0;
    for (unsigned char idx = 0; idx < pidx; idx ++)
    {
        if (parameter[idx] != 0x2d)
        {
            parameter[idx] = parameter[idx] - 48;
            param_value = (param_value * 10) + parameter[idx];
        }
    }

    if (parameter[0] == 0x2d)
    {
        param_value = param_value * (-1);
    }

    return;
}

void chemsense_aquire (void)
{

    while (Serial3.available())
    {
        char inByte = Serial3.read();
        #ifdef DEBUG_chemsense
        SerialUSB.write(inByte);
        #endif
        if (( inByte != '\n') && (cnt < BUFFER_SIZE_CHEMSENSE))
        {
            buffer[cnt] = inByte;
            cnt = cnt + 1;
        }
        else
        {
            chemsense_ready = true;
            cnt = cnt + 1;
        }
    }
    return;
}


void chemsense_pack (void)
{
    if (chemsense_ready == true)
    {
        chemsense_ready = false;
        unsigned char count = 0, pidx = 0;
        for (unsigned char index = CR_ENABLE; index < cnt; index ++)
        {
            if (buffer[index] != ',')
            {
                if ((count == 0) && (pidx < PARAM_SIZE_CHEMSENSE))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }
            }
            else
            {
                count = count + 1;
            }
        }

        if ((count == 15) && (pidx == 12))
        {
            unsigned char count = 0, pidx = 0;
            for (unsigned char index = CR_ENABLE; index < cnt; index ++)
            {
                if ((buffer[index] != ',') && (pidx < PARAM_SIZE_CHEMSENSE))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }

                else
                {
                    if (count == 0)
                    {
                        #ifdef chemsense_MAC_ID_include
                        // chemsense MAC address (format 3)
                        valid = 1;
                        chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;
                        chemsense_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
                        for (unsigned char idx = 0; idx < pidx; idx ++)
                        {
                            if ((parameter[idx] > 96) && (parameter[idx] < 103))
                            {
                                parameter[idx] = parameter[idx] - 87;
                            }
                            else
                            {
                                parameter[idx] = parameter[idx] - 48;
                            }

                            if (idx % 2 == 0)
                            {
                                parameter[idx] = parameter[idx] << 4;
                            }
                            chemsense_MAC_ID[(idx/2)+2] = chemsense_MAC_ID[(idx/2)+2] | parameter[idx];
                        }
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("chemsense MAC ID: ");
                        for (int i = 2; i < (LENGTH_FORMAT3 + 2); i++)
                            SerialUSB.print(chemsense_MAC_ID[i], HEX);
                        SerialUSB.println("");
                        #endif
                        #endif
                    }

                    else if (count == 1)
                    {
                        #ifdef HDC_1000_include
                        SerialUSB.println("HDC_Temp");
                        chemsense_parse_value(pidx);
                        SerialUSB.println(param_value);
                        #endif
                    }
                    else if (count == 2)
                    {
                        #ifdef HDC_1000_include
                        SerialUSB.println("HDC_RH");
                        chemsense_parse_value(pidx);
                        SerialUSB.println(param_value);
                        #endif
                    }
                    else if (count == 3)
                    {
                        #ifdef SHT25_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(int(param_value));
                        SHT25[0] = ID_SHT25;
                        SHT25[1] = (valid << 7) | ((LENGTH_FORMAT5) * 2);
                        SHT25[2] = packet_format5[0];
                        SHT25[3] = packet_format5[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("SHT25 Temperature: ");
                        SerialUSB.println(int(param_value));
                        #endif
                        #endif
                    }
                    else if (count == 4)
                    {
                        #ifdef SHT25_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(int(param_value));
                        SHT25[0] = ID_SHT25;
                        SHT25[1] = (valid << 7) | ((LENGTH_FORMAT5) * 2);
                        SHT25[4] = packet_format5[0];
                        SHT25[5] = packet_format5[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("SHT25 RH: ");
                        SerialUSB.println(int(param_value));
                        #endif
                        #endif

                    }
                    else if (count == 5)
                    {
                        #ifdef LPS25H_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(int(param_value) >> 1);
                        LPS25H[0] = ID_LPS25H;
                        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
                        LPS25H[2] = packet_format5[0];
                        LPS25H[3] = packet_format5[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("LPS25H Temp: ");
                        SerialUSB.println(int(param_value));
                        #endif
                        #endif

                    }
                    else if (count == 6)
                    {
                        #ifdef Si1145_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value) >> 1);
                        Si1145[0] = ID_Si1145;
                        Si1145[1] = (valid << 7) | (LENGTH_FORMAT2);
                        Si1145[2] = packet_format2[0];
                        Si1145[3] = packet_format2[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("Si1145 UV: ");
                        SerialUSB.println(int(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 7)
                    {
                        #ifdef LPS25H_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 2);
                        LPS25H[0] = ID_LPS25H;
                        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
                        LPS25H[4] = packet_format6[0];
                        LPS25H[5] = packet_format6[1];
                        LPS25H[6] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("LPS25H Pressure: ");
                        SerialUSB.println(long(param_value) >> 2);
                        #endif
                        #endif
                    }
                    else if (count == 8)
                    {
                        #ifdef hydrogen_sulphide_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(param_value >> 1);
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        hydrogen_sulphide[2] = packet_format6[0];
                        hydrogen_sulphide[3] = packet_format6[1];
                        hydrogen_sulphide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("H2S: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 9)
                    {
                        #ifdef ozone_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 1);
                        ozone[0] = ID_OZONE;
                        ozone[1] = (valid << 7) | (LENGTH_FORMAT6);
                        ozone[2] = packet_format6[0];
                        ozone[3] = packet_format6[1];
                        ozone[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("O3: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 10)
                    {
                        #ifdef nitrogen_dioxide_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 1);
                        nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
                        nitrogen_dioxide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        nitrogen_dioxide[2] = packet_format6[0];
                        nitrogen_dioxide[3] = packet_format6[1];
                        nitrogen_dioxide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("NO2: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 11)
                    {
                        #ifdef carbon_monoxide_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 1);
                        carbon_monoxide[0] = ID_CARBON_MONOXIDE;
                        carbon_monoxide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        carbon_monoxide[2] = packet_format6[0];
                        carbon_monoxide[3] = packet_format6[1];
                        carbon_monoxide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("CO: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 12)
                    {
                        #ifdef sulfur_dioxide_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 1);
                        sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
                        sulfur_dioxide[1] = (valid << 7) | (LENGTH_FORMAT6);
                        sulfur_dioxide[2] = packet_format6[0];
                        sulfur_dioxide[3] = packet_format6[1];
                        sulfur_dioxide[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("SO2: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }

                    else if (count == 13)
                    {
                        #ifdef total_oxidizing_gases_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 1);
                        total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
                        total_oxidizing_gases[1] = (valid << 7) | (LENGTH_FORMAT6);
                        total_oxidizing_gases[2] = packet_format6[0];
                        total_oxidizing_gases[3] = packet_format6[1];
                        total_oxidizing_gases[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("ToX: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    else if (count == 14)
                    {
                        #ifdef total_reducing_gases_include
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format6(long(param_value) >> 1);
                        total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
                        total_reducing_gases[1] = (valid << 7) | (LENGTH_FORMAT6);
                        total_reducing_gases[2] = packet_format6[0];
                        total_reducing_gases[3] = packet_format6[1];
                        total_reducing_gases[4] = packet_format6[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("ToR: ");
                        SerialUSB.println(long(param_value) >> 1);
                        #endif
                        #endif
                    }
                    count = count + 1;
                    pidx = 0;
                }
            }

            #ifdef ethanol_include
            valid = 1;
            chemsense_parse_value(pidx-1);
            format6(long(param_value) >> 1);
            ethanol[0] = ID_ETHANOL;
            ethanol[1] = (valid << 7) | (LENGTH_FORMAT6);
            ethanol[2] = packet_format6[0];
            ethanol[3] = packet_format6[1];
            ethanol[4] = packet_format6[2];
            #ifdef SERIAL_DEBUG
            SerialUSB.print("ETOH: ");
            SerialUSB.println(long(param_value) >> 1);
            #endif
            #endif
        }
        cnt = 0;
    }
}
