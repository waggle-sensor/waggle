//Global index for webpage to use
var customized_data;
var customized_data_idx = 0;

//Grab the json file to find the correct node object index to use
function grab_json(search_str) {
	var data = new XMLHttpRequest();
	data.open("GET", "http://outworld.mcs.anl.gov/waggle-data/nodes.json", false);
	data.onreadystatechange = function() {
		if(data.readyState == 4 && data.status == "200") {
			customized_data = JSON.parse(data.responseText);
			match_name(search_str);
		}
	};
	data.send(null)
}

//Compare the search name with all the node object names and stop when there is a match. Var i contains the correct index for the webpage to use
function match_name(search_str) {
	for(var i=0; i< customized_data.length; i++) {
		if(search_str.toLowerCase() === customized_data[customized_data_idx]["Name"].toLowerCase()) {
			//Found the match, since customized_data_idx is what we're looking for and its global, can just return
			return;
		}
		customized_data_idx++;	
	}
}

//All the getter functions
function get_name() {
	return customized_data[customized_data_idx]["Name"];
}

function get_group() {
	return customized_data[customized_data_idx]["Group"];
}

function get_organization() {
	return customized_data[customized_data_idx]["Organization"];

}

function get_coordinates(lat_lng) {
	if(lat_lng == 0) {
		return customized_data[customized_data_idx]["Coordinates"][0];
	}
	else {
		return customized_data[customized_data_idx]["Coordinates"][1];
	}

}

function get_location() {
	return customized_data[customized_data_idx]["Location"];

}

function get_position() {
	return customized_data[customized_data_idx]["Position"];

}

function get_banner() {
	return customized_data[customized_data_idx]["Banner"];

}

function get_installedDate() {
	return customized_data[customized_data_idx]["InstalledDate"];

}

function get_status() {
	return customized_data[customized_data_idx]["Status"];

}

function get_data() {
	return customized_data[customized_data_idx]["Data"];

}

function get_ipAddress() {
	return customized_data[customized_data_idx]["IPAddress"];

}
