int buffer_num = 0;

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
    int chg_valid = 0;
    int packet_whole_index = 3; // start at 3 to account for header

    #ifdef SERIAL_DEBUG
    SerialUSB.println("Packing.");
    #endif

    
    #ifdef MAC_ID_include
    // Append MAC_ID
    for (buffer_num = 0; buffer_num < sizeof(MAC_ID); buffer_num++)
    {
        packet_whole[packet_whole_index] = MAC_ID[buffer_num];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    
#ifdef AIRSENSE_INCLUDE
    #ifdef TMP112_include
    // Append TMP112
    if ((TMP112[1] & 0x80) == 0x80)
    {
        for (buffer_num = 0; buffer_num < sizeof(TMP112); buffer_num++)
        {
            packet_whole[packet_whole_index] = TMP112[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }   
        TMP112[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
    #endif

    #ifdef HTU21D_include
    if ((HTU21D[1] & 0x80) == 0x80)
    {
        // Append HTU21D
        for (buffer_num = 0; buffer_num < sizeof(HTU21D); buffer_num++)
        {
            packet_whole[packet_whole_index] = HTU21D[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        HTU21D[1] = (chg_valid << 7) | LENGTH_FORMAT6 ;
    }
    #endif

    // #ifdef GP2Y1010AU0F_include
    // if (GP2Y1010AU0F[1] > 10)
    // {
    //     // Append GP2Y1010AU0F
    //     for (int i = 0; i < sizeof(GP2Y1010AU0F); i++)
    //     {
    //         packet_whole[packet_whole_index] = GP2Y1010AU0F[i];

    //         // Increment index for whole packet
    //         packet_whole_index++;
    //     }
    //     GP2Y1010AU0F[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    // }
    // #endif

    #ifdef BMP180_include
    if ((BMP180[1] & 0x80) == 0x80)
    {
        // Append BMP180
        for (buffer_num = 0; buffer_num < sizeof(BMP180); buffer_num++)
        {
            packet_whole[packet_whole_index] = BMP180[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        BMP180[1] = (chg_valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    }
    #endif

    #ifdef PR103J2_include
    if ((PR103J2[1] & 0x80) == 0x80)
    {
        // Append PR103J2
        for (buffer_num = 0; buffer_num < sizeof(PR103J2); buffer_num++)
        {
            packet_whole[packet_whole_index] = PR103J2[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        PR103J2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSL250RD_1_include
    if ((TSL250RD_1[1] & 0x80) == 0x80)
    {
        // Append TSL250RD_1
        for (buffer_num = 0; buffer_num < sizeof(TSL250RD_1); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL250RD_1[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_1[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef MMA8452Q_include
    if ((MMA8452Q[1] & 0x80) == 0x80)
    {
        // Append MMA8452Q
        for (buffer_num = 0; buffer_num < sizeof(MMA8452Q); buffer_num++)
        {
            packet_whole[packet_whole_index] = MMA8452Q[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        MMA8452Q[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 4);
    }
    #endif

    #ifdef SPV1840LR5HB_1_include
    if ((SPV1840LR5HB_1[1] & 0x80) == 0x80)
    {
        // Append SPV1840LR5HB_1
        for (buffer_num = 0; buffer_num < sizeof(SPV1840LR5HB_1); buffer_num++)
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB_1[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB_1[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSYS01_include
    if ((TSYS01[1] & 0x80) == 0x80)
    {
        // Append TSYS01
        for (buffer_num = 0; buffer_num < sizeof(TSYS01); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSYS01[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSYS01[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
    #endif

#endif

#ifdef LIGHTSENSE_INCLUDE

    #ifdef HMC5883L_include
    if ((HMC5883L[1] & 0x80) == 0x80)
    {
        // Append HMC5883L
        for (buffer_num = 0; buffer_num < sizeof(HMC5883L); buffer_num++)
        {
            packet_whole[packet_whole_index] = HMC5883L[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        HMC5883L[1] = (chg_valid << 7) | (LENGTH_FORMAT8 * 3);
    }
    #endif

    #ifdef HIH6130_include
    if ((HIH6130[1] & 0x80) == 0x80)
    {
        // Append HIH6130
        for (buffer_num = 0; buffer_num < sizeof(HIH6130); buffer_num++)
        {
            packet_whole[packet_whole_index] = HIH6130[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH6130[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 2);
    }
    #endif

    #ifdef APDS9006020_include
    if ((APDS9006020[1] & 0x80) == 0x80)
    {
        // Append APDS9006020
        for (buffer_num = 0; buffer_num < sizeof(APDS9006020); buffer_num++)
        {
            packet_whole[packet_whole_index] = APDS9006020[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        APDS9006020[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSL260RD_include
    if ((TSL260RD[1] & 0x80) == 0x80)
    {
        // Append TSL260RD
        for (buffer_num = 0; buffer_num < sizeof(TSL260RD); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL260RD[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL260RD[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSL250RD_2_include
    if ((TSL250RD_2[1] & 0x80) == 0x80)
    {
        // Append TSL260RD
        for (buffer_num = 0; buffer_num < sizeof(TSL250RD_2); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL250RD_2[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef MLX75305_include
    if ((MLX75305[1] & 0x80) == 0x80)
    {
        // Append MLX75305
        for (buffer_num = 0; buffer_num < sizeof(MLX75305); buffer_num++)
        {
            packet_whole[packet_whole_index] = MLX75305[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        MLX75305[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef ML8511_include
    if ((ML8511[1] & 0x80) == 0x80)
    {
        // Append ML8511
        for (buffer_num = 0; buffer_num < sizeof(ML8511); buffer_num++)
        {
            packet_whole[packet_whole_index] = ML8511[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        ML8511[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    // #ifdef D6T_include
    // if ((D6T[1] & 0x80) == 0x80)
    // {
    //     // Append D6T
    //     for (buffer_num = 0; buffer_num < sizeof(D6T); buffer_num++)
    //     {
    //         packet_whole[packet_whole_index] = D6T[buffer_num];

    //         // Increment index for whole packet
    //         packet_whole_index++;
    //     }
    //     D6T[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 17);
    // }
    // #endif

    // #ifdef MLX90614_include
    // if ((MLX90614[1] & 0x80) == 0x80)
    // {
    //     // Append MLX90614
    //     for (buffer_num = 0; buffer_num < sizeof(MLX90614); buffer_num++)
    //     {
    //         packet_whole[packet_whole_index] = MLX90614[buffer_num];

    //         // Increment index for whole packet
    //         packet_whole_index++;
    //     }
    //     MLX90614[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    // }
    // #endif

    #ifdef TMP421_include
    if ((TMP421[1] & 0x80) == 0x80)
    {
        // Append TMP421
        for (buffer_num = 0; buffer_num < sizeof(TMP421); buffer_num++)
        {
            packet_whole[packet_whole_index] = TMP421[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP421[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
    #endif

    #ifdef SPV1840LR5HB_2_include
    if ((SPV1840LR5HB_2[1] & 0x80) == 0x80)
    {
        // Append SPV1840LR5HB_2
        for (buffer_num = 0; buffer_num < sizeof(SPV1840LR5HB_2); buffer_num++)
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB_2[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB_2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

#endif

#ifdef CHEMSENSE_INCLUDE
    bool chem = false;
    
    if ((chemsense_MAC_ID[1] & 0x80) == 0x80)
    {
        chem = true;
        for (buffer_num = 0; buffer_num < sizeof(chemsense_MAC_ID); buffer_num++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[buffer_num];
            packet_whole_index++;
        }
        chemsense_MAC_ID[1] = (chg_valid << 7) | LENGTH_FORMAT3;
    }

    if ((SHT25[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(SHT25); buffer_num++)
        {
            packet_whole[packet_whole_index] = SHT25[buffer_num];
            packet_whole_index++;
        }
        SHT25[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);

    }
    
    if ((LPS25H[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(LPS25H); buffer_num++)
        {
            packet_whole[packet_whole_index] = LPS25H[buffer_num];
            packet_whole_index++;
        }
        LPS25H[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
    }

    if ((Si1145[1] & 0x80) == 0x80 && chem == true)
    { 
        for (buffer_num = 0; buffer_num <  sizeof(Si1145); buffer_num++)
        {
            packet_whole[packet_whole_index] = Si1145[buffer_num];
            packet_whole_index++;
        }
        Si1145[1] = (chg_valid << 7) | (LENGTH_FORMAT1 * 3);
    }   
    
    if ((total_reducing_gases[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(total_reducing_gases); buffer_num++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[buffer_num];
            packet_whole_index++;
        }
        total_reducing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((total_oxidizing_gases[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(total_oxidizing_gases); buffer_num++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[buffer_num];
            packet_whole_index++;
        }
        total_oxidizing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((sulfur_dioxide[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(sulfur_dioxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[buffer_num];
            packet_whole_index++;
        }
        sulfur_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((hydrogen_sulphide[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(hydrogen_sulphide); buffer_num++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[buffer_num];
            packet_whole_index++;
        }
        hydrogen_sulphide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((ozone[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(ozone); buffer_num++)
        {
            packet_whole[packet_whole_index] = ozone[buffer_num];
            packet_whole_index++;
        }
        ozone[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((nitrogen_dioxide[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(nitrogen_dioxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[buffer_num];
            packet_whole_index++;
        }
        nitrogen_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((carbon_monoxide[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(carbon_monoxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[buffer_num];
            packet_whole_index++;
        }
        carbon_monoxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if ((CO_ADC_temp[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(CO_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = CO_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        CO_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if ((IAQ_IRR_ADC_temp[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(IAQ_IRR_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        IAQ_IRR_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if ((O3_NO2_ADC_temp[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(O3_NO2_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = O3_NO2_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        O3_NO2_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if ((SO2_H2S_ADC_temp[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(SO2_H2S_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        SO2_H2S_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }

    if ((CO_LMP_temp[1] & 0x80) == 0x80 && chem == true)
    { 
        for (buffer_num = 0; buffer_num <  sizeof(CO_LMP_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = CO_LMP_temp[buffer_num];
            packet_whole_index++;
        }
        CO_LMP_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }   
    
    if ((three_accel_and_vib[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(three_accel_and_vib); buffer_num++)
        {
            packet_whole[packet_whole_index] = three_accel_and_vib[buffer_num];
            packet_whole_index++;
        }
        three_accel_and_vib[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
    
    if ((three_gyro_and_orientation[1] & 0x80) == 0x80 && chem == true)
    {
        for (buffer_num = 0; buffer_num <  sizeof(three_gyro_and_orientation); buffer_num++)
        {
            packet_whole[packet_whole_index] = three_gyro_and_orientation[buffer_num];
            packet_whole_index++;
        }
        three_gyro_and_orientation[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
#endif


    // #ifdef system_health_include
    // // Append health
    // for (buffer_num = 0; buffer_num < sizeof(sensor_health); buffer_num++)
    // {
    //     packet_whole[packet_whole_index] = sensor_health[buffer_num];
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

    #ifdef SERIAL_DEBUG
    SerialUSB.println(packet_whole_index,DEC);
    #endif
}
/**************************************************************************************/
