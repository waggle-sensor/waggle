void testnew ()
{

    SerialUSB.println(">>>>>> Airsense Environmental Sensors Test <<<<<<");
    SerialUSB.println(" ");
    SerialUSB.print("Unique Board ID - ");

    for (byte i = 2; i < 8; i++)
    {
        SerialUSB.print(MAC_ID[i],HEX);
        if (i < 7)
        {
            SerialUSB.print(".");
        }

    }
    SerialUSB.println("");

    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif

    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif

    SerialUSB.println(" ");
    SerialUSB.println(">>>>>> Test Finished <<<<<<");

    while(1)
    {
        delay(1);
    }


}
