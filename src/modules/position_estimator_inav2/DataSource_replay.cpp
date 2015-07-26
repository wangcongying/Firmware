#include "DataSource_replay.h"
#include "LogTool.h"

DataSource_replay::DataSource_replay(bool need_log)
	//: _parameter_update_sub(0)
{
	printf("DataSource_replay construct\n");
	_log_tool = need_log ? new LogTool() : nullptr;
}

DataSource_replay::~DataSource_replay(){
	if(_log_tool){
		delete _log_tool;
	}
	printf("DataSource_replay destructor\n");
}

int DataSource_replay::getSensorCombinedPull(pollevent_t *revents){
	return getPullData("SensorCombined", &_sensor_combined_fds, 1000, revents);
}

int DataSource_replay::getVehicleAttitudePull(pollevent_t *revents){
	return getPullData("VehicleAttitude", &_vehicle_attitude_fds, 20, revents);
}

int DataSource_replay::getPullData(const char * topic_name, pollevent_t *revents){
	
	/*char line[256];
	fgets(line, sizeof(line), _src_log_file);
	stringstream sstr;
	sstr << line;

	string log_type_name, topic_name_0;
	sstr>> log_type_name >> topic_name_0;
	assert(log_type_name == "[PULL]");
	assert(topic_name_0 == topic_name);
	
	record._topic_name = topic_name;
	sstr >> record._timestamp >> record._wait_time_interval;

	sstr >> record._event.fd >> record._event.events >> record._event.revents;*/



	int ret = 1;
	*revents = 0
	return ret;
}

hrt_abstime DataSource_replay::getAbsoluteTime(){
	hrt_abstime t = 1;
	if(_log_tool){
		_log_tool->logTime(t);
	}
	return t;
}

void DataSource_replay::getParameter(bool *is_updated, struct parameter_update_s * data){
	//getData("Parameter", _parameter_update_sub, ORB_ID(parameter_update), is_updated, data, _log_tool, DataSerializer::serializeParameter);
}

void DataSource_replay::getSensorCombined(bool *is_updated, struct sensor_combined_s * data){
	//getData("SensorCombined", _sensor_combined_sub, ORB_ID(sensor_combined), is_updated, data, _log_tool, DataSerializer::serializeSensorCombined);
}

void DataSource_replay::getVehicleAttitude(bool *is_updated, struct vehicle_attitude_s * data){
	//getData("VehicleAttitude", _vehicle_attitude_sub, ORB_ID(vehicle_attitude), is_updated, data, _log_tool, DataSerializer::serializeVehicleAttitude);
}

void DataSource_replay::getActuatorControls(bool *is_updated, struct actuator_controls_s * data){
	//getData("ActuatorControls", _actuator_sub, ORB_ID_VEHICLE_ATTITUDE_CONTROLS, is_updated, data, _log_tool, DataSerializer::serializeActuatorControls);
}

void DataSource_replay::getActuatorArmed(bool *is_updated, struct actuator_armed_s * data){
	//getData("ActuatorArmed", _armed_sub, ORB_ID(actuator_armed), is_updated, data, _log_tool, DataSerializer::serializeActuatorArmed);
}

void DataSource_replay::getOpticalFlow(bool *is_updated, struct optical_flow_s * data){
	//getData("OpticalFlow", _optical_flow_sub, ORB_ID(optical_flow), is_updated, data, _log_tool, DataSerializer::serializeOpticalFlow);
}

void DataSource_replay::getHomePosition(bool *is_updated, struct home_position_s * data){
	//getData("HomePosition", _home_position_sub, ORB_ID(home_position), is_updated, data, _log_tool, DataSerializer::serializeHomePosition);
}

void DataSource_replay::getVisionPositionEstimate(bool *is_updated, struct vision_position_estimate_s * data){
	//getData("VisionPositionEstimate", _vision_position_estimate_sub, ORB_ID(vision_position_estimate), is_updated, data, _log_tool, DataSerializer::serializeVisionPositionEstimate);
}

void DataSource_replay::getAttPosMocap(bool *is_updated, struct att_pos_mocap_s * data){
	//getData("AttPosMocap", _att_pos_mocap_sub, ORB_ID(att_pos_mocap), is_updated, data, _log_tool, DataSerializer::serializeAttPosMocap);
}

void DataSource_replay::getVehicleGpsPosition(bool *is_updated, struct vehicle_gps_position_s * data){
	//getData("VehicleGpsPosition", _vehicle_gps_position_sub, ORB_ID(vehicle_gps_position), is_updated, data, _log_tool, DataSerializer::serializeVehicleGpsPosition);
}

void DataSource_replay::pubVehicleGlobalPosition(struct vehicle_global_position_s *global_pos){
	//pubData("VehicleGlobalPosition", _vehicle_global_position_pub, ORB_ID(vehicle_global_position), global_pos, _log_tool, DataSerializer::serializeVehicleGlobalPosition);
}

void DataSource_replay::pubVehicleLocalPosition(struct vehicle_local_position_s *local_pos){
	//pubData("VehicleLocalPosition", _vehicle_local_position_pub, ORB_ID(vehicle_local_position), local_pos, _log_tool, DataSerializer::serializeVehicleLocalPosition);
}

void DataSource_replay::getNextRecord(const char *type_name, const char * topic_name,  char *data_str){
}