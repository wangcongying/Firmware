#include "DataSerializer.h"


void DataSerializer::serializeParameter(struct parameter_update_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);
}

void DataSerializer::serializeSensorCombined(struct sensor_combined_s * data, char * data_str){
	sprintf(data_str, "%llu	", data->timestamp);
	return;
	printf("%s\n", data_str);

	// gyro
	sprintf(data_str, "%d	%d	%d	", data->gyro_raw[0], data->gyro_raw[1], data->gyro_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->gyro_rad_s[0], (double)data->gyro_rad_s[1], (double)data->gyro_rad_s[2]);
	sprintf(data_str, "%u	", data->gyro_errcount);
	sprintf(data_str, "%f	", (double)data->gyro_temp);

	sprintf(data_str, "%llu	", data->gyro1_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->gyro1_raw[0], data->gyro1_raw[1], data->gyro1_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->gyro1_rad_s[0], (double)data->gyro1_rad_s[1], (double)data->gyro1_rad_s[2]);
	sprintf(data_str, "%u	", data->gyro1_errcount);
	sprintf(data_str, "%f	", (double)data->gyro1_temp);

	sprintf(data_str, "%llu	", data->gyro2_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->gyro2_raw[0], data->gyro2_raw[1], data->gyro2_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->gyro2_rad_s[0], (double)data->gyro2_rad_s[1], (double)data->gyro2_rad_s[2]);
	sprintf(data_str, "%u	", data->gyro2_errcount);
	sprintf(data_str, "%f	", (double)data->gyro2_temp);

	printf("%s\n", data_str);
	// acc
	sprintf(data_str, "%d	", data->accelerometer_mode);
	sprintf(data_str, "%f	", (double)data->accelerometer_range_m_s2);

	sprintf(data_str, "%llu	", data->accelerometer_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->accelerometer_raw[0], data->accelerometer_raw[1], data->accelerometer_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->accelerometer_m_s2[0], (double)data->accelerometer_m_s2[1], (double)data->accelerometer_m_s2[2]);
	sprintf(data_str, "%u	", data->accelerometer_errcount);
	sprintf(data_str, "%f	", (double)data->accelerometer_temp);

	sprintf(data_str, "%llu	", data->accelerometer1_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->accelerometer1_raw[0], data->accelerometer1_raw[1], data->accelerometer1_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->accelerometer1_m_s2[0], (double)data->accelerometer1_m_s2[1], (double)data->accelerometer1_m_s2[2]);
	sprintf(data_str, "%u	", data->accelerometer1_errcount);
	sprintf(data_str, "%f	", (double)data->accelerometer1_temp);

	sprintf(data_str, "%llu	", data->accelerometer2_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->accelerometer2_raw[0], data->accelerometer2_raw[1], data->accelerometer2_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->accelerometer2_m_s2[0], (double)data->accelerometer2_m_s2[1], (double)data->accelerometer2_m_s2[2]);
	sprintf(data_str, "%u	", data->accelerometer2_errcount);
	sprintf(data_str, "%f	", (double)data->accelerometer2_temp);

	// mag
	sprintf(data_str, "%d	", data->magnetometer_mode);
	sprintf(data_str, "%f	", (double)data->magnetometer_range_ga);
	sprintf(data_str, "%f	", (double)data->magnetometer_cuttoff_freq_hz);

	sprintf(data_str, "%llu	", data->magnetometer_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->magnetometer_raw[0], data->magnetometer_raw[1], data->magnetometer_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->magnetometer_ga[0], (double)data->magnetometer_ga[1], (double)data->magnetometer_ga[2]);
	sprintf(data_str, "%u	", data->magnetometer_errcount);
	sprintf(data_str, "%f	", (double)data->magnetometer_temp);
	
	sprintf(data_str, "%llu	", data->magnetometer1_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->magnetometer1_raw[0], data->magnetometer1_raw[1], data->magnetometer1_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->magnetometer1_ga[0], (double)data->magnetometer1_ga[1], (double)data->magnetometer1_ga[2]);
	sprintf(data_str, "%u	", data->magnetometer1_errcount);
	sprintf(data_str, "%f	", (double)data->magnetometer1_temp);
	
	sprintf(data_str, "%llu	", data->magnetometer2_timestamp);
	sprintf(data_str, "%d	%d	%d	", data->magnetometer2_raw[0], data->magnetometer2_raw[1], data->magnetometer2_raw[2]);
	sprintf(data_str, "%f	%f	%f	", (double)data->magnetometer2_ga[0], (double)data->magnetometer2_ga[1], (double)data->magnetometer2_ga[2]);
	sprintf(data_str, "%u	", data->magnetometer2_errcount);
	sprintf(data_str, "%f	", (double)data->magnetometer2_temp);

	// baro
	sprintf(data_str, "%llu	", data->baro_timestamp);
	sprintf(data_str, "%f	", (double)data->baro_pres_mbar);
	sprintf(data_str, "%f	", (double)data->baro_alt_meter);
	sprintf(data_str, "%f	", (double)data->baro_temp_celcius);

	sprintf(data_str, "%llu	", data->baro1_timestamp);
	sprintf(data_str, "%f	", (double)data->baro1_pres_mbar);
	sprintf(data_str, "%f	", (double)data->baro1_alt_meter);
	sprintf(data_str, "%f	", (double)data->baro1_temp_celcius);

	// adc
	for (int i = 0; i < 10; ++i)
	{
		sprintf(data_str, "%f	", (double)data->adc_voltage_v[i]);
	}
	for (int i = 0; i < 10; ++i)
	{
		sprintf(data_str, "%u	", data->adc_mapping[i]);
	}

	// mcu
	sprintf(data_str, "%f	", (double)data->mcu_temp_celcius);

	// differential_pressure
	sprintf(data_str, "%llu	", data->differential_pressure_timestamp);
	sprintf(data_str, "%f	", (double)data->differential_pressure_pa);
	sprintf(data_str, "%f	", (double)data->differential_pressure_filtered_pa);

	sprintf(data_str, "%llu	", data->differential_pressure1_timestamp);
	sprintf(data_str, "%f	", (double)data->differential_pressure1_pa);
	sprintf(data_str, "%f	", (double)data->differential_pressure1_filtered_pa);

	printf("%s\n", data_str);
}

void DataSerializer::serializeActuatorControls(struct actuator_controls_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);

}

void DataSerializer::serializeActuatorArmed(struct actuator_armed_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);

}

void DataSerializer::serializeVehicleAttitude(struct vehicle_attitude_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);

}

void DataSerializer::serializeOpticalFlow(struct optical_flow_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);

}

void DataSerializer::serializeVehicleGpsPosition(struct vehicle_gps_position_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp_position);

}

void DataSerializer::serializeVisionPositionEstimate(struct vision_position_estimate_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp_boot);

}

void DataSerializer::serializeAttPosMocap(struct att_pos_mocap_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp_boot);

}

void DataSerializer::serializeHomePosition(struct home_position_s * data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);

}

// void DataSerializer::serializeSensorCombinedPull(pollevent_t *revents) = 0;
// void DataSerializer::serializeVehicleAttitudePull(pollevent_t *revents) = 0;

void DataSerializer::serializeVehicleGlobalPosition(struct vehicle_global_position_s *data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);
}
void DataSerializer::serializeVehicleLocalPosition(struct vehicle_local_position_s *data, char * data_str){
	sprintf(data_str, "%llu", data->timestamp);
}
