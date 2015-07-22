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

window.onload = function() {
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
	setInterval(update_graphs, 2000);

	/*
	 * Update the graph by adding a new data point to the end and removing the data point at the beginning
	 * graph_data elements are stored linearly in the order that they appear in the data file grabbed from
	 * Therefore, the element indecies don't necessarily line up with the layout here
	 */
	function update_graphs() {
		//First column
		//RHT03
		canvas00[0].y = canvas00[1].y;
		canvas00[1].y = canvas00[2].y;
		canvas00[2].y = canvas00[3].y;
		canvas00[3].y = canvas00[4].y;
		canvas00[4].y = canvas00[5].y;
		canvas00[5].y = canvas00[6].y;
		canvas00[6].y = canvas00[7].y;
		canvas00[7].y = canvas00[8].y;
		canvas00[8].y = canvas00[9].y;
		canvas00[9].y = canvas00[10].y;
		canvas00[10].y = 58 - (parseFloat(get_graph_data(14))+40)*0.448;
		
		_svg00.transition()
			  .attr("d", lineFunction(canvas00))
			  .duration(0);

		_svg00_c.transition()
				.attr("cy", canvas00[10].y)
				.duration(0);

		document.getElementById('RHT03_temp').innerHTML = get_graph_data(14).concat(" &degC");

		canvas01[0].y = canvas01[1].y;
		canvas01[1].y = canvas01[2].y;
		canvas01[2].y = canvas01[3].y;
		canvas01[3].y = canvas01[4].y;
		canvas01[4].y = canvas01[5].y;
		canvas01[5].y = canvas01[6].y;
		canvas01[6].y = canvas01[7].y;
		canvas01[7].y = canvas01[8].y;
		canvas01[8].y = canvas01[9].y;
		canvas01[9].y = canvas01[10].y;
		canvas01[10].y = 58 - parseFloat(get_graph_data(15))*0.58;
	
		_svg01.transition()
			  .attr("d", lineFunction(canvas01))
			  .duration(0);

		_svg01_c.transition()
				.attr("cy", canvas01[10].y)
				.duration(0);

		document.getElementById('RHT03_hum').innerHTML = get_graph_data(15).concat(" %RH");
	
		//HTU21D
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
		canvas02[10].y = 58 - (parseFloat(get_graph_data(19))+40)*0.448;
	
		_svg02.transition()
			  .attr("d", lineFunction(canvas02))
			  .duration(0);

		_svg02_c.transition()
				.attr("cy", canvas02[10].y)
				.duration(0);

		document.getElementById('HTU21D_temp').innerHTML = get_graph_data(19).concat(" &degC");
	
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
		canvas03[10].y = 58 - (parseFloat(get_graph_data(20)))*0.58;
	
		_svg03.transition()
			  .attr("d", lineFunction(canvas03))
			  .duration(0);

		_svg03_c.transition()
				.attr("cy", canvas03[10].y)
				.duration(0);

		document.getElementById('HTU21D_hum').innerHTML = get_graph_data(20).concat(" %RH");

		//HIH6130
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
		canvas04[10].y = 58 - (parseFloat(get_graph_data(9))+40)*0.448;
	
		_svg04.transition()
			  .attr("d", lineFunction(canvas04))
			  .duration(0);

		_svg04_c.transition()
				.attr("cy", canvas04[10].y)
				.duration(0);

		document.getElementById('HIH6130_temp').innerHTML = get_graph_data(9).concat(" &degC");
	
		canvas05[0].y = canvas05[1].y;
		canvas05[1].y = canvas05[2].y;
		canvas05[2].y = canvas05[3].y;
		canvas05[3].y = canvas05[4].y;
		canvas05[4].y = canvas05[5].y;
		canvas05[5].y = canvas05[6].y;
		canvas05[6].y = canvas05[7].y;
		canvas05[7].y = canvas05[8].y;
		canvas05[8].y = canvas05[9].y;
		canvas05[9].y = canvas05[10].y;
		canvas05[10].y = 58 - (parseFloat(get_graph_data(10)))*0.58;
	
		_svg05.transition()
			  .attr("d", lineFunction(canvas05))
			  .duration(0);

		_svg05_c.transition()
				.attr("cy", canvas05[10].y)
				.duration(0);

		document.getElementById('HIH6130_hum').innerHTML = get_graph_data(10).concat(" %RH");

		//MLX90614ESF
		canvas06[0].y = canvas06[1].y;
		canvas06[1].y = canvas06[2].y;
		canvas06[2].y = canvas06[3].y;
		canvas06[3].y = canvas06[4].y;
		canvas06[4].y = canvas06[5].y;
		canvas06[5].y = canvas06[6].y;
		canvas06[6].y = canvas06[7].y;
		canvas06[7].y = canvas06[8].y;
		canvas06[8].y = canvas06[9].y;
		canvas06[9].y = canvas06[10].y;
		canvas06[10].y = 58 - (parseFloat(get_graph_data(7))+40)*0.448;
	
		_svg06.transition()
			  .attr("d", lineFunction(canvas06))
			  .duration(0);

		_svg06_c.transition()
				.attr("cy", canvas06[10].y)
				.duration(0);

		document.getElementById('MLX90614ESF').innerHTML = get_graph_data(7).concat(" &degC");

		//MMA8452Q
		canvas07[0].y = canvas07[1].y;
		canvas07[1].y = canvas07[2].y;
		canvas07[2].y = canvas07[3].y;
		canvas07[3].y = canvas07[4].y;
		canvas07[4].y = canvas07[5].y;
		canvas07[5].y = canvas07[6].y;
		canvas07[6].y = canvas07[7].y;
		canvas07[7].y = canvas07[8].y;
		canvas07[8].y = canvas07[9].y;
		canvas07[9].y = canvas07[10].y;
		canvas07[10].y = 58 - (parseFloat(get_graph_data(2))+2)*14.5;
	
		_svg07.transition()
			  .attr("d", lineFunction(canvas07))
			  .duration(0);

		_svg07_c.transition()
				.attr("cy", canvas07[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_x').innerHTML = get_graph_data(2).concat(" g");
	
		canvas08[0].y = canvas08[1].y;
		canvas08[1].y = canvas08[2].y;
		canvas08[2].y = canvas08[3].y;
		canvas08[3].y = canvas08[4].y;
		canvas08[4].y = canvas08[5].y;
		canvas08[5].y = canvas08[6].y;
		canvas08[6].y = canvas08[7].y;
		canvas08[7].y = canvas08[8].y;
		canvas08[8].y = canvas08[9].y;
		canvas08[9].y = canvas08[10].y;
		canvas08[10].y = 58 - (parseFloat(get_graph_data(3))+2)*14.5;
	
		_svg08.transition()
			  .attr("d", lineFunction(canvas08))
			  .duration(0);

		_svg08_c.transition()
				.attr("cy", canvas08[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_y').innerHTML = get_graph_data(3).concat(" g");
	
		canvas09[0].y = canvas09[1].y;
		canvas09[1].y = canvas09[2].y;
		canvas09[2].y = canvas09[3].y;
		canvas09[3].y = canvas09[4].y;
		canvas09[4].y = canvas09[5].y;
		canvas09[5].y = canvas09[6].y;
		canvas09[6].y = canvas09[7].y;
		canvas09[7].y = canvas09[8].y;
		canvas09[8].y = canvas09[9].y;
		canvas09[9].y = canvas09[10].y;
		canvas09[10].y = 58 - (parseFloat(get_graph_data(4))+2)*14.5;
	
		_svg09.transition()
			  .attr("d", lineFunction(canvas09))
			  .duration(0);

		_svg09_c.transition()
				.attr("cy", canvas09[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_z').innerHTML = get_graph_data(4).concat(" g");
	
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
		canvas010[10].y = 58 - (parseFloat(get_graph_data(5))+1)*19.3;
	
		_svg010.transition()
			  .attr("d", lineFunction(canvas010))
			  .duration(0);

		_svg010_c.transition()
				.attr("cy", canvas010[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_rms').innerHTML = get_graph_data(5).concat(" g");

		//Second column
		//SHT15
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
		canvas10[10].y = 58 - (parseFloat(get_graph_data(26))+40)*0.448;
	
		_svg10.transition()
			  .attr("d", lineFunction(canvas10))
			  .duration(0);

		_svg10_c.transition()
				.attr("cy", canvas10[10].y)
				.duration(0);

		document.getElementById('SHT15_temp').innerHTML = get_graph_data(26).concat(" &degC");
	
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
		canvas11[10].y = 58 - (parseFloat(get_graph_data(27)))*0.58;
	
		_svg11.transition()
			  .attr("d", lineFunction(canvas11))
			  .duration(0);

		_svg11_c.transition()
				.attr("cy", canvas11[10].y)
				.duration(0);

		document.getElementById('SHT15_hum').innerHTML = get_graph_data(27).concat(" %RH");
	
		//D6T44L06
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
		canvas12[10].y = 58 - (parseFloat(get_graph_data(1))+40)*0.448;
	
		_svg12.transition()
			  .attr("d", lineFunction(canvas12))
			  .duration(0);

		_svg12_c.transition()
				.attr("cy", canvas12[10].y)
				.duration(0);

		document.getElementById('D6T44L06_avg_temp').innerHTML = get_graph_data(1).concat(" &degC");
		//sensor060.addData([get_graph_data(1)], "");
	
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
		canvas13[10].y = 58 - (parseFloat(get_graph_data(0))+40)*0.448;
	
		_svg13.transition()
			  .attr("d", lineFunction(canvas13))
			  .duration(0);

		_svg13_c.transition()
				.attr("cy", canvas13[10].y)
				.duration(0);

		document.getElementById('D6T44L06_case_temp').innerHTML = get_graph_data(0).concat(" &degC");

		//HIH4030
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
		canvas14[10].y = 58 - (parseFloat(get_graph_data(28)))*0.057;
	
		_svg14.transition()
			  .attr("d", lineFunction(canvas14))
			  .duration(0);

		_svg14_c.transition()
				.attr("cy", canvas14[10].y)
				.duration(0);

		document.getElementById('HIH4030').innerHTML = get_graph_data(28).concat(" raw A/D");

		//TMP102
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
		canvas15[10].y = 58 - (parseFloat(get_graph_data(8))+40)*0.448;
	
		_svg15.transition()
			  .attr("d", lineFunction(canvas15))
			  .duration(0);

		_svg15_c.transition()
				.attr("cy", canvas15[10].y)
				.duration(0);

		document.getElementById('TMP102').innerHTML = get_graph_data(8).concat(" &degC");

		//PR103J2
		canvas16[0].y = canvas16[1].y;
		canvas16[1].y = canvas16[2].y;
		canvas16[2].y = canvas16[3].y;
		canvas16[3].y = canvas16[4].y;
		canvas16[4].y = canvas16[5].y;
		canvas16[5].y = canvas16[6].y;
		canvas16[6].y = canvas16[7].y;
		canvas16[7].y = canvas16[8].y;
		canvas16[8].y = canvas16[9].y;
		canvas16[9].y = canvas16[10].y;
		canvas16[10].y = 58 - (parseFloat(get_graph_data(29)))*0.057;
	
		_svg16.transition()
			  .attr("d", lineFunction(canvas16))
			  .duration(0);

		_svg16_c.transition()
				.attr("cy", canvas16[10].y)
				.duration(0);

		document.getElementById('PR103J2').innerHTML = get_graph_data(29).concat(" raw A/D");

		//HMC5883
		canvas17[0].y = canvas17[1].y;
		canvas17[1].y = canvas17[2].y;
		canvas17[2].y = canvas17[3].y;
		canvas17[3].y = canvas17[4].y;
		canvas17[4].y = canvas17[5].y;
		canvas17[5].y = canvas17[6].y;
		canvas17[6].y = canvas17[7].y;
		canvas17[7].y = canvas17[8].y;
		canvas17[8].y = canvas17[9].y;
		canvas17[9].y = canvas17[10].y;
		canvas17[10].y = 58 - (parseFloat(get_graph_data(16))+5)*5.8;
	
		_svg17.transition()
			  .attr("d", lineFunction(canvas17))
			  .duration(0);

		_svg17_c.transition()
				.attr("cy", canvas17[10].y)
				.duration(0);

		document.getElementById('HMC5883_x').innerHTML = get_graph_data(16).concat(" &microT");
	
		canvas18[0].y = canvas18[1].y;
		canvas18[1].y = canvas18[2].y;
		canvas18[2].y = canvas18[3].y;
		canvas18[3].y = canvas18[4].y;
		canvas18[4].y = canvas18[5].y;
		canvas18[5].y = canvas18[6].y;
		canvas18[6].y = canvas18[7].y;
		canvas18[7].y = canvas18[8].y;
		canvas18[8].y = canvas18[9].y;
		canvas18[9].y = canvas18[10].y;
		canvas18[10].y = 58 - (parseFloat(get_graph_data(17))+5)*5.8;
	
		_svg18.transition()
			  .attr("d", lineFunction(canvas18))
			  .duration(0);

		_svg18_c.transition()
				.attr("cy", canvas18[10].y)
				.duration(0);

		document.getElementById('HMC5883_y').innerHTML = get_graph_data(17).concat(" &microT");
	
		canvas19[0].y = canvas19[1].y;
		canvas19[1].y = canvas19[2].y;
		canvas19[2].y = canvas19[3].y;
		canvas19[3].y = canvas19[4].y;
		canvas19[4].y = canvas19[5].y;
		canvas19[5].y = canvas19[6].y;
		canvas19[6].y = canvas19[7].y;
		canvas19[7].y = canvas19[8].y;
		canvas19[8].y = canvas19[9].y;
		canvas19[9].y = canvas19[10].y;
		canvas19[10].y = 58 - (parseFloat(get_graph_data(18))+5)*5.8;
	
		_svg19.transition()
			  .attr("d", lineFunction(canvas19))
			  .duration(0);

		_svg19_c.transition()
				.attr("cy", canvas19[10].y)
				.duration(0);

		document.getElementById('HMC5883_z').innerHTML = get_graph_data(18).concat(" &microT");

		//Third column
		//SHT75
		canvas20[0].y = canvas20[1].y;
		canvas20[1].y = canvas20[2].y;
		canvas20[2].y = canvas20[3].y;
		canvas20[3].y = canvas20[4].y;
		canvas20[4].y = canvas20[5].y;
		canvas20[5].y = canvas20[6].y;
		canvas20[6].y = canvas20[7].y;
		canvas20[7].y = canvas20[8].y;
		canvas20[8].y = canvas20[9].y;
		canvas20[9].y = canvas20[10].y;
		canvas20[10].y = 58 - (parseFloat(get_graph_data(21))+40)*0.448;
	
		_svg20.transition()
			  .attr("d", lineFunction(canvas20))
			  .duration(0);

		_svg20_c.transition()
				.attr("cy", canvas20[10].y)
				.duration(0);

		document.getElementById('SHT75_temp').innerHTML = get_graph_data(21).concat(" &degC");

		canvas21[0].y = canvas21[1].y;
		canvas21[1].y = canvas21[2].y;
		canvas21[2].y = canvas21[3].y;
		canvas21[3].y = canvas21[4].y;
		canvas21[4].y = canvas21[5].y;
		canvas21[5].y = canvas21[6].y;
		canvas21[6].y = canvas21[7].y;
		canvas21[7].y = canvas21[8].y;
		canvas21[8].y = canvas21[9].y;
		canvas21[9].y = canvas21[10].y;
		canvas21[10].y = 58 - (parseFloat(get_graph_data(22)))*0.58;
	
		_svg21.transition()
			  .attr("d", lineFunction(canvas21))
			  .duration(0);

		_svg21_c.transition()
				.attr("cy", canvas21[10].y)
				.duration(0);

		document.getElementById('SHT75_hum').innerHTML = get_graph_data(22).concat(" %RH");
	
		//BMP180
		canvas22[0].y = canvas22[1].y;
		canvas22[1].y = canvas22[2].y;
		canvas22[2].y = canvas22[3].y;
		canvas22[3].y = canvas22[4].y;
		canvas22[4].y = canvas22[5].y;
		canvas22[5].y = canvas22[6].y;
		canvas22[6].y = canvas22[7].y;
		canvas22[7].y = canvas22[8].y;
		canvas22[8].y = canvas22[9].y;
		canvas22[9].y = canvas22[10].y;
		canvas22[10].y = 58 - (parseFloat(get_graph_data(11))+40)*0.448;
	
		_svg22.transition()
			  .attr("d", lineFunction(canvas22))
			  .duration(0);

		_svg22_c.transition()
				.attr("cy", canvas22[10].y)
				.duration(0);

		document.getElementById('BMP180_temp').innerHTML = get_graph_data(11).concat(" &degC");
	
		canvas23[0].y = canvas23[1].y;
		canvas23[1].y = canvas23[2].y;
		canvas23[2].y = canvas23[3].y;
		canvas23[3].y = canvas23[4].y;
		canvas23[4].y = canvas23[5].y;
		canvas23[5].y = canvas23[6].y;
		canvas23[6].y = canvas23[7].y;
		canvas23[7].y = canvas23[8].y;
		canvas23[8].y = canvas23[9].y;
		canvas23[9].y = canvas23[10].y;
		canvas23[10].y = 58 - (parseFloat(get_graph_data(12))-800)*0.193;
	
		_svg23.transition()
			  .attr("d", lineFunction(canvas23))
			  .duration(0);

		_svg23_c.transition()
				.attr("cy", canvas23[10].y)
				.duration(0);

		document.getElementById('BMP180_pres').innerHTML = get_graph_data(12).concat(" hPa");

		//DS18B20
		canvas24[0].y = canvas24[1].y;
		canvas24[1].y = canvas24[2].y;
		canvas24[2].y = canvas24[3].y;
		canvas24[3].y = canvas24[4].y;
		canvas24[4].y = canvas24[5].y;
		canvas24[5].y = canvas24[6].y;
		canvas24[6].y = canvas24[7].y;
		canvas24[7].y = canvas24[8].y;
		canvas24[8].y = canvas24[9].y;
		canvas24[9].y = canvas24[10].y;
		canvas24[10].y = 58 - (parseFloat(get_graph_data(6))+40)*0.448;
	
		_svg24.transition()
			  .attr("d", lineFunction(canvas24))
			  .duration(0);

		_svg24_c.transition()
				.attr("cy", canvas24[10].y)
				.duration(0);

		document.getElementById('DS18B20').innerHTML = get_graph_data(6).concat(" &degC");

		//TMP421
		canvas25[0].y = canvas25[1].y;
		canvas25[1].y = canvas25[2].y;
		canvas25[2].y = canvas25[3].y;
		canvas25[3].y = canvas25[4].y;
		canvas25[4].y = canvas25[5].y;
		canvas25[5].y = canvas25[6].y;
		canvas25[6].y = canvas25[7].y;
		canvas25[7].y = canvas25[8].y;
		canvas25[8].y = canvas25[9].y;
		canvas25[9].y = canvas25[10].y;
		canvas25[10].y = 58 - (parseFloat(get_graph_data(24))+40)*0.448;
	
		_svg25.transition()
			  .attr("d", lineFunction(canvas25))
			  .duration(0);

		_svg25_c.transition()
				.attr("cy", canvas25[10].y)
				.duration(0);

		document.getElementById('TMP421').innerHTML = get_graph_data(24).concat(" &degC");

		//GA1A1SP20WP
		canvas26[0].y = canvas26[1].y;
		canvas26[1].y = canvas26[2].y;
		canvas26[2].y = canvas26[3].y;
		canvas26[3].y = canvas26[4].y;
		canvas26[4].y = canvas26[5].y;
		canvas26[5].y = canvas26[6].y;
		canvas26[6].y = canvas26[7].y;
		canvas26[7].y = canvas26[8].y;
		canvas26[8].y = canvas26[9].y;
		canvas26[9].y = canvas26[10].y;
		canvas26[10].y = 58 - (parseFloat(get_graph_data(25)))*0.057;
	
		_svg26.transition()
			  .attr("d", lineFunction(canvas26))
			  .duration(0);

		_svg26_c.transition()
				.attr("cy", canvas26[10].y)
				.duration(0);

		document.getElementById('GA1A1S201WP').innerHTML = get_graph_data(25).concat(" raw A/D");

		//PDVP8104
		canvas27[0].y = canvas27[1].y;
		canvas27[1].y = canvas27[2].y;
		canvas27[2].y = canvas27[3].y;
		canvas27[3].y = canvas27[4].y;
		canvas27[4].y = canvas27[5].y;
		canvas27[5].y = canvas27[6].y;
		canvas27[6].y = canvas27[7].y;
		canvas27[7].y = canvas27[8].y;
		canvas27[8].y = canvas27[9].y;
		canvas27[9].y = canvas27[10].y;
		canvas27[10].y = 58 - (parseFloat(get_graph_data(13)))*0.057;
	
		_svg27.transition()
			  .attr("d", lineFunction(canvas27))
			  .duration(0);

		_svg27_c.transition()
				.attr("cy", canvas27[10].y)
				.duration(0);

		document.getElementById('PDVP8104').innerHTML = get_graph_data(13).concat(" raw A/D");

		//MAX4466
		canvas28[0].y = canvas28[1].y;
		canvas28[1].y = canvas28[2].y;
		canvas28[2].y = canvas28[3].y;
		canvas28[3].y = canvas28[4].y;
		canvas28[4].y = canvas28[5].y;
		canvas28[5].y = canvas28[6].y;
		canvas28[6].y = canvas28[7].y;
		canvas28[7].y = canvas28[8].y;
		canvas28[8].y = canvas28[9].y;
		canvas28[9].y = canvas28[10].y;
		canvas28[10].y = 58 - (parseFloat(get_graph_data(23)))*0.057;

		_svg28.transition()
			  .attr("d", lineFunction(canvas28))
			  .duration(0);

		_svg28_c.transition()
				.attr("cy", canvas28[10].y)
				.duration(0);

		document.getElementById('MAX4466').innerHTML = get_graph_data(23).concat(" raw A/D");
	}
}