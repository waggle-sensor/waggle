/*
 * /coresensors/v2/pbay/integrated
 * initialization.ino V2 (including NEW INTEL CHEMSENSE BOARD)
 */

int sensor_initial = 0;

void sensor_buff_initialization()
{
	MAC_ID[0] = ID_MAC;

	// airsense board
	#ifdef AIRSENSE_INCLUDE
	TMP112[0] = ID_TMP112;
	HTU21D[0] = ID_HTU21D;

	BMP180[0] = ID_BMP180;
	PR103J2[0] = ID_PR103J2;
	TSL250RD_1[0] = ID_TSL250RD_1;

	MMA8452Q[0] = ID_MMA8452Q;
	SPV1840LR5HB_1[0] = ID_SPV1840LR5HB_1;
	TSYS01[0] = ID_TSYS01;
	#endif



	// lightsense board
	#ifdef LIGHTSENSE_INCLUDE
	HMC5883L[0] = ID_HMC5883L;
	HIH6130[0] = ID_HIH6130;

	APDS9006020[0] = ID_APDS9006020;
	TSL260RD[0] = ID_TSL260RD;
	TSL250RD_2[0] = ID_TSL250RD_2;

	MLX75305[0] = ID_MLX75305;
	ML8511[0] = ID_ML8511;

	D6T[0] = ID_D6T;
	MLX90614[0] = ID_MLX90614;

	TMP421[0] = ID_TMP421;
	SPV1840LR5HB_2[0] = ID_SPV1840LR5HB_2;
	#endif


	//chemsense board
	#ifdef CHEMSENSE_INCLUDE
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
	#endif


	// airsense initialization
	MAC_ID[1] = (1 << 7) | LENGTH_FORMAT3;

	// airsense initialization
	#ifdef AIRSENSE_INCLUDE
	TMP112[1] = (sensor_initial << 7) | LENGTH_FORMAT6;
	HTU21D[1] = (sensor_initial << 7) | LENGTH_FORMAT6;

	BMP180[1] = (sensor_initial << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
	PR103J2[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
	TSL250RD_1[1] = (sensor_initial << 7) | LENGTH_FORMAT1;

	MMA8452Q[1] = (sensor_initial << 7) | (LENGTH_FORMAT6 * 4);
	SPV1840LR5HB_1[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
	TSYS01[1] = (sensor_initial << 7) | LENGTH_FORMAT6;
	#endif


	// lightsense initialization
	#ifdef LIGHTSENSE_INCLUDE
	HMC5883L[1] = (sensor_initial << 7) | (LENGTH_FORMAT8 * 3);
	HIH6130[1] = (sensor_initial << 7) | (LENGTH_FORMAT6 * 2);

	APDS9006020[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
	TSL260RD[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
	TSL250RD_2[1] = (sensor_initial << 7) | LENGTH_FORMAT1;

	MLX75305[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
	ML8511[1] = (sensor_initial << 7) | LENGTH_FORMAT1;

	D6T[1] = (sensor_initial << 7) | (LENGTH_FORMAT6 * 17);
	MLX90614[1] = (sensor_initial << 7 ) | LENGTH_FORMAT1;

	TMP421[1] = (sensor_initial << 7) | LENGTH_FORMAT6;
	SPV1840LR5HB_2[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
	#endif

	// chemsemse initialization
	#ifdef CHEMSENSE_INCLUDE
	chemsense_MAC_ID[1] = (sensor_initial << 7) | LENGTH_FORMAT3;

	SHT25[1] = (sensor_initial << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
	LPS25H[1] = (sensor_initial << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
	Si1145[1] = (sensor_initial << 7) | (LENGTH_FORMAT1 * 3);

	total_reducing_gases[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	total_oxidizing_gases[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	sulfur_dioxide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	hydrogen_sulphide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	ozone[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	nitrogen_dioxide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	carbon_monoxide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;

	CO_ADC_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;
	IAQ_IRR_ADC_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;
	O3_NO2_ADC_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;
	SO2_H2S_ADC_temp[1] = (sensor_initial >> 7) | LENGTH_FORMAT2;
	CO_LMP_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;

	three_accel_and_vib[1] = (sensor_initial << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
	three_gyro_and_orientation[1] = (sensor_initial << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
	#endif
}