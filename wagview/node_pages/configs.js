/*
 * Configs.js sets all user defined variables for displays and updates
 */

/***Sensor display data***/
//Height of graph in pixels
var GRAPH_HEIGHT = 56;

//Lower bounds for sensors
var TEMP_C_LOWER = -40;
var TEMP_F_LOWER = -40;
var RH_LOWER = 0;
var PRESSURE_LOWER = 80000;
var MAG_UT_LOWER = -100;
var ACC_G_LOWER = -10;
var RAW_LOWER = 0;

//Upper bounds for sensors
var TEMP_C_UPPER = 100;
var TEMP_F_UPPER = 180;
var RH_UPPER = 100;
var PRESSURE_UPPER = 120000;
var MAG_UT_UPPER = 100;
var ACC_G_UPPER = 10;
var RAW_UPPER = 1023;

//Height scales (px/unit)
//Computed for user...DO NOT CHANGE!
var TEMP_C_SCALE = GRAPH_HEIGHT/(TEMP_C_UPPER - TEMP_C_LOWER);
var TEMP_F_SCALE = GRAPH_HEIGHT/(TEMP_F_UPPER - TEMP_F_LOWER);
var RH_SCALE = GRAPH_HEIGHT/(RH_UPPER - RH_LOWER);
var PRESSURE_SCALE = GRAPH_HEIGHT/(PRESSURE_UPPER - PRESSURE_LOWER);
var MAG_UT_SCALE = GRAPH_HEIGHT/(MAG_UT_UPPER - MAG_UT_LOWER);
var ACC_G_SCALE = GRAPH_HEIGHT/(ACC_G_UPPER - ACC_G_LOWER);
var RAW_SCALE = GRAPH_HEIGHT/(RAW_UPPER - RAW_LOWER);

//Buffer size of graphs
var BUFFER = 11;

//Update interval
var UPDATE_INTERVAL = 3000;

/***Setter functions***/
function set_graph_height(val) {
	var ret = true;
	(val > 0) ? (GRAPH_HEIGHT = val) : (ret = false);
	return ret;
}

function set_temp_c(lower, upper) {
	TEMP_C_LOWER = lower;
	TEMP_C_UPPER = upper;
}

function set_temp_f(lower, upper) {
	TEMP_F_LOWER = lower;
	TEMP_F_UPPER = upper;
}

function set_rh(lower, upper) {
	var ret = true;
	(lower >= 0 && lower <= 100) ? (RH_LOWER = lower) : (ret = false);
	(upper >= 0 && upper <= 100) ? (RH_UPPER = upper) : (ret = false);
	return ret;
}

function set_pressure(lower, upper) {
	var ret = true;
	(lower > 0) ? (PRESSURE_LOWER = lower) : (ret = false);
	(upper > 0) ? (PRESSURE_UPPER = upper) : (ret = false);
	return ret;
}

function set_pressure_upper(val) {
	var ret = true;
	(val > 0) ? (PRESSURE_UPPER = val) : (ret = false);
	return ret;
}

function set_mag_ut(lower, upper) {
	MAG_UT_LOWER = lower;
	MAG_UT_UPPER = upper;
}

function set_acc_g(lower, upper) {
	ACC_G_LOWER = lower;
	ACC_G_UPPER = upper;
}

function set_raw(lower, upper) {
	var ret = true;
	(lower > 0 && lower < 1023) ? (RAW_LOWER = lower) : (ret = false);
	(upper > 0 && upper < 1023) ? (RAW_UPPER = upper) : (ret = false);
	return ret;
}

function set_buffer(val) {
	var ret = true;
	(val > 0) ? (BUFFER = val) : (ret = false);
	return ret;
}

function set_update_interval(val) {
	var ret = true;
	(val > 0) ? (UPDATE_INTERVAL = val) : (ret = false);
	return ret;
}
