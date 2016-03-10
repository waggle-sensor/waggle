void chemsense_parse_value (byte pidx)
{
    param_value = 0;
    for (byte idx = 0; idx < pidx; idx ++)
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
//     SerialUSB.println(param_value);
    return;
}

void chemsense_aquire (void)
{

//     let us acquire a line of chemsense data
    while (Serial3.available())
    {
        // every line of data terminates with a newline and carriage return char, lock to the carriage return,
        // parse the next line in full, until the newline char is encountered

        //read a byte of data from serial buffer
        inByte = Serial3.read();
        SerialUSB.write(inByte);

        //check if we have locked to carriage return - end of previous line.
        if (inByte == '\r')
        {
            cnt = 0;
            Chemsense_locked = 1;
        }

        //given that we are locked in, let us proceed to fill the
        //char buffer with ASCIIs we are receiving
        if (Chemsense_locked == 1)
        {
            // we have seen a newline char, a complete line of data has been acquired
            if (inByte == '\n')
            {
                cnt = cnt + 1;
                ChemSensed = 1;
                chemsense_ready = true;
            }
            //not a newline char, continue to fill the buffer
            else
            {
                //fill the buffer only if the data received by serial is under the allocated buffer length
                if ( cnt < BUFFER_SIZE_CHEMSENSE )
                {
                    buffer[cnt] = inByte;
                    cnt = cnt + 1;
                }
            }
        }
    }
    return;
}

// Chemsense line output -
// 72f1addaffff,25600,29720,6644,1563,-25510,23,4103258,-1238233,-123432,8388606,-58790,-1495769,2432,5739770,-271490
// 72f1addaffff,25600,29720,6644,1563,-25510,23,4103258,-1224139,-151913,8388606,-58558,-1514697,2425,5741330,-270681
// 0   MAC - 6 Bytes
// 1   HDC_Temp - Ignore
// 2   HDC_RH - Ignore
// 3   SHT_Temp - 2 Bytes (15 bits + sign) (14 bits raw, encoded as is)
// 4   SHT_RH - 2 Bytes (15 bits + sign) (12 bits raw, encoded as is)
// 5   LPS_Temp - 2 Bytes (15 bits + sign) (16 bits raw, encoded after right shifting by 1)
// 6   UV - 2 Bytes (16 bits) (16 bits raw, encoded as is)
// 7   Pressure - 3 Bytes (24 bits) (24 bits raw, encoded as is)
// 8   H2S - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 9   O3 - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 10  NO2 - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 11  CO - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 12  SO2 - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 13  TotalOX - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 14  TotalRed - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)
// 15  ETOH - 3 Bytes (23 bits + sign) (The AFE produces 23 bits precision output + sign bit)

void chemsense_pack (void)
{
    // if there is data to be packed, acquired earlier using chemsense acquire, then
    // let us pack the data
    if (chemsense_ready == true)
    {
        chemsense_ready = false;

        byte count = 0, pidx = 0;

        for (byte index = CR_ENABLE; index < cnt; index ++)
        {
            // Tokenize the buffer with ',' as the delimiter, count the number of
            // tokens (count variable) and the length of the MACID field, also
            // grab the MAC ID field from buffer

            if (buffer[index] != ',')
            {
                if ((count == 0) && (pidx < PARAM_SIZE_CHEMSENSE))
                {
                    pidx = pidx + 1;
                }
            }
            else
            {
                count = count + 1;
            }
        }

        // check if a valid line of data was acquired.

        if ((count == 15) && (pidx == 13))
        {
            byte count = 0, pidx = 0;
            // parse the valid line of data
            for (byte index = CR_ENABLE + 1; index < cnt; index ++)
            {

                // segregate every token, one by one.
                if ((buffer[index] != ',') && (pidx < PARAM_SIZE_CHEMSENSE))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }

                // a token has been segregated as the next char is the delimiter ','
                else
                {

                    if (count == 0)
                    {
                        #ifdef chemsense_MAC_ID_include
                        // chemsense MAC address (format 3)
                        valid = 1;
                        chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;
                        chemsense_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
                        for (byte idx = 0; idx < pidx; idx ++)
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

                    #ifdef SHT25_include
                    else if (count == 3)
                    {

                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value));
                        SHT25[0] = ID_SHT25;
                        SHT25[1] = (valid << 7) | ((LENGTH_FORMAT2) * 2);
                        SHT25[2] = formatted_data_buffer[0];
                        SHT25[3] = formatted_data_buffer[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("SHT25 Temperature: ");
                        SerialUSB.println(int(param_value));
                        #endif

                    }
                    else if (count == 4)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value));
                        SHT25[0] = ID_SHT25;
                        SHT25[1] = (valid << 7) | ((LENGTH_FORMAT2) * 2);
                        SHT25[4] = formatted_data_buffer[0];
                        SHT25[5] = formatted_data_buffer[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("SHT25 RH: ");
                        SerialUSB.println(int(param_value));
                        #endif
                    }
                    #endif

                    #ifdef LPS25H_include
                    else if (count == 5)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format2(int(param_value) >> 1); // have to check if this is needed.
                        LPS25H[0] = ID_LPS25H;
                        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
                        LPS25H[2] = formatted_data_buffer[0];
                        LPS25H[3] = formatted_data_buffer[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("LPS25H Temp: ");
                        SerialUSB.println(int(param_value));
                        #endif
                    }

                   else if (count == 7)
                   {
                       valid = 1;
                       chemsense_parse_value(pidx);
                       format4(long(param_value));
                       LPS25H[0] = ID_LPS25H;
                       LPS25H[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
                       LPS25H[4] = formatted_data_buffer[0];
                       LPS25H[5] = formatted_data_buffer[1];
                       LPS25H[6] = formatted_data_buffer[2];
                       #ifdef SERIAL_DEBUG
                       SerialUSB.print("LPS25H Pressure: ");
                       SerialUSB.println(long(param_value));
                       #endif

                   }
                   #endif

                    #ifdef Si1145_include
                    else if (count == 6)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format1(int(param_value));
                        Si1145[0] = ID_Si1145;
                        Si1145[1] = (valid << 7) | (LENGTH_FORMAT1);
                        Si1145[2] = formatted_data_buffer[0];
                        Si1145[3] = formatted_data_buffer[1];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("Si1145 UV: ");
                        SerialUSB.println(int(param_value));
                        #endif
                    }
                    #endif

                    #ifdef hydrogen_sulphide_include
                    else if (count == 8)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
                        hydrogen_sulphide[1] = (valid << 7) | (LENGTH_FORMAT5);
                        hydrogen_sulphide[2] = formatted_data_buffer[0];
                        hydrogen_sulphide[3] = formatted_data_buffer[1];
                        hydrogen_sulphide[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("H2S: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    #ifdef ozone_include
                    else if (count == 9)
                    {

                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        ozone[0] = ID_OZONE;
                        ozone[1] = (valid << 7) | (LENGTH_FORMAT5);
                        ozone[2] = formatted_data_buffer[0];
                        ozone[3] = formatted_data_buffer[1];
                        ozone[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("O3: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    #ifdef nitrogen_dioxide_include
                    else if (count == 10)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
                        nitrogen_dioxide[1] = (valid << 7) | (LENGTH_FORMAT5);
                        nitrogen_dioxide[2] = formatted_data_buffer[0];
                        nitrogen_dioxide[3] = formatted_data_buffer[1];
                        nitrogen_dioxide[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("NO2: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    #ifdef carbon_monoxide_include
                    else if (count == 11)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        carbon_monoxide[0] = ID_CARBON_MONOXIDE;
                        carbon_monoxide[1] = (valid << 7) | (LENGTH_FORMAT5);
                        carbon_monoxide[2] = formatted_data_buffer[0];
                        carbon_monoxide[3] = formatted_data_buffer[1];
                        carbon_monoxide[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("CO: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    #ifdef sulfur_dioxide_include
                    else if (count == 12)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
                        sulfur_dioxide[1] = (valid << 7) | (LENGTH_FORMAT5);
                        sulfur_dioxide[2] = formatted_data_buffer[0];
                        sulfur_dioxide[3] = formatted_data_buffer[1];
                        sulfur_dioxide[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("SO2: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    #ifdef total_oxidizing_gases_include
                    else if (count == 13)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
                        total_oxidizing_gases[1] = (valid << 7) | (LENGTH_FORMAT5);
                        total_oxidizing_gases[2] = formatted_data_buffer[0];
                        total_oxidizing_gases[3] = formatted_data_buffer[1];
                        total_oxidizing_gases[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("ToX: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    #ifdef total_reducing_gases_include
                    else if (count == 14)
                    {
                        valid = 1;
                        chemsense_parse_value(pidx);
                        format5(long(param_value));
                        total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
                        total_reducing_gases[1] = (valid << 7) | (LENGTH_FORMAT5);
                        total_reducing_gases[2] = formatted_data_buffer[0];
                        total_reducing_gases[3] = formatted_data_buffer[1];
                        total_reducing_gases[4] = formatted_data_buffer[2];
                        #ifdef SERIAL_DEBUG
                        SerialUSB.print("ToR: ");
                        SerialUSB.println(long(param_value));
                        #endif
                    }
                    #endif

                    count = count + 1;
                    pidx = 0;
                }
            }

            #ifdef ethanol_include
            valid = 1;
            chemsense_parse_value(pidx-1);
            format5(long(param_value));
            ethanol[0] = ID_ETHANOL;
            ethanol[1] = (valid << 7) | (LENGTH_FORMAT5);
            ethanol[2] = formatted_data_buffer[0];
            ethanol[3] = formatted_data_buffer[1];
            ethanol[4] = formatted_data_buffer[2];
            #ifdef SERIAL_DEBUG
            SerialUSB.print("ETOH: ");
            SerialUSB.println(long(param_value));
            #endif
            #endif
        }
        cnt = 0;
        ChemSensed = 1;
    }
}
