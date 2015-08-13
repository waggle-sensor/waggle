/** Assemble empty packet *************************************************************/
void assemble_packet_empty()
{
    packet_whole[0x02]= 0x00;
    packet_whole[LENGTH_WHOLE-2] = 0x00;
}
/**************************************************************************************/


/** Assemble whole packet *************************************************************/
void assemble_packet_whole()
{
    int packet_whole_index = 3; // start at 3 to account for header
//     #ifdef SERIAL_DEBUG SerialUSB.println("Packer Called.");
    #ifdef MAC_ID_include
    // Append MAC_ID
    for (int i = 0; i < sizeof(MAC_ID); i++)
    {
        packet_whole[packet_whole_index] = MAC_ID[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef TMP112_include

    // Append TMP112
    for (int i = 0; i < sizeof(TMP112); i++)
    {
        packet_whole[packet_whole_index] = TMP112[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef HTU21D_include

    // Append HTU21D
    for (int i = 0; i < sizeof(HTU21D); i++)
    {
        packet_whole[packet_whole_index] = HTU21D[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef GP2Y1010AU0F_include

    // Append GP2Y1010AU0F
    for (int i = 0; i < sizeof(GP2Y1010AU0F); i++)
    {
        packet_whole[packet_whole_index] = GP2Y1010AU0F[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef BMP180_include


    // Append BMP180
    for (int i = 0; i < sizeof(BMP180); i++)
    {
        packet_whole[packet_whole_index] = BMP180[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef PR103J2_include

    // Append PR103J2
    for (int i = 0; i < sizeof(PR103J2); i++)
    {
        packet_whole[packet_whole_index] = PR103J2[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef TSL250RD_1_include

    // Append TSL250RD_1
    for (int i = 0; i < sizeof(TSL250RD_1); i++)
    {
        packet_whole[packet_whole_index] = TSL250RD_1[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef MMA8452Q_include

    // Append MMA8452Q
    for (int i = 0; i < sizeof(MMA8452Q); i++)
    {
        packet_whole[packet_whole_index] = MMA8452Q[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef SPV1840LR5HB_1_include

    // Append SPV1840LR5HB_1
    for (int i = 0; i < sizeof(SPV1840LR5HB_1); i++)
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB_1[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef TSYS01_include

    // Append TSYS01
    for (int i = 0; i < sizeof(TSYS01); i++)
    {
        packet_whole[packet_whole_index] = TSYS01[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef HMC5883L_include

    // Append HMC5883L
    for (int i = 0; i < sizeof(HMC5883L); i++)
    {
        packet_whole[packet_whole_index] = HMC5883L[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef HIH6130_include

    // Append HIH6130
    for (int i = 0; i < sizeof(HIH6130); i++)
    {
        packet_whole[packet_whole_index] = HIH6130[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef APDS9006020_include

    // Append APDS9006020
    for (int i = 0; i < sizeof(APDS9006020); i++)
    {
        packet_whole[packet_whole_index] = APDS9006020[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef TSL260RD_include

    // Append TSL260RD
    for (int i = 0; i < sizeof(TSL260RD); i++)
    {
        packet_whole[packet_whole_index] = TSL260RD[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef TSL250RD_2_include

    // Append TSL250RD_2
    for (int i = 0; i < sizeof(TSL250RD_2); i++)
    {
        packet_whole[packet_whole_index] = TSL250RD_2[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef MLX75305_include

    // Append MLX75305
    for (int i = 0; i < sizeof(MLX75305); i++)
    {
        packet_whole[packet_whole_index] = MLX75305[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef ML8511_include

    // Append ML8511
    for (int i = 0; i < sizeof(ML8511); i++)
    {
        packet_whole[packet_whole_index] = ML8511[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef D6T_include

    // Append D6T
    for (int i = 0; i < sizeof(D6T); i++)
    {
        packet_whole[packet_whole_index] = D6T[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef MLX90614_include

    // Append MLX90614
    for (int i = 0; i < sizeof(MLX90614); i++)
    {
        packet_whole[packet_whole_index] = MLX90614[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef TMP421_include

    // Append TMP421
    for (int i = 0; i < sizeof(TMP421); i++)
    {
        packet_whole[packet_whole_index] = TMP421[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    #ifdef SPV1840LR5HB_2_include

    // Append SPV1840LR5HB_2
    for (int i = 0; i < sizeof(SPV1840LR5HB_2); i++)
    {
        packet_whole[packet_whole_index] = SPV1840LR5HB_2[i];

        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif


    #ifdef total_reducing_gases_include
    // Append total_reducing_gases
    #ifdef SERIAL_DEBUG
    SerialUSB.println("ToR");
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
    SerialUSB.println("ETOH");
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
    SerialUSB.println("NO2");
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
    SerialUSB.println("OZONE");
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
    SerialUSB.println("H2S");
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
    SerialUSB.println("ToX");
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
    SerialUSB.println("CO");
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
    SerialUSB.println("SO2");
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
    SerialUSB.println("SHT25");
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
    SerialUSB.println("LPS25H");
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
    SerialUSB.println("Si1145");
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
    #ifdef system_health_include
    // Append health
    for (int i = 0; i < sizeof(sensor_health); i++)
    {
        packet_whole[packet_whole_index] = sensor_health[i];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    // Length
    packet_whole[2] = packet_whole_index - 0x03;
    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = END_BYTE;
}
/**************************************************************************************/
