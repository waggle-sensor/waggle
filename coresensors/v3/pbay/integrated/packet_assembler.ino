byte packet_seq_number = 0x00;

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
    
#ifdef SERIAL_DEBUG
    SerialUSB.println("Packing.");
#endif

#ifdef AIRSENSE_INCLUDE
#ifdef MAC_ID_include    // Append MAC_ID
    for (int i = 0; i < sizeof(MAC_ID); i++)
    {
        packet_whole[packet_whole_index] = MAC_ID[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    MAC_ID[1] = (chg_valid << 7) | (LENGTH_FORMAT3);
#endif

#ifdef TMP112_include    // Append TMP112
    for (int i = 0; i < sizeof(TMP112); i++)
    {
        packet_whole[packet_whole_index] = TMP112[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    TMP112[1] = (chg_valid << 7) | (LENGTH_FORMAT6);
#endif

#ifdef HTU21D_include    // Append HTU21D
    for (int i = 0; i < sizeof(HTU21D); i++)
    {
        packet_whole[packet_whole_index] = HTU21D[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    HTU21D[1] = (chg_valid << 7) | ((LENGTH_FORMAT6 * 2));
#endif

// ************************************************************************ does not exist byte array in integrated.ino
#ifdef GP2Y1010AU0F_include    // Append GP2Y1010AU0F
    for (int i = 0; i < sizeof(GP2Y1010AU0F); i++)
    {
        packet_whole[packet_whole_index] = GP2Y1010AU0F[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    GP2Y1010AU0F[1] = (chg_valid << 7) | 0;
#endif

#ifdef SPV1840LR5HB_1_include    // Append SPV1840LR5HB_1
    for (int i = 0; i < sizeof(SPV1840LR5HB_1); i++)
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB_1[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    SPV1840LR5HB_1[1] = (chg_valid << 7) | 0;
#endif
// ************************************************************************ does not exist byte array in integrated.ino

#ifdef BMP180_include    // Append BMP180
    for (int i = 0; i < sizeof(BMP180); i++)
    {
        packet_whole[packet_whole_index] = BMP180[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    BMP180[1] = (chg_valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
#endif

#ifdef PR103J2_include    // Append PR103J2
    for (int i = 0; i < sizeof(PR103J2); i++)
    {
        packet_whole[packet_whole_index] = PR103J2[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    PR103J2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef TSL250RD_1_include    // Append TSL250RD_1
    for (int i = 0; i < sizeof(TSL250RD_1); i++)
    {
        packet_whole[packet_whole_index] = TSL250RD_1[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    TSL250RD_1[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef MMA8452Q_include    // Append MMA8452Q
    for (int i = 0; i < sizeof(MMA8452Q); i++)
    {
        packet_whole[packet_whole_index] = MMA8452Q[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    MMA8452Q[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 4);
#endif

#ifdef TSYS01_include    // Append TSYS01
    for (int i = 0; i < sizeof(TSYS01); i++)
    {
        packet_whole[packet_whole_index] = TSYS01[i];
        // Increment index for whole packet
        packet_whole_index++;
    TSYS01[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
#endif
#endif

#ifdef LIGHTSENSE_INCLUDE
#ifdef HMC5883L_include    // Append HMC5883L
    for (int i = 0; i < sizeof(HMC5883L); i++)
    {
        packet_whole[packet_whole_index] = HMC5883L[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    HMC5883L[1] = (chg_valid << 7) | (LENGTH_FORMAT8 * 3);
#endif

#ifdef HIH6130_include    // Append HIH6130
    for (int i = 0; i < sizeof(HIH6130); i++)
    {
        packet_whole[packet_whole_index] = HIH6130[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    HIH6130[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 2);
#endif

#ifdef APDS9006020_include    // Append APDS9006020
    for (int i = 0; i < sizeof(APDS9006020); i++)
    {
        packet_whole[packet_whole_index] = APDS9006020[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    APDS9006020[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef TSL260RD_include    // Append TSL260RD
    for (int i = 0; i < sizeof(TSL260RD); i++)
    {
        packet_whole[packet_whole_index] = TSL260RD[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    TSL260RD[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef TSL250RD_2_include    // Append TSL250RD_2
    for (int i = 0; i < sizeof(TSL250RD_2); i++)
    {
        packet_whole[packet_whole_index] = TSL250RD_2[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    TSL250RD_2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef MLX75305_include    // Append MLX75305
    for (int i = 0; i < sizeof(MLX75305); i++)
    {
        packet_whole[packet_whole_index] = MLX75305[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    MLX75305[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef ML8511_include
    // Append ML8511
    for (int i = 0; i < sizeof(ML8511); i++)
    {
        packet_whole[packet_whole_index] = ML8511[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    ML8511[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef D6T_include    // Append D6T
    for (int i = 0; i < sizeof(D6T); i++)
    {
        packet_whole[packet_whole_index] = D6T[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    D6T[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 17);
#endif

#ifdef MLX90614_include    // Append MLX90614
    for (int i = 0; i < sizeof(MLX90614); i++)
    {
        packet_whole[packet_whole_index] = MLX90614[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    MLX90614[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif

#ifdef TMP421_include    // Append TMP421
    for (int i = 0; i < sizeof(TMP421); i++)
    {
        packet_whole[packet_whole_index] = TMP421[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    TMP421[1] = (chg_valid << 7) | LENGTH_FORMAT6;
#endif

#ifdef SPV1840LR5HB_2_include    // Append SPV1840LR5HB_2
    for (int i = 0; i < sizeof(SPV1840LR5HB_2); i++)
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB_2[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    SPV1840LR5HB[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif
#endif

#ifdef CHEMSENSE_INCLUDE
#ifdef chemsense_MAC_ID_include
    for (int i = 0; i < sizeof(chemsense_MAC_ID); i++)
    {
        packet_whole[packet_whole_index] = chemsense_MAC_ID[i];
        packet_whole_index++;
    }
#endif

#ifdef SHT25_include
    for (int i = 0; i < sizeof(SHT25); i++)
    {
        packet_whole[packet_whole_index] = SHT25[i];
        packet_whole_index++;
    }
#endif

#ifdef LPS25H_include
    for (int i = 0; i < sizeof(LPS25H); i++)
    {
        packet_whole[packet_whole_index] = LPS25H[i];
        packet_whole_index++;
    }
#endif

#ifdef Si1145_include
    for (int i = 0; i < sizeof(Si1145); i++)
    {
        packet_whole[packet_whole_index] = Si1145[i];
        packet_whole_index++;
    }
#endif

#ifdef total_reducing_gases_include
    for (int i = 0; i < sizeof(total_reducing_gases); i++)
    {
        packet_whole[packet_whole_index] = total_reducing_gases[i];
        packet_whole_index++;
    }
#endif

#ifdef total_oxidizing_gases_include
    for (int i = 0; i < sizeof(total_oxidizing_gases); i++)
    {
        packet_whole[packet_whole_index] = total_oxidizing_gases[i];
        packet_whole_index++;
    }
#endif

#ifdef sulfur_dioxide_include
    for (int i = 0; i < sizeof(sulfur_dioxide); i++)
    {
        packet_whole[packet_whole_index] = sulfur_dioxide[i];
        packet_whole_index++;
    }
#endif

#ifdef hydrogen_sulphide_include
    for (int i = 0; i < sizeof(hydrogen_sulphide); i++)
    {
        packet_whole[packet_whole_index] = hydrogen_sulphide[i];
        packet_whole_index++;
    }
#endif

#ifdef ozone_include
    for (int i = 0; i < sizeof(ozone); i++)
    {
        packet_whole[packet_whole_index] = ozone[i];
        packet_whole_index++;
    }
#endif

#ifdef nitrogen_dioxide_include
    for (int i = 0; i < sizeof(nitrogen_dioxide); i++)
    {
        packet_whole[packet_whole_index] = nitrogen_dioxide[i];
        packet_whole_index++;
    }
#endif

#ifdef carbon_monoxide_include
    for (int i = 0; i < sizeof(carbon_monoxide); i++)
    {
        packet_whole[packet_whole_index] = carbon_monoxide[i];
        packet_whole_index++;
    }
#endif

#ifdef CO_ADC_temp_include
    for (int i = 0; i < sizeof(CO_ADC_temp); i++)
    {
        packet_whole[packet_whole_index] = CO_ADC_temp[i];
        packet_whole_index++;
    }
#endif

#ifdef IAQ_IRR_ADC_temp_include
    for (int i = 0; i < sizeof(IAQ_IRR_ADC_temp); i++)
    {
        packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[i];
        packet_whole_index++;
    }
#endif

#ifdef O3_NO2_ADC_temp_include
    for (int i = 0; i < sizeof(O3_NO2_ADC_temp); i++)
    {
        packet_whole[packet_whole_index] = O3_NO2_ADC_temp[i];
        packet_whole_index++;
    }
#endif

#ifdef SO2_H2S_ADC_temp_include
    for (int i = 0; i < sizeof(SO2_H2S_ADC_temp); i++)
    {
        packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[i];
        packet_whole_index++;
    }
#endif

#ifdef CO_LMP_temp_include
    for (int i = 0; i < sizeof(CO_LMP_temp); i++)
    {
        packet_whole[packet_whole_index] = CO_LMP_temp[i];
        packet_whole_index++;
    }
#endif

#ifdef three_accel_and_vib_include
    for (int i = 0; i < sizeof(three_accel_and_vib); i++)
    {
        packet_whole[packet_whole_index] = three_accel_and_vib[i];
        packet_whole_index++;
    }
#endif

#ifdef three_gyro_and_orientation_include
    for (int i = 0; i < sizeof(three_gyro_and_orientation); i++)
    {
        packet_whole[packet_whole_index] = three_gyro_and_orientation[i];
        packet_whole_index++;
    }
#endif
#endif
//     SerialUSB.write("\r\n\t");
//     SerialUSB.write(chemsense_MAC_ID, sizeof(chemsense_MAC_ID));
//     SerialUSB.write(SHT25, sizeof(SHT25));
//     SerialUSB.write(LPS25H, sizeof(LPS25H));
//     SerialUSB.write(Si1145, sizeof(Si1145));
//     
//     SerialUSB.write(total_reducing_gases, sizeof(total_reducing_gases));
//     SerialUSB.write(total_oxidizing_gases, sizeof(total_oxidizing_gases));
//     SerialUSB.write(sulfur_dioxide, sizeof(sulfur_dioxide));
//     SerialUSB.write(hydrogen_sulphide, sizeof(hydrogen_sulphide));
//     SerialUSB.write(ozone, sizeof(ozone));
//     SerialUSB.write(nitrogen_dioxide, sizeof(nitrogen_dioxide));
//     SerialUSB.write(carbon_monoxide, sizeof(carbon_monoxide));
//     
//     SerialUSB.write(CO_ADC_temp, sizeof(CO_ADC_temp));
//     SerialUSB.write(IAQ_IRR_ADC_temp, sizeof(IAQ_IRR_ADC_temp));
//     SerialUSB.write(O3_NO2_ADC_temp, sizeof(O3_NO2_ADC_temp));
//     SerialUSB.write(SO2_H2S_ADC_temp, sizeof(SO2_H2S_ADC_temp));
//     SerialUSB.write(CO_LMP_temp, sizeof(CO_LMP_temp));
//     
//     SerialUSB.write(three_accel_and_vib, sizeof(three_accel_and_vib));
//     SerialUSB.write(three_gyro_and_orientation, sizeof(three_gyro_and_orientation));
//     SerialUSB.print("\n");
    
//     chemsense_MAC_ID[1] = (chg_valid << 7) | LENGTH_FORMAT3;
// 
//     SHT25[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
//     LPS25H[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
//     Si1145[1] = (chg_valid << 7) | (LENGTH_FORMAT1 * 3);
// 
//     total_reducing_gases[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
//     total_oxidizing_gases[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
//     sulfur_dioxide[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
//     hydrogen_sulphide[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
//     ozone[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
//     nitrogen_dioxide[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
//     carbon_monoxide[1] = (chg_valid << 7) | (LENGTH_FORMAT5);
// 
//     CO_ADC_temp[1] = (chg_valid << 7) | (LENGTH_FORMAT2);
//     IAQ_IRR_ADC_temp[1] = (chg_valid << 7) | (LENGTH_FORMAT2);
//     O3_NO2_ADC_temp[1] = (chg_valid << 7) | (LENGTH_FORMAT2);
//     SO2_H2S_ADC_temp[1] = (chg_valid << 7) | (LENGTH_FORMAT2);
//     CO_LMP_temp[1] = (chg_valid << 7) | (LENGTH_FORMAT2);
// 
//     three_accel_and_vib[1] = (chg_valid << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
//     three_gyro_and_orientation[1] = (chg_valid << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);

    
/*
    if (ChemSensed == 1)
    {

        #ifdef total_reducing_gases_include
        // Append total_reducing_gases
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("ToR");
        #endif
        for (int i = 0; i < sizeof(total_reducing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[i];
            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif


        #ifdef ethanol_include
        // Append ethanol
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("ETOH");
        #endif
        for (int i = 0; i < sizeof(ethanol); i++)
        {
            packet_whole[packet_whole_index] = ethanol[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef nitrogen_dioxide_include

        // Append nitrogen_dioxide
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("NO2");
        #endif
        for (int i = 0; i < sizeof(nitrogen_dioxide); i++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef ozone_include

        // Append ozone
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("OZONE");
        #endif
        for (int i = 0; i < sizeof(ozone); i++)
        {
            packet_whole[packet_whole_index] = ozone[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef hydrogen_sulphide_include

        // Append hydrogen_sulphide
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("H2S");
        #endif
        for (int i = 0; i < sizeof(hydrogen_sulphide); i++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef total_oxidizing_gases_include

        // Append total_oxidizing_gases
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("ToX");
        #endif
        for (int i = 0; i < sizeof(total_oxidizing_gases); i++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef carbon_monoxide_include

        // Append carbon_monoxide
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("CO");
        #endif
        for (int i = 0; i < sizeof(carbon_monoxide); i++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef sulfur_dioxide_include

        // Append sulfur_dioxide
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("SO2");
        #endif
        for (int i = 0; i < sizeof(sulfur_dioxide); i++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[i];

            // Increment index for whole packet
            packet_whole_index++;
        }

        #endif
        #ifdef SHT25_include
        // Append sensirion
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("SHT25");
        #endif
        for (int i = 0; i < sizeof(SHT25); i++)
        {
            packet_whole[packet_whole_index] = SHT25[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif
        #ifdef LPS25H_include

        // Append LPS25H
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("LPS25H");
        #endif
        for (int i = 0; i < sizeof(LPS25H); i++)
        {
            packet_whole[packet_whole_index] = LPS25H[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif

        #ifdef Si1145_include

        // Append Si1145
        #ifdef SERIAL_DEBUG
        //SerialUSB.println("Si1145");
        #endif
        for (int i = 0; i < sizeof(Si1145); i++)
        {
            packet_whole[packet_whole_index] = Si1145[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif

        #ifdef chemsense_MAC_ID_include

        // Append chemsense_MAC_ID
        for (int i = 0; i < sizeof(chemsense_MAC_ID); i++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[i];

            // Increment index for whole packet
            packet_whole_index++;
        }
        #endif

    }

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

    #ifdef SERIAL_DEBUG
    SerialUSB.println(packet_whole_index, DEC);
    #endif
}
/**************************************************************************************/
