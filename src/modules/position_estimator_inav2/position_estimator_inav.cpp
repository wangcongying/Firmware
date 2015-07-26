/****************************************************************************
 * main
 ****************************************************************************/
//#include "DataSource_realtime.h"
#include "position_estimator_inav.h"
#include "IDataSource.h"

static IDataSource * data_source = NULL;

void initIO(bool need_log){
	if(data_source == NULL){
		data_source = new_data_source(need_log);
	}
	printf("initIO: %d\n", data_source);
}

void closeIO(void){
	printf("closeIO: %d\n", data_source);
	if(data_source){
		delete data_source;
		data_source = NULL;
	}
	printf("closeIOed: %d\n", data_source);
}

hrt_abstime get_absolute_time(void){
	return data_source->getAbsoluteTime();
}

void get_vehicle_gps_position(bool *updated, struct vehicle_gps_position_s *data){
	data_source->getVehicleGpsPosition(updated, data);
}

void get_vehicle_attitude(bool *updated, struct vehicle_attitude_s *data){
	data_source->getVehicleAttitude(updated, data);
}

void get_parameter(bool *updated, struct parameter_update_s *data){	
	data_source->getParameter(updated, data);
}

void get_sensor_combined(bool *updated, struct sensor_combined_s *data){
	data_source->getSensorCombined(updated, data);
}

void get_actuator_controls(bool *updated, struct actuator_controls_s *data){
	data_source->getActuatorControls(updated, data);
}

void get_actuator_armed(bool *updated, struct actuator_armed_s *data){
	data_source->getActuatorArmed(updated, data);
}

void get_optical_flow(bool *updated, struct optical_flow_s *data){
	data_source->getOpticalFlow(updated, data);
}

void get_home_position(bool *updated, struct home_position_s *data){
	data_source->getHomePosition(updated, data);
}

void get_vision_position_estimate(bool *updated, struct vision_position_estimate_s *data){
	data_source->getVisionPositionEstimate(updated, data);
}

void get_att_pos_mocap(bool *updated, struct att_pos_mocap_s *data){
	data_source->getAttPosMocap(updated, data);
}


int get_sensor_combined_pull(pollevent_t *revents){
	return data_source->getSensorCombinedPull(revents);
}

int get_vehicle_attitude_pull(pollevent_t *revents){
	return data_source->getVehicleAttitudePull(revents);
}

void pub_vehicle_local_position(struct vehicle_local_position_s * local_pos){
	data_source->pubVehicleLocalPosition(local_pos);
}

void pub_vehicle_global_position(struct vehicle_global_position_s *global_pos){
	data_source->pubVehicleGlobalPosition(global_pos);
}