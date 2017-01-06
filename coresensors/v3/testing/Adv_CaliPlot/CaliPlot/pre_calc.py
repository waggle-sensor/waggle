

from RTlist import getRT

SIGN_SENSOR = "coresense:3"

class PreSets(object):

	def __init__(self):
		pass

	def read(self, args):
		self._get_data_parsing(args)

	def _HIH4030_humid(self, input):
		HIH4030_voltage = (int(input) * 5.0) / 1023.00    # extended exposure to > 90% RH causes a reversible shift of 3% RH
		HIH4030_humidity = (HIH4030_voltage - 0.85) * 100.00 / 3.00 # PUT DARK LEVEL VOLTAGE 0.85 FOR NOW
		return str(HIH4030_humidity)

	def _convert_PR(self, sensor_data):
		PR_data = getRT(int(sensor_data))
		return str(PR_data)

	def _intesity(self, sensor_name, sensor_data):
		sensor_data = self._calc_input_voltage(sensor_data)

		if sensor_name == "TSL250RD_intensity":
			sensor_data = self._TSL250_irrad(sensor_data)

		elif sensor_name == "TSL260RD_intensity":
			sensor_data = self._TSL260_irrad(sensor_data)

		elif sensor_name == "APDS-9006-020_intensity":
			sensor_data = self._APDS_irrad(sensor_data)

		elif sensor_name == "MLX75305_intensity":
			sensor_data = self._MLX_irrad(sensor_data)

		# elif sensor_name == "ML8511_intensity":
		# 	sensor_data = self._ML_UV(sensor_data)
		# sensor data of ML8511_intensity is output voltage from the sensor

		return sensor_data

	def _get_file_name(self, input):
		if "/" in input:
			op = ""

			name = input.split("/")
			for j in range(len(name) - 1):
				op = op + name[j] + "/"

			new_file = op + "_" + name[-1]
		else:
			new_file = "_" + input

		return new_file

	def _get_data_parsing(self, file_list):
		for filename in file_list:

			if "ref" in filename:
				continue

			new_file = self._get_file_name(filename)
			print(new_file)
			fobj = open(new_file, 'w+')
			
			try:
				with open(filename) as data_file:
					for line in data_file:
						if SIGN_SENSOR in line:
							step_one = line.split(";")

							sensor_name = step_one[2] + "_" + step_one[3]
							sensor_data = step_one[-2]

							if sensor_name == "HIH4030_humidity":
								sensor_data = self._HIH4030_humid(sensor_data)

							elif sensor_name == "BMP180_pressure":
								sensor_data = float(sensor_data) / 100

							elif sensor_name == "PR103J2_temperature":
								sensor_data = self._convert_PR(sensor_data)

							elif step_one[3] == "intensity" and step_one[2] != "SPV1840LR5H-B":
								sensor_data = self._intesity(sensor_name, sensor_data)

							elif step_one[3] == "adc_temperature":
								result = self._adc_temp(line)
								step_one[2] = result[0]
								sensor_data = result[1]

							elif step_one[2] == "SHT25" or step_one[2] == "LPS25H":
								sensor_data = self._chem_THP(sensor_data)

							new_line = step_one[0] + ";" + step_one[1] + ";" + step_one[2] + ";" + step_one[3] + ";" + str(sensor_data) + ";" + step_one[-1]
							fobj.write(new_line)

						else:
							pass

				data_file.close()
				fobj.close()

			except(KeyboardInterrupt, SystemExit):
				date_file.close()
				fobj.close()


	def _calc_input_voltage(self, input):
		# calc value before voltage divider, unit: V
		# MCP output code transform factor 0.065 mV/(uW/cm^2): MCP mux
		in_voltage = int(input) * 0.0000625
		# voltage divider factor 5/2 to calc input voltage: voltage divider circuit
		out_from_sensor = (in_voltage * 5.00) / 2.00
		return out_from_sensor

	def _TSL260_irrad(self, input):
		irrad = (input - 0.006250) / 0.058
		return irrad

	# def TSL250_irrad_air(self, input):
	#     irrad = input / 0.064
	#     return irrad

	def _TSL250_irrad(self, input):
		irrad = (input - 0.005781) / 0.064
		return irrad

	def _APDS_irrad(self, input):
		irrad = input / 0.001944   # 405.1 unit: mA/lux
		return irrad

	def _MLX_irrad(self, input):
		irrad = (input - 0.09234) / 0.007
		return irrad

	def _ML_UV(self, input):
		irrad = input * 1.49916 / 0.15 - (1.49916 / 0.15) - 2.3
		return irrad

	def _adc_temp(self, line):
		result = []
		step_one = line.split(";")
		step_two_s_name = step_one[2].split(" ")
		
		sensor_name = step_two_s_name[0]
		for i in range(len(step_two_s_name) - 1):
			sensor_name = sensor_name + "_" + step_two_s_name[i + 1]
		result.append(sensor_name)
		result.append(float(step_one[-2]) / 100)

		return result

	def _chem_THP(self, input):
		sensor_data = float(input) / 100
		return sensor_data