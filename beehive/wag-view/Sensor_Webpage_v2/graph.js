/*
 * Define Chart variables for each sensor
 * Labels should be empty strings and initial data is 10 points for history size
 * The canvas variables follow a column, row ordering: canvas<col><row><multiple>
 */

//First column
//RHT03 Temperature Sensor
var canvas000 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas001 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//SHT15 Temperature, Humidity Sensor
var canvas010 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas011 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//SHT75 Temperature, Humidity Sensor
var canvas020 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas021 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HMC5883 Magnetic Field x, y, z Sensor
var canvas030 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas031 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas032 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//BMP180 Temperature, Pressure Sensor
var canvas040 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas041 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//MMA8452Q Acceleration x, y, z, rms Vibration Sensor
var canvas050 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas051 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas052 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas053 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Second column
//DS18B20 Temperature Sensor
var canvas10 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//GA1A1SP20WP Light Intensity Sensor
var canvas11 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//PDVP8104 Light Intensity Sensor
var canvas12 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//MAX4466 Acoustic Intensity Sensor
var canvas13 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//MLX90614ESF Temperature Sensor
var canvas14 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//PR103J2 Temperature Sensor
var canvas15 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//TMP102 Temperature Sensor
var canvas16 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//TMP421 Temperature Sensor
var canvas17 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HIH4030 Humidity Sensor
var canvas18 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HIH6130 Temperature, Humidity Sensor
var canvas190 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas191 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//HTU21D Temperature, Humidity Sensor
var canvas1100 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas1101 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//D6T44L06 Avg. Temperature, Casing Temperature Sensor
var canvas1110 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

var canvas1111 = [{"x":0, "y":30}, {"x":19, "y":30}, {"x":38, "y":30}, {"x":57, "y":30}, {"x":76, "y":30}, {"x":95, "y":30},
				 {"x":114, "y":30}, {"x":133, "y":30}, {"x":152, "y":30}, {"x":171, "y":30}, {"x":190, "y":30}];

//Third column
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
	//First column
	var svg000 = d3.select("div#graph000")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg001 = d3.select("div#graph001")
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

	var svg020 = d3.select("div#graph020")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg021 = d3.select("div#graph021")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg030 = d3.select("div#graph030")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg031 = d3.select("div#graph031")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg032 = d3.select("div#graph032")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg040 = d3.select("div#graph040")
				  .append("svg")
				  .attr("width", w)
				  .attr("height", h);

	var svg041 = d3.select("div#graph041")
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

	var svg052 = d3.select("div#graph052")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg053 = d3.select("div#graph053")
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

	var svg190 = d3.select("div#graph190")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg191 = d3.select("div#graph191")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg1100 = d3.select("div#graph1100")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg1101 = d3.select("div#graph1101")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg1110 = d3.select("div#graph1110")
				   .append("svg")
				   .attr("width", w)
				   .attr("height", h);

	var svg1111 = d3.select("div#graph1111")
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

	//Create the surfaces and current value circles
	//First column
	var _svg000 = svg000.append("path")
					  .attr("d", lineFunction(canvas000))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg000_c = svg000.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas000[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg001 = svg001.append("path")
					  .attr("d", lineFunction(canvas001))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg001_c = svg001.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas001[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg010 = svg010.append("path")
					  .attr("d", lineFunction(canvas010))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg010_c = svg010.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas010[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg011 = svg011.append("path")
					  .attr("d", lineFunction(canvas011))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg011_c = svg011.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas011[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg020 = svg020.append("path")
					  .attr("d", lineFunction(canvas020))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg020_c = svg020.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas020[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg021 = svg021.append("path")
					  .attr("d", lineFunction(canvas021))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg021_c = svg021.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas021[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg030 = svg030.append("path")
					  .attr("d", lineFunction(canvas030))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg030_c = svg030.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas030[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg031 = svg031.append("path")
					  .attr("d", lineFunction(canvas031))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg031_c = svg031.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas031[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg032 = svg032.append("path")
					  .attr("d", lineFunction(canvas032))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg032_c = svg032.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas032[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg040 = svg040.append("path")
					  .attr("d", lineFunction(canvas040))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg040_c = svg040.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas040[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg041 = svg041.append("path")
					  .attr("d", lineFunction(canvas041))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg041_c = svg041.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas041[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg050 = svg050.append("path")
					  .attr("d", lineFunction(canvas050))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg050_c = svg050.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas050[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg051 = svg051.append("path")
					  .attr("d", lineFunction(canvas051))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg051_c = svg051.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas051[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg052 = svg052.append("path")
					  .attr("d", lineFunction(canvas052))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg052_c = svg052.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas052[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg053 = svg053.append("path")
					  .attr("d", lineFunction(canvas053))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg053_c = svg053.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas053[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	//Second column
	var _svg10 = svg10.append("path")
					  .attr("d", lineFunction(canvas10))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg10_c = svg10.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas10[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg11 = svg11.append("path")
					  .attr("d", lineFunction(canvas11))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg11_c = svg11.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas11[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg12 = svg12.append("path")
					  .attr("d", lineFunction(canvas12))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg12_c = svg12.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas12[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg13 = svg13.append("path")
					  .attr("d", lineFunction(canvas13))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg13_c = svg13.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas13[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg14 = svg14.append("path")
					  .attr("d", lineFunction(canvas14))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg14_c = svg14.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas14[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg15 = svg15.append("path")
					  .attr("d", lineFunction(canvas15))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg15_c = svg15.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas15[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg16 = svg16.append("path")
					  .attr("d", lineFunction(canvas16))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg16_c = svg16.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas16[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg17 = svg17.append("path")
					  .attr("d", lineFunction(canvas17))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg17_c = svg17.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas17[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg18 = svg18.append("path")
					  .attr("d", lineFunction(canvas18))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg18_c = svg18.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas18[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg190 = svg190.append("path")
					  .attr("d", lineFunction(canvas190))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg190_c = svg190.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas190[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg191 = svg191.append("path")
					  .attr("d", lineFunction(canvas191))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg191_c = svg191.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas191[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg1100 = svg1100.append("path")
					  .attr("d", lineFunction(canvas1100))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg1100_c = svg1100.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas1100[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg1101 = svg1101.append("path")
					  .attr("d", lineFunction(canvas1101))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg1101_c = svg1101.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas1101[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg1110 = svg1110.append("path")
					  .attr("d", lineFunction(canvas1110))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg1110_c = svg1110.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas1110[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg1111 = svg1111.append("path")
					  .attr("d", lineFunction(canvas1111))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg1111_c = svg1111.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas1111[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	//Third column
	var _svg20 = svg20.append("path")
					  .attr("d", lineFunction(canvas20))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg20_c = svg20.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas20[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg21 = svg21.append("path")
					  .attr("d", lineFunction(canvas21))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg21_c = svg21.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas21[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg22 = svg22.append("path")
					  .attr("d", lineFunction(canvas22))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg22_c = svg22.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas22[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg23 = svg23.append("path")
					  .attr("d", lineFunction(canvas23))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg23_c = svg23.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas23[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg24 = svg24.append("path")
					  .attr("d", lineFunction(canvas24))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg24_c = svg24.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas24[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg25 = svg25.append("path")
					  .attr("d", lineFunction(canvas25))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg25_c = svg25.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas25[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg26 = svg26.append("path")
					  .attr("d", lineFunction(canvas26))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg26_c = svg26.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas26[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");

	var _svg27 = svg27.append("path")
					  .attr("d", lineFunction(canvas27))
					  .attr("stroke", "#ff5000")
					  .attr("stroke-width", 1)
					  .attr("fill", "none");

	var _svg27_c = svg27.append("circle")
						.attr("cx", 190)
						.attr("cy", canvas27[10].y)
						.attr("r", 2)
						.attr("fill", "#3f3f3f");
	//Time interval to update graphs
	setInterval(update_graphs, 5000);

	/*
	 * Update the graph by adding a new data point to the end and removing the data point at the beginning
	 * graph_data elements are stored linearly in the order that they appear in the data file grabbed from
	 * Therefore, the element indecies don't necessarily line up with the layout here
	 */
	function update_graphs() {
		//First column
		//RHT03
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
		canvas000[10].y = 58 - (parseFloat(get_graph_data(14))+40)*0.448;
		
		_svg000.transition()
			  .attr("d", lineFunction(canvas000))
			  .duration(0);

		_svg000_c.transition()
				.attr("cy", canvas000[10].y)
				.duration(0);

		document.getElementById('RHT03_temp').innerHTML = get_graph_data(14).concat(" &degC");

		canvas001[0].y = canvas001[1].y;
		canvas001[1].y = canvas001[2].y;
		canvas001[2].y = canvas001[3].y;
		canvas001[3].y = canvas001[4].y;
		canvas001[4].y = canvas001[5].y;
		canvas001[5].y = canvas001[6].y;
		canvas001[6].y = canvas001[7].y;
		canvas001[7].y = canvas001[8].y;
		canvas001[8].y = canvas001[9].y;
		canvas001[9].y = canvas001[10].y;
		canvas001[10].y = 58 - parseFloat(get_graph_data(15))*0.58;
	
		_svg001.transition()
			  .attr("d", lineFunction(canvas001))
			  .duration(0);

		_svg001_c.transition()
				.attr("cy", canvas001[10].y)
				.duration(0);

		document.getElementById('RHT03_hum').innerHTML = get_graph_data(15).concat(" %RH");
	
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
		canvas010[10].y = 58 - (parseFloat(get_graph_data(26))+40)*0.448;
	
		_svg010.transition()
			  .attr("d", lineFunction(canvas010))
			  .duration(0);

		_svg010_c.transition()
				.attr("cy", canvas010[10].y)
				.duration(0);

		document.getElementById('SHT15_temp').innerHTML = get_graph_data(26).concat(" &degC");
	
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
		canvas011[10].y = 58 - (parseFloat(get_graph_data(27)))*0.58;
	
		_svg011.transition()
			  .attr("d", lineFunction(canvas011))
			  .duration(0);

		_svg011_c.transition()
				.attr("cy", canvas011[10].y)
				.duration(0);

		document.getElementById('SHT15_hum').innerHTML = get_graph_data(27).concat(" %RH");
	
		//SHT75
		canvas020[0].y = canvas020[1].y;
		canvas020[1].y = canvas020[2].y;
		canvas020[2].y = canvas020[3].y;
		canvas020[3].y = canvas020[4].y;
		canvas020[4].y = canvas020[5].y;
		canvas020[5].y = canvas020[6].y;
		canvas020[6].y = canvas020[7].y;
		canvas020[7].y = canvas020[8].y;
		canvas020[8].y = canvas020[9].y;
		canvas020[9].y = canvas020[10].y;
		canvas020[10].y = 58 - (parseFloat(get_graph_data(21))+40)*0.448;
	
		_svg020.transition()
			  .attr("d", lineFunction(canvas020))
			  .duration(0);

		_svg020_c.transition()
				.attr("cy", canvas020[10].y)
				.duration(0);

		document.getElementById('SHT75_temp').innerHTML = get_graph_data(21).concat(" &degC");

		canvas021[0].y = canvas021[1].y;
		canvas021[1].y = canvas021[2].y;
		canvas021[2].y = canvas021[3].y;
		canvas021[3].y = canvas021[4].y;
		canvas021[4].y = canvas021[5].y;
		canvas021[5].y = canvas021[6].y;
		canvas021[6].y = canvas021[7].y;
		canvas021[7].y = canvas021[8].y;
		canvas021[8].y = canvas021[9].y;
		canvas021[9].y = canvas021[10].y;
		canvas021[10].y = 58 - (parseFloat(get_graph_data(22)))*0.58;
	
		_svg021.transition()
			  .attr("d", lineFunction(canvas021))
			  .duration(0);

		_svg021_c.transition()
				.attr("cy", canvas021[10].y)
				.duration(0);

		document.getElementById('SHT75_hum').innerHTML = get_graph_data(22).concat(" %RH");
	
		//HMC5883
		canvas030[0].y = canvas030[1].y;
		canvas030[1].y = canvas030[2].y;
		canvas030[2].y = canvas030[3].y;
		canvas030[3].y = canvas030[4].y;
		canvas030[4].y = canvas030[5].y;
		canvas030[5].y = canvas030[6].y;
		canvas030[6].y = canvas030[7].y;
		canvas030[7].y = canvas030[8].y;
		canvas030[8].y = canvas030[9].y;
		canvas030[9].y = canvas030[10].y;
		canvas030[10].y = 58 - (parseFloat(get_graph_data(16))+5)*5.8;
	
		_svg030.transition()
			  .attr("d", lineFunction(canvas030))
			  .duration(0);

		_svg030_c.transition()
				.attr("cy", canvas030[10].y)
				.duration(0);

		document.getElementById('HMC5883_x').innerHTML = get_graph_data(16).concat(" &microT");
	
		canvas031[0].y = canvas031[1].y;
		canvas031[1].y = canvas031[2].y;
		canvas031[2].y = canvas031[3].y;
		canvas031[3].y = canvas031[4].y;
		canvas031[4].y = canvas031[5].y;
		canvas031[5].y = canvas031[6].y;
		canvas031[6].y = canvas031[7].y;
		canvas031[7].y = canvas031[8].y;
		canvas031[8].y = canvas031[9].y;
		canvas031[9].y = canvas031[10].y;
		canvas031[10].y = 58 - (parseFloat(get_graph_data(17))+5)*5.8;
	
		_svg031.transition()
			  .attr("d", lineFunction(canvas031))
			  .duration(0);

		_svg031_c.transition()
				.attr("cy", canvas031[10].y)
				.duration(0);

		document.getElementById('HMC5883_y').innerHTML = get_graph_data(17).concat(" &microT");
	
		canvas032[0].y = canvas032[1].y;
		canvas032[1].y = canvas032[2].y;
		canvas032[2].y = canvas032[3].y;
		canvas032[3].y = canvas032[4].y;
		canvas032[4].y = canvas032[5].y;
		canvas032[5].y = canvas032[6].y;
		canvas032[6].y = canvas032[7].y;
		canvas032[7].y = canvas032[8].y;
		canvas032[8].y = canvas032[9].y;
		canvas032[9].y = canvas032[10].y;
		canvas032[10].y = 58 - (parseFloat(get_graph_data(18))+5)*5.8;
	
		_svg032.transition()
			  .attr("d", lineFunction(canvas032))
			  .duration(0);

		_svg032_c.transition()
				.attr("cy", canvas032[10].y)
				.duration(0);

		document.getElementById('HMC5883_z').innerHTML = get_graph_data(18).concat(" &microT");
	
		//BMP180
		canvas040[0].y = canvas040[1].y;
		canvas040[1].y = canvas040[2].y;
		canvas040[2].y = canvas040[3].y;
		canvas040[3].y = canvas040[4].y;
		canvas040[4].y = canvas040[5].y;
		canvas040[5].y = canvas040[6].y;
		canvas040[6].y = canvas040[7].y;
		canvas040[7].y = canvas040[8].y;
		canvas040[8].y = canvas040[9].y;
		canvas040[9].y = canvas040[10].y;
		canvas040[10].y = 58 - (parseFloat(get_graph_data(11))+40)*0.448;
	
		_svg040.transition()
			  .attr("d", lineFunction(canvas040))
			  .duration(0);

		_svg040_c.transition()
				.attr("cy", canvas040[10].y)
				.duration(0);

		document.getElementById('BMP180_temp').innerHTML = get_graph_data(11).concat(" &degC");
	
		canvas041[0].y = canvas041[1].y;
		canvas041[1].y = canvas041[2].y;
		canvas041[2].y = canvas041[3].y;
		canvas041[3].y = canvas041[4].y;
		canvas041[4].y = canvas041[5].y;
		canvas041[5].y = canvas041[6].y;
		canvas041[6].y = canvas041[7].y;
		canvas041[7].y = canvas041[8].y;
		canvas041[8].y = canvas041[9].y;
		canvas041[9].y = canvas041[10].y;
		canvas041[10].y = 58 - (parseFloat(get_graph_data(12))-800)*0.193;
	
		_svg041.transition()
			  .attr("d", lineFunction(canvas041))
			  .duration(0);

		_svg041_c.transition()
				.attr("cy", canvas041[10].y)
				.duration(0);

		document.getElementById('BMP180_pres').innerHTML = get_graph_data(12).concat(" hPa");

		//MMA8452Q
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
		canvas050[10].y = 58 - (parseFloat(get_graph_data(2))+2)*14.5;
	
		_svg050.transition()
			  .attr("d", lineFunction(canvas050))
			  .duration(0);

		_svg050_c.transition()
				.attr("cy", canvas050[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_x').innerHTML = get_graph_data(2).concat(" g");
	
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
		canvas051[10].y = 58 - (parseFloat(get_graph_data(3))+2)*14.5;
	
		_svg051.transition()
			  .attr("d", lineFunction(canvas051))
			  .duration(0);

		_svg051_c.transition()
				.attr("cy", canvas051[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_y').innerHTML = get_graph_data(3).concat(" g");
	
		canvas052[0].y = canvas052[1].y;
		canvas052[1].y = canvas052[2].y;
		canvas052[2].y = canvas052[3].y;
		canvas052[3].y = canvas052[4].y;
		canvas052[4].y = canvas052[5].y;
		canvas052[5].y = canvas052[6].y;
		canvas052[6].y = canvas052[7].y;
		canvas052[7].y = canvas052[8].y;
		canvas052[8].y = canvas052[9].y;
		canvas052[9].y = canvas052[10].y;
		canvas052[10].y = 58 - (parseFloat(get_graph_data(4))+2)*14.5;
	
		_svg052.transition()
			  .attr("d", lineFunction(canvas052))
			  .duration(0);

		_svg052_c.transition()
				.attr("cy", canvas052[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_z').innerHTML = get_graph_data(4).concat(" g");
	
		canvas053[0].y = canvas053[1].y;
		canvas053[1].y = canvas053[2].y;
		canvas053[2].y = canvas053[3].y;
		canvas053[3].y = canvas053[4].y;
		canvas053[4].y = canvas053[5].y;
		canvas053[5].y = canvas053[6].y;
		canvas053[6].y = canvas053[7].y;
		canvas053[7].y = canvas053[8].y;
		canvas053[8].y = canvas053[9].y;
		canvas053[9].y = canvas053[10].y;
		canvas053[10].y = 58 - (parseFloat(get_graph_data(5))+1)*19.3;
	
		_svg053.transition()
			  .attr("d", lineFunction(canvas053))
			  .duration(0);

		_svg053_c.transition()
				.attr("cy", canvas053[10].y)
				.duration(0);

		document.getElementById('MMA8452Q_rms').innerHTML = get_graph_data(5).concat(" g");

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
		canvas10[10].y = 58 - (parseFloat(get_graph_data(6))+40)*0.448;
	
		_svg10.transition()
			  .attr("d", lineFunction(canvas10))
			  .duration(0);

		_svg10_c.transition()
				.attr("cy", canvas10[10].y)
				.duration(0);

		document.getElementById('DS18B20').innerHTML = get_graph_data(6).concat(" &degC");

		//GA1A1SP20WP
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
		canvas11[10].y = 58 - (parseFloat(get_graph_data(25)))*0.057;
	
		_svg11.transition()
			  .attr("d", lineFunction(canvas11))
			  .duration(0);

		_svg11_c.transition()
				.attr("cy", canvas11[10].y)
				.duration(0);

		document.getElementById('GA1A1S201WP').innerHTML = get_graph_data(25).concat(" raw A/D");

		//PDVP8104
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
		canvas12[10].y = 58 - (parseFloat(get_graph_data(13)))*0.057;
	
		_svg12.transition()
			  .attr("d", lineFunction(canvas12))
			  .duration(0);

		_svg12_c.transition()
				.attr("cy", canvas12[10].y)
				.duration(0);

		document.getElementById('PDVP8104').innerHTML = get_graph_data(13).concat(" raw A/D");

		//MAX4466
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
		canvas13[10].y = 58 - (parseFloat(get_graph_data(23)))*0.057;

		_svg13.transition()
			  .attr("d", lineFunction(canvas13))
			  .duration(0);

		_svg13_c.transition()
				.attr("cy", canvas13[10].y)
				.duration(0);

		document.getElementById('MAX4466').innerHTML = get_graph_data(23).concat(" raw A/D");

		//MLX90614ESF
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
		canvas14[10].y = 58 - (parseFloat(get_graph_data(7))+40)*0.448;
	
		_svg14.transition()
			  .attr("d", lineFunction(canvas14))
			  .duration(0);

		_svg14_c.transition()
				.attr("cy", canvas14[10].y)
				.duration(0);

		document.getElementById('MLX90614ESF').innerHTML = get_graph_data(7).concat(" &degC");

		//PR103J2
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
		canvas15[10].y = 58 - (parseFloat(get_graph_data(29)))*0.057;
	
		_svg15.transition()
			  .attr("d", lineFunction(canvas15))
			  .duration(0);

		_svg15_c.transition()
				.attr("cy", canvas15[10].y)
				.duration(0);

		document.getElementById('PR103J2').innerHTML = get_graph_data(29).concat(" raw A/D");

		//TMP102
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
		canvas16[10].y = 58 - (parseFloat(get_graph_data(8))+40)*0.448;
	
		_svg16.transition()
			  .attr("d", lineFunction(canvas16))
			  .duration(0);

		_svg16_c.transition()
				.attr("cy", canvas16[10].y)
				.duration(0);

		document.getElementById('TMP102').innerHTML = get_graph_data(8).concat(" &degC");

		//TMP421
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
		canvas17[10].y = 58 - (parseFloat(get_graph_data(24))+40)*0.448;
	
		_svg17.transition()
			  .attr("d", lineFunction(canvas17))
			  .duration(0);

		_svg17_c.transition()
				.attr("cy", canvas17[10].y)
				.duration(0);

		document.getElementById('TMP421').innerHTML = get_graph_data(24).concat(" &degC");

		//HIH4030
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
		canvas18[10].y = 58 - (parseFloat(get_graph_data(28)))*0.057;
	
		_svg18.transition()
			  .attr("d", lineFunction(canvas18))
			  .duration(0);

		_svg18_c.transition()
				.attr("cy", canvas18[10].y)
				.duration(0);

		document.getElementById('HIH4030').innerHTML = get_graph_data(28).concat(" raw A/D");
	
		//HIH6130
		canvas190[0].y = canvas190[1].y;
		canvas190[1].y = canvas190[2].y;
		canvas190[2].y = canvas190[3].y;
		canvas190[3].y = canvas190[4].y;
		canvas190[4].y = canvas190[5].y;
		canvas190[5].y = canvas190[6].y;
		canvas190[6].y = canvas190[7].y;
		canvas190[7].y = canvas190[8].y;
		canvas190[8].y = canvas190[9].y;
		canvas190[9].y = canvas190[10].y;
		canvas190[10].y = 58 - (parseFloat(get_graph_data(9))+40)*0.448;
	
		_svg190.transition()
			  .attr("d", lineFunction(canvas190))
			  .duration(0);

		_svg190_c.transition()
				.attr("cy", canvas190[10].y)
				.duration(0);

		document.getElementById('HIH6130_temp').innerHTML = get_graph_data(9).concat(" &degC");
	
		canvas191[0].y = canvas191[1].y;
		canvas191[1].y = canvas191[2].y;
		canvas191[2].y = canvas191[3].y;
		canvas191[3].y = canvas191[4].y;
		canvas191[4].y = canvas191[5].y;
		canvas191[5].y = canvas191[6].y;
		canvas191[6].y = canvas191[7].y;
		canvas191[7].y = canvas191[8].y;
		canvas191[8].y = canvas191[9].y;
		canvas191[9].y = canvas191[10].y;
		canvas191[10].y = 58 - (parseFloat(get_graph_data(10)))*0.58;
	
		_svg191.transition()
			  .attr("d", lineFunction(canvas191))
			  .duration(0);

		_svg191_c.transition()
				.attr("cy", canvas191[10].y)
				.duration(0);

		document.getElementById('HIH6130_hum').innerHTML = get_graph_data(10).concat(" %RH");

		//HTU21D
		canvas1100[0].y = canvas1100[1].y;
		canvas1100[1].y = canvas1100[2].y;
		canvas1100[2].y = canvas1100[3].y;
		canvas1100[3].y = canvas1100[4].y;
		canvas1100[4].y = canvas1100[5].y;
		canvas1100[5].y = canvas1100[6].y;
		canvas1100[6].y = canvas1100[7].y;
		canvas1100[7].y = canvas1100[8].y;
		canvas1100[8].y = canvas1100[9].y;
		canvas1100[9].y = canvas1100[10].y;
		canvas1100[10].y = 58 - (parseFloat(get_graph_data(19))+40)*0.448;
	
		_svg1100.transition()
			  .attr("d", lineFunction(canvas1100))
			  .duration(0);

		_svg1100_c.transition()
				.attr("cy", canvas1100[10].y)
				.duration(0);

		document.getElementById('HTU21D_temp').innerHTML = get_graph_data(19).concat(" &degC");
	
		canvas1101[0].y = canvas1101[1].y;
		canvas1101[1].y = canvas1101[2].y;
		canvas1101[2].y = canvas1101[3].y;
		canvas1101[3].y = canvas1101[4].y;
		canvas1101[4].y = canvas1101[5].y;
		canvas1101[5].y = canvas1101[6].y;
		canvas1101[6].y = canvas1101[7].y;
		canvas1101[7].y = canvas1101[8].y;
		canvas1101[8].y = canvas1101[9].y;
		canvas1101[9].y = canvas1101[10].y;
		canvas1101[10].y = 58 - (parseFloat(get_graph_data(20)))*0.58;
	
		_svg1101.transition()
			  .attr("d", lineFunction(canvas1101))
			  .duration(0);

		_svg1101_c.transition()
				.attr("cy", canvas1101[10].y)
				.duration(0);

		document.getElementById('HTU21D_hum').innerHTML = get_graph_data(20).concat(" %RH");
	
		//D6T44L06
		canvas1110[0].y = canvas1110[1].y;
		canvas1110[1].y = canvas1110[2].y;
		canvas1110[2].y = canvas1110[3].y;
		canvas1110[3].y = canvas1110[4].y;
		canvas1110[4].y = canvas1110[5].y;
		canvas1110[5].y = canvas1110[6].y;
		canvas1110[6].y = canvas1110[7].y;
		canvas1110[7].y = canvas1110[8].y;
		canvas1110[8].y = canvas1110[9].y;
		canvas1110[9].y = canvas1110[10].y;
		canvas1110[10].y = 58 - (parseFloat(get_graph_data(1))+40)*0.448;
	
		_svg1110.transition()
			  .attr("d", lineFunction(canvas1110))
			  .duration(0);

		_svg1110_c.transition()
				.attr("cy", canvas1110[10].y)
				.duration(0);

		document.getElementById('D6T44L06_avg_temp').innerHTML = get_graph_data(1).concat(" &degC");
		//sensor060.addData([get_graph_data(1)], "");
	
		canvas1111[0].y = canvas1111[1].y;
		canvas1111[1].y = canvas1111[2].y;
		canvas1111[2].y = canvas1111[3].y;
		canvas1111[3].y = canvas1111[4].y;
		canvas1111[4].y = canvas1111[5].y;
		canvas1111[5].y = canvas1111[6].y;
		canvas1111[6].y = canvas1111[7].y;
		canvas1111[7].y = canvas1111[8].y;
		canvas1111[8].y = canvas1111[9].y;
		canvas1111[9].y = canvas1111[10].y;
		canvas1111[10].y = 58 - (parseFloat(get_graph_data(0))+40)*0.448;
	
		_svg1111.transition()
			  .attr("d", lineFunction(canvas1111))
			  .duration(0);

		_svg1111_c.transition()
				.attr("cy", canvas1111[10].y)
				.duration(0);

		document.getElementById('D6T44L06_case_temp').innerHTML = get_graph_data(0).concat(" &degC");
	}
}