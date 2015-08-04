/*Linear array to hold sensor data values
 * Each sensor stores its data in the order it appears in the data file
 * Programmer will need to know this ordering for graph to grab appropriate data
 */
var graph_data = [-999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999, -999];

function parse_data(data, iteration) {
	var avg_sum = 0;
	var n = 0;
	var graph_data_size = 0;
	var data_size = 0;
	
	//Loop through all the sensor objects
	for(var i=0; i<data.length; i++) {
		//Determine which sensor is being read to calculate and put data into appropriate place
		switch(data[i]["sensor_name"]) {
			case "D6T-44L-06.Omron.2012":
				avg_sum = 0;
				n = data[i]["value"].length;
				for(var j=1; j<data.length; j++) {
					avg_sum += parseFloat(data[i]["value"][j]);
				}

				//Casing temp., Avg. temp
				graph_data[0] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2)); //Placed in graph_data[0]

				graph_data[1] = parseFloat(parseFloat(avg_sum/n).toFixed(2));
				break;
			case "MMA8452Q.Freescale.8_1-2013":
				//Acc. x, Acc. y, Acc. z, Vibration
				graph_data[2] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[3] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2));
				graph_data[4] = parseFloat(parseFloat(data[i]["value"][2]).toFixed(2));
				graph_data[5] = parseFloat(parseFloat(data[i]["value"][3]).toFixed(2));
				break;
			case "DS18B20.Maxim.2008":
				//Temp
				graph_data[6] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "MLX90614ESF-DAA.Melexis.008-2013":
				//Temp
               		        graph_data[7] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "TMP102.Texas_Instruments.2008":
				//Temp
				graph_data[8] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "HIH6130.Honeywell.2011":
				//Temp, Hum
				graph_data[9] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[10] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2)); //Placed in graph_data[10]
				break;
			case "BMP180.Bosch.2_5-2013":
				//Temp, Pres
				graph_data[11] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[12] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2));
				break;
			case "PDV_P8104.API.2006":
				//Light Intensity
				graph_data[13] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "RHT03.Maxdetect.2011":
				//Temp, Hum
				graph_data[14] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[15] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2));
				break;
			case "HMC5883.Honeywell.2013":
				//Mag. x, Mag. y, Mag. z
				graph_data[16] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[17] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2));
				graph_data[18] = parseFloat(parseFloat(data[i]["value"][2]).toFixed(2));
				break;
			case "HTU21D.MeasSpec.2013":
				//Temp, Hum
				graph_data[19] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[20] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2)); //Placed in graph_data[20]
				break;
			case "SHT75.Sensirion.5_2011":
				//Temp, Hum
				graph_data[21] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[22] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2));
				break;
			case "MAX4466.Maxim.2001":
				//Acoustic Intensity
				graph_data[23] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "TMP421.Texas_Instruments.2012":
				//Temp
				graph_data[24] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "GA1A1S201WP.Sharp.2007":
				//Light Intensity
				graph_data[25] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "SHT15.Sensirion.4_3-2010":
				//Temp, Hum
				graph_data[26] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				graph_data[27] = parseFloat(parseFloat(data[i]["value"][1]).toFixed(2));
				break;
			case "HIH4030.Honeywell.2008":
				//Hum
				graph_data[28] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2));
				break;
			case "Thermistor_NTC_PR103J2.US_Sensor.2003":
				//Temp
				graph_data[29] = parseFloat(parseFloat(data[i]["value"][0]).toFixed(2)); //Placed in graph_data[29]
				break;
			default:
				//Invalid sensor read, User needs to add it here and in the graph.js file
				console.log("You forgot your Waggle Dance and now the other bees can't find their way to help out!\nAdd the sensor in the files so they can locate the digital pollen and produce good results!");
				break;
		}
	}
	if(init) {
		//Set all canvases to the initial value found from the parse
		for(var i = 0; i < BUFFER; i++) {
			canvas00[i].y = get_graph_data(14);
			canvas01[i].y = get_graph_data(15);
			canvas02[i].y = get_graph_data(19);
			canvas03[i].y = get_graph_data(20);
			canvas04[i].y = get_graph_data(9);
			canvas05[i].y = get_graph_data(10);
			canvas06[i].y = get_graph_data(7);
			canvas07[i].y = get_graph_data(2);
			canvas08[i].y = get_graph_data(3);
			canvas09[i].y = get_graph_data(4);
			canvas010[i].y = get_graph_data(5);
			canvas10[i].y = get_graph_data(26);
			canvas11[i].y = get_graph_data(27);
			canvas12[i].y = get_graph_data(1);
			canvas13[i].y = get_graph_data(0);
			canvas14[i].y = get_graph_data(28);
			canvas15[i].y = get_graph_data(8);
			canvas16[i].y = get_graph_data(29);
			canvas17[i].y = get_graph_data(16);
			canvas18[i].y = get_graph_data(17);
			canvas19[i].y = get_graph_data(18);
			canvas20[i].y = get_graph_data(21);
			canvas21[i].y = get_graph_data(22);
			canvas22[i].y = get_graph_data(11);
			canvas23[i].y = get_graph_data(12);
			canvas24[i].y = get_graph_data(6);
			canvas25[i].y = get_graph_data(24);
			canvas26[i].y = get_graph_data(25);
			canvas27[i].y = get_graph_data(13);
			canvas28[i].y = get_graph_data(23);
		}
	}
}

//Allow graph.js to grab the graph_data array
function get_graph_data(idx) {
	return graph_data[idx].toString();
}
