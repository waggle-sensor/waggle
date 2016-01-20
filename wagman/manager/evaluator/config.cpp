// The board has the following hardware -
//     HIH4030 Sensor - Connected via A/D pin.
//     MCP79412 RTC - Connected via I2C bus.
//     ACS764 Current Sensors (6) - Connected via I2C bus
//     HTU21D Sensor - Connected via I2C bus
//     Thermistor for Node Controller - Connected via A/D pin.
//     Thermistors for other devices - via MCP3428 Chip.
//     MCP3428 A/D Chip - Via I2C.


// Analog PINs assignment
#define PIN_Therm_NC A0
#define PIN_Light_Sensor A1
#define PIN_HIH4030_Sensor A2
#define PIN_BootSelect_GM A3
#define PIN_HBT3    A4
#define PIN_HBT5    A5

#define PIN_NC_POW_State_Latch 0
#define PIN_BootSelect_NC 1
#define PIN_NC_POW_State 4
#define PIN_HBT1    5
#define PIN_POW_2   6
#define PIN_HBT2    7
#define PIN_POW_3   8
#define PIN_Debug_L1    9
#define PIN_POW_4   10
#define PIN_HBT4    11
#define PIN_POW_5   12
#define PIN_Debug_L   13


// Current Sensors
#define ADDR_CURRENT_SYS 0x60
#define ADDR_CURRENT_POW1 0x62
#define ADDR_CURRENT_POW2 0x63
#define ADDR_CURRENT_POW3 0x68
#define ADDR_CURRENT_POW4 0x6A
#define ADDR_CURRENT_POW5 0x6B
// Resolution of current sensors (with 8A range) (mA)
#define MILLIAMPS_PER_STEP 16
