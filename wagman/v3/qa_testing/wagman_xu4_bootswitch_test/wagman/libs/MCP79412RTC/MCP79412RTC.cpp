/*----------------------------------------------------------------------*
 * MCP79412RTC.cpp - Arduino library for the Microchip MCP7941x         *
 * Real-Time Clocks. This library is intended for use with the Arduino  *
 * Time.h library, http://www.arduino.cc/playground/Code/Time           *
 *                                                                      *
 * This library is a drop-in replacement for the DS1307RTC.h library    *
 * by Michael Margolis that is supplied with the Arduino Time library   *
 * above. To change from using a DS1307 RTC to an MCP7941x RTC, it is   *
 * only necessary to change the #include statement to include this      *
 * library instead of DS1307RTC.h.                                      *
 *                                                                      *
 * In addition, this library implements functions to support the        *
 * additional features of the MCP7941x.                                 *
 *                                                                      *
 * Jack Christensen 29Jul2012                                           *
 *                                                                      *
 * This work is licensed under the Creative Commons Attribution-        *
 * ShareAlike 3.0 Unported License. To view a copy of this license,     *
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       *
 * letter to Creative Commons, 171 Second Street, Suite 300,            *
 * San Francisco, California, 94105, USA.                               *
 *----------------------------------------------------------------------*/

#include "MCP79412RTC.h"

//define release-independent I2C functions
#if defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#include <TinyWireM.h>
#define i2cBegin TinyWireM.begin
#define i2cBeginTransmission TinyWireM.beginTransmission
#define i2cEndTransmission TinyWireM.endTransmission
#define i2cRequestFrom TinyWireM.requestFrom
#define i2cRead TinyWireM.receive
#define i2cWrite TinyWireM.send
#elif ARDUINO >= 100
#include <Wire.h>
#define i2cBegin Wire.begin
#define i2cBeginTransmission Wire.beginTransmission
#define i2cEndTransmission Wire.endTransmission
#define i2cRequestFrom Wire.requestFrom
#define i2cRead Wire.read
#define i2cWrite Wire.write
#else
#include <Wire.h>
#define i2cBegin Wire.begin
#define i2cBeginTransmission Wire.beginTransmission
#define i2cEndTransmission Wire.endTransmission
#define i2cRequestFrom Wire.requestFrom
#define i2cRead Wire.receive
#define i2cWrite Wire.send
#endif

/*----------------------------------------------------------------------*
 * Constructor.                                                         *
 *----------------------------------------------------------------------*/
MCP79412RTC::MCP79412RTC()
{
    i2cBegin();
}

/*----------------------------------------------------------------------*
 * Read the current time from the RTC and return it as a time_t value.  *
 * Returns a zero value if RTC not present (I2C I/O error).             *
 *----------------------------------------------------------------------*/
time_t MCP79412RTC::get(void)
{
    tmElements_t tm;

    if ( read(tm) )
        return( makeTime(tm) );
    else
        return 0;
}

/*----------------------------------------------------------------------*
 * Set the RTC to the given time_t value.                               *
 *----------------------------------------------------------------------*/
void MCP79412RTC::set(time_t t)
{
    tmElements_t tm;

    breakTime(t, tm);
    write(tm);
}

/*----------------------------------------------------------------------*
 * Read the current time from the RTC and return it in a tmElements_t   *
 * structure. Returns false if RTC not present (I2C I/O error).         *
 *----------------------------------------------------------------------*/
boolean MCP79412RTC::read(tmElements_t &tm)
{
    i2cBeginTransmission(RTC_ADDR);
    i2cWrite((uint8_t)TIME_REG);
    if (i2cEndTransmission() != 0) {
        return false;
    }
    else {
        //request 7 bytes (secs, min, hr, dow, date, mth, yr)
        i2cRequestFrom(RTC_ADDR, tmNbrFields);
        tm.Second = bcd2dec(i2cRead() & ~_BV(ST));
        tm.Minute = bcd2dec(i2cRead());
        tm.Hour = bcd2dec(i2cRead() & ~_BV(HR1224));    //assumes 24hr clock
        tm.Wday = i2cRead() & ~(_BV(OSCON) | _BV(VBAT) | _BV(VBATEN));    //mask off OSCON, VBAT, VBATEN bits
        tm.Day = bcd2dec(i2cRead());
        tm.Month = bcd2dec(i2cRead() & ~_BV(LP));       //mask off the leap year bit
        tm.Year = y2kYearToTm(bcd2dec(i2cRead()));
        return true;
    }
}

/*----------------------------------------------------------------------*
 * Set the RTC's time from a tmElements_t structure.                    *
 *----------------------------------------------------------------------*/
void MCP79412RTC::write(tmElements_t &tm)
{
    i2cBeginTransmission(RTC_ADDR);
    i2cWrite((uint8_t)TIME_REG);
    i2cWrite((uint8_t)0x00);                     //stops the oscillator (Bit 7, ST == 0)
    i2cWrite(dec2bcd(tm.Minute));
    i2cWrite(dec2bcd(tm.Hour));                  //sets 24 hour format (Bit 6 == 0)
    i2cWrite(tm.Wday | _BV(VBATEN));             //enable battery backup operation
    i2cWrite(dec2bcd(tm.Day));
    i2cWrite(dec2bcd(tm.Month));
    i2cWrite(dec2bcd(tmYearToY2k(tm.Year)));
    i2cEndTransmission();

    i2cBeginTransmission(RTC_ADDR);
    i2cWrite((uint8_t)TIME_REG);
    i2cWrite(dec2bcd(tm.Second) | _BV(ST));    //set the seconds and start the oscillator (Bit 7, ST == 1)
    i2cEndTransmission();
}

/*----------------------------------------------------------------------*
 * Write a single byte to RTC RAM.                                      *
 * Valid address range is 0x00 - 0x5F, no checking.                     *
 *----------------------------------------------------------------------*/
void MCP79412RTC::ramWrite(byte addr, byte value)
{
    ramWrite(addr, &value, 1);
}

/*----------------------------------------------------------------------*
 * Write multiple bytes to RTC RAM.                                     *
 * Valid address range is 0x00 - 0x5F, no checking.                     *
 * Number of bytes (nBytes) must be between 1 and 31 (Wire library      *
 * limitation).                                                         *
 *----------------------------------------------------------------------*/
void MCP79412RTC::ramWrite(byte addr, byte *values, byte nBytes)
{
    i2cBeginTransmission(RTC_ADDR);
    i2cWrite(addr);
    for (byte i=0; i<nBytes; i++) i2cWrite(values[i]);
    i2cEndTransmission();
}

/*----------------------------------------------------------------------*
 * Read a single byte from RTC RAM.                                     *
 * Valid address range is 0x00 - 0x5F, no checking.                     *
 *----------------------------------------------------------------------*/
byte MCP79412RTC::ramRead(byte addr)
{
    byte value;

    ramRead(addr, &value, 1);
    return value;
}

/*----------------------------------------------------------------------*
 * Read multiple bytes from RTC RAM.                                    *
 * Valid address range is 0x00 - 0x5F, no checking.                     *
 * Number of bytes (nBytes) must be between 1 and 32 (Wire library      *
 * limitation).                                                         *
 *----------------------------------------------------------------------*/
void MCP79412RTC::ramRead(byte addr, byte *values, byte nBytes)
{
    i2cBeginTransmission(RTC_ADDR);
    i2cWrite(addr);
    i2cEndTransmission();
    i2cRequestFrom( (uint8_t)RTC_ADDR, nBytes );
    for (byte i=0; i<nBytes; i++) values[i] = i2cRead();
}

/*----------------------------------------------------------------------*
 * Write a single byte to Static RAM.                                   *
 * Address (addr) is constrained to the range (0, 63).                  *
 *----------------------------------------------------------------------*/
void MCP79412RTC::sramWrite(byte addr, byte value)
{
    ramWrite( (addr & (SRAM_SIZE - 1) ) + SRAM_START_ADDR, &value, 1 );
}

/*----------------------------------------------------------------------*
 * Write multiple bytes to Static RAM.                                  *
 * Address (addr) is constrained to the range (0, 63).                  *
 * Number of bytes (nBytes) must be between 1 and 31 (Wire library      *
 * limitation).                                                         *
 * Invalid values for nBytes, or combinations of addr and nBytes        *
 * that would result in addressing past the last byte of SRAM will      *
 * result in no action.                                                 *
 *----------------------------------------------------------------------*/
void MCP79412RTC::sramWrite(byte addr, byte *values, byte nBytes)
{
#if defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    if (nBytes >= 1 && (addr + nBytes) <= SRAM_SIZE) {
#else
    if (nBytes >= 1 && nBytes <= (BUFFER_LENGTH - 1) && (addr + nBytes) <= SRAM_SIZE) {
#endif
        ramWrite( (addr & (SRAM_SIZE - 1) ) + SRAM_START_ADDR, values, nBytes );
    }
}

/*----------------------------------------------------------------------*
 * Read a single byte from Static RAM.                                  *
 * Address (addr) is constrained to the range (0, 63).                  *
 *----------------------------------------------------------------------*/
byte MCP79412RTC::sramRead(byte addr)
{
    byte value;

    ramRead( (addr & (SRAM_SIZE - 1) ) + SRAM_START_ADDR, &value, 1 );
    return value;
}

/*----------------------------------------------------------------------*
 * Read multiple bytes from Static RAM.                                 *
 * Address (addr) is constrained to the range (0, 63).                  *
 * Number of bytes (nBytes) must be between 1 and 32 (Wire library      *
 * limitation).                                                         *
 * Invalid values for nBytes, or combinations of addr and               *
 * nBytes that would result in addressing past the last byte of SRAM    *
 * result in no action.                                                 *
 *----------------------------------------------------------------------*/
void MCP79412RTC::sramRead(byte addr, byte *values, byte nBytes)
{
#if defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    if (nBytes >= 1 && (addr + nBytes) <= SRAM_SIZE) {
#else
    if (nBytes >= 1 && nBytes <= BUFFER_LENGTH && (addr + nBytes) <= SRAM_SIZE) {
#endif
        ramRead((addr & (SRAM_SIZE - 1) ) + SRAM_START_ADDR, values, nBytes);
    }
}

/*----------------------------------------------------------------------*
 * Write a single byte to EEPROM.                                       *
 * Address (addr) is constrained to the range (0, 127).                 *
 * Can't leverage page write function because a write can't start       *
 * mid-page.                                                            *
 *----------------------------------------------------------------------*/
void MCP79412RTC::eepromWrite(byte addr, byte value)
{
    i2cBeginTransmission(EEPROM_ADDR);
    i2cWrite( addr & (EEPROM_SIZE - 1) );
    i2cWrite(value);
    i2cEndTransmission();
    eepromWait();
}

/*----------------------------------------------------------------------*
 * Write a page (or less) to EEPROM. An EEPROM page is 8 bytes.         *
 * Address (addr) should be a page start address (0, 8, ..., 120), but  *
 * is ruthlessly coerced into a valid value.                            *
 * Number of bytes (nBytes) must be between 1 and 8, other values       *
 * result in no action.                                                 *
 *----------------------------------------------------------------------*/
void MCP79412RTC::eepromWrite(byte addr, byte *values, byte nBytes)
{
    if (nBytes >= 1 && nBytes <= EEPROM_PAGE_SIZE) {
        i2cBeginTransmission(EEPROM_ADDR);
        i2cWrite( addr & ~(EEPROM_PAGE_SIZE - 1) & (EEPROM_SIZE - 1) );
        for (byte i=0; i<nBytes; i++) i2cWrite(values[i]);
        i2cEndTransmission();
        eepromWait();
    }
}

/*----------------------------------------------------------------------*
 * Read a single byte from EEPROM.                                      *
 * Address (addr) is constrained to the range (0, 127).                  *
 *----------------------------------------------------------------------*/
byte MCP79412RTC::eepromRead(byte addr)
{
    byte value;

    eepromRead( addr & (EEPROM_SIZE - 1), &value, 1 );
    return value;
}

/*----------------------------------------------------------------------*
 * Read multiple bytes from EEPROM.                                     *
 * Address (addr) is constrained to the range (0, 127).                 *
 * Number of bytes (nBytes) must be between 1 and 32 (Wire library      *
 * limitation).                                                         *
 * Invalid values for addr or nBytes, or combinations of addr and       *
 * nBytes that would result in addressing past the last byte of EEPROM  *
 * result in no action.                                                 *
 *----------------------------------------------------------------------*/
void MCP79412RTC::eepromRead(byte addr, byte *values, byte nBytes)
{
#if defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    if (nBytes >= 1 && (addr + nBytes) <= EEPROM_SIZE) {
#else
    if (nBytes >= 1 && nBytes <= BUFFER_LENGTH && (addr + nBytes) <= EEPROM_SIZE) {
#endif
        i2cBeginTransmission(EEPROM_ADDR);
        i2cWrite( addr & (EEPROM_SIZE - 1) );
        i2cEndTransmission();
        i2cRequestFrom( (uint8_t)EEPROM_ADDR, nBytes );
        for (byte i=0; i<nBytes; i++) values[i] = i2cRead();
    }
}

/*----------------------------------------------------------------------*
 * Wait for EEPROM write to complete.                                   *
 *----------------------------------------------------------------------*/
byte MCP79412RTC::eepromWait(void)
{
    byte waitCount = 0;
    byte txStatus;

    do
    {
        ++waitCount;
        i2cBeginTransmission(EEPROM_ADDR);
        i2cWrite((uint8_t)0);
        txStatus = i2cEndTransmission();

    } while (txStatus != 0);

    return waitCount;
}

/*----------------------------------------------------------------------*
 * Read the calibration register.                                       *
 * The calibration value is not a twos-complement number. The MSB is    *
 * the sign bit, and the 7 LSBs are an unsigned number, so we convert   *
 * it and return it to the caller as a regular twos-complement integer. *
 *----------------------------------------------------------------------*/
int MCP79412RTC::calibRead(void)
{
    byte val = ramRead(CALIB_REG);

    if ( val & 0x80 ) return -(val & 0x7F);
    else return val;
}

/*----------------------------------------------------------------------*
 * Write the calibration register.                                      *
 * Calibration value must be between -127 and 127, others result        *
 * in no action. See note above on the format of the calibration value. *
 *----------------------------------------------------------------------*/
void MCP79412RTC::calibWrite(int value)
{
    byte calibVal;

    if (value >= -127 && value <= 127) {
        calibVal = abs(value);
        if (value < 0) calibVal += 128;
        ramWrite(CALIB_REG, calibVal);
    }
}

/*----------------------------------------------------------------------*
 * Read the unique ID.                                                  *
 * For the MCP79411 (EUI-48), the first two bytes will contain 0xFF.    *
 * Caller must provide an 8-byte array to contain the results.          *
 *----------------------------------------------------------------------*/
void MCP79412RTC::idRead(byte *uniqueID)
{
    i2cBeginTransmission(EEPROM_ADDR);
    i2cWrite(UNIQUE_ID_ADDR);
    i2cEndTransmission();
    i2cRequestFrom( EEPROM_ADDR, UNIQUE_ID_SIZE );
    for (byte i=0; i<UNIQUE_ID_SIZE; i++) uniqueID[i] = i2cRead();
}

/*----------------------------------------------------------------------*
 * Returns an EUI-64 ID. For an MCP79411, the EUI-48 ID is converted to *
 * EUI-64. For an MCP79412, calling this function is equivalent to      *
 * calling idRead(). For an MCP79412, if the RTC type is known, calling *
 * idRead() will be a bit more efficient.                               *
 * Caller must provide an 8-byte array to contain the results.          *
 *----------------------------------------------------------------------*/
void MCP79412RTC::getEUI64(byte *uniqueID)
{
    byte rtcID[8];

    idRead(rtcID);
    if (rtcID[0] == 0xFF && rtcID[1] == 0xFF) {
        rtcID[0] = rtcID[2];
        rtcID[1] = rtcID[3];
        rtcID[2] = rtcID[4];
        rtcID[3] = 0xFF;
        rtcID[4] = 0xFE;
    }
    for (byte i=0; i<UNIQUE_ID_SIZE; i++) uniqueID[i] = rtcID[i];
}

/*----------------------------------------------------------------------*
 * Check to see if a power failure has occurred. If so, returns TRUE    *
 * as the function value, and returns the power down and power up       *
 * timestamps. After returning the time stamps, the RTC's timestamp     *
 * registers are cleared and the VBAT bit which indicates a power       *
 * failure is reset.                                                    *
 *                                                                      *
 * Note that the power down and power up timestamp registers do not     *
 * contain values for seconds or for the year. The returned time stamps *
 * will therefore contain the current year from the RTC. However, there *
 * is a chance that a power outage spans from one year to the next.     *
 * If we find the power down timestamp to be later (larger) than the    *
 * power up timestamp, we will assume this has happened, and well       *
 * subtract one year from the power down timestamp.                     *
 *                                                                      *
 * Still, there is an assumption that the timestamps are being read     *
 * in the same year as that when the power up occurred.                 *
 *                                                                      *
 * Finally, note that once the RTC records a power outage, it must be   *
 * cleared before another will be recorded.                             *
 *----------------------------------------------------------------------*/
boolean MCP79412RTC::powerFail(time_t *powerDown, time_t *powerUp)
{
    byte day, yr;                   //copies of the RTC Day and Year registers
    tmElements_t dn, up;            //power down and power up times

    ramRead(DAY_REG, &day, 1);
    ramRead(YEAR_REG, &yr, 1);
    yr = y2kYearToTm(bcd2dec(yr));
    if ( day & _BV(VBAT) ) {
        i2cBeginTransmission(RTC_ADDR);
        i2cWrite(PWRDWN_TS_REG);
        i2cEndTransmission();

        i2cRequestFrom(RTC_ADDR, TIMESTAMP_SIZE);     //read both timestamp registers, 8 bytes total
        dn.Second = 0;
        dn.Minute = bcd2dec(i2cRead());
        dn.Hour = bcd2dec(i2cRead() & ~_BV(HR1224));    //assumes 24hr clock
        dn.Day = bcd2dec(i2cRead());
        dn.Month = bcd2dec(i2cRead() & 0x1F);           //mask off the day, we don't need it
        dn.Year = yr;                                   //assume current year
        up.Second = 0;
        up.Minute = bcd2dec(i2cRead());
        up.Hour = bcd2dec(i2cRead() & ~_BV(HR1224));    //assumes 24hr clock
        up.Day = bcd2dec(i2cRead());
        up.Month = bcd2dec(i2cRead() & 0x1F);           //mask off the day, we don't need it
        up.Year = yr;                                   //assume current year

        *powerDown = makeTime(dn);
        *powerUp = makeTime(up);

        //clear the VBAT bit, which causes the RTC hardware to clear the timestamps too.
        //I suppose there is a risk here that the day has changed since we read it,
        //but the Day of Week is actually redundant data and the makeTime() function
        //does not use it. This could be an issue if someone is reading the RTC
        //registers directly, but as this library is meant to be used with the Time library,
        //and also because we don't provide a method to read the RTC clock/calendar
        //registers directly, we won't lose any sleep about it at this point unless
        //some issue is actually brought to our attention ;-)
        day &= ~_BV(VBAT);
        ramWrite(DAY_REG, &day , 1);

        //adjust the powerDown timestamp if needed (see notes above)
        if (*powerDown > *powerUp) {
            --dn.Year;
            *powerDown = makeTime(dn);
        }
        return true;
    }
    else
        return false;
}

/*----------------------------------------------------------------------*
 * Enable or disable the square wave output.                            *
 *----------------------------------------------------------------------*/
void MCP79412RTC::squareWave(uint8_t freq)
{
    uint8_t ctrlReg;

    ramRead(CTRL_REG, &ctrlReg, 1);
    if (freq > 3) {
        ctrlReg &= ~_BV(SQWE);
    }
    else {
        ctrlReg = (ctrlReg & 0xF8) | _BV(SQWE) | freq;
    }
    ramWrite(CTRL_REG, &ctrlReg, 1);
}

/*----------------------------------------------------------------------*
 * Set an alarm time. Sets the alarm registers only, does not enable    *
 * the alarm. See enableAlarm().                                        *
 *----------------------------------------------------------------------*/
void MCP79412RTC::setAlarm(uint8_t alarmNumber, time_t alarmTime)
{
    tmElements_t tm;
    uint8_t day;        //need to preserve bits in the day (of week) register

    alarmNumber &= 0x01;        //ensure a valid alarm number
    ramRead( ALM0_DAY + alarmNumber * (ALM1_REG - ALM0_REG) , &day, 1);
    breakTime(alarmTime, tm);
    i2cBeginTransmission(RTC_ADDR);
    i2cWrite( ALM0_REG + alarmNumber * (ALM1_REG - ALM0_REG) );
    i2cWrite(dec2bcd(tm.Second));
    i2cWrite(dec2bcd(tm.Minute));
    i2cWrite(dec2bcd(tm.Hour));                  //sets 24 hour format (Bit 6 == 0)
    i2cWrite( (day & 0xF8) + tm.Wday );
    i2cWrite(dec2bcd(tm.Day));
    i2cWrite(dec2bcd(tm.Month));
    i2cEndTransmission();
}

/*----------------------------------------------------------------------*
 * Enable or disable an alarm, and set the trigger criteria,            *
 * e.g. match only seconds, only minutes, entire time and date, etc.    *
 *----------------------------------------------------------------------*/
void MCP79412RTC::enableAlarm(uint8_t alarmNumber, uint8_t alarmType)
{
    uint8_t day;                //alarm day register has config & flag bits
    uint8_t ctrl;               //control register has alarm enable bits

    alarmNumber &= 0x01;        //ensure a valid alarm number
    ramRead(CTRL_REG, &ctrl, 1);
    if (alarmType < ALM_DISABLE) {
        ramRead(ALM0_DAY + alarmNumber * (ALM1_REG - ALM0_REG), &day, 1);
        day = ( day & 0x87 ) | alarmType << 4;  //reset interrupt flag, OR in the config bits
        ramWrite(ALM0_DAY + alarmNumber * (ALM1_REG - ALM0_REG), &day, 1);
        ctrl |= _BV(ALM0 + alarmNumber);        //enable the alarm
    }
    else {
        ctrl &= ~(_BV(ALM0 + alarmNumber));     //disable the alarm
    }
    ramWrite(CTRL_REG, &ctrl, 1);
}

/*----------------------------------------------------------------------*
 * Returns true or false depending on whether the given alarm has been  *
 * triggered, and resets the alarm "interrupt" flag. This is not a real *
 * interrupt, just a bit that's set when an alarm is triggered.         *
 *----------------------------------------------------------------------*/
boolean MCP79412RTC::alarm(uint8_t alarmNumber)
{
    uint8_t day;                //alarm day register has config & flag bits

    alarmNumber &= 0x01;        //ensure a valid alarm number
    ramRead( ALM0_DAY + alarmNumber * (ALM1_REG - ALM0_REG), &day, 1);
    if (day & _BV(ALMIF)) {
        day &= ~_BV(ALMIF);     //turn off the alarm "interrupt" flag
        ramWrite( ALM0_DAY + alarmNumber * (ALM1_REG - ALM0_REG), &day, 1);
        return true;
    }
    else
        return false;
}

/*----------------------------------------------------------------------*
 * Sets the logic level on the MFP when it's not being used as a        *
 * square wave or alarm output. The default is HIGH.                    *
 *----------------------------------------------------------------------*/
void MCP79412RTC::out(boolean level)
{
    uint8_t ctrlReg;

    ramRead(CTRL_REG, &ctrlReg, 1);
    if (level)
        ctrlReg |= _BV(OUT);
    else
        ctrlReg &= ~_BV(OUT);
    ramWrite(CTRL_REG, &ctrlReg, 1);
}

/*----------------------------------------------------------------------*
 * Specifies the logic level on the Multi-Function Pin (MFP) when an    *
 * alarm is triggered. The default is LOW. When both alarms are         *
 * active, the two are ORed together to determine the level of the MFP. *
 * With alarm polarity set to LOW (the default), this causes the MFP    *
 * to go low only when BOTH alarms are triggered. With alarm polarity   *
 * set to HIGH, the MFP will go high when EITHER alarm is triggered.    *
 *                                                                      *
 * Note that the state of the MFP is independent of the alarm           *
 * "interrupt" flags, and the alarm() function will indicate when an    *
 * alarm is triggered regardless of the polarity.                       *
 *----------------------------------------------------------------------*/
void MCP79412RTC::alarmPolarity(boolean polarity)
{
    uint8_t alm0Day;

    ramRead(ALM0_DAY, &alm0Day, 1);
    if (polarity)
        alm0Day |= _BV(OUT);
    else
        alm0Day &= ~_BV(OUT);
    ramWrite(ALM0_DAY, &alm0Day, 1);
}

/*----------------------------------------------------------------------*
 * Check to see if the RTC's oscillator is started (ST bit in seconds   *
 * register). Returns true if started.                                  *
 *----------------------------------------------------------------------*/
boolean MCP79412RTC::isRunning(void)
{
    i2cBeginTransmission(RTC_ADDR);
    i2cWrite((uint8_t)TIME_REG);
    i2cEndTransmission();

    //request just the seconds register
    i2cRequestFrom(RTC_ADDR, 1);
    return i2cRead() & _BV(ST);
}

/*----------------------------------------------------------------------*
 * Set or clear the VBATEN bit. Setting the bit powers the clock and    *
 * SRAM from the backup battery when Vcc falls. Note that setting the   *
 * time via set() or write() sets the VBATEN bit.                       *
 *----------------------------------------------------------------------*/
void MCP79412RTC::vbaten(boolean enable)
{
    uint8_t day;

    ramRead(DAY_REG, &day, 1);
    if (enable)
        day |= _BV(VBATEN);
    else
        day &= ~_BV(VBATEN);

    ramWrite(DAY_REG, &day, 1);
    return;
}

/*----------------------------------------------------------------------*
 * Decimal-to-BCD conversion                                            *
 *----------------------------------------------------------------------*/
uint8_t MCP79412RTC::dec2bcd(uint8_t n)
{
    return n + 6 * (n / 10);
}

/*----------------------------------------------------------------------*
 * BCD-to-Decimal conversion                                            *
 *----------------------------------------------------------------------*/
uint8_t __attribute__ ((noinline)) MCP79412RTC::bcd2dec(uint8_t n)
{
    return n - 6 * (n >> 4);
}

MCP79412RTC RTC = MCP79412RTC();    //instantiate an RTC object

