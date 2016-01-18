
/** Generate fake sensor data *********************************************************/
void generate_data()
{
    byte valid;
    byte integer1, integer2, integer3;
    int fractional;
    byte neg;
    int value_i;
    float value_f;
    long value_l;
    int valid_index = 0;


    #ifdef MAC_ID_include
    // MAC address (format 3)
    valid = 1; // always valid
    // Store validity in temp array
    MAC_ID[0] = ID_MAC; // ID
    MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
    MAC_ID[2] = 0x06;
    MAC_ID[3] = 0x05;
    MAC_ID[4] = 0x04;
    MAC_ID[5] = 0x03;
    MAC_ID[6] = 0x02;
    MAC_ID[7] = 0x01;
    #ifdef SERIAL_DEBUG
    Serial.print("MAC ID: ");
    for (int i = 2; i < (LENGTH_FORMAT3 + 2); i++)
      Serial.print(MAC_ID[i], HEX);
    Serial.println("");
    #endif
    #endif

    #ifdef TMP112_include
    // Temp (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional * 0.01);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    TMP112[0] = ID_TMP112;
    TMP112[1] = (valid << 7) | LENGTH_FORMAT1;
    TMP112[2] = packet_format1[0];
    TMP112[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("TMP112: ");
    Serial.println(value_f);
    Serial.print("TMP112: ");
    Serial.print(TMP112[2]);
    Serial.print(" ");
    Serial.println(TMP112[3]);
    #endif
    #endif

    #ifdef HTU21D_include
    // Temp (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    HTU21D[0] = ID_HTU21D;
    HTU21D[1] = (valid << 7) | (LENGTH_FORMAT1 * 2);
    HTU21D[2] = packet_format1[0];
    HTU21D[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HTU21D temp: ");
    Serial.println(value_f);
    #endif

    // RH (format 1)
    integer1 = random(0, 101); // percentage
    fractional = random(0, 100);
    value_f = integer1 + ((float)fractional / 100);
    format1(value_f);  // Put it into format 1
    HTU21D[4] = packet_format1[0];
    HTU21D[5] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HTU21D RH: ");
    Serial.println(value_f);
    #endif
    #endif

    #ifdef GP2Y1010AU0F_include
    // Dust density (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    GP2Y1010AU0F[0] = ID_GP2Y1010AU0F;
    GP2Y1010AU0F[1] = (valid << 7) | LENGTH_FORMAT2;
    GP2Y1010AU0F[2] = packet_format2[0];
    GP2Y1010AU0F[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("GP2Y1010AU0F: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef BMP180_include
    // Temp (format 1)
    #ifdef RANDOMIZE_VALID

    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    BMP180[0] = ID_BMP180;
    BMP180[1] = (valid << 7) | (LENGTH_FORMAT1 + LENGTH_FORMAT6);
    BMP180[2] = packet_format1[0];
    BMP180[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("BMP180 temp: ");
    Serial.println(value_f);
    #endif

    // Atmospheric pressure (format 6)
    integer1 = random(0, 64);
    integer2 = random(0, 256);
    integer3 = random(0, 256);
    value_l = integer1;
    value_l = value_l << 8;
    value_l = value_l + integer2;
    value_l = value_l << 8;
    value_l = value_l + integer3;
    neg = random(0, 2);
    if (neg)
        value_l *= -1;
    format6(value_l);
    BMP180[4] = packet_format6[0];
    BMP180[5] = packet_format6[1];
    BMP180[6] = packet_format6[2];
    #ifdef SERIAL_DEBUG
    Serial.print("BMP180 pressure: ");
    Serial.println(value_l);
    #endif
    #endif

    #ifdef PR103J2_include
    // Light (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    PR103J2[0] = ID_PR103J2;
    PR103J2[1] = (valid << 7) | LENGTH_FORMAT2;
    PR103J2[2] = packet_format2[0];
    PR103J2[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("PR103J2: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef TSL250RD_1_include
    // Light (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    TSL250RD_1[0] = ID_TSL250RD_1;
    TSL250RD_1[1] = (valid << 7) | LENGTH_FORMAT2;
    TSL250RD_1[2] = packet_format2[0];
    TSL250RD_1[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("TSL250RD: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef MMA8452Q_include
    // Accel_x (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    MMA8452Q[0] = ID_MMA8452Q;
    MMA8452Q[1] = (valid << 7) | (LENGTH_FORMAT1 * 4);
    MMA8452Q[2] = packet_format1[0];
    MMA8452Q[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("MMA8452Q x: ");
    Serial.println(value_f);
    #endif

    // Accel_y (format 1)
    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    MMA8452Q[4] = packet_format1[0];
    MMA8452Q[5] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("MMA8452Q y: ");
    Serial.println(value_f);
    #endif

    // Accel_x (format 1)
    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    MMA8452Q[6] = packet_format1[0];
    MMA8452Q[7] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("MMA8452Q z: ");
    Serial.println(value_f);
    #endif

    // Accel RMS (format 1)
    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    MMA8452Q[8] = packet_format1[0];
    MMA8452Q[9] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("MMA8452Q rms: ");
    Serial.println(value_f);
    #endif
    #endif

    #ifdef SPV1840LR5HB_1_include
    // Sound pressure (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    SPV1840LR5HB_1[0] = ID_SPV1840LR5HB_1;
    SPV1840LR5HB_1[1] = (valid << 7) | LENGTH_FORMAT2;
    SPV1840LR5HB_1[2] = packet_format2[0];
    SPV1840LR5HB_1[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("SPV1840LR5HB: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef TSYS01_include
    // Temp (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    TSYS01[0] = ID_TSYS01;
    TSYS01[1] = (valid << 7) | LENGTH_FORMAT2;
    TSYS01[2] = packet_format2[0];
    TSYS01[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("TSYS01: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef HMC5883L_include
    // Magnetic field strength x (format 4)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 8);
    fractional = random(0, 1000);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 1000);
    if (neg)
        value_f *= -1;
    format4(value_f);  // Put it into format 4
    HMC5883L[0] = ID_HMC5883L;
    HMC5883L[1] = (valid << 7) | (LENGTH_FORMAT4 * 3);
    HMC5883L[2] = packet_format4[0];
    HMC5883L[3] = packet_format4[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HMC5883L x: ");
    Serial.println(value_f, 3);
    #endif

    // Magnetic field strength y (format 4)
    integer1 = random(0, 8);
    fractional = random(0, 1000);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 1000);
    if (neg)
        value_f *= -1;
    format4(value_f);  // Put it into format 4
    HMC5883L[4] = packet_format4[0];
    HMC5883L[5] = packet_format4[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HMC5883L y: ");
    Serial.println(value_f, 3);
    #endif

    // Magnetic field strength z (format 4)
    integer1 = random(0, 8);
    fractional = random(0, 1000);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 1000);
    if (neg)
        value_f *= -1;
    format4(value_f);  // Put it into format 4
    HMC5883L[6] = packet_format4[0];
    HMC5883L[7] = packet_format4[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HMC5883L z: ");
    Serial.println(value_f, 3);
    #endif
    #endif

    #ifdef HIH6130_include
    //     // Temp inside transparent box (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    HIH6130[0] = ID_HIH6130;
    HIH6130[1] = (valid << 7) | (LENGTH_FORMAT1 * 2);
    HIH6130[2] = packet_format1[0];
    HIH6130[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HIH6130 temp: ");
    Serial.println(value_f);
    #endif

    // RH inside transparent box (format 1)
    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    HIH6130[4] = packet_format1[0];
    HIH6130[5] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("HIH6130 RH: ");
    Serial.println(value_f);
    #endif
    #endif

    #ifdef APDS9006020_include
    // Ambient light inside the cavity (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    APDS9006020[0] = ID_APDS9006020;
    APDS9006020[1] = (valid << 7) | LENGTH_FORMAT2;
    APDS9006020[2] = packet_format2[0];
    APDS9006020[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("APDS9006020: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef TSL260RD_include
    // Solar near IR (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    TSL260RD[0] = ID_TSL260RD;
    TSL260RD[1] = (valid << 7) | LENGTH_FORMAT2;
    TSL260RD[2] = packet_format2[0];
    TSL260RD[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("TSL260RD: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef TSL250RD_2_include
    // Solar visible light (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    TSL250RD_2[0] = ID_TSL250RD_2;
    TSL250RD_2[1] = (valid << 7) | LENGTH_FORMAT2;
    TSL250RD_2[2] = packet_format2[0];
    TSL250RD_2[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("TSL250RD: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef MLX75305_include
    // Solar visible light (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    MLX75305[0] = ID_MLX75305;
    MLX75305[1] = (valid << 7) | LENGTH_FORMAT2;
    MLX75305[2] = packet_format2[0];
    MLX75305[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("MLX75305: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef ML8511_include
    // Solar UV (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    ML8511[0] = ID_ML8511;
    ML8511[1] = (valid << 7) | LENGTH_FORMAT2;
    ML8511[2] = packet_format2[0];
    ML8511[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("ML8511: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef D6T_include
    // Temp of surrounding objects 1 (format 1)

    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif
    D6T[0] = ID_D6T;
    D6T[1] = (valid << 7) | (LENGTH_FORMAT1 * 17);
    #ifdef SERIAL_DEBUG
    Serial.print("D6T: ");
    #endif
    // Temp of surrounding objects 1-17 (format 1)
    for (int i = 2; i < LENGTH_FORMAT1 * 18; i += 2)
    {
        integer1 = random(0, 128);
        fractional = random(0, 100);
        neg = random(0, 2);
        value_f = integer1 + ((float)fractional / 100);
        if (neg)
            value_f *= -1;
        format1(value_f);  // Put it into format 1
        D6T[i] = packet_format1[0];
        D6T[i + 1] = packet_format1[1];
        #ifdef SERIAL_DEBUG
        Serial.print(value_f);
        Serial.print(" ");
        #endif
    }
    #ifdef SERIAL_DEBUG
    Serial.println("");
    #endif
    #endif

    #ifdef MLX90614_include
    // Temp of pavement (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    MLX90614[0] = ID_MLX90614;
    MLX90614[1] = (valid << 7) | LENGTH_FORMAT1;
    MLX90614[2] = packet_format1[0];
    MLX90614[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("MLX90614: ");
    Serial.println(value_f);
    #endif
    #endif

    #ifdef TMP421_include
    // Temp inside transparent box (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    TMP421[0] = ID_TMP421;
    TMP421[1] = (valid << 7) | LENGTH_FORMAT1;
    TMP421[2] = packet_format1[0];
    TMP421[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("TMP421: ");
    Serial.println(value_f);
    #endif
    #endif

    #ifdef SPV1840LR5HB_2_include
    // Sound pressure (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    SPV1840LR5HB_2[0] = ID_SPV1840LR5HB_2;
    SPV1840LR5HB_2[1] = (valid << 7) | LENGTH_FORMAT2;
    SPV1840LR5HB_2[2] = packet_format2[0];
    SPV1840LR5HB_2[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("SPV1840LR5HB: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef total_reducing_gases_include
    // Ambient concentration of total reducing gases (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
    total_reducing_gases[1] = (valid << 7) | LENGTH_FORMAT2;
    total_reducing_gases[2] = packet_format2[0];
    total_reducing_gases[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Total reducing gases: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef ethanol_include
    // Ambient concentration of ethanol (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    ethanol[0] = ID_ETHANOL;
    ethanol[1] = (valid << 7) | LENGTH_FORMAT2;
    ethanol[2] = packet_format2[0];
    ethanol[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Ethanol: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef nitrogen_dioxide_include
    // Ambient concentration of nitrogen dioxide (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
    nitrogen_dioxide[1] = (valid << 7) | LENGTH_FORMAT2;
    nitrogen_dioxide[2] = packet_format2[0];
    nitrogen_dioxide[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Nitrogen dioxide: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef ozone_include
    // Ambient concentration of ozone (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    ozone[0] = ID_OZONE;
    ozone[1] = (valid << 7) | LENGTH_FORMAT2;
    ozone[2] = packet_format2[0];
    ozone[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Ozone: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef hydrogen_sulphide_include
    // Ambient concentration of hydrogen sulphide (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
    hydrogen_sulphide[1] = (valid << 7) | LENGTH_FORMAT2;
    hydrogen_sulphide[2] = packet_format2[0];
    hydrogen_sulphide[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Hydrogen sulphide: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef total_oxidizing_gases_include
    // Ambient concentration of total oxidizing gases (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
    total_oxidizing_gases[1] = (valid << 7) | LENGTH_FORMAT2;
    total_oxidizing_gases[2] = packet_format2[0];
    total_oxidizing_gases[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Total oxidizing gases: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef carbon_monoxide_include
    // Ambient concentration of carbon monoxide (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    carbon_monoxide[0] = ID_CARBON_MONOXIDE;
    carbon_monoxide[1] = (valid << 7) | LENGTH_FORMAT2;
    carbon_monoxide[2] = packet_format2[0];
    carbon_monoxide[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Carbon monoxide: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef sulfur_dioxide_include
    // Ambient concentration of sulfur dioxide (format 2)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    integer2 = random(0, 256);
    value_i = (integer1 << 8) | integer2;
    format2(value_i);  // Put it into format 2
    sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
    sulfur_dioxide[1] = (valid << 7) | LENGTH_FORMAT2;
    sulfur_dioxide[2] = packet_format2[0];
    sulfur_dioxide[3] = packet_format2[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Sulfur dioxide: ");
    Serial.println(value_i);
    #endif
    #endif

    #ifdef sensirion_include
    // Temp (format 1)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 128);
    fractional = random(0, 100);
    neg = random(0, 2);
    value_f = integer1 + ((float)fractional / 100);
    if (neg)
        value_f *= -1;
    format1(value_f);  // Put it into format 1
    sensirion[0] = ID_SENSIRION;
    sensirion[1] = (valid << 7) | (LENGTH_FORMAT1 * 2);
    sensirion[2] = packet_format1[0];
    sensirion[3] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Sensirion temp: ");
    Serial.println(value_f);
    #endif

    // RH (format 1)
    integer1 = random(0, 101); // percentage
    fractional = random(0, 100);
    value_f = integer1 + ((float)fractional / 100);
    format1(value_f);  // Put it into format 1
    sensirion[4] = packet_format1[0];
    sensirion[5] = packet_format1[1];
    #ifdef SERIAL_DEBUG
    Serial.print("Sensirion RH: ");
    Serial.println(value_f);
    #endif
    #endif

    #ifdef bosh_include
    // Atmospheric pressure (format 6)
    #ifdef RANDOMIZE_VALID
    valid = random(0, 2);
    #endif

    integer1 = random(0, 64);
    integer2 = random(0, 256);
    integer3 = random(0, 256);
    value_l = integer1;
    value_l =  value_l << 8;
    value_l = value_l + integer2;
    value_l =  value_l << 8;
    value_l = value_l + integer3;
    neg = random(0, 2);
    if (neg)
        value_l *= -1;
    format6(value_l);  // Put it into format 6
    bosh[0] = ID_BOSH;
    bosh[1] = (valid << 7) | LENGTH_FORMAT6;
    bosh[2] = packet_format6[0];
    bosh[3] = packet_format6[1];
    bosh[4] = packet_format6[2];
    #ifdef SERIAL_DEBUG
    Serial.print("Bosh: ");
    Serial.println(value_l);
    #endif
    #endif

    #ifdef intel_MAC_ID_include
    // Intel MAC address (format 3)
    valid = 1;
    intel_MAC_ID[0] = ID_INTEL_MAC;
    intel_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;
    intel_MAC_ID[2] = 0x0C;
    intel_MAC_ID[3] = 0x0B;
    intel_MAC_ID[4] = 0x0A;
    intel_MAC_ID[5] = 0x09;
    intel_MAC_ID[6] = 0x08;
    intel_MAC_ID[7] = 0x07;
    #ifdef SERIAL_DEBUG
    Serial.print("Intel MAC ID: ");
    for (int i = 2; i < (LENGTH_FORMAT3 + 2); i++)
      Serial.print(intel_MAC_ID[i], HEX);
    Serial.println("");
    #endif
    #endif

    #ifdef system_health_include
    // Health status
    valid = 1;
    #ifdef RANDOMIZE_VALID
    //valid = random(0, 2);
    #endif
    sensor_health[0] = ID_HEALTH;
    sensor_health[1] = (valid << 7) | SENSOR_HEALTH_SIZE;
    for (int i = 0; i < SENSOR_HEALTH_SIZE; i++ )
    {
        sensor_health[i+2] = 0xFF;
    }
    #endif

    #ifdef SERIAL_DEBUG
    Serial.println("");
    Serial.println("");
    #endif
}
/**************************************************************************************/
