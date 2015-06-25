//Given a string, parse into appropriate tokens

function parse_data(data) {
	var sensor = [];
	var token = [];
	var name = "";

	var populate = [];

	sensor = data.split("\n");

	for(var i=0; i<sensor.length; i++) {
		token[i] = sensor[i].split(",");

		for(var test_idx=0; test_idx<token[i].length; test_idx++) {
			console.log("token["+i+"]["+test_idx+"]: "+token[i][test_idx]);
		}

		for(var j=2; j<token[i].length; j++) {
			data[j-2] = token[i][j].split(";");
		}

		//Determine which sensor is being read to put data in appropriate queue
		switch(token[i][0]) {
			case "D6T-44L-06.Omron.2012":
				//poplulate.push("");
				break;
			case "MMA8452Q.Freescale.8_1-2013":
				//TODO
				break;
			case "DS18B20.Maxim.2008":
				//TODO
				break;
			case "MLX90614ESF-DAA.Melexis.008-2013":
				//TODO
				break;
			case "TMP102.Texas_Instruments.2008":
				//TODO
				break;
			case "HIH6130.Honeywell.2011":
				//TODO
				break;
			case "BMP180.Bosch.2_5-2013":
				//TODO
				break;
			case "PDV_P8104.API.2006":
				//TODO
				break;
			case "RHT03.Maxdetect.2011":
				//TODO
				break;
			case "HMC5883.Honeywell.2013":
				//TODO
				break;
			case "HTU21D.MeasSpec.2013":
				//TODO
				break;
			case "SHT75.Sensirion.5_2011":
				//TODO
				break;
			case "MAX4466.Maxim.2001":
				//TODO
				break;
			case "TMP421.Texas_Instruments.2012":
				//TODO
				break;
			case "GA1A1S201WP.Sharp.2007":
				//TODO
				break;
			case "SHT15.Sensirion.4_3-2010":
				//TODO
				break;
			case "HIH4030.Honeywell.2008":
				//TODO
				break;
			case "Thermistor_NTC_PR103J2.US_Sensor.2003":
				//TODO
				break;
			default:
				//TODO: Create a new queue
				break;
		}
	}
}