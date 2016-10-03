
/** Assemble empty packet *************************************************************/
void assemble_packet_empty()
{
    packet_whole[0x00] = START_BYTE;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = END_BYTE;
}
/**************************************************************************************/

/** Assemble whole packet *************************************************************/
void assemble_packet_whole()
{
    packet_whole_index = 3; // start at 3 to account for header
    
#ifdef SERIAL_DEBUG
    SerialUSB.println("Packing.");
#endif

#ifdef AIRSENSE_INCLUDE

#ifdef MAC_ID_include    // Append MAC_ID

    for (i = 0; i < sizeof(MAC_ID); i++)
    {
        packet_whole[packet_whole_index] = MAC_ID[i];
        // Increment index for whole packet
        packet_whole_index++;
    }

    #ifdef PRINT_ADDRESS
    SerialUSB.print("Airsense-");
   for (unsigned char a = 0x02; a < 0x08; a++)
    {
        if ((MAC_ID[a] & 0xF0) == 0x00)
        {

            SerialUSB.print('0');            
        }

        SerialUSB.print(MAC_ID[a],HEX);

        if (a < 0x07) { SerialUSB.print(":"); }
        else { SerialUSB.println("\r"); }
    }

    SerialUSB.print("Lightsense-");
    for (unsigned char a = 0x02; a < 0x08; a++)
    {
        if ((MAC_ID[a] & 0xF0) == 0x00)
        {

            SerialUSB.print('0');            
        }

        SerialUSB.print(MAC_ID[a],HEX);

        if (a < 0x07) { SerialUSB.print(":"); }
        else { SerialUSB.println("\r"); }
    }
#endif

#endif

#ifdef TMP112_include    // Append TMP112
    if ((TMP112[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TMP112); i++)
        {
            packet_whole[packet_whole_index] = TMP112[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP112[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif

#ifdef HTU21D_include    // Append HTU21D
    if((HTU21D_array[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HTU21D_array); i++)
        {
            packet_whole[packet_whole_index] = HTU21D_array[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HTU21D_array[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif

#ifdef HIH4030_include    // Append HIH4030
    if((HIH4030[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HIH4030); i++)
        {
            packet_whole[packet_whole_index] = HIH4030[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH4030[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef BMP180_include    // Append BMP180
    if ((BMP180[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(BMP180); i++)
        {
            packet_whole[packet_whole_index] = BMP180[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        BMP180[1] = (0 << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    }
#endif

#ifdef PR103J2_include    // Append PR103J2
    if ((PR103J2[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(PR103J2); i++)
        {
            packet_whole[packet_whole_index] = PR103J2[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        PR103J2[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL250RD_1_include    // Append TSL250RD_1
    if ((TSL250RD_1[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSL250RD_1); i++)
        {
            packet_whole[packet_whole_index] = TSL250RD_1[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_1[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef MMA8452Q_include    // Append MMA8452Q
    if ((MMA8452Q[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(MMA8452Q); i++)
        {
            packet_whole[packet_whole_index] = MMA8452Q[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        MMA8452Q[1] = (0 << 7) | (LENGTH_FORMAT6 * 4);
    }
#endif

#ifdef SPV1840LR5HB_include    // Append SPV1840LR5HB_2
    if ((SPV1840LR5HB[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(SPV1840LR5HB); i++)  //********************was SPV1840LR5HB_2
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB[i]; //********************was SPV1840LR5HB_2
            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif
    
#ifdef TSYS01_include    // Append TSYS01
    if ((TSYS01[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSYS01); i++)
        {
            packet_whole[packet_whole_index] = TSYS01[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSYS01[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif
#endif

#ifdef LIGHTSENSE_INCLUDE
#ifdef HMC5883L_include    // Append HMC5883L
    if ((HMC5883L[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HMC5883L); i++)
        {
            packet_whole[packet_whole_index] = HMC5883L[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HMC5883L[1] = (0 << 7) | (LENGTH_FORMAT8 * 3);
    }
#endif

#ifdef HIH6130_include    // Append HIH6130
    if ((HIH6130[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(HIH6130); i++)
        {
            packet_whole[packet_whole_index] = HIH6130[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH6130[1] = (0 << 7) | (LENGTH_FORMAT6 * 2);
    }
#endif

#ifdef APDS9006020_include    // Append APDS9006020
    if ((APDS9006020[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(APDS9006020); i++)
        {
            packet_whole[packet_whole_index] = APDS9006020[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        APDS9006020[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL260RD_include    // Append TSL260RD
    if ((TSL250RD_2[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSL260RD); i++)
        {
            packet_whole[packet_whole_index] = TSL260RD[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL260RD[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL250RD_2_include    // Append TSL250RD_2
    if ((TSL250RD_2[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TSL250RD_2); i++)
        {
            packet_whole[packet_whole_index] = TSL250RD_2[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_2[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef MLX75305_include    // Append MLX75305
    if ((MLX75305[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(MLX75305); i++)
        {
            packet_whole[packet_whole_index] = MLX75305[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        MLX75305[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef ML8511_include
    // Append ML8511
    if ((ML8511[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(ML8511); i++)
        {
            packet_whole[packet_whole_index] = ML8511[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        ML8511[1] = (0 << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TMP421_include    // Append TMP421
    if ((TMP421[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(TMP421); i++)
        {
            packet_whole[packet_whole_index] = TMP421[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP421[1] = (0 << 7) | LENGTH_FORMAT6;
    }
#endif

#endif

#ifdef CHEMSENSE_INCLUDE

#ifdef chemsense_MAC_ID_include
    if ((chemsense_MAC_ID[1] & 0x80) == 0x80)
    {
        for (i = 0; i < sizeof(chemsense_MAC_ID); i++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[i];
            packet_whole_index++;
        }
        chemsense_MAC_ID[1] = (0 << 7) | LENGTH_FORMAT3;
    }
    
#ifdef PRINT_ADDRESS
        // to check output
        SerialUSB.print("Chemsense-");
        for (i = 0x02; i < 0x08; i++)
        {
            if ((chemsense_MAC_ID[i] & 0xf0) == 0x00)
                SerialUSB.print('0');
            SerialUSB.print(chemsense_MAC_ID[i],HEX);
            if (i < LENGTH_FORMAT3 + 1) { SerialUSB.print(":"); }
            else { SerialUSB.println("\r"); }
        }
#endif
#endif

#ifdef SHT25_include
    if ((SHT25[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(SHT25); i++)
        {
            packet_whole[packet_whole_index] = SHT25[i];
            packet_whole_index++;
        }
        SHT25[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);

    }
#endif

#ifdef LPS25H_include
    if ((LPS25H[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(LPS25H); i++)
        {
            packet_whole[packet_whole_index] = LPS25H[i];
            packet_whole_index++;
        }
        LPS25H[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
    }
#endif

#ifdef Si1145_include
    if ((Si1145[1] & 0x80) == 0x80)
    { 
        for (i = 0; i <  sizeof(Si1145); i++)
        {
            packet_whole[packet_whole_index] = Si1145[i];
            packet_whole_index++;
        }
        Si1145[1] = (0 << 7) | (LENGTH_FORMAT1 * 3);
    }   
#endif

#ifdef total_reducing_gases_include
    if ((total_reducing_gases[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(total_reducing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[i];
            packet_whole_index++;
        }
        total_reducing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef total_oxidizing_gases_include
    if ((total_oxidizing_gases[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(total_oxidizing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[i];
            packet_whole_index++;
        }
        total_oxidizing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef sulfur_dioxide_include
    if ((sulfur_dioxide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(sulfur_dioxide); i++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[i];
            packet_whole_index++;
        }
        sulfur_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef hydrogen_sulphide_include
    if ((hydrogen_sulphide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(hydrogen_sulphide); i++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[i];
            packet_whole_index++;
        }
        hydrogen_sulphide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef ozone_include
    if ((ozone[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(ozone); i++)
        {
            packet_whole[packet_whole_index] = ozone[i];
            packet_whole_index++;
        }
        ozone[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef nitrogen_dioxide_include
    if ((nitrogen_dioxide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(nitrogen_dioxide); i++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[i];
            packet_whole_index++;
        }
        nitrogen_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef carbon_monoxide_include
    if ((carbon_monoxide[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(carbon_monoxide); i++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[i];
            packet_whole_index++;
        }
        carbon_monoxide[1] = (0 << 7) | LENGTH_FORMAT5;
    }
#endif

#ifdef CO_ADC_temp_include
    if ((CO_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(CO_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = CO_ADC_temp[i];
            packet_whole_index++;
        }
        CO_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef IAQ_IRR_ADC_temp_include
    if ((IAQ_IRR_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(IAQ_IRR_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[i];
            packet_whole_index++;
        }
        IAQ_IRR_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef O3_NO2_ADC_temp_include
    if ((O3_NO2_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(O3_NO2_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = O3_NO2_ADC_temp[i];
            packet_whole_index++;
        }
        O3_NO2_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef SO2_H2S_ADC_temp_include
    if ((SO2_H2S_ADC_temp[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(SO2_H2S_ADC_temp); i++)
        {
            packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[i];
            packet_whole_index++;
        }
        SO2_H2S_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }
#endif

#ifdef CO_LMP_temp_include
    if ((CO_LMP_temp[1] & 0x80) == 0x80)
    { 
        for (i = 0; i <  sizeof(CO_LMP_temp); i++)
        {
            packet_whole[packet_whole_index] = CO_LMP_temp[i];
            packet_whole_index++; 
        }
        CO_LMP_temp[1] = (0 << 7) | LENGTH_FORMAT2;
    }   
#endif

#ifdef three_accel_and_vib_include
    if ((three_accel_and_vib[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(three_accel_and_vib); i++)
        {
            packet_whole[packet_whole_index] = three_accel_and_vib[i];
            packet_whole_index++;
        }
        three_accel_and_vib[1] = (0 << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
#endif

#ifdef three_gyro_and_orientation_include
    if ((three_gyro_and_orientation[1] & 0x80) == 0x80)
    {
        for (i = 0; i <  sizeof(three_gyro_and_orientation); i++)
        {
            packet_whole[packet_whole_index] = three_gyro_and_orientation[i];
            packet_whole_index++;
        }
        three_gyro_and_orientation[1] = (0 << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        
        OIX_packet_count++;
    }
#endif

#endif
    




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
