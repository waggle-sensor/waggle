
#define MAX_FMT_SIZE 6
byte formatted_data_buffer[MAX_FMT_SIZE];

char one;
char *KEY;
char *VAL;
//char KEY[3];
//char VAL[12];
char *carrier;
char CMP[2];

int idx = 0;
int pre_idx = 0;
int SQ_num = 0;
	
int key_id = 0;
int val_id = 0;

bool flag_KEY = false;
bool flag_CMP = false;

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
	if (flag_KEY)
		return;
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
	//Serial.write(KEY);
}

void Put_VAL()
{
	if (!flag_KEY)
		return;

	Formatting(KEY);

	int j = 0;
	for (int i = pre_idx; i < idx; i++)
	{
		carrier[i] = VAL[j];
		if (flag_CMP)
		{
			SQ_num = SQ_num % 4;	
			//Serial.println(SQ_num);
			CMP[j] = VAL[j];
		}
		j++;
	}

	val_id = 0;
	pre_idx = idx;
	flag_KEY = false;
	flag_CMP = false;
	//flag_SQ = false;
	//Serial.write(VAL);
}

void Send_CARR()
{
	//Serial.print("send_carr");
	if (!flag_KEY)
		return;
	// flush
	//Serial.println(" ");
	//Serial.write(carrier, idx);
	
	flag_KEY = false;
	pre_idx = idx = 0;
	SQ_num++;
	//Serial.println(CMP);
}

void parsing(char in)
{
	switch(in) 
	{
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
	int type = 9;

	if (strncmp(KEY, "BAD", 3) == 0)						//string
		type = 0;
	else if (strncmp(KEY, "SQN", 3) == 0)					//uint8
	{
		flag_CMP = true;
		type = 1;
	}
	else if (strncmp(KEY, "SHH", 3) == 0 | strncmp(KEY, "LPP", 3) == 0)	//uint16 from string: format1
		type = 2;
	else if (strncmp(KEY, "SUV", 3) == 0 | strncmp(KEY, "SVL", 3) == 0 | strncmp(KEY, "SIR", 3) == 0)	//uint16 from hex deciamal from string: format1
		type = 3;
	else if (strncmp(CMP, "01", 2) == 0)  			//the last for if else, int24: format5
	{
		//Serial.print ("SQ=1");
		type = 4;
	}
	else							//for default, int16: format2
		type = 9;

	int SQ_num;
	int j = 0;

//	char obj[2];
//	strncpy(VAL, 
	
	char tmp[val_id];
	strncpy(tmp, VAL, val_id);

	switch(type)
	{
		case 0:	//string "BAD"
			//Serial.println(two);
			break;

		case 1:	//uint8 "SQN"
		{
			//Serial.println("sqn");
			SQ_num = (int)strtol(tmp, NULL, 16);   //hex string to int
			Serial.println(SQ_num);
			//SQ_num = SQ_num % 4;
			//Serial.println("sqn");
			//Serial.println(sqn);
			break;
		}

		case 2: 	//uint16 from string: format1 "SHH"
			unsigned int form1;
			form1 = (unsigned int)atoi(tmp);
			format1(form1);
			//Serial.println(form1);
			Serial.write(formatted_data_buffer, 2);
			Serial.print(formatted_data_buffer[0]);
			for (int i = pre_idx; i < pre_idx + 2; i++)
			{
				carrier[i] = formtted_data_buffer[j];
				j++;
			}
			break;
/*
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
			break;*/

		default:
	//	    form2 = two.toInt();
	//	    format2(form2);
			//Serial.println(form2);
	//	    Serial.write(formatted_data_buffer, 2);
			break;
    }
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
    }
}
