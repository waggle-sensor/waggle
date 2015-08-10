#ifndef RCM_TMP112_H
#define RCM_TMP112_H

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Wire.h"

#define TMP112_RAWADDRESS               (0x49)
#define TMP112_ADDRESS                  ((TMP112_RAWADDRESS << 1)  & ~0x01)
#define TMP112_CONVERSION_DELAY_IN_MS   (50)
#define TMP112_PERIODIC_TIMEOUT         (1 << 4)
#define TMP112_CONVERSION_TIMEOUT       (1 << 5)
#define TMP112_TEMPERATURE_REGISTER     (0x00)
#define TMP112_CONFIGURATION_REGISTER   (0x01)


class RCM_TMP112
{
    
public:
    uint8_t readBuffer[2];
    char pTemperature;
    uint16_t pTemperatureRaw;
    RCM_TMP112();
    boolean begin();
    void readTemperature();
    
private:
    void read16(uint8_t addr);
    void write16(uint8_t addr, uint8_t data1,uint8_t data2);
    
};



bool TMP112_open(void);


#endif

