byte packet_seq_number = 0x00;
int CHECK_LEN = 0;

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
    packet_whole_index = 3; // start at 3 to account for header
    
// #ifdef SERIAL_DEBUG
//     SerialUSB.println("Packing.");
// #endif

#ifdef AIRSENSE_INCLUDE

#ifdef MAC_ID_include    // Append MAC_ID


    // if (MAC_ID[1] > 10)
    // {
        for (buffer_num = 0; buffer_num < sizeof(MAC_ID); buffer_num++)
        {
            packet_whole[packet_whole_index] = MAC_ID[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
    // }
    
    #ifdef SERIAL_DEBUG
    SerialUSB.print("Airsense-");
    for (int a = 2; a < 8; a++)
    {
      if ((MAC_ID[0x09-a] & 0xF0) == 0x00)
      {
            SerialUSB.print("0");           
      }

        SerialUSB.print(MAC_ID[0x09-a],HEX);

        if (a < 7) { SerialUSB.print(":"); }
        else { SerialUSB.println("\r"); }
    }

    SerialUSB.print("Lightsense-");
    for (int a = 2; a < 8; a++)
    {
        if ((MAC_ID[0x09-a] & 0xF0) == 0x00)
      {
            SerialUSB.print("0");           
      }

        SerialUSB.print(MAC_ID[0x09-a],HEX);

        if (a < 7) { SerialUSB.print(":"); }
        else { SerialUSB.println("\r"); }
    }
    #endif

#endif

#ifdef TMP112_include    // Append TMP112
    if (TMP112[1] > 10)
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

#ifdef HTU21D_include    // Append HTU21D
    if(HTU21D[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(HTU21D); buffer_num++)
        {
            packet_whole[packet_whole_index] = HTU21D[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HTU21D[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
#endif


#ifdef BMP180_include    // Append BMP180
    if (BMP180[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(BMP180); buffer_num++)
        {
            packet_whole[packet_whole_index] = BMP180[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        BMP180[1] = (chg_valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    }
#endif

#ifdef PR103J2_include    // Append PR103J2
    if (PR103J2[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(PR103J2); buffer_num++)
        {
            packet_whole[packet_whole_index] = PR103J2[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        PR103J2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL250RD_1_include    // Append TSL250RD_1
    if (TSL250RD_1[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(TSL250RD_1); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL250RD_1[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_1[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef MMA8452Q_include    // Append MMA8452Q
    if (MMA8452Q[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(MMA8452Q); buffer_num++)
        {
            packet_whole[packet_whole_index] = MMA8452Q[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        MMA8452Q[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 4);
    }
#endif

#ifdef SPV1840LR5HB_include    // Append SPV1840LR5HB_2
    if (SPV1840LR5HB[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(SPV1840LR5HB); buffer_num++)  //********************was SPV1840LR5HB_2
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB[buffer_num]; //********************was SPV1840LR5HB_2
            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif
    
#ifdef TSYS01_include    // Append TSYS01
    if (TSYS01[1] > 10)
    {
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
#ifdef HMC5883L_include    // Append HMC5883L
    if (HMC5883L[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(HMC5883L); buffer_num++)
        {
            packet_whole[packet_whole_index] = HMC5883L[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HMC5883L[1] = (chg_valid << 7) | (LENGTH_FORMAT8 * 3);
    }
#endif

#ifdef HIH6130_include    // Append HIH6130
    if (HIH6130[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(HIH6130); buffer_num++)
        {
            packet_whole[packet_whole_index] = HIH6130[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH6130[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 2);
    }
#endif

#ifdef APDS9006020_include    // Append APDS9006020
    if (APDS9006020[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(APDS9006020); buffer_num++)
        {
            packet_whole[packet_whole_index] = APDS9006020[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        APDS9006020[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL260RD_include    // Append TSL260RD
    if (TSL250RD_2[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(TSL260RD); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL260RD[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL260RD[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef TSL250RD_2_include    // Append TSL250RD_2
    if (TSL250RD_2[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(TSL250RD_2); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL250RD_2[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif

#ifdef MLX75305_include    // Append MLX75305
    if (MLX75305[1] > 10)
    {
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
    // Append ML8511
    if (ML8511[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(ML8511); buffer_num++)
        {
            packet_whole[packet_whole_index] = ML8511[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        ML8511[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
#endif

// #ifdef D6T_include    // Append D6T
//     if (D6T[1] > 10)
//     {
//         for (buffer_num = 0; buffer_num < sizeof(D6T); buffer_num++)
//         {
//             packet_whole[packet_whole_index] = D6T[buffer_num];
//             // Increment index for whole packet
//             packet_whole_index++;
//         }
//         D6T[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 17);
//     }
// #endif

// #ifdef MLX90614_include    // Append MLX90614
//     if (MLX90614[1] > 10)
//     {
//         for (buffer_num = 0; buffer_num < sizeof(MLX90614); buffer_num++)
//         {
//             packet_whole[packet_whole_index] = MLX90614[buffer_num];
//             // Increment index for whole packet
//             packet_whole_index++;
//         }
//         MLX90614[1] = (chg_valid << 7) | LENGTH_FORMAT1;
//     }
// #endif

#ifdef TMP421_include    // Append TMP421
    if (TMP421[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(TMP421); buffer_num++)
        {
            packet_whole[packet_whole_index] = TMP421[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP421[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
#endif

#endif

#ifdef CHEMSENSE_INCLUDE

    if (chemsense_MAC_ID[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(chemsense_MAC_ID); buffer_num++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[buffer_num];
            packet_whole_index++;
        }
        chemsense_MAC_ID[1] = (chg_valid << 7) | LENGTH_FORMAT3;
    }

#ifdef SERIAL_DEBUG
        // to check output
        SerialUSB.print("Chemsense-");

        for (j = 0x02; j < 0x08; j++)
        {
            
            if ((chemsense_MAC_ID[0x09-j] & 0xF0) == 0x00)
      {
            SerialUSB.print("0");           
      }
            SerialUSB.print(chemsense_MAC_ID[0x09-j],HEX);
            
            if (j < 0x07) { SerialUSB.print(":"); }
            else { SerialUSB.println("\r"); }
        }
#endif



#ifdef  NOT_A_TEST
    if (SHT25[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(SHT25); buffer_num++)
        {
            packet_whole[packet_whole_index] = SHT25[buffer_num];
            packet_whole_index++;
        }
        SHT25[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);

    }
    
    if (LPS25H[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(LPS25H); buffer_num++)
        {
            packet_whole[packet_whole_index] = LPS25H[buffer_num];
            packet_whole_index++;
        }
        LPS25H[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
    }

    if (Si1145[1] > 10)
    { 
        for (buffer_num = 0; buffer_num <  sizeof(Si1145); buffer_num++)
        {
            packet_whole[packet_whole_index] = Si1145[buffer_num];
            packet_whole_index++;
        }
        Si1145[1] = (chg_valid << 7) | (LENGTH_FORMAT1 * 3);
    }   
    
    if (total_reducing_gases[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(total_reducing_gases); buffer_num++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[buffer_num];
            packet_whole_index++;
        }
        total_reducing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (total_oxidizing_gases[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(total_oxidizing_gases); buffer_num++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[buffer_num];
            packet_whole_index++;
        }
        total_oxidizing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (sulfur_dioxide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(sulfur_dioxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[buffer_num];
            packet_whole_index++;
        }
        sulfur_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (hydrogen_sulphide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(hydrogen_sulphide); buffer_num++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[buffer_num];
            packet_whole_index++;
        }
        hydrogen_sulphide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (ozone[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(ozone); buffer_num++)
        {
            packet_whole[packet_whole_index] = ozone[buffer_num];
            packet_whole_index++;
        }
        ozone[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (nitrogen_dioxide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(nitrogen_dioxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[buffer_num];
            packet_whole_index++;
        }
        nitrogen_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (carbon_monoxide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(carbon_monoxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[buffer_num];
            packet_whole_index++;
        }
        carbon_monoxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (CO_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(CO_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = CO_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        CO_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if (IAQ_IRR_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(IAQ_IRR_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        IAQ_IRR_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if (O3_NO2_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(O3_NO2_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = O3_NO2_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        O3_NO2_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if (SO2_H2S_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(SO2_H2S_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        SO2_H2S_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }

    if (CO_LMP_temp[1] > 10)
    { 
        for (buffer_num = 0; buffer_num <  sizeof(CO_LMP_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = CO_LMP_temp[buffer_num];
            packet_whole_index++;
        }
        CO_LMP_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }   
    
    if (three_accel_and_vib[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(three_accel_and_vib); buffer_num++)
        {
            packet_whole[packet_whole_index] = three_accel_and_vib[buffer_num];
            packet_whole_index++;
        }
        three_accel_and_vib[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
    
    if (three_gyro_and_orientation[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(three_gyro_and_orientation); buffer_num++)
        {
            packet_whole[packet_whole_index] = three_gyro_and_orientation[buffer_num];
            packet_whole_index++;
        }
        three_gyro_and_orientation[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
#endif
    
#endif

    /*

    #ifdef system_health_include
    // Append health
    for (int i = 0; i < sizeof(sensor_health); i++)
    {
        packet_whole[packet_whole_index] = sensor_health[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif*/


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
