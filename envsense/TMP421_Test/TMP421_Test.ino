#include <inttypes.h>
#include <Wire.h>
float TMP421_1_temperature;

/**********************************************************
 * getRegisterValue
 *  Get the TMP421 register value via I2C
 *
 * @return uint8_t - The register value
 **********************************************************/
uint8_t TMP421_getRegisterValue(void) {
    
    int TMP_err = Wire.requestFrom(0x2A, 1);
    if (TMP_err != 0) {
        while(Wire.available() <= 0) {
            ; //wait
        }
        return Wire.read();
    }
    else {
        return -999;
    }
}

/**********************************************************
 * setPtrLoc
 *  Sets the TMP421 pointer register location via I2C
 *
 * @param ptrLoc - The pointer register address
 **********************************************************/
void TMP421_setPtrLoc(uint8_t ptrLoc) {
    
    //Set the pointer location
    Wire.beginTransmission(0x2A);   //begin
    Wire.write(ptrLoc);             //send the pointer location
    Wire.endTransmission();         //end
    delay(8);
}

/**********************************************************
 * GetTemperature
 *  Gets the current temperature from the sensor.
 *
 * @return float - The local temperature in degrees C
 **********************************************************/
float TMP421_GetTemperature(void) {
    uint8_t in[2];
    float frac = 0.0;
    uint8_t bit;
    
    TMP421_setPtrLoc(0x00);                //high-byte
    in[0] = TMP421_getRegisterValue();
    
    TMP421_setPtrLoc(0x10);                //low-byte
    in[1] = TMP421_getRegisterValue();
    in[1] >>=4;                     //shift-off the unused bits
    
    if (in[0] == -999 || in[1] == -999) {
        frac = -999;
    }
    else {
        /* Assemble the fraction */
        bit = in[1] & 0x01;
        frac += (bit * 0.5) * (bit * 0.5) * (bit * 0.5) * (bit * 0.5);
        
        in[1] >>= 1;
        bit = in[1] & 0x01;
        frac += (bit * 0.5) * (bit * 0.5) * (bit * 0.5);
        
        in[1] >>= 1;
        bit = in[1] & 0x01;
        frac += (bit * 0.5) * (bit * 0.5);
        
        in[1] >>= 1;
        bit = in[1] & 0x01;
        frac += (bit * 0.5);
        
        /* Add the MSB to the fraction */
        frac += in[0];
        
        /* frac is unsigned, make it signed to allow for negative temps */
        if (frac > 128.0)
            frac -= 256;
    }
    return frac;
}


void setup()
{
        Serial.begin(57600);
        pinMode(A2, INPUT);        // GND pin
        pinMode(A3, INPUT);        // VCC pin
        digitalWrite(A3, LOW);     // turn off pullups
        Wire.begin();
}
void loop()
{
    TMP421_1_temperature = TMP421_GetTemperature(); // Some error, check this out!
    Serial.print("WXSensor;");
    if (TMP421_1_temperature == -999) {
        #ifndef SILENCE_BAD_SENSORS
        Serial.print("TMP421_1_T_C:");
        Serial.print(TMP421_1_temperature, 2);
        Serial.print(";");
        #endif
    }
    else {
        Serial.print("TMP421_1_T_C:");
        Serial.print(TMP421_1_temperature, 2);
        Serial.print(";");
    }
    Serial.println("WXSensor");
}