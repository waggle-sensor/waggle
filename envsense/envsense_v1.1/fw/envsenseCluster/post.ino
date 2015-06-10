#ifdef POST


void post() { 
    byte testing_bit = EEPROM.read(testing_addr); 
    // Do I have to start testing or am I in the middle of a test?
    byte current_sensor = 1; 
    // which sensor am I going to be testing, starts with 1, but if I rebooted in 
    // the middle of the previous test, this number will get updated later in 
    // the code
    
    if(testing_bit==0)      // Just beginning POST
    {
        Serial.println("Commencing POST");
        Serial.flush();
        for(byte i = 1; i <= numSensors; i++)
        {
            EEPROM.write(i, 0);     // clear "tested" array
            
            byte history = EEPROM.read(i+128);
            history = history << 1;         // left shift "passed" array to shift history
            EEPROM.write(i+128, history); 
        }
        EEPROM.write(testing_addr, 1);   // POST has begun
    }
    
    
    // Post in progress, continuing from last time. 
    else        
    {
       // obtain next sensor to be tested - start from the sensor following the
       // one that led to watchdog triggered reset. 
       for(byte j = 1; j <= numSensors; j++)
       {
           if(EEPROM.read(j)==1)
           {
               current_sensor=j;
           }
       }
       current_sensor++;
       Serial.print("Test Failed, resuming from sensor ");
       Serial.println(current_sensor);
       Serial.flush();
    }
    
//     testing_bit = EEPROM.read(testing_addr);
//     if(testing_bit==1)  // continue to watchdog testing loop
//     {
    wdt_enable(WDTO_2S);    // Two Second Watchdog enabled
    for(byte k = current_sensor; k<=numSensors; k++)     // Test Sensors
    {
        
        #ifdef SHT75_ADD              // k=1
        if(k==1)
        {
            EEPROM.write(k,1);
            Serial.print("Testing SHT75\t");
            Serial.flush();
                            
            // reading sensor, if this hangs, the watchdog will not be reset in time and 
            // the board will reboot
            // Test is repeated 10x to ensure sensor functionality
            float SHT75_1_temperature;
            float SHT75_1_humidity;
            uint16_t SHT75_1_rawData;
            uint8_t SHT75_1_error;
            for(int a = 0; a<10; a++)
            // Perform test 10x to ensure accuracy
            {
                SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
                SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
                SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
                SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
                wdt_reset();
                delay(500);     // 
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        #ifdef BMP180_ADD             // k=2
        if(k==2)
        {
            EEPROM.write(k, 1);
            
            Serial.print("Testing BMP\t");
            Serial.flush();
            Wire.begin();
            Adafruit_BMP085_Unified BMP_180_2 = Adafruit_BMP085_Unified(10085);
            float BMP_180_2_temperature, BMP_180_2_pressure;
            BMP_180_2.begin();
            
            for(int a = 0; a<10; a++)
            {
                BMP_180_2.getTemperature(&BMP_180_2_temperature);
                BMP_180_2.getPressure(&BMP_180_2_pressure);
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif          
                    // Single Wire devices
        #ifdef RHT03_ADD              // k=3
        if(k==3)
        {
            EEPROM.write(k, 1);
            Serial.print("Testing RHT03\t");
            Serial.flush();
            
            dht RHT03_1;
            int chk_RHT03_1;
            
            for(int a = 0; a<10; a++)
            {
                chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        #ifdef TMP102_ADD             // k=4
        if(k==4)
        {
            EEPROM.write(k, 1);
            
            const int tmp102_1_Address = 0x48;
            float tmp102_1_temperature;
            byte tmp102_1_MSB, tmp102_1_LSB;
            int err;
            Wire.begin();
            
            Serial.print("Testing TMP102\t");
            Serial.flush();
            for(int a = 0; a<10; a++)
            {
                err = Wire.requestFrom(tmp102_1_Address,2);
                if (err != 0) {
                    byte tmp102_1_MSB = Wire.read();
                    byte tmp102_1_LSB = Wire.read();
                    tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32; //it's a 12bit int, using two's compliment for negative
                }
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);        // Update history
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif

        // Two Wire devices
        #ifdef SHT15_ADD              // k=5
        #define SHT15_1_dataPin  11     // SHT15_1 serial data
        #define SHT15_1_sclkPin  12     // SHT15_1 serial clock
        if(k==5)
        {
            EEPROM.write(k, 1);
            
            float SHT15_1_temperature;
            float SHT15_1_humidity;
            uint16_t SHT15_1_rawData;
            uint8_t SHT15_1_error;
            
            Serial.print("Testing SHT15\t");
            Serial.flush();
            
            Sensirion SHT15_1_tempSensor = Sensirion(SHT15_1_dataPin, SHT15_1_sclkPin);
            for(int a = 0; a<10; a++)
            {
                SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
                SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
                SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
                SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif

        #ifdef MMA8452        // k=6
        if(k==6)
        {
            EEPROM.write(k,1);
            int accelCount[3]; // Stores the 12-bit signed value
            float accelG[3]; // Stores the real accel value in g's
            
            Serial.print("Testing MMA\t");
            Serial.flush();

//                 #ifndef I2C_INIT_ADD
//                 i2c_init();
//                 #endif //I2C_INIT_ADD
//                 
//                 MMA_found = initMMA8452();
            for(int a = 0; a<10; a++)
            {
//                 bool good_data = readAccelData(accelCount); // Read the x/y/z adc values
            
                MMA_found = initMMA8452();
                MMA8452_get_means();
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        #ifdef HIH6130_ADD            // k=7
        if(k==7)
        {
            EEPROM.write(k,1);
            Serial.print("Testing HIH6130\t");
            Serial.flush();
            
            for(int a = 0; a<10; a++)
            {
                HIH_6130_1_hih.start();
                HIH_6130_1_hih.update();
                HIH_6130_1_hih.humidity();
                HIH_6130_1_hih.temperature();
                HIH_6130_1_hih.stop();
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        // // 1-wire devices
        #ifdef DS18B20_ADD            // k=8
        if(k==8)
        {
            EEPROM.write(k,1);
            Serial.print("Testing DS18B20\t");
            Serial.flush();
            for(int a = 0; a<10; a++)
            {
                float data = DS18B20_1_getTemp();
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif

        
        #ifdef MLX90614_ADD   // k=9
        if(k==9)
        {
            EEPROM.write(k,1);
            Serial.print("Testing MLX\t");
            Serial.flush();
            
            i2c_init(); //Initialise the i2c bus
            #define I2C_INIT_ADD 1
            for(int a = 0; a<10; a++)
            {
                PORTC = (1 << PORTC4) | (1 << PORTC5);//enable pullups
                
                start_err = i2c_start(dev+I2C_WRITE);
                write_err = i2c_write(0x07);

                
                start_err = i2c_start(dev+I2C_WRITE);
                write_err = i2c_write(0x07);

                // read
                rep_start_err = i2c_rep_start(dev+I2C_READ);
                data_low = i2c_readAck(); //Read 1 byte and then send ack
                data_high = i2c_readAck(); //Read 1 byte and then send ack
                pec = i2c_readNak();
                i2c_stop();       
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        // Analog Inputs
        #ifdef GA1A1S201WP_ADD       // k=10
        if(k==10)
        {
            EEPROM.write(k, 1);
            Serial.print("Testing GA1A\t");
            Serial.flush();
            for(int a = 0; a<10; a++)
            {
                AMBI_1_Value = analogRead(AMBI_1_Pin);
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif

                    
        #ifdef THERMIS_100K_ADD      // k=11
        if(k==11)
        {
            EEPROM.write(k, 1);
            Serial.print("Testing THERMIS\t");
            Serial.flush();
            
            for(int a = 0; a<10; a++)
            {
                THERMIS_1_Value = analogRead(THERMIS_100K_Pin);
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif

                    
        #ifdef MAX4466_ADD          // k=12
        if(k==12)
        {
            EEPROM.write(k, 1);
            Serial.print("Testing MAX\t");
            Serial.flush();
            for(int a = 0; a<10; a++)
            {
//                 int data = analogRead(MAX4466_PIN);
                MAX4466_get_max();
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        #ifdef TMP421_ADD           // k=13
        if(k==13)
        {
            EEPROM.write(k, 1);
            pinMode(A2, INPUT);        // GND pin
            pinMode(A3, INPUT);        // VCC pin
            digitalWrite(A3, LOW);     // turn off pullups
            
            Serial.print("Testing TMP421\t");
            Serial.flush();
            
            for(int a = 0; a<10; a++)
            {
                TMP421_1_temperature = TMP421_1.GetTemperature();
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }                
        #endif
        
        #ifdef IR_D6T_44L_06_ADD    // k=14
        if(k==14)
        {
            EEPROM.write(k,1);
            Serial.print("Testing IR_D6T\t");
            Serial.flush();

            int rbuf[35];
            float tdata[16];
            float t_PTAT;
            float tPEC;
            bool data_check;
            
            #ifndef I2C_INIT_ADD
            i2c_init();
            #define I2C_INIT_ADD 1
            #endif //I2C_INIT_ADD
            pinMode(17,OUTPUT);    // Power (VCC) for setting D17 (A3) pin
            digitalWrite(17,HIGH);
            pinMode(16,OUTPUT);    // Power supply (GND) for setting D16 (A2) pin
            digitalWrite(16,LOW);
            pinMode(A4,INPUT);
            digitalWrite(A4,HIGH); // Pull-up resistor for SDA
            pinMode(A5,INPUT);
            digitalWrite(A5,HIGH); // Pull-up resistor for SCL
            
            for(int a = 0; a<10; a++)
            // Perform test 10x
            {
                bool temp = D6T_get_data(); // Read sensor
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            i2c_stop();
            
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        #ifdef HIH4030_ADD          // k=15
        if(k==15)
        {
            EEPROM.write(k, 1);
            Serial.print("Testing HIH4030\t");
            Serial.flush();
            for(int a = 0; a<10; a++)
            // Perform test 10 times
            {
                HIH4030_1_Value = analogRead(HIH4030_PIN);  // Read sensor
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif

                    
        #ifdef PhoRes_ADD           // k=16
        if(k==16)
        {
            EEPROM.write(k,1);
            Serial.print("Testing PhoRes\t");
            Serial.flush();
            for(int a = 0; a<10; a++)
            // Perform test 10 times
            {
                PhoRes_1_Value = analogRead(PhoRes_PIN);    // Read sensor
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
                    
        #ifdef WindVel_ADD           // k=17, untested
        if(k==17)
        {
            EEPROM.write(k,1);
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
        }
        #endif

        #ifdef HTU21D_ADD            // k=18
        if(k==18)
        {
            EEPROM.write(k, 1);
            
            Serial.print("Testing HTU21D\t");
            Serial.flush();
            
            myHumidity.begin();
            
            if(myHumidity.readHumidity()!=998 && myHumidity.readTemperature()!=998)
            //  HTU21D built in function returns 998 for temp and/or humidity if timeout 
            {   
                wdt_reset();
                byte history = EEPROM.read(k+128);
                history = history | 0x01;           // Demonstrate successful test pass
                EEPROM.write(k+128,history);
                Serial.print("Test passed successfully: History = ");
                Serial.println(history);
                Serial.flush();
                wdt_reset();
            }
            else
            {
                Serial.println("\nTest failed, resuming from sensor 19");
            }
        }
        #endif
        wdt_reset();

        #ifdef HMC5883_ADD          // k=19
        if(k==19)
        {
            EEPROM.write(k, 1);
            Serial.print("Testing HMC\t");
            Serial.flush();
            
            Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23181);
            sensors_event_t HMC5883_event;
            
            
            mag.begin();
            for(int a = 0; a<10; a++)
            // Perform test 10 times
            {
                mag.getEvent(&HMC5883_event);   // read sensor
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(k+128);
            history = history | 0x01;           // Demonstrate successful test pass
            EEPROM.write(k+128,history);
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            wdt_reset();
        }
        #endif
        
        wdt_reset();
    }
    EEPROM.write(testing_addr, 0);      // Self test complete
    Serial.println("POST TEST RESULTS:");
    Serial.print("SHT75:\t\t");
//     if((int)(EEPROM.read(1+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("BMP180:\t\t");
//     if((int)(EEPROM.read(2+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("RHT03:\t\t");
//     if((int)(EEPROM.read(3+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("TMP102:\t\t");
//     if((int)(EEPROM.read(4+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("SHT15:\t\t");
//     if((int)(EEPROM.read(5+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("MMA8452:\t");
//     if((int)(EEPROM.read(6+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("HIH6130:\t");
//     if((int)(EEPROM.read(7+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("DS18B20:\t");
//     if((int)(EEPROM.read(8+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("MLX90614\t");
//     if((int)(EEPROM.read(9+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("GA1A1S201WP:\t");
//     if((int)(EEPROM.read(10+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("THERMIS_100K:\t");
//     if((int)(EEPROM.read(11+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("MAX4466:\t");
//     if((int)(EEPROM.read(12+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("TMP421:\t\t");
//     if((int)(EEPROM.read(13+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("IR_D6T:\t\t");
//     if((int)(EEPROM.read(14+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("HIH4030:\t");
//     if((int)(EEPROM.read(15+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("PhoRes:\t\t");
//     if((int)(EEPROM.read(16+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("WindVel:\t");
//     if((int)(EEPROM.read(17+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("HTU21D:\t\t");
//     if((int)(EEPROM.read(18+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
// 
//     Serial.print("HMC5883:\t");
//     if((int)(EEPROM.read(19+128) & Consistency_Mask) == (int)Consistency_Mask)
//         Serial.println("Functioning");
//     else
//         Serial.println("Offline");
    
    if((EEPROM.read(1+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("BMP180:\t\t");
    if((EEPROM.read(2+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("RHT03:\t\t");
    if((EEPROM.read(3+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("TMP102:\t\t");
    if((EEPROM.read(4+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("SHT15:\t\t");
    if((EEPROM.read(5+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("MMA8452:\t");
    if((EEPROM.read(6+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("HIH6130:\t");
    if((EEPROM.read(7+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("DS18B20:\t");
    if((EEPROM.read(8+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("MLX90614\t");
    if((EEPROM.read(9+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("GA1A1S201WP:\t");
    if((EEPROM.read(10+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("THERMIS_100K:\t");
    if((EEPROM.read(11+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("MAX4466:\t");
    if((EEPROM.read(12+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("TMP421:\t\t");
    if((EEPROM.read(13+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("IR_D6T:\t\t");
    if((EEPROM.read(14+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("HIH4030:\t");
    if((EEPROM.read(15+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("PhoRes:\t\t");
    if((EEPROM.read(16+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("WindVel:\t");
    if((EEPROM.read(17+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("HTU21D:\t\t");
    if((EEPROM.read(18+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.print("HMC5883:\t");
    if((EEPROM.read(19+128) & Consistency_Mask) == Consistency_Mask)
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.flush();
    wdt_reset();
}
#endif   
