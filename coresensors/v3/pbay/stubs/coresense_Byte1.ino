
//#include <ctype.h>

/*char incoming[256] = "";
char * token;
char * taken;
String one = " ";
String two = " ";
*/
#define MAX_FMT_SIZE 6
byte formatted_data_buffer[MAX_FMT_SIZE];

char one;
char *KEY;
char *VAL;

char CMP[2];

int idx = 0;
int pre_idx = 0;

int SQ_idx = 0;

int key_id = 0;
int val_id = 0;

bool flag_KEY = false;
bool flag_SQ = false;

//bool flag_FIELD = false;
//bool flag_LINE = false;

int type = 0;

int SQ_num = 0;

char *carrier;
/*
uint8_t sqn = 0;
int type = 0;
int sq_num;
int form1;
int hex;
int form5;
int form2;
*/
void setup()
{
	SerialUSB.begin(115200);    //sendData
	while(!SerialUSB) {;}
	Serial.begin(115200);       //getData
	while(!Serial) {;}

	KEY = (char*)malloc(3);
	VAL = (char*)malloc(12);
	carrier = (char*)malloc(126);
}

void Put_KEY()
{
	//Serial.print(idx);
	if (flag_KEY)
		return;
	//Serial.println("put_key");
	flag_KEY = true;
	//Serial.println(pre_idx);
	int j = 0;
	//Serial.println(idx);
	for (int i = pre_idx; i < idx; i++)
	{
		carrier[i] = KEY[j];
		j++;
	}
	key_id = 0;
	pre_idx = idx;
	//Serial.println("put_key_end");
	//Serial.write(carrier, idx);
	//Serial.println(" ");
	//Serial.println("put_key_real_end");
	//Serial.write(KEY);
}

void Put_VAL()
{
	//Serial.println("put_val");
	if (!flag_KEY)
		return;
	//Serial.println("put_val_a");

	Formatting(KEY);
	
/*	int j = 0;
	for (int i = pre_idx; i < idx; i++)
	{
		carrier[i] = VAL[j];
		//Serial.println(VAL[j]);
		if (flag_SQ)
		{
			//Serial.println("put_sqn");
			//Serial.println(j);
			CMP[j] = VAL[j];
			//Serial.print(VAL[j]);
			//Serial.print(CMP[j]);
		}
		j++;
	}
	//Serial.println(CMP);
*/

	int j = 0;
	for (int i = pre_idx; i < idx; i++)
		carrier[i] = VAL[j];
/*
	if (flag_SQ)
	{
		for (int i = 0; i < 2; i++)
		{
			//Serial.println(i);
			CMP[i] = VAL[i];
			//Serial.println(VAL[i]);
			//Serial.println(CMP[i]);
			CMP = CMP % 4;
		}
		Serial.println(CMP);
	}
*/
/*
	if (flag_SQ)
	{
		Serial.println("put_sqn");
		//Serial.print(VAL);
		for (int i = 0; i < 3; i++)
		{
			Serial.println(i);
			CMP[i] = VAL[i];
			Serial.println(VAL[i]);
			Serial.println(CMP[i]);
		}
		Serial.println(CMP);
	}
*/
	val_id = 0;
	pre_idx = idx;
	flag_KEY = false;
	//flag_SQ = false;
	//Serial.write(VAL);
}

void Send_CARR()
{
	//Serial.print(idx);
	Serial.println("send_carr");
	if (!flag_KEY)
		return;
	// flush
	//Serial.write(idx);
	//Serial.println(" ");
	//Serial.write(carrier, idx);
	pre_idx = idx = 0;
}

void parsing(char in)
{
	switch(in) {
		case '=':
			Put_KEY();
			break;
		case ' ':
			Put_VAL();
			break;
		case '\r':
			Send_CARR();
			break;
		case 48 ... 57:	// numbers
		case 65 ... 90: // Upper case letter
		case 97 ... 122: // Lower case letter
			{
				//Serial.println(in);
				//Serial.print(in);
				if (!flag_KEY)
				{
					KEY[key_id] = in;
					key_id++;
					//Serial.print(KEY);
				}
				else
				{
					VAL[val_id] = in;
					val_id++;
				}
				idx++;
				break;
			} 
		default:
			break;
	}
}

void Formatting(char* KEY)
{
	//Serial.print("formatting");
	//Serial.print(KEY);
	//Serial.print("begins");
	if (strncmp(KEY, "BAD", 3) == 0)						//string
	{
		type = 0;
		//Serial.println("BAD found");
	}
	else if (strncmp(KEY, "SQN", 3) == 0)					//uint8
	{
		//flag_SQ = true;
		//Serial.println("sqn");
		SQ_idx++;
		SQ_idx = SQ_idx % 4;
		type = 1;
	}
	else if (strncmp(KEY, "SHH", 3) == 0 | strncmp(KEY, "LPP", 3) == 0)	//uint16 from string: format1
		type = 2;
	else if (strncmp(KEY, "SUV", 3) == 0 | strncmp(KEY, "SVL", 3) == 0 | strncmp(KEY, "SIR", 3) == 0)	//uint16 from hex deciamal from string: format1
		type = 3;
	else if (SQ_idx = 1)  			//the last for if else, int24: format5
	{
		Serial.print("CMP");
		type = 4;
	}
	else							//for default, int16: format2
		type = 9;


/*

	switch(type)
	{
	case 0:	//string "BAD"
		//Serial.println(two);
		break;

	case 1:	//uint8 "SQN"
	    SQ_num = (int)strtol(VAL.c_str(), NULL, 16);   //hex string to int
	    //Serial.println(sqn);
		SQ_num = SQ_num % 4;
		//Serial.println("sqn");
		//Serial.println(sqn);
	    }
	    break;

	case 2: 	//uint16 from string: format1 "SHH"
	    form1 = two.toInt();
	    format1(form1);
	    //Serial.println(form1);
	    Serial.write(formatted_data_buffer, 3);
	    break;

	case 3: 	//uint16 from hex deciamal from string: format1 "SUV" "SVL" "SIR"
	    hex = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
	    format1(hex);
	    //Serial.println(hex);
	    Serial.write(formatted_data_buffer, 2);
	    break;

	case 4:	//int24: format5 sqn == 1 & two != "1"
	    form5 = two.toInt();
	    format5(form5);
	    //Serial.println(form5);
	    Serial.write(formatted_data_buffer, 3);
	    break;

	default:
	    form2 = two.toInt();
	    format2(form2);
	    //Serial.println(form2);
	    Serial.write(formatted_data_buffer, 2);
	    break;
    }*/
}

void loop()
{
	while (SerialUSB.available() > 0) 
	{
		one = SerialUSB.read();     //read the incoming byte
		//SerialUSB.readBytes(one, 1);
		//Serial.print(one);
		//Serial.print(*KEY);
		//Serial.println(one);
		//Serial.print(one);
		parsing(one);
		//Serial.write(one);
/*
		if (flag_KEY == false)
		{
			KEY[key_id] = one;
			key_id++;
			idx++;
		}
		else if (flag_FIELD = false)
		{
			VAL[val_id] = one;
			val_id++;
			idx++;

			if (KEY == "BAD")					//string
				type = 0;
			else if (KEY == "SQN")					//uint8
				type = 1;
			else if (KEY == "SHH" | KEY == "LPP")					//uint16 from string: format1
				type = 2;
			else if (KEY == "SUV" | KEY == "SVL" | KEY == "SIR")	//uint16 from hex deciamal from string: format1
				type = 3;
//			else if (sqn == 1 & two != "1")  			//the last for if else, int24: format5
//				type = 4;
			else							//for default, int16: format2
				type = 9;

			idx++;
		}
		else
		{

		}
*/
//	if (one == "A" | one == "B" | one == "C" | one == "G"
    //}

/*    while (1)
    {
	SerialUSB.readBytes(incoming, 1);
	int num = atoi(one);
	Serial.print(one);
	Serial.print(" ");
	Serial.print(num);

	if (one == "a")
	{
	    KEY[idx] = one;
	    idx++;
	}
	else
	{
	    int j = 0;
	    for (int i = pre_idx; i = idx; i++)
	    {
		carrier[i] = KEY[j];
		j++;
	    }
	    pre_idx = idx;
	}
*/

/*
	token = strtok(incoming, " ");
//	taken = token;
//	Serial.println(token);

	while (token != NULL)
	{
	    String one = " ";
	    one = token;	   

	    String oneP = one.substring(0, 3);
	    two = one.substring(4);	
	    //Serial.println(two);

	    if (oneP == "BAD")					//string
		type = 0;
	    else if (oneP == "SQN")					//uint8
		type = 1;
	    else if (oneP == "SHH" | oneP == "LPP")					//uint16 from string: format1
		type = 2;
	    else if (oneP == "SUV" | oneP == "SVL" | oneP == "SIR")	//uint16 from hex deciamal from string: format1
		type = 3;
	    else if (sqn == 1 & two != "1")  			//the last for if else, int24: format5
		type = 4;
	    else							//for default, int16: format2
		type = 9;

	    //Serial.print(two);
	    //Serial.print(" "); 

	    switch(type)
	    {
		case 0:	//string "BAD"
		    //Serial.println(two);
		    break;

		case 1:	//uint8 "SQN"
		    sq_num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    sqn = sq_num;
		    //Serial.println(sqn);

		    while (sqn > 4)
		    {
			sqn = sqn % 4;
			//Serial.println("sqn");
			//Serial.println(sqn);
		    }
		    break;

		case 2: 	//uint16 from string: format1 "SHH"
		    form1 = two.toInt();
		    format1(form1);
		    //Serial.println(form1);
		    Serial.write(formatted_data_buffer, 3);
		    break;

		case 3: 	//uint16 from hex deciamal from string: format1 "SUV" "SVL" "SIR"
		    hex = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    format1(hex);
		    //Serial.println(hex);
		    Serial.write(formatted_data_buffer, 2);
		    break;

		case 4:	//int24: format5 sqn == 1 & two != "1"
		    form5 = two.toInt();
		    format5(form5);
		    //Serial.println(form5);
		    Serial.write(formatted_data_buffer, 3);
		    break;

		default:
		    form2 = two.toInt();
		    format2(form2);
		    //Serial.println(form2);
		    Serial.write(formatted_data_buffer, 2);
		    break;
	    }

	    Serial.println(" ");

	    token = strtok(NULL, " ");
	    one = " ";
	    two = " ";
	}
*/

	//one = null;
	//memset(KEY, 0, 3);
    }
}
