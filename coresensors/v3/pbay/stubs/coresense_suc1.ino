char incoming[256] = "";
char * token;

void setup()
{
    SerialUSB.begin(115200);    //sendData
    while(!SerialUSB) {;}
    Serial.begin(115200);       //getData
    while(!Serial) {;}
}

void loop()
{
    SerialUSB.println(">>get data packets and parse and send back?<<");
    while (1)
    {
        SerialUSB.println("...");
	SerialUSB.readBytes(incoming, 256);
//	Serial.write(incoming);

	token = strtok(incoming, " ");
//	Serial.println(token);

	while (token != NULL)
	{
	    String one = " ";
	    one = token;
//	    Serial.println(token);	   

//	    if (one.substring(0, 1) != ">")
//	    {
		Serial.print(one.substring(0, 3));
		Serial.print(" ");

		String two = " ";
		two = one.substring(4);	
//		Serial.println(two);

		if (one.substring(0, 3) == "BAD")
		{
		    Serial.println(two);
		}
		else
		{
		    Serial.print(two.toInt());
		    Serial.print(" ");
		}
//	    }
//	    else
//	    {
//		Serial.println(one.substring(1, 4));
//		Serial.println(one.substring(5));
//	    }

	    token = strtok(NULL, " ");
	}
	memset(incoming, 0, 256);
    }
}
