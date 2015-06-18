void loop() {
    #ifdef debug_serial
    Serial.println("...entering Sensor Loop...");
    #endif //debug_serial
    //      while(1)
    //      {
    //       delay(1000);   
    //       #ifdef POST
    //       wdt_reset();
    //       #endif
    //      }
    
    
    
    #ifdef IR_D6T_44L_06_ADD
    if((EEPROM.read(14+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("IR_D6T_44L_06");
        Serial.flush();
        #endif //debug_serial
        data_check = D6T_get_data();
    }
    #endif //IR_D6T_44L_06_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef SHT15_ADD
    if((EEPROM.read(5+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("SHT_15");
        Serial.flush();
        #endif //debug_serial
        SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
        SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
        SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
        SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
    }
    #endif //SHT15_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef SHT75_ADD
    if((EEPROM.read(1+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("SHT75");
        Serial.flush();
        #endif //debug_serial
        SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
        #ifdef POST
        wdt_reset();
        #endif
        SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
        #ifdef POST
        wdt_reset();
        #endif
        SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
        #ifdef POST
        wdt_reset();
        #endif
        SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
    }
    #endif //SHT75_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef GA1A1S201WP_ADD
    if((EEPROM.read(10+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef POST
        wdt_reset();
        #endif
        #ifdef debug_serial
        Serial.println("GA1A1S201WP");
        Serial.flush();
        #endif //debug_serial
        AMBI_1_Value = analogRead(AMBI_1_Pin);
        //         AMBI_1_Value=0;
    }
    #endif //GA1A1S201WP_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef PhoRes_ADD
    if((EEPROM.read(16+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("PhoRes");
        Serial.flush();
        #endif //debug_serial
        PhoRes_1_Value = analogRead(PhoRes_PIN);
    }
    #endif //PhoRes_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef HTU21D_ADD
    if((EEPROM.read(18+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("HTU21D");
        Serial.flush();
        #ifdef POST
        wdt_reset();
        #endif
        #endif //debug_serial
        HTU21D_T = myHumidity.readTemperature();
        #ifdef POST
        wdt_reset();
        #endif
        HTU21D_H = myHumidity.readHumidity();
    }
    #endif //HTU21D_ADD
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef HIH4030_ADD
    if((EEPROM.read(7+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("HIH4030");
        Serial.flush();
        #endif //debug_serial
        HIH4030_1_Value = analogRead(HIH4030_PIN);
    }
    #endif //HIH4030_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef THERMIS_100K_ADD
    if((EEPROM.read(11+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("THERMIS_100K");
        Serial.flush();
        #endif //debug_serial
        THERMIS_1_Value = analogRead(THERMIS_100K_Pin);
    }
    #endif //THERMIS_100K_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef DS18B20_ADD
    if((EEPROM.read(8+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("DS18B20");
        Serial.flush();
        #endif //debug_serial
        DS18B20_1_temperature = DS18B20_1_getTemp();
    }
    #endif //DS18B20_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef TMP421_ADD
    if((EEPROM.read(13+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("TMP421");
        Serial.flush();
        #endif //debug_serial
        TMP421_1_temperature = TMP421_1.GetTemperature(); // Some error, check this out!
    }
    #endif //TMP421_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef RHT03_ADD
    if((EEPROM.read(3+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("RHT03");
        Serial.flush();
        #endif //debug_serial
        chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
    }
    #endif //RHT03_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef BMP180_ADD
    if((EEPROM.read(2+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("BMP180");
        Serial.flush();
        #endif //debug_serial
        BMP_180_1.getPressure(&BMP_180_1_pressure);
        BMP_180_1.getTemperature(&BMP_180_1_temperature);
    }
    #endif //BMP180_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef TMP102_ADD
    if((EEPROM.read(4+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("TMP102");
        Serial.flush();
        #endif //debug_serial
        err = Wire.requestFrom(tmp102_1_Address,2);
        if (err != 0) {
            byte tmp102_1_MSB = Wire.read();
            byte tmp102_1_LSB = Wire.read();
            tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32; //it's a 12bit int, using two's compliment for negative
        }
        else {
            tmp102_1_temperature = -999;
        }
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef HIH6130_ADD
    if((EEPROM.read(7+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("HIH6130");
        Serial.flush();
        #endif //debug_serial
        
        HIH_6130_1_hih.start();
        #ifdef POST
        wdt_reset();
        #endif
        HIH_6130_1_hih.update();
        #ifdef POST
        wdt_reset();
        #endif
        HIH_6130_1_hih.stop();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #ifdef debug_serial
    Serial.println("Get here");
    Serial.flush();
    #endif //debug_serial
    #endif //HIH6130_ADD
    //     Serial.println("GET HERE 2");
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef MLX90614_ADD
    if((EEPROM.read(9+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("MLX90614");
        Serial.flush();
        #endif //debug_serial
        start_err = i2c_start(dev+I2C_WRITE);
        #ifdef POST
        wdt_reset();
        #endif
        write_err = i2c_write(0x07);
        
        #ifdef POST
        wdt_reset();
        #endif
        // read
        rep_start_err = i2c_rep_start(dev+I2C_READ);
        #ifdef POST
        wdt_reset();
        #endif
        data_low = i2c_readAck(); //Read 1 byte and then send ack
        #ifdef POST
        wdt_reset();
        #endif
        data_high = i2c_readAck(); //Read 1 byte and then send ack
        #ifdef POST
        wdt_reset();
        #endif
        pec = i2c_readNak();
        // i2c_stop();
        #ifdef POST
        wdt_reset();
        #endif
        //This converts high and low bytes together and processes temperature, MSB is a error bit and is ignored for temps
        tempData = 0x0000; // zero out the data
        
        // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
        tempData = (double)(((data_high & 0x007F) << 8) + data_low);
        tempData = (tempData * tempFactor)-0.01;
        
        celcius = tempData - 273.15;
        fahrenheit = (celcius*1.8) + 32;
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif //MLX90614_ADD
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef HMC5883_ADD
    if((EEPROM.read(19+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("HMC5883");
        Serial.flush();
        #endif
        mag.getEvent(&HMC5883_event);
        /*
         *       // Changing for Verical mount
         *       HMC5883_heading = atan2(HMC5883_event.magnetic.y, HMC5883_event.magnetic.z);
         * 
         *       // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
         *       // Find yours here: http://www.magnetic-declination.com/
         *       // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
         *       // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
         *       HMC5883_declinationAngle = -0.052; //Chicago
         *       HMC5883_heading += HMC5883_declinationAngle;
         * 
         *       // Correct for when signs are reversed.
         *       if(HMC5883_heading < 0)
         *           HMC5883_heading += 2*PI;
         * 
         *       // Check for wrap due to addition of declination.
         *       if(HMC5883_heading > 2*PI)
         *           HMC5883_heading -= 2*PI;
         * 
         *       // Convert radians to degrees for readability.
         *       HMC5883_headingDegrees = HMC5883_heading * 180/M_PI;*/
    }
    #endif //HMC5883_ADD
    #ifdef POST
    wdt_reset();
    #endif
    
    //Interrupt based continuous sampling devices begin here
    for (unsigned int perform_loop = 0; perform_loop < MMA_Buff_size - 10 ; perform_loop ++ )
    {
        increment_time();
        #ifdef POST
        wdt_reset();
        #endif
        #ifdef debug_serial
        Serial.println("increment time");
        Serial.flush();
        #endif //debug_serial
        #ifdef POST
        wdt_reset();
        #endif
        delay(sleep_time_loop);
        #ifdef POST
        wdt_reset();
        #endif
        #ifdef debug_serial
        Serial.println("delay");
        Serial.flush();
        #endif //debug_serial
        #ifdef POST
        wdt_reset();
        #endif
        
    }
    //Serial.println("Completed Interrupt Based Continuous Sampling Devices");
    
    #ifdef MMA8452
    if((EEPROM.read(6+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("MMA8452");
        Serial.print("Number of samples:");
        Serial.println(q);
        Serial.flush();
        #endif //debug_serial
        #ifdef POST
        wdt_reset();
        #endif
        calc_MMA_RMS();
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef debug_serial
    Serial.print("Sensor");
    Serial.flush();
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    sensor_print();
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef debug_serial
    Serial.flush();
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    // #ifdef WindVel_ADD
    // pos = 0;
    // max_airspeed = 0;
    // #endif
    #ifdef MAX4466_ADD
    if((EEPROM.read(12+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("MAX4466");
        Serial.flush();
        #endif //debug_serial
        MAX4466_Value = 0;
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef MMA8452
    if((EEPROM.read(6+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("MMA8452");
        Serial.flush();
        #endif
        q = 0;
        xmean = 0;
        ymean = 0;
        zmean = 0;
        rt_mean_sq = 0;
        xvar = 0;
        yvar = 0;
        zvar = 0;
        mean_square_var = 0;
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef debug_serial
    Serial.flush();
    #endif //debug_serial
}
