//Given a string, parse into appropriate tokens

/*Linear array to hold sensor data values
 * Each sensor stores its data in the order it appears in the data file
 * Programmer will need to know this ordering for graph to grab appropriate data
 */
 var graph_data = [];

 //Given a string, parse into appropriate tokens
function parse_data(data_str) {
	var sensor = [];
	var token = [];
	var data = [];
	var avg_sum = 0;
	var n = 0;
	var graph_data_size = 0;
	var token_size = 0;
	var data_size = 0;

	//Ensure graph_data is empty before proceeding
	if(graph_data.length > 0) {
		graph_data_size = graph_data.length;
		for(var a=0; a<graph_data_size; a++) {
			graph_data.pop();
		}
	}

	//Split the text file into an array holding a sensor dataset each index
	//Ex. sensor[0]: 1st sensor, sensor[1]: 2nd sensor...
	sensor = data_str.split("\n");

	//Loop through each sensor dataset and split into arrays holding partitioned data
	for(var i=0; i<sensor.length; i++) {
		//Ensure the token and data arrays are empty for each iteration
		if(token.length > 0) {
			token_size = token.length;
			for(var b=0; b<token_size; b++) {
				token.pop();
			}
		}

		if(data.length > 0) {
			data_size = data.length;
			for(var c=0; c<data_size; c++) {
				data.pop();
			}
		}

		//Parse the sensor data
		//Ex. token[0]: name, token[1]: date/time of reading, token[2]: 1st reading...
		token = sensor[i].split(",");

		//console.log("token["+i+"]: "+token[i]);

		//Loop through each sensor reading and split into array holding partitioned readings
		//Ex. data[0][0]: data type, data[0][1]: value, data[0][2]: units, data[0][3]: extra...
		for(var j=2; j<token.length; j++) {
			data[j-2] = token[j].split(";");

			//console.log("data["+j-2+"]: "+data[j-2]+" data[0][1]: "+data[0][1]+" End");
		}

		//Determine which sensor is being read to calculate and put data in appropriate place
		switch(token[0]) {
			case "D6T-44L-06.Omron.2012":
				avg_sum = 0;
				n = data.length - 1;
				for(var k=1; k<data.length; k++) {
					avg_sum += parseFloat(data[k][1]);
				}

				//Casing temp., Avg. temp
				graph_data.push(parseFloat(data[0][1]).toFixed(2)); //Placed in graph_data[0]
				graph_data.push(parseFloat(avg_sum/n).toFixed(2));
				break;
			case "MMA8452Q.Freescale.8_1-2013":
				//Acc. x, Acc. y, Acc. z, Vibration
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2));
				graph_data.push(parseFloat(data[2][1]).toFixed(2));
				graph_data.push(parseFloat(data[3][1]).toFixed(2));
				break;
			case "DS18B20.Maxim.2008":
				//Temp
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "MLX90614ESF-DAA.Melexis.008-2013":
				//Temp
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "TMP102.Texas_Instruments.2008":
				//Temp
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "HIH6130.Honeywell.2011":
				//Temp, Hum
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2)); //Placed in graph_data[10]
				break;
			case "BMP180.Bosch.2_5-2013":
				//Temp, Pres
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2));
				break;
			case "PDV_P8104.API.2006":
				//Light Intensity
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "RHT03.Maxdetect.2011":
				//Temp, Hum
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2));
				break;
			case "HMC5883.Honeywell.2013":
				//Mag. x, Mag. y, Mag. z
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2));
				graph_data.push(parseFloat(data[2][1]).toFixed(2));
				break;
			case "HTU21D.MeasSpec.2013":
				//Temp, Hum
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2)); //Placed in graph_data[20]
				break;
			case "SHT75.Sensirion.5_2011":
				//Temp, Hum
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2));
				break;
			case "MAX4466.Maxim.2001":
				//Acoustic Intensity
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "TMP421.Texas_Instruments.2012":
				//Temp
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "GA1A1S201WP.Sharp.2007":
				//Light Intensity
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "SHT15.Sensirion.4_3-2010":
				//Temp, Hum
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				graph_data.push(parseFloat(data[1][1]).toFixed(2));
				break;
			case "HIH4030.Honeywell.2008":
				//Hum
				graph_data.push(parseFloat(data[0][1]).toFixed(2));
				break;
			case "Thermistor_NTC_PR103J2.US_Sensor.2003":
				//Temp
				graph_data.push(parseFloat(data[0][1]).toFixed(2)); //Placed in graph_data[29]
				break;
			default:
				//Invalid sensor read, User needs to add it here and in the graph.js file
				alert("You forgot your Waggle Dance and now the other bees can't find their way to help out!\nAdd the sensor in the files so they can locate the digital pollen and produce good results!");
				break;
		}
	}
}

//Allow graph.js to grab the graph_data array
function get_graph_data(idx) {
	return graph_data[idx];
}