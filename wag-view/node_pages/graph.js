/*
 * Define Chart variables for each sensor
 * Labels should be empty strings and initial data is 10 points for history size
 * The canvas variables follow a column, row ordering: canvas<col><row>
 */

//First column
//RHT03 Temperature Sensor
var canvas00 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas01 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HTU21D Temperature, Humidity Sensor
var canvas02 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas03 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HIH6130 Temperature, Humidity Sensor
var canvas04 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas05 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//MLX90614ESF Temperature Sensor
var canvas06 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//MMA8452Q Acceleration x, y, z, rms Vibration Sensor
var canvas07 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas08 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas09 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas010 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Second column
//SHT15 Temperature, Humidity Sensor
var canvas10 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas11 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//D6T44L06 Avg. Temperature, Casing Temperature Sensor
var canvas12 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas13 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HIH4030 Humidity Sensor
var canvas14 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//TMP102 Temperature Sensor
var canvas15 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//PR103J2 Temperature Sensor
var canvas16 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HMC5883 Magnetic Field x, y, z Sensor
var canvas17 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas18 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas19 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Third column
//SHT75 Temperature, Humidity Sensor
var canvas20 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas21 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//BMP180 Temperature, Pressure Sensor
var canvas22 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas23 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//DS18B20 Temperature Sensor
var canvas24 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//TMP421 Temperature Sensor
var canvas25 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//GA1A1SP20WP Light Intensity Sensor
var canvas26 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//PDVP8104 Light Intensity Sensor
var canvas27 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//MAX4466 Acoustic Intensity Sensor
var canvas28 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

/*
//Totoal Reducing Gases Sensor
var canvas20 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Ethanol Sensor
var canvas21 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Nitrogen Sensor
var canvas22 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Ozone Sensor
var canvas23 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Hydrogen Sulphide Sensor
var canvas24 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Total Oxidizing Gases Sensor
var canvas25 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Carbon Monoxide Sensor
var canvas26 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Sulphur Dioxide Sensor
var canvas27 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];
*/

/*
 * Display the graph data and update them at a specified time interval
 */
function setupGraphs() {
	var w = 194;
	var h = 60;

	var line_color = "#e6e6e6";//"#ff5000";
	var circle_color = "#ebebeb";//"#3f3f3f";

	//Define the function variable that puts the value to the graph
	var lineFunction = d3.svg.line()
							 .x(function(d) {return d.x;})
							 .y(function(d) {return d.y;})
							 .interpolate("basis");

	//Create the svg elements
	//First column
	var svg00 = d3.select("div#graph00")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg01 = d3.select("div#graph01")
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

	var svg05 = d3.select("div#graph05")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg06 = d3.select("div#graph06")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg07 = d3.select("div#graph07")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg08 = d3.select("div#graph08")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg09 = d3.select("div#graph09")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg010 = d3.select("div#graph010")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	//Second column
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

	var svg16 = d3.select("div#graph16")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg17 = d3.select("div#graph17")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg18 = d3.select("div#graph18")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg19 = d3.select("div#graph19")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	//Third column
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

	var svg28 = d3.select("div#graph28")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	//Create the surfaces and current value circles
	//First column
	var _svg00 = svg00.append("path")
					  .attr("d", lineFunction(canvas00))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg00_c = svg00.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas00[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg01 = svg01.append("path")
					  .attr("d", lineFunction(canvas01))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg01_c = svg01.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas01[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg02 = svg02.append("path")
					  .attr("d", lineFunction(canvas02))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg02_c = svg02.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas02[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg03 = svg03.append("path")
					  .attr("d", lineFunction(canvas03))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg03_c = svg03.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas03[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg04 = svg04.append("path")
					  .attr("d", lineFunction(canvas04))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg04_c = svg04.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas04[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg05 = svg05.append("path")
					  .attr("d", lineFunction(canvas05))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg05_c = svg05.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas05[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg06 = svg06.append("path")
					  .attr("d", lineFunction(canvas06))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg06_c = svg06.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas06[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg07 = svg07.append("path")
					  .attr("d", lineFunction(canvas07))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg07_c = svg07.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas07[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg08 = svg08.append("path")
					  .attr("d", lineFunction(canvas08))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg08_c = svg08.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas08[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg09 = svg09.append("path")
					  .attr("d", lineFunction(canvas09))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg09_c = svg09.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas09[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg010 = svg010.append("path")
					  .attr("d", lineFunction(canvas010))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg010_c = svg010.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas010[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	//Second column
	var _svg10 = svg10.append("path")
					  .attr("d", lineFunction(canvas10))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg10_c = svg10.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas10[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg11 = svg11.append("path")
					  .attr("d", lineFunction(canvas11))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg11_c = svg11.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas11[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg12 = svg12.append("path")
					  .attr("d", lineFunction(canvas12))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg12_c = svg12.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas12[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg13 = svg13.append("path")
					  .attr("d", lineFunction(canvas13))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg13_c = svg13.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas13[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg14 = svg14.append("path")
					  .attr("d", lineFunction(canvas14))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg14_c = svg14.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas14[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg15 = svg15.append("path")
					  .attr("d", lineFunction(canvas15))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg15_c = svg15.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas15[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg16 = svg16.append("path")
					  .attr("d", lineFunction(canvas16))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg16_c = svg16.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas16[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg17 = svg17.append("path")
					  .attr("d", lineFunction(canvas17))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg17_c = svg17.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas17[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg18 = svg18.append("path")
					  .attr("d", lineFunction(canvas18))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg18_c = svg18.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas18[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg19 = svg19.append("path")
					  .attr("d", lineFunction(canvas19))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg19_c = svg19.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas19[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	//Third column
	var _svg20 = svg20.append("path")
					  .attr("d", lineFunction(canvas20))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg20_c = svg20.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas20[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg21 = svg21.append("path")
					  .attr("d", lineFunction(canvas21))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg21_c = svg21.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas21[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg22 = svg22.append("path")
					  .attr("d", lineFunction(canvas22))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg22_c = svg22.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas22[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg23 = svg23.append("path")
					  .attr("d", lineFunction(canvas23))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg23_c = svg23.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas23[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg24 = svg24.append("path")
					  .attr("d", lineFunction(canvas24))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg24_c = svg24.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas24[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg25 = svg25.append("path")
					  .attr("d", lineFunction(canvas25))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg25_c = svg25.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas25[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg26 = svg26.append("path")
					  .attr("d", lineFunction(canvas26))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg26_c = svg26.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas26[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg27 = svg27.append("path")
					  .attr("d", lineFunction(canvas27))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg27_c = svg27.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas27[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	var _svg28 = svg28.append("path")
					  .attr("d", lineFunction(canvas28))
					  .attr("stroke", line_color)
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg28_c = svg28.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas28[10].y)
						.attr("r", 2)
						.attr("fill", circle_color);

	//Time interval to update graphs
   	update_graphs();
	setInterval(update_graphs, TIME_TO_WAIT);

	/*
	 * Update the graph by adding a new data point to the end and removing the data point at the beginning
	 * graph_data elements are stored linearly in the order that they appear in the data file grabbed from
	 * Therefore, the element indecies don't necessarily line up with the layout here
	 */
	function update_graphs() {
        console.log("I am updating the graphs");
		//RHT03
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
        		canvas00[index].y = canvas00[index + 1].y;
       		}
		canvas00[10].y = (get_graph_data(14) < TEMP_C_LOWER || get_graph_data(14) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(14)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg00.transition()
			  .attr("d", lineFunction(canvas00))
			  .duration(0);

		_svg00_c.transition()
				.attr("cy", canvas00[10].y)
				.duration(0);
                document.getElementById('RHT03_temp').innerHTML = ((get_graph_data(14) < TEMP_C_LOWER || get_graph_data(14) > TEMP_C_UPPER) ? "NA" : get_graph_data(14)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas01[index].y = canvas01[index + 1].y;
       		}
		canvas01[10].y = (get_graph_data(15) < RH_LOWER || get_graph_data(15) > RH_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(15))*RH_SCALE);

		_svg01.transition()
			  .attr("d", lineFunction(canvas01))
			  .duration(0);

		_svg01_c.transition()
				.attr("cy", canvas01[10].y)
				.duration(0);

                document.getElementById('RHT03_hum').innerHTML = ((get_graph_data(15) < RH_LOWER || get_graph_data(15) > RH_UPPER) ? "NA" : get_graph_data(15)).concat(" %RH");

		//HTU21D
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas02[index].y = canvas02[index + 1].y;
       		}
		canvas02[10].y = (get_graph_data(19) < TEMP_C_LOWER || get_graph_data(19) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(19)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg02.transition()
			  .attr("d", lineFunction(canvas02))
			  .duration(0);

		_svg02_c.transition()
				.attr("cy", canvas02[10].y)
				.duration(0);

                document.getElementById('HTU21D_temp').innerHTML = ((get_graph_data(19) < TEMP_C_LOWER || get_graph_data(19) > TEMP_C_UPPER) ? "NA" : get_graph_data(19)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas03[index].y = canvas03[index + 1].y;
       		}
		canvas03[10].y = (get_graph_data(20) < RH_LOWER || get_graph_data(20) > RH_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(20))*RH_SCALE);

		_svg03.transition()
			  .attr("d", lineFunction(canvas03))
			  .duration(0);

		_svg03_c.transition()
				.attr("cy", canvas03[10].y)
				.duration(0);

                document.getElementById('HTU21D_hum').innerHTML = ((get_graph_data(20) < RH_LOWER || get_graph_data(20) > RH_UPPER) ? "NA" : get_graph_data(20)).concat(" %RH");

		//HIH6130
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas04[index].y = canvas04[index + 1].y;
       		}
		canvas04[10].y = (get_graph_data(9) < TEMP_C_LOWER || get_graph_data(9) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(9)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg04.transition()
			  .attr("d", lineFunction(canvas04))
			  .duration(0);

		_svg04_c.transition()
				.attr("cy", canvas04[10].y)
				.duration(0);
                document.getElementById('HIH6130_temp').innerHTML = ((get_graph_data(9) < TEMP_C_LOWER || get_graph_data(9) > TEMP_C_UPPER) ? "NA" : get_graph_data(9)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas05[index].y = canvas05[index + 1].y;
       		}
		canvas05[10].y = (get_graph_data(10) < RH_LOWER || get_graph_data(10) > RH_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(10))*RH_SCALE);

		_svg05.transition()
			  .attr("d", lineFunction(canvas05))
			  .duration(0);

		_svg05_c.transition()
				.attr("cy", canvas05[10].y)
				.duration(0);

		document.getElementById('HIH6130_hum').innerHTML = ((get_graph_data(10) < RH_LOWER || get_graph_data(10) > RH_UPPER) ? "NA" : get_graph_data(10)).concat(" %RH");

		//MLX90614ESF
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas06[index].y = canvas06[index + 1].y;
       		}
		canvas06[10].y = (get_graph_data(7) < TEMP_F_LOWER || get_graph_data(7) > TEMP_F_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(7)) - TEMP_F_LOWER)*TEMP_F_SCALE);

		_svg06.transition()
			  .attr("d", lineFunction(canvas06))
			  .duration(0);

		_svg06_c.transition()
				.attr("cy", canvas06[10].y)
				.duration(0);

                document.getElementById('MLX90614ESF').innerHTML = ((get_graph_data(7) < TEMP_F_LOWER || get_graph_data(7) > TEMP_F_UPPER) ? "NA" : get_graph_data(7)).concat(" &degF");

		//MMA8452Q
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas07[index].y = canvas07[index + 1].y;
       		}

		canvas07[10].y = (get_graph_data(2) < ACC_G_LOWER || get_graph_data(2) > ACC_G_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(2)) - ACC_G_LOWER)*ACC_G_SCALE);

		_svg07.transition()
			  .attr("d", lineFunction(canvas07))
			  .duration(0);

		_svg07_c.transition()
				.attr("cy", canvas07[10].y)
				.duration(0);

                document.getElementById('MMA8452Q_x').innerHTML = ((get_graph_data(2) < ACC_G_LOWER || get_graph_data(2) > ACC_G_UPPER) ? "NA" : get_graph_data(2)).concat(" g");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas08[index].y = canvas08[index + 1].y;
       		}
		canvas08[10].y = (get_graph_data(3) < ACC_G_LOWER || get_graph_data(3) > ACC_G_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(3)) - ACC_G_LOWER)*ACC_G_SCALE);

		_svg08.transition()
			  .attr("d", lineFunction(canvas08))
			  .duration(0);

		_svg08_c.transition()
				.attr("cy", canvas08[10].y)
				.duration(0);

                document.getElementById('MMA8452Q_y').innerHTML = ((get_graph_data(3) < ACC_G_LOWER || get_graph_data(3) > ACC_G_UPPER) ? "NA" : get_graph_data(3)).concat(" g");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas09[index].y = canvas09[index + 1].y;
       		}
		canvas09[10].y = (get_graph_data(4) < ACC_G_LOWER || get_graph_data(4) > ACC_G_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(4)) - ACC_G_LOWER)*ACC_G_SCALE);

		_svg09.transition()
			  .attr("d", lineFunction(canvas09))
			  .duration(0);

		_svg09_c.transition()
				.attr("cy", canvas09[10].y)
				.duration(0);

                document.getElementById('MMA8452Q_z').innerHTML = ((get_graph_data(4) < ACC_G_LOWER || get_graph_data(4) > ACC_G_UPPER) ? "NA" : get_graph_data(4)).concat(" g");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas010[index].y = canvas010[index + 1].y;
       		}
		canvas010[10].y = (get_graph_data(5) < ACC_G_LOWER || get_graph_data(5) > ACC_G_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(5)) - ACC_G_LOWER)*ACC_G_SCALE);

		_svg010.transition()
			  .attr("d", lineFunction(canvas010))
			  .duration(0);

		_svg010_c.transition()
				.attr("cy", canvas010[10].y)
				.duration(0);

                document.getElementById('MMA8452Q_rms').innerHTML = ((get_graph_data(5) < ACC_G_LOWER || get_graph_data(5) > ACC_G_UPPER) ? "NA" : get_graph_data(5)).concat(" g");

		//Second column
		//SHT15
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas10[index].y = canvas10[index + 1].y;
       		}
		canvas10[10].y = (get_graph_data(26) < TEMP_C_LOWER || get_graph_data(26) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(26)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg10.transition()
			  .attr("d", lineFunction(canvas10))
			  .duration(0);

		_svg10_c.transition()
				.attr("cy", canvas10[10].y)
				.duration(0);

                document.getElementById('SHT15_temp').innerHTML = ((get_graph_data(26) < TEMP_C_LOWER || get_graph_data(26) > TEMP_C_UPPER) ? "NA" : get_graph_data(26)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas11[index].y = canvas11[index + 1].y;
       		}
		canvas11[10].y = (get_graph_data(27) < RH_LOWER || get_graph_data(27) > RH_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(27))*RH_SCALE);

		_svg11.transition()
			  .attr("d", lineFunction(canvas11))
			  .duration(0);

		_svg11_c.transition()
				.attr("cy", canvas11[10].y)
				.duration(0);

                document.getElementById('SHT15_hum').innerHTML = ((get_graph_data(27) < RH_LOWER || get_graph_data(27) > RH_UPPER) ? "NA" : get_graph_data(27)).concat(" %RH");

		//D6T44L06
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
            		canvas12[index].y = canvas12[index + 1].y;
       		}
		canvas12[10].y = (get_graph_data(1) < TEMP_C_LOWER || get_graph_data(1) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(1)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg12.transition()
			  .attr("d", lineFunction(canvas12))
			  .duration(0);

		_svg12_c.transition()
				.attr("cy", canvas12[10].y)
				.duration(0);

                document.getElementById('D6T44L06_avg_temp').innerHTML = ((get_graph_data(1) < TEMP_C_LOWER || get_graph_data(1) > TEMP_C_UPPER) ? "NA" : get_graph_data(1)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas13[index].y = canvas13[index + 1].y;
       		}
		canvas13[10].y = (get_graph_data(0) < TEMP_C_LOWER || get_graph_data(0) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(0)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg13.transition()
			  .attr("d", lineFunction(canvas13))
			  .duration(0);

		_svg13_c.transition()
				.attr("cy", canvas13[10].y)
				.duration(0);
                document.getElementById('D6T44L06_case_temp').innerHTML = ((get_graph_data(0) < TEMP_C_LOWER || get_graph_data(0) > TEMP_C_UPPER) ? "NA" : get_graph_data(0)).concat(" &degC");
		
		//HIH4030
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas14[index].y = canvas14[index + 1].y;
       		}
		canvas14[10].y = (get_graph_data(28) < RAW_LOWER || get_graph_data(28) > RAW_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(28))*RAW_SCALE);

		_svg14.transition()
			  .attr("d", lineFunction(canvas14))
			  .duration(0);

		_svg14_c.transition()
				.attr("cy", canvas14[10].y)
				.duration(0);

                document.getElementById('HIH4030').innerHTML = ((get_graph_data(28) < RAW_LOWER || get_graph_data(28) > RAW_UPPER) ? "NA" : get_graph_data(28)).concat(" raw A/D");

		//TMP102
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas15[index].y = canvas15[index + 1].y;
       		}
		canvas15[10].y = (get_graph_data(8) < TEMP_C_LOWER || get_graph_data(8) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(8)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg15.transition()
			  .attr("d", lineFunction(canvas15))
			  .duration(0);

		_svg15_c.transition()
				.attr("cy", canvas15[10].y)
				.duration(0);

                document.getElementById('TMP102').innerHTML = ((get_graph_data(8) < TEMP_C_LOWER || get_graph_data(8) > TEMP_C_UPPER) ? "NA" : get_graph_data(8)).concat(" &degC");

		//PR103J2
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas16[index].y = canvas16[index + 1].y;
       		}
		canvas16[10].y = (get_graph_data(29) < RAW_LOWER || get_graph_data(29) > RAW_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(29))*RAW_SCALE);

		_svg16.transition()
			  .attr("d", lineFunction(canvas16))
			  .duration(0);

		_svg16_c.transition()
				.attr("cy", canvas16[10].y)
				.duration(0);

                document.getElementById('PR103J2').innerHTML = ((get_graph_data(29) < RAW_LOWER || get_graph_data(29) > RAW_UPPER) ? "NA" : get_graph_data(29)).concat(" raw A/D");

		//HMC5883
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas17[index].y = canvas17[index + 1].y;
       		}
		canvas17[10].y = (get_graph_data(16) < MAG_UT_LOWER || get_graph_data(16) > MAG_UT_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(16)) - MAG_UT_LOWER)*MAG_UT_SCALE);

		_svg17.transition()
			  .attr("d", lineFunction(canvas17))
			  .duration(0);

		_svg17_c.transition()
				.attr("cy", canvas17[10].y)
				.duration(0);

                document.getElementById('HMC5883_x').innerHTML = ((get_graph_data(16) < MAG_UT_LOWER || get_graph_data(16) > MAG_UT_UPPER) ? "NA" : get_graph_data(16)).concat(" &microT");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas18[index].y = canvas18[index + 1].y;
       		}
		canvas18[10].y = (get_graph_data(17) < MAG_UT_LOWER || get_graph_data(17) > MAG_UT_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(17)) - MAG_UT_LOWER)*MAG_UT_SCALE);

		_svg18.transition()
			  .attr("d", lineFunction(canvas18))
			  .duration(0);

		_svg18_c.transition()
				.attr("cy", canvas18[10].y)
				.duration(0);

                document.getElementById('HMC5883_y').innerHTML = ((get_graph_data(17) < MAG_UT_LOWER || get_graph_data(17) > MAG_UT_UPPER) ? "NA" : get_graph_data(17)).concat(" &microT");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas19[index].y = canvas19[index + 1].y;
       		}
		canvas19[10].y = (get_graph_data(18) < MAG_UT_LOWER || get_graph_data(18) > MAG_UT_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(18)) - MAG_UT_LOWER)*MAG_UT_SCALE);

		_svg19.transition()
			  .attr("d", lineFunction(canvas19))
			  .duration(0);

		_svg19_c.transition()
				.attr("cy", canvas19[10].y)
				.duration(0);

                document.getElementById('HMC5883_z').innerHTML = ((get_graph_data(18) < MAG_UT_LOWER || get_graph_data(18) > MAG_UT_UPPER) ? "NA" : get_graph_data(18)).concat(" &microT");

		//Third column
		//SHT75
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
          		canvas20[index].y = canvas20[index + 1].y;
       		}
		canvas20[10].y = (get_graph_data(21) < TEMP_C_LOWER || get_graph_data(21) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(21)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg20.transition()
			  .attr("d", lineFunction(canvas20))
			  .duration(0);

		_svg20_c.transition()
				.attr("cy", canvas20[10].y)
				.duration(0);

                document.getElementById('SHT75_temp').innerHTML = ((get_graph_data(21) < TEMP_C_LOWER || get_graph_data(21) > TEMP_C_UPPER) ? "NA" : get_graph_data(21)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas21[index].y = canvas21[index + 1].y;
       		}
		canvas21[10].y = (get_graph_data(22) < RH_LOWER || get_graph_data(22) > RH_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(22))*RH_SCALE);

		_svg21.transition()
			  .attr("d", lineFunction(canvas21))
			  .duration(0);

		_svg21_c.transition()
				.attr("cy", canvas21[10].y)
				.duration(0);

                document.getElementById('SHT75_hum').innerHTML = ((get_graph_data(22) < RH_LOWER || get_graph_data(22) > RH_UPPER) ? "NA" : get_graph_data(22)).concat(" %RH");

		//BMP180
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas22[index].y = canvas22[index + 1].y;
       		}
		canvas22[10].y = (get_graph_data(11) < TEMP_C_LOWER || get_graph_data(11) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(11)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg22.transition()
			  .attr("d", lineFunction(canvas22))
			  .duration(0);

		_svg22_c.transition()
				.attr("cy", canvas22[10].y)
				.duration(0);

                document.getElementById('BMP180_temp').innerHTML = ((get_graph_data(11) < TEMP_C_LOWER || get_graph_data(11) > TEMP_C_UPPER) ? "NA":get_graph_data(11)).concat(" &degC");

       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas23[index].y = canvas23[index + 1].y;
       		}
		canvas23[10].y = (get_graph_data(12) < PRESSURE_LOWER || get_graph_data(12) > PRESSURE_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(12)) - PRESSURE_LOWER)*PRESSURE_SCALE);

		_svg23.transition()
			  .attr("d", lineFunction(canvas23))
			  .duration(0);

		_svg23_c.transition()
				.attr("cy", canvas23[10].y)
				.duration(0);

                document.getElementById('BMP180_pres').innerHTML = ((get_graph_data(12) < PRESSURE_LOWER || get_graph_data(12) > PRESSURE_UPPER) ? "NA" : get_graph_data(12)).concat(" Pa");

		//DS18B20
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas24[index].y = canvas24[index + 1].y;
       		}
		canvas24[10].y = (get_graph_data(6) < TEMP_C_LOWER || get_graph_data(6) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(6)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg24.transition()
			  .attr("d", lineFunction(canvas24))
			  .duration(0);

		_svg24_c.transition()
				.attr("cy", canvas24[10].y)
				.duration(0);

                document.getElementById('DS18B20').innerHTML = ((get_graph_data(6) < TEMP_C_LOWER || get_graph_data(6) > TEMP_C_UPPER) ? "NA" : get_graph_data(6)).concat(" &degC");

		//TMP421
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas25[index].y = canvas25[index + 1].y;
       		}
		canvas25[10].y = (get_graph_data(24) < TEMP_C_LOWER || get_graph_data(24) > TEMP_C_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - (parseFloat(get_graph_data(24)) - TEMP_C_LOWER)*TEMP_C_SCALE);

		_svg25.transition()
			  .attr("d", lineFunction(canvas25))
			  .duration(0);

		_svg25_c.transition()
				.attr("cy", canvas25[10].y)
				.duration(0);

                document.getElementById('TMP421').innerHTML = ((get_graph_data(24) < TEMP_C_LOWER || get_graph_data(24) > TEMP_C_UPPER) ? "NA" : get_graph_data(24)).concat(" &degC");

		//GA1A1SP20WP
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas26[index].y = canvas26[index + 1].y;
       		}
		canvas26[10].y = (get_graph_data(25) < RAW_LOWER || get_graph_data(25) > RAW_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(25))*RAW_SCALE);

		_svg26.transition()
			  .attr("d", lineFunction(canvas26))
			  .duration(0);

		_svg26_c.transition()
				.attr("cy", canvas26[10].y)
				.duration(0);

                document.getElementById('GA1A1S201WP').innerHTML = ((get_graph_data(25) < RAW_LOWER || get_graph_data(25) > RAW_UPPER) ? "NA" : get_graph_data(25)).concat(" raw A/D");

		//PDVP8104
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas27[index].y = canvas27[index + 1].y;
       		}
		canvas27[10].y = (get_graph_data(13) < RAW_LOWER || get_graph_data(13) > RAW_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(13))*RAW_SCALE);

		_svg27.transition()
			  .attr("d", lineFunction(canvas27))
			  .duration(0);

		_svg27_c.transition()
				.attr("cy", canvas27[10].y)
				.duration(0);

                document.getElementById('PDVP8104').innerHTML =((get_graph_data(13) < RAW_LOWER || get_graph_data(13) > RAW_UPPER) ? "NA" : get_graph_data(13)).concat(" raw A/D");

		//MAX4466
       		for (var index = 0; index < BUFFER - 1; index++)
       		{
           		canvas28[index].y = canvas28[index + 1].y;
       		}
		canvas28[10].y = (get_graph_data(23) < RAW_LOWER || get_graph_data(23) > RAW_UPPER) ? GRAPH_HEIGHT : (GRAPH_HEIGHT - parseFloat(get_graph_data(23))*RAW_SCALE);

		_svg28.transition()
			  .attr("d", lineFunction(canvas28))
			  .duration(0);

		_svg28_c.transition()
				.attr("cy", canvas28[10].y)
				.duration(0);

                document.getElementById('MAX4466').innerHTML = ((get_graph_data(23) < RAW_LOWER || get_graph_data(23) > RAW_UPPER) ? "NA" : get_graph_data(23)).concat(" raw A/D");
	}
}
