//Global linked list
var list = new linked_list();

//Set the timer to update page every 2 seconds
function timer() {
	setInterval(read_file, 4000);
}

//Look for new file data, parse, and update page

/*
 * JSON file format:
 *
 * [
 * {"name": "__", "lat":"__", "lng":"__", "active":"__", "page":"__"},
 * {"name": "__", "lat":"__", "lng":"__", "active":"__", "page":"__"},
 * ...
 * ]
 *
 */

//Read the file from the server
function read_file() {
	var data = new XMLHttpRequest();

	data.overrideMimeType("application/json");

	//Change this to the appropriate server address
	data.open("GET", "http://outworld.mcs.anl.gov/internal/dashboard/node.json", true);
	data.onreadystatechange = function() {
		if(data.readyState == 4 && data.status == "200") {
			var json = JSON.parse(data.responseText);
			update(json);
		}
	};
	data.send(null);
}

function update(data) {
	var exists = 0;
	var idx = 0;
	var array = [];
	var table = document.getElementById("node_table");
	var row;
	var cell_0;
	var cell_1;
	var cell_2;
	var cell_3;
	var cell_loc = [];
	//var page = "";

	//Update the list according to the data array
	array = list.list_update(data);

	for(var j = 0; j < array.length; j++) {
		console.log("idx: "+array[j][0]+" type: "+array[j][1]+" name: "+array[j][2]);
	}
		
	//Update the table
	//Table format: [[idx, type, name], [idx, type, name], ...]
	for(var i = 0; i < array.length; i++) {
		idx = list.at(array[i][2]);

		console.log("idx: "+idx+" rows[idx]: "+table.rows[idx]);

		if(array[i][1] == 0) {
			//The node was updated
			table.rows[array[i][0]].cells[0].innerHTML = array[i][2];
			cell_loc = list.get_lat_lng(idx);
			table.rows[array[i][0]].cells[1].innerHTML = cell_loc[0].concat(", ", cell_loc[1]);
			table.rows[array[i][0]].cells[2].innerHTML = list.get_status(idx);
			//page = list.get_page(array[i][0]);
			//table.rows[array[i][0]].cells[3].innerHTML = '<button type="button" class="btn btn-default" id="page" onclick="location.href = "node.txt";">View Data</button>';
			table.rows[array[i][0]].cells[3].innerHTML = '<a class="btn btn-default" href="'.concat(list.get_page(idx), '" role=button">View Data</a>');
			console.log("Added row to table");
		}
		else if(array[i][1] == 1) {
			//A node was added
			row = table.insertRow(array[i][0]);
			row.id = 'node_row';
			cell_0 = row.insertCell(0);
			cell_1 = row.insertCell(1);
			cell_2 = row.insertCell(2);
			cell_3 = row.insertCell(3);
			cell_loc = list.get_lat_lng(idx);
			cell_0.innerHTML = array[i][2];
			cell_1.innerHTML = cell_loc[0].concat(", ", cell_loc[1]);
			cell_2.innerHTML = list.get_status(idx);
			//cell_3.innerHTML = '<button type="button" class="btn btn-default" id="page" onclick=\"location.href = \"node.txt\";>View Data</button>';
			cell_3.innerHTML = '<a class="btn btn-default" href="'.concat(list.get_page(idx), '" role=button">View Data</a>');
			console.log("Added row to table");
		}
		else if(array[i][1] == 2) {
			//A node was deleted
			table.deleteRow(array[i][0]);
		}
	}
}
