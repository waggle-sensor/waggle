/*
 * data.js maintains a queue for each set of sensor data and updates the graph each time interval
 */
var DATA_SOURCE = "http://outworld.mcs.anl.gov/waggle-data/ucaot01/data/current.json";
var init = true;
var TIME_TO_WAIT = 3000;

//Load the customized data to the webpage
//The variable "customized_data_idx" was declared globally in page_id.js and is used to access the correct element in the json data
function load_customized_data(search_str) {
	grab_json(search_str);
	document.getElementById("org_loc_pos_data").innerHTML = get_organization().concat(" | "+get_location()+((get_position() != "")?(", "+get_position()):(""))+" | "+"<a class=\"styleWeblinks\" href=\""+get_data()+"\">Data Archive</a>");
	document.getElementById("coordinates").innerHTML = "Lat: ".concat(get_coordinates(0)+" &nbsp Lon: "+get_coordinates(1));
	document.getElementById("installed").innerHTML = "Installed ".concat(get_installedDate());
	document.getElementById("banner").innerHTML = "<img id=\"photo\" src=\"".concat(get_banner()+"\" alt=\"Photo\"/>");
}
/*
//Initialize the graph array
window.onload = function() {
	var data = new XMLHttpRequest();
	data.open("GET", DATA_SOURCE, true);
	data.onreadystatechange = function() {
		if(data.readyState == 4 && data.status == "200") {
			var json = JSON.parse(data.responseText);
			parse_data(json, iteration);
			iteration++;
		}
	};
	data.send(null);
    setupGraphs();
}

//Set a timer to update the page every second
function timer() {
	//update_time();
	setInterval(update_time, 1000);
	setInterval(update, TIME_TO_WAIT);
}*/
window.onload = function() {
	//Set timer to update page every second
	update_time();
	update();
	setupGraphs();
	setInterval(update_time, 1000);
	setInterval(update, TIME_TO_WAIT);
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
 	document.getElementById("date").innerHTML = month_str.concat(" "+day.toString()+", "+year.toString()+" "+hr.toString()+":"+((min < 10) ? "0"+min.toString() : min.toString())+":"+((sec < 10) ? "0"+sec.toString() : sec.toString())+" "+am_pm);
 }

 //Update the data on the webpage
 function update() {
 	var data = new XMLHttpRequest();
 	data.open("GET", DATA_SOURCE, true);
 	data.onreadystatechange = function() {
 		if(data.readyState == 4 && data.status == "200") {
			var json = JSON.parse(data.responseText);
			parse_data(json, init);
			init = false;
 		}
 	};
 	data.send(null);
 }
