/*
 * data.js maintains a queue for each set of sensor data and updates the graph each time interval
 */

 //Global variables


 //Set a timer to update the page every second
 function timer() {
 	//setInterval(function() {update_time(); update();}, 1000);
 	setInterval(function() {update_time(); test_parse();}, 1000);
 }

 //Update the time on the webpage
 function update_time() {
 	var date = new Date();
 	var year = date.getFullYear();
 	var month = date.getMonth();
 	var day = date.getDate();
 	var hr = date.getHours();
 	var min = date.getMinutes();
 	var sec = date.getSeconds();
 	var month_str = "";
 	var am_pm = "";

 	switch(month) {
 		case 0:
 			month_str = "Jan";
 			break;
 		case 1:
 			month_str = "Feb";
 			break;
 		case 2:
 			month_str = "Mar";
 			break;
 		case 3:
 			month_str = "Apr";
 			break;
 		case 4:
 			month_str = "May";
 			break;
 		case 5:
 			month_str = "Jun";
 			break;
 		case 6:
 			month_str = "Jul";
 			break;
 		case 7:
 			month_str = "Aug";
 			break;
 		case 8:
 			month_str = "Sep";
 			break;
 		case 9:
 			month_str = "Oct";
 			break;
 		case 10:
 			month_str = "Nov";
 			break;
 		case 11:
 			month_str = "Dec";
 			break;
 		default:
 			month_str = "";
 	}

 	if(hr == 0) {
 		hr = 12;
 		am_pm = "am";
 	}
 	else if(hr >= 12) {
 		if(hr > 12) {
 			hr -= 12;
 		}
 		am_pm = "pm";
 	}
 	else {
 		am_pm = "am";
 	}
 	document.getElementById("date").innerHTML = month_str.concat(" "+day.toString()+", "+year.toString());
 	document.getElementById("time").innerHTML = hr.toString().concat(":"+((min < 10) ? "0"+min.toString() : min.toString())+":"+((sec < 10) ? "0"+sec.toString() : sec.toString())+" "+am_pm);
 }

 function test_parse() {
 	var data = "";
 	data = "D6T-44L-06.Omron.2012,06/18/15 02:52:19,Temperature;-30.59;C;PTAT,Temperature;-30.59;C;1x1,Temperature;-30.59;C;1x2,Temperature;-30.59;C;1x3,Temperature;-30.59;C;1x4,Temperature;-30.59;C;2x1,Temperature;-30.59;C;2x2,Temperature;-30.59;C;2x3,Temperature;-30.59;C;2x4,Temperature;-30.59;C;3x1,Temperature;-30.59;C;3x2,Temperature;-30.59;C;3x3,Temperature;-30.59;C;3x4,Temperature;-30.59;C;4x1,Temperature;-30.59;C;4x2,Temperature;-30.59;C;4x3,Temperature;-30.59;C;4x4\nMMA8452Q.Freescale.8_1-2013,06/18/15 02:52:19,Acceleration;-4.17;g;X,Acceleration;9.25;g;Y,Acceleration;3.47;g;Z,Vibration;7.09;g;RMS_3Axis\nDS18B20.Maxim.2008,06/18/15 02:52:19,Temperature;-30.59;C;none\nMLX90614ESF-DAA.Melexis.008-2013,06/18/15 02:52:19,Temperature;-24.05;F;none\nTMP102.Texas_Instruments.2008,06/18/15 02:52:19,Temperature;-24.05;F;none\nHIH6130.Honeywell.2011,06/18/15 02:52:19,Temperature;-30.59;C;none,Humidity;249;%RH;none\nBMP180.Bosch.2_5-2013,06/18/15 02:52:19,Temperature;-30.59;C;none,Pressure;999655.351061;PA;Barometric\nPDV_P8104.API.2006,06/18/15 02:52:19,Luminous_Intensity;809;Units10B0V5;Voltage_Divider_5V_PDV_Tap_4K7_GND\nRHT03.Maxdetect.2011,06/18/15 02:52:19,Temperature;-30.59;C;none,Humidity;592;%RH;RH\nHMC5883.Honeywell.2013,06/18/15 02:52:19,Magnetic_Field;-3.56;gauss;X,Magnetic_Field;-4.53;gauss;Y,Magnetic_Field;1.08;gauss;Z\nHTU21D.MeasSpec.2013,06/18/15 02:52:19,Temperature;-30.59;C;none,Humidity;18;%RH;RH\nSHT75.Sensirion.5_2011,06/18/15 02:52:19,Temperature;-30.59;C;none,Humidity;862;%RH;RH\nMAX4466.Maxim.2001,06/18/15 02:52:19,Acoustic_Intensity;911;Units10B0V5;non-standard\nTMP421.Texas_Instruments.2012,06/18/15 02:52:19,Temperature;-30.59;C;none\nGA1A1S201WP.Sharp.2007,06/18/15 02:52:19,Luminous_Intensity;99;Units10B0V5;non-standard\nSHT15.Sensirion.4_3-2010,06/18/15 02:52:19,Temperature;-30.59;C;none,Humidity;338;%RH;RH\nHIH4030.Honeywell.2008,06/18/15 02:52:19,Humidity;420;Units10B0V5;RH\nThermistor_NTC_PR103J2.US_Sensor.2003,06/18/15 02:52:19,Temperature;399;Units10B0V5;Voltage_Divider_5V_NTC_Tap_68K_GND"
	parse_data(data);
 }

 //Update the data on the webpage
 function update() {
 	var data = new XMLHttpRequest();

 	//Change this to the appropriate server address
 	data.open("GET", "http://127.0.0.1:31338/Volumes/Argonne/repos/waggle_version0.3_nathan/www/sensor_page/data/current/current", true);
 	data.onreadystatechange = function() {
 		if(data.readyState == 4 && data.status == "200") {
 			parse_data(data.responseText);
 		}
 	};
 	data.send(null);
 }