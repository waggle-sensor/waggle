/*
 * Define Chart variables for each sensor
 * Labels should be empty strings and initial data is 60 null points for history size
 * The canvas variables follow a column, row ordering: canvas<col><row><extra>
 */

//First column

//RHT103 Temperature Sensor
var canvas000 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//SHT15 Temperature, Humidity Sensor
var canvas010 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas011 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//PDVP8104 Light Intensity Sensor
var canvas02 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//MAX4466 Acoustic Intensity Sensor
var canvas03 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//HIH4030 Humidity Sensor
var canvas04 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//HIH6130 Temperature, Humidity Sensor
var canvas050 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas051 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//D6T44L06 Avg. Temperature, Casing Temperature
var canvas060 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas061 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//HMC5883 Magnetic Field x, y, z Sensor
var canvas070 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas071 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas072 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];
//Second column

//DS18B20 Temperature Sensor
var canvas10 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//PR103J2 Temperature Sensor
var canvas11 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//GA1A1SP20WP Light Intensity Sensor
var canvas12 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//SHT75 Temperature Sensor
var canvas13 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//TMP421 Temperature Sensor
var canvas14 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//MLX90614ESF Temperature Sensor
var canvas15 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//BMP180 Temperature, Pressure Sensor
var canvas160 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas161 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//HTU21D Temperature, Humidity Sensor
var canvas170 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas171 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//MMA8452Q Acceleration x, y, z, RMS Vibration Sensor
var canvas180 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas181 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas182 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

var canvas183 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Third column

//Totoal Reducing Gases Sensor
var canvas20 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Ethanol Sensor
var canvas21 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Nitrogen Sensor
var canvas22 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Ozone Sensor
var canvas23 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Hydrogen Sulphide Sensor
var canvas24 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Total Oxidizing Gases Sensor
var canvas25 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Carbon Monoxide Sensor
var canvas26 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

//Sulphur Dioxide Sensor
var canvas27 = [{"x":0, "y":30}, {"x":10, "y":30}, {"x":20, "y":30}, {"x":30, "y":30}, {"x":40, "y":30},
				{"x":50, "y":30}, {"x":60, "y":30}, {"x":70, "y":30}, {"x":80, "y":30}, {"x":90, "y":30},
				{"x":100, "y":30}, {"x":110, "y":30}, {"x":120, "y":30}, {"x":130, "y":30}, {"x":140, "y":30},
				{"x":150, "y":30}, {"x":160, "y":30}, {"x":170, "y":30}, {"x":180, "y":30}, {"x":190, "y":30}];

/*
 * Display the graph data and update them at a specified time interval
 */

window.onload = function() {
	var w = 194;
	var h = 60;

	//Define the function variable that puts the value to the graph
	var lineFunction = d3.svg.line()
							 .x(function(d) {return d.x;})
							 .y(function(d) {return d.y;})
							 .interpolate("basis");

	//Create the svg elements
	var svg000 = d3.select("div#graph000")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg010 = d3.select("div#graph010")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg011 = d3.select("div#graph011")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg02 = d3.select("div#graph02")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg03 = d3.select("div#graph03")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg04 = d3.select("div#graph04")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg050 = d3.select("div#graph050")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg051 = d3.select("div#graph051")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg060 = d3.select("div#graph060")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg061 = d3.select("div#graph061")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg070 = d3.select("div#graph070")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg071 = d3.select("div#graph071")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg072 = d3.select("div#graph072")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg10 = d3.select("div#graph10")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg11 = d3.select("div#graph11")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg12 = d3.select("div#graph12")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg13 = d3.select("div#graph13")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg14 = d3.select("div#graph14")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg15 = d3.select("div#graph15")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg160 = d3.select("div#graph160")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg161 = d3.select("div#graph161")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg170 = d3.select("div#graph170")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg171 = d3.select("div#graph171")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg180 = d3.select("div#graph180")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg181 = d3.select("div#graph181")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg182 = d3.select("div#graph182")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg183 = d3.select("div#graph183")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg20 = d3.select("div#graph20")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg21 = d3.select("div#graph21")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg22 = d3.select("div#graph22")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg23 = d3.select("div#graph23")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg24 = d3.select("div#graph24")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg25 = d3.select("div#graph25")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg26 = d3.select("div#graph26")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg27 = d3.select("div#graph27")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	//Create the surfaces and current value circles
	var _svg000 = svg000.append("path")
					  .attr("d", lineFunction(canvas000))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg000_c = svg000.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas000[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg010 = svg010.append("path")
					  .attr("d", lineFunction(canvas010))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg010_c = svg010.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas010[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg011 = svg011.append("path")
					  .attr("d", lineFunction(canvas011))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg011_c = svg011.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas011[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg02 = svg02.append("path")
					  .attr("d", lineFunction(canvas02))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg02_c = svg02.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas02[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg03 = svg03.append("path")
					  .attr("d", lineFunction(canvas03))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg03_c = svg03.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas03[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg04 = svg04.append("path")
					  .attr("d", lineFunction(canvas04))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg04_c = svg04.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas04[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg050 = svg050.append("path")
					  .attr("d", lineFunction(canvas050))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg050_c = svg050.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas050[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg051 = svg051.append("path")
					  .attr("d", lineFunction(canvas051))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg051_c = svg051.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas051[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg060 = svg060.append("path")
					  .attr("d", lineFunction(canvas060))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg060_c = svg060.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas060[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg061 = svg061.append("path")
					  .attr("d", lineFunction(canvas061))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg061_c = svg061.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas061[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg070 = svg070.append("path")
					  .attr("d", lineFunction(canvas070))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg070_c = svg070.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas070[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg071 = svg071.append("path")
					  .attr("d", lineFunction(canvas071))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg071_c = svg071.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas071[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg072 = svg072.append("path")
					  .attr("d", lineFunction(canvas072))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg072_c = svg072.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas072[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg10 = svg10.append("path")
					  .attr("d", lineFunction(canvas10))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg10_c = svg10.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas10[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg11 = svg11.append("path")
					  .attr("d", lineFunction(canvas11))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg11_c = svg11.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas11[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg12 = svg12.append("path")
					  .attr("d", lineFunction(canvas12))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg12_c = svg12.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas12[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg13 = svg13.append("path")
					  .attr("d", lineFunction(canvas13))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg13_c = svg13.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas13[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg14 = svg14.append("path")
					  .attr("d", lineFunction(canvas14))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg14_c = svg14.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas14[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg15 = svg15.append("path")
					  .attr("d", lineFunction(canvas15))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg15_c = svg15.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas15[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg160 = svg160.append("path")
					  .attr("d", lineFunction(canvas160))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg160_c = svg160.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas160[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg161 = svg161.append("path")
					  .attr("d", lineFunction(canvas161))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg161_c = svg161.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas161[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg170 = svg170.append("path")
					  .attr("d", lineFunction(canvas170))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg170_c = svg170.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas170[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg171 = svg171.append("path")
					  .attr("d", lineFunction(canvas171))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg171_c = svg171.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas171[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg180 = svg180.append("path")
					  .attr("d", lineFunction(canvas180))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg180_c = svg180.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas180[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg181 = svg181.append("path")
					  .attr("d", lineFunction(canvas181))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg181_c = svg181.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas181[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg182 = svg182.append("path")
					  .attr("d", lineFunction(canvas182))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg182_c = svg182.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas182[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg183 = svg183.append("path")
					  .attr("d", lineFunction(canvas183))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg183_c = svg183.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas183[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg20 = svg20.append("path")
					  .attr("d", lineFunction(canvas20))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg20_c = svg20.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas20[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg21 = svg21.append("path")
					  .attr("d", lineFunction(canvas21))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg21_c = svg21.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas21[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg22 = svg22.append("path")
					  .attr("d", lineFunction(canvas22))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg22_c = svg22.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas22[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg23 = svg23.append("path")
					  .attr("d", lineFunction(canvas23))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg23_c = svg23.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas23[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg24 = svg24.append("path")
					  .attr("d", lineFunction(canvas24))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg24_c = svg24.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas24[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg25 = svg25.append("path")
					  .attr("d", lineFunction(canvas25))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg25_c = svg25.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas25[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg26 = svg26.append("path")
					  .attr("d", lineFunction(canvas26))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg26_c = svg26.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas26[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg27 = svg27.append("path")
					  .attr("d", lineFunction(canvas27))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg27_c = svg27.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas27[19].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");
	//Time interval to update graphs
	setInterval(update_graphs, 3000);

	/*
	 * Update the graph by adding a new data point to the end and removing the data point at the beginning
	 * graph_data elements are stored linearly in the order that they appear in the data file grabbed from
	 * Therefore, the element indecies don't necessarily line up with the layout here
	 */
	function update_graphs() {
		//First column
		//RHT103
		canvas000[0].y = canvas000[1].y;
		canvas000[1].y = canvas000[2].y;
		canvas000[2].y = canvas000[3].y;
		canvas000[3].y = canvas000[4].y;
		canvas000[4].y = canvas000[5].y;
		canvas000[5].y = canvas000[6].y;
		canvas000[6].y = canvas000[7].y;
		canvas000[7].y = canvas000[8].y;
		canvas000[8].y = canvas000[9].y;
		canvas000[9].y = canvas000[10].y;
		canvas000[10].y = canvas000[11].y;
		canvas000[11].y = canvas000[12].y;
		canvas000[12].y = canvas000[13].y;
		canvas000[13].y = canvas000[14].y;
		canvas000[14].y = canvas000[15].y;
		canvas000[15].y = canvas000[16].y;
		canvas000[16].y = canvas000[17].y;
		canvas000[17].y = canvas000[18].y;
		canvas000[18].y = canvas000[19].y;
		canvas000[19].y = 58 - (parseFloat(get_graph_data(14))+40)*0.448;
	
		_svg000.transition()
			  .attr("d", lineFunction(canvas000))
			  .duration(2000);

		_svg000_c.transition()
				.attr("cy", canvas000[19].y)
				.duration(2000);

		document.getElementById('RHT103_temp').innerHTML = get_graph_data(14).concat(" &degC");
		//sensor000.addData([get_graph_data(14)], "");
	
		//SHT15
		canvas010[0].y = canvas010[1].y;
		canvas010[1].y = canvas010[2].y;
		canvas010[2].y = canvas010[3].y;
		canvas010[3].y = canvas010[4].y;
		canvas010[4].y = canvas010[5].y;
		canvas010[5].y = canvas010[6].y;
		canvas010[6].y = canvas010[7].y;
		canvas010[7].y = canvas010[8].y;
		canvas010[8].y = canvas010[9].y;
		canvas010[9].y = canvas010[10].y;
		canvas010[10].y = canvas010[11].y;
		canvas010[11].y = canvas010[12].y;
		canvas010[12].y = canvas010[13].y;
		canvas010[13].y = canvas010[14].y;
		canvas010[14].y = canvas010[15].y;
		canvas010[15].y = canvas010[16].y;
		canvas010[16].y = canvas010[17].y;
		canvas010[17].y = canvas010[18].y;
		canvas010[18].y = canvas010[19].y;
		canvas010[19].y = 58 - (parseFloat(get_graph_data(25))+40)*0.448;
	
		_svg010.transition()
			  .attr("d", lineFunction(canvas010))
			  .duration(2000);

		_svg010_c.transition()
				.attr("cy", canvas010[19].y)
				.duration(2000);

		document.getElementById('SHT15_temp').innerHTML = get_graph_data(25).concat(" &degC");
		//sensor010.addData([get_graph_data(25)], "");
	
		canvas011[0].y = canvas011[1].y;
		canvas011[1].y = canvas011[2].y;
		canvas011[2].y = canvas011[3].y;
		canvas011[3].y = canvas011[4].y;
		canvas011[4].y = canvas011[5].y;
		canvas011[5].y = canvas011[6].y;
		canvas011[6].y = canvas011[7].y;
		canvas011[7].y = canvas011[8].y;
		canvas011[8].y = canvas011[9].y;
		canvas011[9].y = canvas011[10].y;
		canvas011[10].y = canvas011[11].y;
		canvas011[11].y = canvas011[12].y;
		canvas011[12].y = canvas011[13].y;
		canvas011[13].y = canvas011[14].y;
		canvas011[14].y = canvas011[15].y;
		canvas011[15].y = canvas011[16].y;
		canvas011[16].y = canvas011[17].y;
		canvas011[17].y = canvas011[18].y;
		canvas011[18].y = canvas011[19].y;
		canvas011[19].y = 58 - (Math.random()*20)*0.58;
	
		_svg011.transition()
			  .attr("d", lineFunction(canvas011))
			  .duration(2000);

		_svg011_c.transition()
				.attr("cy", canvas011[19].y)
				.duration(2000);

		document.getElementById('SHT15_hum').innerHTML = get_graph_data(26).concat(" %RH");
		//sensor011.addData([get_graph_data(26)], "");
	
	
		//PDVP8104
		canvas02[0].y = canvas02[1].y;
		canvas02[1].y = canvas02[2].y;
		canvas02[2].y = canvas02[3].y;
		canvas02[3].y = canvas02[4].y;
		canvas02[4].y = canvas02[5].y;
		canvas02[5].y = canvas02[6].y;
		canvas02[6].y = canvas02[7].y;
		canvas02[7].y = canvas02[8].y;
		canvas02[8].y = canvas02[9].y;
		canvas02[9].y = canvas02[10].y;
		canvas02[10].y = canvas02[11].y;
		canvas02[11].y = canvas02[12].y;
		canvas02[12].y = canvas02[13].y;
		canvas02[13].y = canvas02[14].y;
		canvas02[14].y = canvas02[15].y;
		canvas02[15].y = canvas02[16].y;
		canvas02[16].y = canvas02[17].y;
		canvas02[17].y = canvas02[18].y;
		canvas02[18].y = canvas02[19].y;
		canvas02[19].y = 58 - (Math.random()*200)*0.057;
	
		_svg02.transition()
			  .attr("d", lineFunction(canvas02))
			  .duration(2000);

		_svg02_c.transition()
				.attr("cy", canvas02[19].y)
				.duration(2000);

		document.getElementById('PDVP8104').innerHTML = get_graph_data(13).concat(" &degC");
		//sensor02.addData([get_graph_data(13)], "");
	
	
		//MAX4466
		canvas03[0].y = canvas03[1].y;
		canvas03[1].y = canvas03[2].y;
		canvas03[2].y = canvas03[3].y;
		canvas03[3].y = canvas03[4].y;
		canvas03[4].y = canvas03[5].y;
		canvas03[5].y = canvas03[6].y;
		canvas03[6].y = canvas03[7].y;
		canvas03[7].y = canvas03[8].y;
		canvas03[8].y = canvas03[9].y;
		canvas03[9].y = canvas03[10].y;
		canvas03[10].y = canvas03[11].y;
		canvas03[11].y = canvas03[12].y;
		canvas03[12].y = canvas03[13].y;
		canvas03[13].y = canvas03[14].y;
		canvas03[14].y = canvas03[15].y;
		canvas03[15].y = canvas03[16].y;
		canvas03[16].y = canvas03[17].y;
		canvas03[17].y = canvas03[18].y;
		canvas03[18].y = canvas03[19].y;
		canvas03[19].y = 58 - (Math.random()*200)*0.057;
	
		_svg03.transition()
			  .attr("d", lineFunction(canvas03))
			  .duration(2000);

		_svg03_c.transition()
				.attr("cy", canvas03[19].y)
				.duration(2000);

		document.getElementById('MAX4466').innerHTML = get_graph_data(22).concat(" raw A/D");
		//sensor03.addData([get_graph_data(22)], "");
	
	
		//HIH4030
		canvas04[0].y = canvas04[1].y;
		canvas04[1].y = canvas04[2].y;
		canvas04[2].y = canvas04[3].y;
		canvas04[3].y = canvas04[4].y;
		canvas04[4].y = canvas04[5].y;
		canvas04[5].y = canvas04[6].y;
		canvas04[6].y = canvas04[7].y;
		canvas04[7].y = canvas04[8].y;
		canvas04[8].y = canvas04[9].y;
		canvas04[9].y = canvas04[10].y;
		canvas04[10].y = canvas04[11].y;
		canvas04[11].y = canvas04[12].y;
		canvas04[12].y = canvas04[13].y;
		canvas04[13].y = canvas04[14].y;
		canvas04[14].y = canvas04[15].y;
		canvas04[15].y = canvas04[16].y;
		canvas04[16].y = canvas04[17].y;
		canvas04[17].y = canvas04[18].y;
		canvas04[18].y = canvas04[19].y;
		canvas04[19].y = 58 - (Math.random()*20)*0.58;
	
		_svg04.transition()
			  .attr("d", lineFunction(canvas04))
			  .duration(2000);

		_svg04_c.transition()
				.attr("cy", canvas04[19].y)
				.duration(2000);

		document.getElementById('HIH4030').innerHTML = get_graph_data(27).concat(" %RH");
		//sensor04.addData([get_graph_data(27)], "");
	
	
		//HIH6130
		canvas050[0].y = canvas050[1].y;
		canvas050[1].y = canvas050[2].y;
		canvas050[2].y = canvas050[3].y;
		canvas050[3].y = canvas050[4].y;
		canvas050[4].y = canvas050[5].y;
		canvas050[5].y = canvas050[6].y;
		canvas050[6].y = canvas050[7].y;
		canvas050[7].y = canvas050[8].y;
		canvas050[8].y = canvas050[9].y;
		canvas050[9].y = canvas050[10].y;
		canvas050[10].y = canvas050[11].y;
		canvas050[11].y = canvas050[12].y;
		canvas050[12].y = canvas050[13].y;
		canvas050[13].y = canvas050[14].y;
		canvas050[14].y = canvas050[15].y;
		canvas050[15].y = canvas050[16].y;
		canvas050[16].y = canvas050[17].y;
		canvas050[17].y = canvas050[18].y;
		canvas050[18].y = canvas050[19].y;
		canvas050[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg050.transition()
			  .attr("d", lineFunction(canvas050))
			  .duration(2000);

		_svg050_c.transition()
				.attr("cy", canvas050[19].y)
				.duration(2000);

		document.getElementById('HIH6130_temp').innerHTML = get_graph_data(9).concat(" &degC");
		//sensor050.addData([get_graph_data(9)], "");
	
		canvas051[0].y = canvas051[1].y;
		canvas051[1].y = canvas051[2].y;
		canvas051[2].y = canvas051[3].y;
		canvas051[3].y = canvas051[4].y;
		canvas051[4].y = canvas051[5].y;
		canvas051[5].y = canvas051[6].y;
		canvas051[6].y = canvas051[7].y;
		canvas051[7].y = canvas051[8].y;
		canvas051[8].y = canvas051[9].y;
		canvas051[9].y = canvas051[10].y;
		canvas051[10].y = canvas051[11].y;
		canvas051[11].y = canvas051[12].y;
		canvas051[12].y = canvas051[13].y;
		canvas051[13].y = canvas051[14].y;
		canvas051[14].y = canvas051[15].y;
		canvas051[15].y = canvas051[16].y;
		canvas051[16].y = canvas051[17].y;
		canvas051[17].y = canvas051[18].y;
		canvas051[18].y = canvas051[19].y;
		canvas051[19].y = 58 - (Math.random()*20)*0.58;
	
		_svg051.transition()
			  .attr("d", lineFunction(canvas051))
			  .duration(2000);

		_svg051_c.transition()
				.attr("cy", canvas051[19].y)
				.duration(2000);

		document.getElementById('HIH6130_hum').innerHTML = get_graph_data(10).concat(" %RH");
		//sensor051.addData([get_graph_data(10)], "");
	
	
		//D6T44L06
		canvas060[0].y = canvas060[1].y;
		canvas060[1].y = canvas060[2].y;
		canvas060[2].y = canvas060[3].y;
		canvas060[3].y = canvas060[4].y;
		canvas060[4].y = canvas060[5].y;
		canvas060[5].y = canvas060[6].y;
		canvas060[6].y = canvas060[7].y;
		canvas060[7].y = canvas060[8].y;
		canvas060[8].y = canvas060[9].y;
		canvas060[9].y = canvas060[10].y;
		canvas060[10].y = canvas060[11].y;
		canvas060[11].y = canvas060[12].y;
		canvas060[12].y = canvas060[13].y;
		canvas060[13].y = canvas060[14].y;
		canvas060[14].y = canvas060[15].y;
		canvas060[15].y = canvas060[16].y;
		canvas060[16].y = canvas060[17].y;
		canvas060[17].y = canvas060[18].y;
		canvas060[18].y = canvas060[19].y;
		canvas060[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg060.transition()
			  .attr("d", lineFunction(canvas060))
			  .duration(2000);

		_svg060_c.transition()
				.attr("cy", canvas060[19].y)
				.duration(2000);

		document.getElementById('D6T44L06_avg_temp').innerHTML = get_graph_data(1).concat(" &degC");
		//sensor060.addData([get_graph_data(1)], "");
	
		canvas061[0].y = canvas061[1].y;
		canvas061[1].y = canvas061[2].y;
		canvas061[2].y = canvas061[3].y;
		canvas061[3].y = canvas061[4].y;
		canvas061[4].y = canvas061[5].y;
		canvas061[5].y = canvas061[6].y;
		canvas061[6].y = canvas061[7].y;
		canvas061[7].y = canvas061[8].y;
		canvas061[8].y = canvas061[9].y;
		canvas061[9].y = canvas061[10].y;
		canvas061[10].y = canvas061[11].y;
		canvas061[11].y = canvas061[12].y;
		canvas061[12].y = canvas061[13].y;
		canvas061[13].y = canvas061[14].y;
		canvas061[14].y = canvas061[15].y;
		canvas061[15].y = canvas061[16].y;
		canvas061[16].y = canvas061[17].y;
		canvas061[17].y = canvas061[18].y;
		canvas061[18].y = canvas061[19].y;
		canvas061[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg061.transition()
			  .attr("d", lineFunction(canvas061))
			  .duration(2000);

		_svg061_c.transition()
				.attr("cy", canvas061[19].y)
				.duration(2000);

		document.getElementById('D6T44L06_case_temp').innerHTML = get_graph_data(0).concat(" &degC");
		//sensor061.addData([get_graph_data(0)], "");
	
	
		//HMC5883
		canvas070[0].y = canvas070[1].y;
		canvas070[1].y = canvas070[2].y;
		canvas070[2].y = canvas070[3].y;
		canvas070[3].y = canvas070[4].y;
		canvas070[4].y = canvas070[5].y;
		canvas070[5].y = canvas070[6].y;
		canvas070[6].y = canvas070[7].y;
		canvas070[7].y = canvas070[8].y;
		canvas070[8].y = canvas070[9].y;
		canvas070[9].y = canvas070[10].y;
		canvas070[10].y = canvas070[11].y;
		canvas070[11].y = canvas070[12].y;
		canvas070[12].y = canvas070[13].y;
		canvas070[13].y = canvas070[14].y;
		canvas070[14].y = canvas070[15].y;
		canvas070[15].y = canvas070[16].y;
		canvas070[16].y = canvas070[17].y;
		canvas070[17].y = canvas070[18].y;
		canvas070[18].y = canvas070[19].y;
		canvas070[19].y = 58 - (Math.random()*2)*5.8;
	
		_svg070.transition()
			  .attr("d", lineFunction(canvas070))
			  .duration(2000);

		_svg070_c.transition()
				.attr("cy", canvas070[19].y)
				.duration(2000);

		document.getElementById('HMC5883_x').innerHTML = get_graph_data(16).concat(" &microT");
		//sensor070.addData([get_graph_data(16)], "");
	
		canvas071[0].y = canvas071[1].y;
		canvas071[1].y = canvas071[2].y;
		canvas071[2].y = canvas071[3].y;
		canvas071[3].y = canvas071[4].y;
		canvas071[4].y = canvas071[5].y;
		canvas071[5].y = canvas071[6].y;
		canvas071[6].y = canvas071[7].y;
		canvas071[7].y = canvas071[8].y;
		canvas071[8].y = canvas071[9].y;
		canvas071[9].y = canvas071[10].y;
		canvas071[10].y = canvas071[11].y;
		canvas071[11].y = canvas071[12].y;
		canvas071[12].y = canvas071[13].y;
		canvas071[13].y = canvas071[14].y;
		canvas071[14].y = canvas071[15].y;
		canvas071[15].y = canvas071[16].y;
		canvas071[16].y = canvas071[17].y;
		canvas071[17].y = canvas071[18].y;
		canvas071[18].y = canvas071[19].y;
		canvas071[19].y = 58 - (Math.random()*2)*5.8;
	
		_svg071.transition()
			  .attr("d", lineFunction(canvas071))
			  .duration(2000);

		_svg071_c.transition()
				.attr("cy", canvas071[19].y)
				.duration(2000);

		document.getElementById('HMC5883_y').innerHTML = get_graph_data(17).concat(" &microT");
		//sensor071.addData([get_graph_data(17)], "");
	
		canvas072[0].y = canvas072[1].y;
		canvas072[1].y = canvas072[2].y;
		canvas072[2].y = canvas072[3].y;
		canvas072[3].y = canvas072[4].y;
		canvas072[4].y = canvas072[5].y;
		canvas072[5].y = canvas072[6].y;
		canvas072[6].y = canvas072[7].y;
		canvas072[7].y = canvas072[8].y;
		canvas072[8].y = canvas072[9].y;
		canvas072[9].y = canvas072[10].y;
		canvas072[10].y = canvas072[11].y;
		canvas072[11].y = canvas072[12].y;
		canvas072[12].y = canvas072[13].y;
		canvas072[13].y = canvas072[14].y;
		canvas072[14].y = canvas072[15].y;
		canvas072[15].y = canvas072[16].y;
		canvas072[16].y = canvas072[17].y;
		canvas072[17].y = canvas072[18].y;
		canvas072[18].y = canvas072[19].y;
		canvas072[19].y = 58 - (Math.random()*2)*5.8;
	
		_svg072.transition()
			  .attr("d", lineFunction(canvas072))
			  .duration(2000);

		_svg072_c.transition()
				.attr("cy", canvas072[19].y)
				.duration(2000);

		document.getElementById('HMC5883_z').innerHTML = get_graph_data(18).concat(" &microT");
		//sensor072.addData([get_graph_data(18)], "");
	
	
		//Second column
		//DS18B20
		canvas10[0].y = canvas10[1].y;
		canvas10[1].y = canvas10[2].y;
		canvas10[2].y = canvas10[3].y;
		canvas10[3].y = canvas10[4].y;
		canvas10[4].y = canvas10[5].y;
		canvas10[5].y = canvas10[6].y;
		canvas10[6].y = canvas10[7].y;
		canvas10[7].y = canvas10[8].y;
		canvas10[8].y = canvas10[9].y;
		canvas10[9].y = canvas10[10].y;
		canvas10[10].y = canvas10[11].y;
		canvas10[11].y = canvas10[12].y;
		canvas10[12].y = canvas10[13].y;
		canvas10[13].y = canvas10[14].y;
		canvas10[14].y = canvas10[15].y;
		canvas10[15].y = canvas10[16].y;
		canvas10[16].y = canvas10[17].y;
		canvas10[17].y = canvas10[18].y;
		canvas10[18].y = canvas10[19].y;
		canvas10[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg10.transition()
			  .attr("d", lineFunction(canvas10))
			  .duration(2000);

		_svg10_c.transition()
				.attr("cy", canvas10[19].y)
				.duration(2000);

		document.getElementById('DS18B20').innerHTML = get_graph_data(6).concat(" &degC");
		//sensor10.addData([get_graph_data(6)], "");
	
	
		//PR103J2
		canvas11[0].y = canvas11[1].y;
		canvas11[1].y = canvas11[2].y;
		canvas11[2].y = canvas11[3].y;
		canvas11[3].y = canvas11[4].y;
		canvas11[4].y = canvas11[5].y;
		canvas11[5].y = canvas11[6].y;
		canvas11[6].y = canvas11[7].y;
		canvas11[7].y = canvas11[8].y;
		canvas11[8].y = canvas11[9].y;
		canvas11[9].y = canvas11[10].y;
		canvas11[10].y = canvas11[11].y;
		canvas11[11].y = canvas11[12].y;
		canvas11[12].y = canvas11[13].y;
		canvas11[13].y = canvas11[14].y;
		canvas11[14].y = canvas11[15].y;
		canvas11[15].y = canvas11[16].y;
		canvas11[16].y = canvas11[17].y;
		canvas11[17].y = canvas11[18].y;
		canvas11[18].y = canvas11[19].y;
		canvas11[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg11.transition()
			  .attr("d", lineFunction(canvas11))
			  .duration(2000);

		_svg11_c.transition()
				.attr("cy", canvas11[19].y)
				.duration(2000);

		document.getElementById('PR103J2').innerHTML = get_graph_data(28).concat(" &degC");
		//sensor11.addData([get_graph_data(28)], "");
	
	
		//GA1A1SP20WP
		canvas12[0].y = canvas12[1].y;
		canvas12[1].y = canvas12[2].y;
		canvas12[2].y = canvas12[3].y;
		canvas12[3].y = canvas12[4].y;
		canvas12[4].y = canvas12[5].y;
		canvas12[5].y = canvas12[6].y;
		canvas12[6].y = canvas12[7].y;
		canvas12[7].y = canvas12[8].y;
		canvas12[8].y = canvas12[9].y;
		canvas12[9].y = canvas12[10].y;
		canvas12[10].y = canvas12[11].y;
		canvas12[11].y = canvas12[12].y;
		canvas12[12].y = canvas12[13].y;
		canvas12[13].y = canvas12[14].y;
		canvas12[14].y = canvas12[15].y;
		canvas12[15].y = canvas12[16].y;
		canvas12[16].y = canvas12[17].y;
		canvas12[17].y = canvas12[18].y;
		canvas12[18].y = canvas12[19].y;
		canvas12[19].y = 58 - (Math.random()*200)*0.057;
	
		_svg12.transition()
			  .attr("d", lineFunction(canvas12))
			  .duration(2000);

		_svg12_c.transition()
				.attr("cy", canvas12[19].y)
				.duration(2000);

		document.getElementById('GA1A1SP20WP').innerHTML = get_graph_data(24).concat(" raw A/D");
		//sensor12.addData([get_graph_data(24)], "");
	
	
		//SHT75
		canvas13[0].y = canvas13[1].y;
		canvas13[1].y = canvas13[2].y;
		canvas13[2].y = canvas13[3].y;
		canvas13[3].y = canvas13[4].y;
		canvas13[4].y = canvas13[5].y;
		canvas13[5].y = canvas13[6].y;
		canvas13[6].y = canvas13[7].y;
		canvas13[7].y = canvas13[8].y;
		canvas13[8].y = canvas13[9].y;
		canvas13[9].y = canvas13[10].y;
		canvas13[10].y = canvas13[11].y;
		canvas13[11].y = canvas13[12].y;
		canvas13[12].y = canvas13[13].y;
		canvas13[13].y = canvas13[14].y;
		canvas13[14].y = canvas13[15].y;
		canvas13[15].y = canvas13[16].y;
		canvas13[16].y = canvas13[17].y;
		canvas13[17].y = canvas13[18].y;
		canvas13[18].y = canvas13[19].y;
		canvas13[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg13.transition()
			  .attr("d", lineFunction(canvas13))
			  .duration(2000);

		_svg13_c.transition()
				.attr("cy", canvas13[19].y)
				.duration(2000);

		document.getElementById('SHT75').innerHTML = get_graph_data(21).concat(" &degC");
		//sensor13.addData([get_graph_data(21)], "");
	
	
		//TMP421
		canvas14[0].y = canvas14[1].y;
		canvas14[1].y = canvas14[2].y;
		canvas14[2].y = canvas14[3].y;
		canvas14[3].y = canvas14[4].y;
		canvas14[4].y = canvas14[5].y;
		canvas14[5].y = canvas14[6].y;
		canvas14[6].y = canvas14[7].y;
		canvas14[7].y = canvas14[8].y;
		canvas14[8].y = canvas14[9].y;
		canvas14[9].y = canvas14[10].y;
		canvas14[10].y = canvas14[11].y;
		canvas14[11].y = canvas14[12].y;
		canvas14[12].y = canvas14[13].y;
		canvas14[13].y = canvas14[14].y;
		canvas14[14].y = canvas14[15].y;
		canvas14[15].y = canvas14[16].y;
		canvas14[16].y = canvas14[17].y;
		canvas14[17].y = canvas14[18].y;
		canvas14[18].y = canvas14[19].y;
		canvas14[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg14.transition()
			  .attr("d", lineFunction(canvas14))
			  .duration(2000);

		_svg14_c.transition()
				.attr("cy", canvas14[19].y)
				.duration(2000);

		document.getElementById('TMP421').innerHTML = get_graph_data(23).concat(" &degC");
		//sensor14.addData([get_graph_data(23)], "");
	
	
		//MLX90614ESF
		canvas15[0].y = canvas15[1].y;
		canvas15[1].y = canvas15[2].y;
		canvas15[2].y = canvas15[3].y;
		canvas15[3].y = canvas15[4].y;
		canvas15[4].y = canvas15[5].y;
		canvas15[5].y = canvas15[6].y;
		canvas15[6].y = canvas15[7].y;
		canvas15[7].y = canvas15[8].y;
		canvas15[8].y = canvas15[9].y;
		canvas15[9].y = canvas15[10].y;
		canvas15[10].y = canvas15[11].y;
		canvas15[11].y = canvas15[12].y;
		canvas15[12].y = canvas15[13].y;
		canvas15[13].y = canvas15[14].y;
		canvas15[14].y = canvas15[15].y;
		canvas15[15].y = canvas15[16].y;
		canvas15[16].y = canvas15[17].y;
		canvas15[17].y = canvas15[18].y;
		canvas15[18].y = canvas15[19].y;
		canvas15[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg15.transition()
			  .attr("d", lineFunction(canvas15))
			  .duration(2000);

		_svg15_c.transition()
				.attr("cy", canvas15[19].y)
				.duration(2000);

		document.getElementById('MLX90614ESF').innerHTML = get_graph_data(7).concat(" &degC");
		//sensor15.addData([get_graph_data(7)], "");
	
	
		//BMP180
		canvas160[0].y = canvas160[1].y;
		canvas160[1].y = canvas160[2].y;
		canvas160[2].y = canvas160[3].y;
		canvas160[3].y = canvas160[4].y;
		canvas160[4].y = canvas160[5].y;
		canvas160[5].y = canvas160[6].y;
		canvas160[6].y = canvas160[7].y;
		canvas160[7].y = canvas160[8].y;
		canvas160[8].y = canvas160[9].y;
		canvas160[9].y = canvas160[10].y;
		canvas160[10].y = canvas160[11].y;
		canvas160[11].y = canvas160[12].y;
		canvas160[12].y = canvas160[13].y;
		canvas160[13].y = canvas160[14].y;
		canvas160[14].y = canvas160[15].y;
		canvas160[15].y = canvas160[16].y;
		canvas160[16].y = canvas160[17].y;
		canvas160[17].y = canvas160[18].y;
		canvas160[18].y = canvas160[19].y;
		canvas160[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg160.transition()
			  .attr("d", lineFunction(canvas160))
			  .duration(2000);

		_svg160_c.transition()
				.attr("cy", canvas160[19].y)
				.duration(2000);

		document.getElementById('BMP180_temp').innerHTML = get_graph_data(11).concat(" &degC");
		//sensor160.addData([get_graph_data(11)], "");
	
		canvas161[0].y = canvas161[1].y;
		canvas161[1].y = canvas161[2].y;
		canvas161[2].y = canvas161[3].y;
		canvas161[3].y = canvas161[4].y;
		canvas161[4].y = canvas161[5].y;
		canvas161[5].y = canvas161[6].y;
		canvas161[6].y = canvas161[7].y;
		canvas161[7].y = canvas161[8].y;
		canvas161[8].y = canvas161[9].y;
		canvas161[9].y = canvas161[10].y;
		canvas161[10].y = canvas161[11].y;
		canvas161[11].y = canvas161[12].y;
		canvas161[12].y = canvas161[13].y;
		canvas161[13].y = canvas161[14].y;
		canvas161[14].y = canvas161[15].y;
		canvas161[15].y = canvas161[16].y;
		canvas161[16].y = canvas161[17].y;
		canvas161[17].y = canvas161[18].y;
		canvas161[18].y = canvas161[19].y;
		canvas161[19].y = 58 - (Math.random()*100+1000-800)*0.193;
	
		_svg161.transition()
			  .attr("d", lineFunction(canvas161))
			  .duration(2000);

		_svg161_c.transition()
				.attr("cy", canvas161[19].y)
				.duration(2000);

		document.getElementById('BMP180_pres').innerHTML = get_graph_data(12).concat(" hPa");
		//sensor161.addData([get_graph_data(12)], "");
	
	
		//HTU21D
		canvas170[0].y = canvas170[1].y;
		canvas170[1].y = canvas170[2].y;
		canvas170[2].y = canvas170[3].y;
		canvas170[3].y = canvas170[4].y;
		canvas170[4].y = canvas170[5].y;
		canvas170[5].y = canvas170[6].y;
		canvas170[6].y = canvas170[7].y;
		canvas170[7].y = canvas170[8].y;
		canvas170[8].y = canvas170[9].y;
		canvas170[9].y = canvas170[10].y;
		canvas170[10].y = canvas170[11].y;
		canvas170[11].y = canvas170[12].y;
		canvas170[12].y = canvas170[13].y;
		canvas170[13].y = canvas170[14].y;
		canvas170[14].y = canvas170[15].y;
		canvas170[15].y = canvas170[16].y;
		canvas170[16].y = canvas170[17].y;
		canvas170[17].y = canvas170[18].y;
		canvas170[18].y = canvas170[19].y;
		canvas170[19].y = 58 - (Math.random()*20+40)*0.448;
	
		_svg170.transition()
			  .attr("d", lineFunction(canvas170))
			  .duration(2000);

		_svg170_c.transition()
				.attr("cy", canvas170[19].y)
				.duration(2000);

		document.getElementById('HTU21D_temp').innerHTML = get_graph_data(19).concat(" &degC");
		//sensor170.addData([get_graph_data(19)], "");
	
		canvas171[0].y = canvas171[1].y;
		canvas171[1].y = canvas171[2].y;
		canvas171[2].y = canvas171[3].y;
		canvas171[3].y = canvas171[4].y;
		canvas171[4].y = canvas171[5].y;
		canvas171[5].y = canvas171[6].y;
		canvas171[6].y = canvas171[7].y;
		canvas171[7].y = canvas171[8].y;
		canvas171[8].y = canvas171[9].y;
		canvas171[9].y = canvas171[10].y;
		canvas171[10].y = canvas171[11].y;
		canvas171[11].y = canvas171[12].y;
		canvas171[12].y = canvas171[13].y;
		canvas171[13].y = canvas171[14].y;
		canvas171[14].y = canvas171[15].y;
		canvas171[15].y = canvas171[16].y;
		canvas171[16].y = canvas171[17].y;
		canvas171[17].y = canvas171[18].y;
		canvas171[18].y = canvas171[19].y;
		canvas171[19].y = 58 - (Math.random()*20)*0.58;
	
		_svg171.transition()
			  .attr("d", lineFunction(canvas171))
			  .duration(2000);

		_svg171_c.transition()
				.attr("cy", canvas171[19].y)
				.duration(2000);

		document.getElementById('HTU21D_hum').innerHTML = get_graph_data(20).concat(" %RH");
		//sensor171.addData([get_graph_data(20)], "");
	
	
		//MMA8452Q
		canvas180[0].y = canvas180[1].y;
		canvas180[1].y = canvas180[2].y;
		canvas180[2].y = canvas180[3].y;
		canvas180[3].y = canvas180[4].y;
		canvas180[4].y = canvas180[5].y;
		canvas180[5].y = canvas180[6].y;
		canvas180[6].y = canvas180[7].y;
		canvas180[7].y = canvas180[8].y;
		canvas180[8].y = canvas180[9].y;
		canvas180[9].y = canvas180[10].y;
		canvas180[10].y = canvas180[11].y;
		canvas180[11].y = canvas180[12].y;
		canvas180[12].y = canvas180[13].y;
		canvas180[13].y = canvas180[14].y;
		canvas180[14].y = canvas180[15].y;
		canvas180[15].y = canvas180[16].y;
		canvas180[16].y = canvas180[17].y;
		canvas180[17].y = canvas180[18].y;
		canvas180[18].y = canvas180[19].y;
		canvas180[19].y = 58 - (Math.random()+2)*14.5;
	
		_svg180.transition()
			  .attr("d", lineFunction(canvas180))
			  .duration(2000);

		_svg180_c.transition()
				.attr("cy", canvas180[19].y)
				.duration(2000);

		document.getElementById('MMA8452Q_x').innerHTML = get_graph_data(2).concat(" g");
		//sensor180.addData([get_graph_data(2)], "");
	
		canvas181[0].y = canvas181[1].y;
		canvas181[1].y = canvas181[2].y;
		canvas181[2].y = canvas181[3].y;
		canvas181[3].y = canvas181[4].y;
		canvas181[4].y = canvas181[5].y;
		canvas181[5].y = canvas181[6].y;
		canvas181[6].y = canvas181[7].y;
		canvas181[7].y = canvas181[8].y;
		canvas181[8].y = canvas181[9].y;
		canvas181[9].y = canvas181[10].y;
		canvas181[10].y = canvas181[11].y;
		canvas181[11].y = canvas181[12].y;
		canvas181[12].y = canvas181[13].y;
		canvas181[13].y = canvas181[14].y;
		canvas181[14].y = canvas181[15].y;
		canvas181[15].y = canvas181[16].y;
		canvas181[16].y = canvas181[17].y;
		canvas181[17].y = canvas181[18].y;
		canvas181[18].y = canvas181[19].y;
		canvas181[19].y = 58 - (Math.random()+2)*14.5;
	
		_svg181.transition()
			  .attr("d", lineFunction(canvas181))
			  .duration(2000);

		_svg181_c.transition()
				.attr("cy", canvas181[19].y)
				.duration(2000);

		document.getElementById('MMA8452Q_y').innerHTML = get_graph_data(3).concat(" g");
		//sensor181.addData([get_graph_data(3)], "");
	
		canvas182[0].y = canvas182[1].y;
		canvas182[1].y = canvas182[2].y;
		canvas182[2].y = canvas182[3].y;
		canvas182[3].y = canvas182[4].y;
		canvas182[4].y = canvas182[5].y;
		canvas182[5].y = canvas182[6].y;
		canvas182[6].y = canvas182[7].y;
		canvas182[7].y = canvas182[8].y;
		canvas182[8].y = canvas182[9].y;
		canvas182[9].y = canvas182[10].y;
		canvas182[10].y = canvas182[11].y;
		canvas182[11].y = canvas182[12].y;
		canvas182[12].y = canvas182[13].y;
		canvas182[13].y = canvas182[14].y;
		canvas182[14].y = canvas182[15].y;
		canvas182[15].y = canvas182[16].y;
		canvas182[16].y = canvas182[17].y;
		canvas182[17].y = canvas182[18].y;
		canvas182[18].y = canvas182[19].y;
		canvas182[19].y = 58 - (Math.random()+2)*14.5;
	
		_svg182.transition()
			  .attr("d", lineFunction(canvas182))
			  .duration(2000);

		_svg182_c.transition()
				.attr("cy", canvas182[19].y)
				.duration(2000);

		document.getElementById('MMA8452Q_z').innerHTML = get_graph_data(4).concat(" g");
		//sensor182.addData([get_graph_data(4)], "");
	
		canvas183[0].y = canvas183[1].y;
		canvas183[1].y = canvas183[2].y;
		canvas183[2].y = canvas183[3].y;
		canvas183[3].y = canvas183[4].y;
		canvas183[4].y = canvas183[5].y;
		canvas183[5].y = canvas183[6].y;
		canvas183[6].y = canvas183[7].y;
		canvas183[7].y = canvas183[8].y;
		canvas183[8].y = canvas183[9].y;
		canvas183[9].y = canvas183[10].y;
		canvas183[10].y = canvas183[11].y;
		canvas183[11].y = canvas183[12].y;
		canvas183[12].y = canvas183[13].y;
		canvas183[13].y = canvas183[14].y;
		canvas183[14].y = canvas183[15].y;
		canvas183[15].y = canvas183[16].y;
		canvas183[16].y = canvas183[17].y;
		canvas183[17].y = canvas183[18].y;
		canvas183[18].y = canvas183[19].y;
		canvas183[19].y = 58 - (Math.random()+1)*19.3;
	
		_svg183.transition()
			  .attr("d", lineFunction(canvas183))
			  .duration(2000);

		_svg183_c.transition()
				.attr("cy", canvas183[19].y)
				.duration(2000);

		document.getElementById('MMA8452Q_rms').innerHTML = get_graph_data(5).concat(" g");
		//sensor183.addData([get_graph_data(5)], "");
	
	}
}