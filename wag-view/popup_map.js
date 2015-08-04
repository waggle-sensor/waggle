window.onload = function() {
	var ucaot01_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.791848,-87.599566&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var ucaot02_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.785573,-87.604143&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var ucaot03_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.793373,-87.602294&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var ucaot04_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.793685,-87.600131&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var ucaot05_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.790758,-87.598514&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var ucaot06_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.789009,-87.597298&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var ucaot07_settings = {
		placement: 'bottom',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.789274,-87.600936&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var wxsenetdepaul01_settings = {
		placement: 'top',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.923693,-87.656892&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var wxsenetanl01_settings = {
		placement: 'top',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.717602,-87.982415&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	var wxsenetanl02_settings = {
		placement: 'top',
		container: 'body',
		html: true,
		trigger: "hover",
		content: function() {
			return '<img src="https://maps.googleapis.com/maps/api/staticmap?center=41.701558,-87.994766&zoom=14&size=200x200&maptype=hybrid&markers=color:blue%7C41.791848,-87.599566"/>';
		}
	};

	$('a#UCAOT01').popover(ucaot01_settings);
	$('a#UCAOT02').popover(ucaot02_settings);
	$('a#UCAOT03').popover(ucaot03_settings);
	$('a#UCAOT04').popover(ucaot04_settings);
	$('a#UCAOT05').popover(ucaot05_settings);
	$('a#UCAOT06').popover(ucaot06_settings);
	$('a#UCAOT07').popover(ucaot07_settings);
	$('a#WXSENETDEPAUL01').popover(wxsenetdepaul01_settings);
	$('a#WXSENETANL01').popover(wxsenetanl01_settings);
	$('a#WXSENETANL02').popover(wxsenetanl02_settings);
}
