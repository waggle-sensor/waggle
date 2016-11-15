
#ifdef AIRSENSE_INCLUDE

    #ifdef HTU21D_include
    #include "./libs/HTU21D/HTU21D.h"
    HTU21D myHumidity = HTU21D();
    #endif

    #ifdef  BMP180_include
    #include "./libs/Adafruit_Sensor-master/Adafruit_Sensor.h"
    #include "./libs/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h"
    Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
    sensors_event_t event;
    #endif

    #ifdef  PR103J2_include
    #define A2D_PRJ103J2 0
    #endif

    #ifdef TSL250RD_1_include
    #define A2D_TSL250RD_1 1
    #endif

    #ifdef MMA8452Q_include
    #define MMA8452_ADDRESS 0x1C
    #define OUT_X_MSB 0x01
    #define XYZ_DATA_CFG  0x0E
    #define WHO_AM_I   0x0D
    #define CTRL_REG1  0x2A
    #define GSCALE 2 // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.
    #endif

    #ifdef SPV1840LR5HB_1_include
    #define SPV_1_SPL 6
    #define SPV_1_AMP 5
    #endif

    #ifdef TSYS01_include
    #define TSYS01Address 0x76  //address left shifted by arduino as required to match datasheet
    #define TSYS01Reset 0x1E //initiates reset
    #define TSYS01StartReg 0x48 //commands sensor to begin measurement / output calculation
    #define TSYS01TempReg 0x00 //requests most recent output from measurement
    typedef enum TSYS_KPoly_E //structure to hold calibration values from temperature sensor registers
    {
        TSYS_K4 = 0,
        TSYS_K3,
        TSYS_K2,
        TSYS_K1,
        TSYS_K0
    }
    TSYS_KPoly_T;
    uint16_t TSYS_coefficents[5];

    #endif
#endif

    

#ifdef LIGHTSENSE_INCLUDE
    #include "./libs/MCP342X_Waggle/MCP342X_Waggle.h"
    MCP342X mcp3428_1;
    MCP342X mcp3428_2;

    #ifdef HMC5883L_include
    #include "./libs/HMC5883L_waggle/HMC5883L_waggle.h"
    HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire1);
    #endif

    #ifdef HIH6130_include
    #define HIH_ADDRESS 0x27
    #endif

    #ifdef TMP421_include
    #include "./libs/LibTempTMP421/LibTempTMP421.h"
    LibTempTMP421 TMP421_Sensor = LibTempTMP421();
    #endif
#endif

#ifdef CHEMSENSE_INCLUDE
    #define PIN_CHEMSENSE_POW   47
#endif