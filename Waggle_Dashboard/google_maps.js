function google_maps(lat, lng)
{
	google.maps.event.addDomListener(window, 'load', function(){init(lat, lng)});
}

function init(lat, lng)
{
	var map_options = {
		center: new google.maps.LatLng(lat, lng),
		zoom: 13,
		mapTypeId: google.maps.MapTypeId.ROADMAP
	};

	var map = new google.maps.Map(document.getElementById("node_table"), map_options);
}

function initializeGoogleMaps()
{
	$(document).foundation();
	var latlng = new google.maps.LatLng(41.714266, -87.982485);
	//var latlng_2 = new google.maps.LatLng(41.714266, -87.982485);

	/* ^^^ Add more locations above ^^^ */

	var map_options = {
		center: latlng,
		zoom: 14,
		mapTypeId: google.maps.MapTypeId.ROADMAP
	};

	/*var map_options_2 = {
		center: latlng_2,
		zoom: 14,
		mapTypeId: google.maps.MapTypeId.ROADMAP
	};*/

	/* ^^^ Add more options above ^^^ */

	var map = new google.maps.Map(document.getElementById("map-canvas"), map_options);
	//var map_2 = new google.maps.Map(document.getElementById("map_canvas_3"), map_options_2);

	/* ^^^ Add more maps above ^^^ */

	var my_marker = new google.maps.Marker({
		position: latlng,
		map: map,
		title: "Argonne National Lab"
	});

	/*var my_marker_2 = new google.maps.Marker({
		position: latlng_2,
		map: map_2,
		title: "ANL"
	});*/

	/* ^^^ Add more markers above ^^^ */
}