
void sensor_buff_initialization()
{
#ifdef DECAGON_INCLUDE
	DECAGON[0] = ID_DECAGON;  // three float data
	DECAGON[1] = (0 << 7) | (LENGTH_FORMAT6 * 3);
#endif

#ifdef RAIN_GAUGER_INCLUDE
	RAIN_GAUGER[0] = ID_RAIN_GAUGER; // one int data (2 bytes)
	RAIN_GAUGER[1] = (0 << 7) | LENGTH_FORMAT1;
#endif


#ifdef VERSION_INCLUDE
	FIRMWARE_VERSION[0] = ID_FIRMWARE_VERSION;
	FIRMWARE_VERSION[1] = (1 << 7) | (LENGTH_FORMAT1 + LENGTH_BUILD_TIME + LENGTH_BUILD_GIT);
#endif
	
#ifdef AIRSENSE_INCLUDE
	// initialize FIRST BYTE of the array
	MAC_ID[0] = ID_MAC;
	// initialize SECOND BYTE of the array
	MAC_ID[1] = (1 << 7) | LENGTH_FORMAT3;


#ifdef I2C_SENSORS
	// initialize FIRST BYTE of the arrays
    BMP180[0] = ID_BMP180;
    TMP112[0] = ID_TMP112;
    HTU21D_array[0] = ID_HTU21D;
    MMA8452Q[0] = ID_MMA8452Q;
    TSYS01[0] = ID_TSYS01;


	// initialize SECOND BYTE of the arrays
    BMP180[1] = (0 << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    TMP112[1] = (0 << 7) | LENGTH_FORMAT6;
    HTU21D_array[1] = (0 << 7) | LENGTH_FORMAT6;
    MMA8452Q[1] = (0 << 7) | (LENGTH_FORMAT6 * 4);
    TSYS01[1] = (0 << 7) | LENGTH_FORMAT6;
#endif

#ifdef ANALOG_SENSORS
	// initialize FIRST BYTE of the arrays
    HIH4030[0] = ID_HIH4030;
    PR103J2[0] = ID_PR103J2;
    TSL250RD_1[0] = ID_TSL250RD_1;
    SPV1840LR5HB[0] = ID_SPV1840LR5HB;


	// initialize SECOND BYTE of the arrays
    HIH4030[1] = (0 << 7) | LENGTH_FORMAT1;
    PR103J2[1] = (0 << 7) | LENGTH_FORMAT1;
    TSL250RD_1[1] = (0 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB[1] = (0 << 7) | LENGTH_FORMAT1;
#endif
#endif

#ifdef LIGHTSENSE_INCLUDE
#ifdef I2C_SENSORS
	// initialize FIRST BYTE of the arrays
    HMC5883L[0] = ID_HMC5883L;
    HIH6130[0] = ID_HIH6130;

    APDS9006020[0] = ID_APDS9006020;
    TSL260RD[0] = ID_TSL260RD;
    TSL250RD_2[0] = ID_TSL250RD_2;

    MLX75305[0] = ID_MLX75305;
    ML8511[0] = ID_ML8511;
    TMP421[0] = ID_TMP421;


	// SECOND BYTE of the array
    // lightsense initialization
    HMC5883L[1] = (0 << 7) | (LENGTH_FORMAT8 * 3);
    HIH6130[1] = (0 << 7) | (LENGTH_FORMAT6 * 2);

    APDS9006020[1] = (0 << 7) | LENGTH_FORMAT1;
    TSL260RD[1] = (0 << 7) | LENGTH_FORMAT1;
    TSL250RD_2[1] = (0 << 7) | LENGTH_FORMAT1;

    MLX75305[1] = (0 << 7) | LENGTH_FORMAT1;
    ML8511[1] = (0 << 7) | LENGTH_FORMAT1;
    TMP421[1] = (0 << 7) | LENGTH_FORMAT6;
#endif
#endif


#ifdef CHEMSENSE_INCLUDE
	// initialize FIRST BYTE of the arrays
	chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;

	SHT25[0] = ID_SHT25;
	LPS25H[0] = ID_LPS25H;
	Si1145[0] = ID_Si1145;

	total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
	total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
	sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
	hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
	ozone[0] = ID_OZONE;
	nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
	carbon_monoxide[0] = ID_CARBON_MONOXIDE;

	CO_ADC_temp[0] = ID_CO_ADC_TEMP;
	IAQ_IRR_ADC_temp[0] = ID_IAQ_IRR_ADC_TEMP;
	O3_NO2_ADC_temp[0] = ID_O3_NO2_ADC_TEMP;
	SO2_H2S_ADC_temp[0] = ID_SO2_H2S_ADC_TEMP;
	CO_LMP_temp[0] = ID_CO_LMP_TEMP;

	three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
	three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;


	// initialize SECOND BYTE of the arrays
	chemsense_MAC_ID[1] = (0 << 7) | LENGTH_FORMAT3;

	SHT25[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
	LPS25H[1] = (0 << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
	Si1145[1] = (0 << 7) | (LENGTH_FORMAT1 * 3);

	total_reducing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
	total_oxidizing_gases[1] = (0 << 7) | LENGTH_FORMAT5;
	sulfur_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
	hydrogen_sulphide[1] = (0 << 7) | LENGTH_FORMAT5;
	ozone[1] = (0 << 7) | LENGTH_FORMAT5;
	nitrogen_dioxide[1] = (0 << 7) | LENGTH_FORMAT5;
	carbon_monoxide[1] = (0 << 7) | LENGTH_FORMAT5;

	CO_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
	IAQ_IRR_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
	O3_NO2_ADC_temp[1] = (0 << 7) | LENGTH_FORMAT2;
	SO2_H2S_ADC_temp[1] = (0 >> 7) | LENGTH_FORMAT2;
	CO_LMP_temp[1] = (0 << 7) | LENGTH_FORMAT2;

	three_accel_and_vib[1] = (0 << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
	three_gyro_and_orientation[1] = (0 << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
#endif


#ifdef ALPHASENSE_INCLUDE
	// initialize FIRST BYTE of the arrays
	alpha_histogram[0] = ID_ALPHA_HISTOGRAM;
	alpha_serial[0] = ID_ALPHA_SERIAL;
	alpha_firmware[0] = ID_ALPHA_FIRMWARE;

	alpha_config_a[0] = ID_ALPHA_CONFIG_A;
	alpha_config_b[0] = ID_ALPHA_CONFIG_B;
	alpha_config_c[0] = ID_ALPHA_CONFIG_C;
	alpha_config_d[0] = ID_ALPHA_CONFIG_D;


	// initialize SECOND BYTE of the arrays
	alpha_histogram[1] = (0 << 7) | LENGTH_ALPHA_HISTOGRAM;
	alpha_serial[1] = (0 << 7) | LENGTH_ALPAH_SERIAL;
	alpha_firmware[1] = (0 << 7) | LENGTH_ALPHA_FIRMWARE;

	alpha_config_a[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_A;
	alpha_config_b[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_B;
	alpha_config_c[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_C;
	alpha_config_d[1] = (0 << 7) | LENGTH_ALPHA_CONFIG_D;
#endif
}
