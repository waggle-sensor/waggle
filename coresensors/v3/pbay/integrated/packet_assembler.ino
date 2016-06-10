byte packet_seq_number = 0x00;
int CHECK_LEN = 0;

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
// #ifdef GP2Y1010AU0F_include    // Append GP2Y1010AU0F
//     for (int i = 0; i < sizeof(GP2Y1010AU0F); i++)
//     {
//         packet_whole[packet_whole_index] = GP2Y1010AU0F[i];
//         // Increment index for whole packet
//         packet_whole_index++;
//     }
//     GP2Y1010AU0F[1] = (chg_valid << 7) | 0;
// #endif
// 
// #ifdef SPV1840LR5HB_1_include    // Append SPV1840LR5HB_1
//     for (int i = 0; i < sizeof(SPV1840LR5HB_1); i++)
//     {
//         packet_whole[packet_whole_index] = SPV1840LR5HB_1[i];
//         // Increment index for whole packet
//         packet_whole_index++;
//     }
//     SPV1840LR5HB_1[1] = (chg_valid << 7) | 0;
// #endif
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

#ifdef SPV1840LR5HB_include    // Append SPV1840LR5HB_2
    for (int i = 0; i < sizeof(SPV1840LR5HB); i++)  //********************was SPV1840LR5HB_2
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB[i]; //********************was SPV1840LR5HB_2
        // Increment index for whole packet
        packet_whole_index++;
    }
    SPV1840LR5HB[1] = (chg_valid << 7) | LENGTH_FORMAT1;
#endif
#endif

#ifdef CHEMSENSE_INCLUDE
    
#ifdef chemsense_MAC_ID_include
    CHECK_LEN = chemsense_MAC_ID[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = chemsense_MAC_ID[i];
        packet_whole_index++;
    }
    chemsense_MAC_ID[1] = (chg_valid << 7) | LENGTH_FORMAT3;
#endif

#ifdef SHT25_include
    CHECK_LEN = SHT25[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = SHT25[i];
        packet_whole_index++;
    }
    SHT25[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
#endif

#ifdef LPS25H_include
    CHECK_LEN = LPS25H[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = LPS25H[i];
        packet_whole_index++;
    }
    LPS25H[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
#endif

#ifdef Si1145_include
    CHECK_LEN = Si1145[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = Si1145[i];
        packet_whole_index++;
    }
    Si1145[1] = (chg_valid << 7) | (LENGTH_FORMAT1 * 3);
#endif

#ifdef total_reducing_gases_include
    CHECK_LEN = total_reducing_gases[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = total_reducing_gases[i];
        packet_whole_index++;
    }
    total_reducing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef total_oxidizing_gases_include
    CHECK_LEN = total_oxidizing_gases[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = total_oxidizing_gases[i];
        packet_whole_index++;
    }
    total_oxidizing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef sulfur_dioxide_include
    CHECK_LEN = sulfur_dioxide[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = sulfur_dioxide[i];
        packet_whole_index++;
    }
    sulfur_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef hydrogen_sulphide_include
    CHECK_LEN = hydrogen_sulphide[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = hydrogen_sulphide[i];
        packet_whole_index++;
    }
    hydrogen_sulphide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef ozone_include
    CHECK_LEN = ozone[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = ozone[i];
        packet_whole_index++;
    }
    ozone[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef nitrogen_dioxide_include
    CHECK_LEN = nitrogen_dioxide[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = nitrogen_dioxide[i];
        packet_whole_index++;
    }
    nitrogen_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef carbon_monoxide_include
    CHECK_LEN = carbon_monoxide[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = carbon_monoxide[i];
        packet_whole_index++;
    }
    carbon_monoxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
#endif

#ifdef CO_ADC_temp_include
    CHECK_LEN = CO_ADC_temp[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = CO_ADC_temp[i];
        packet_whole_index++;
    }
    CO_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
#endif

#ifdef IAQ_IRR_ADC_temp_include
    CHECK_LEN = IAQ_IRR_ADC_temp[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[i];
        packet_whole_index++;
    }
    IAQ_IRR_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
#endif

#ifdef O3_NO2_ADC_temp_include
    CHECK_LEN = O3_NO2_ADC_temp[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = O3_NO2_ADC_temp[i];
        packet_whole_index++;
    }
    O3_NO2_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
#endif

#ifdef SO2_H2S_ADC_temp_include
    CHECK_LEN = SO2_H2S_ADC_temp[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[i];
        packet_whole_index++;
    }
    SO2_H2S_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
#endif

#ifdef CO_LMP_temp_include
    CHECK_LEN = CO_LMP_temp[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = CO_LMP_temp[i];
        packet_whole_index++;
    }
    CO_LMP_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
#endif

#ifdef three_accel_and_vib_include
    CHECK_LEN = three_accel_and_vib[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = three_accel_and_vib[i];
        packet_whole_index++;
    }
    three_accel_and_vib[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
#endif

#ifdef three_gyro_and_orientation_include
    CHECK_LEN = three_gyro_and_orientation[1] & 0x7F;
    CHECK_LEN += 2;
    for (int i = 0; i < CHECK_LEN; i++)
    {
        packet_whole[packet_whole_index] = three_gyro_and_orientation[i];
        packet_whole_index++;
    }
    three_gyro_and_orientation[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
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
