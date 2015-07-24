#include "DataSource_realtime.h"
#include "LogTool.h"
#include "DataSerializer.h"

#define getData(topic_name, sub, orb_id, is_updated, data, log_tool, parse_func)\
	orb_check(sub, is_updated);\
	orb_copy(orb_id, sub, data);\
	if(log_tool){\
		assert(data);\
		char * datastr = new char [1000];\
		parse_func(data, datastr);\
		log_tool->logSub(topic_name, is_updated, datastr);\
		delete datastr;\
	}

#define pubData(topic_name, pub, orb_id, data, log_tool, parse_func)\
	if (pub == NULL) {\
		pub = orb_advertise(orb_id, data);\
	} else {\
		orb_publish(orb_id, pub, data);\
	}\
	if(log_tool){\
		assert(data);\
		char * datastr = new char [1000];\
		parse_func(data, datastr);\
		log_tool->logPub(topic_name, datastr);\
		delete datastr;\
	}

DataSource_realtime::DataSource_realtime(bool need_log)
	//: _parameter_update_sub(0)
{
	printf("DataSource_realtime construct\n");
	_log_tool = need_log ? new LogTool() : nullptr;

	// subscribe
	_parameter_update_sub = orb_subscribe(ORB_ID(parameter_update));
	_actuator_sub = orb_subscribe(ORB_ID_VEHICLE_ATTITUDE_CONTROLS);
	_armed_sub = orb_subscribe(ORB_ID(actuator_armed));
	_sensor_combined_sub = orb_subscribe(ORB_ID(sensor_combined));
	_vehicle_attitude_sub = orb_subscribe(ORB_ID(vehicle_attitude));
	_optical_flow_sub = orb_subscribe(ORB_ID(optical_flow));
	_vehicle_gps_position_sub = orb_subscribe(ORB_ID(vehicle_gps_position));
	_vision_position_estimate_sub = orb_subscribe(ORB_ID(vision_position_estimate));
	_att_pos_mocap_sub = orb_subscribe(ORB_ID(att_pos_mocap));
	_home_position_sub = orb_subscribe(ORB_ID(home_position));

	_sensor_combined_fds.fd = _sensor_combined_sub;
	_sensor_combined_fds.events = POLLIN;

	_vehicle_attitude_fds.fd = _vehicle_attitude_sub;
	_vehicle_attitude_fds.events = POLLIN;

	// advertise
	_vehicle_local_position_pub = _vehicle_global_position_pub = NULL;
}

DataSource_realtime::~DataSource_realtime(){
	if(_log_tool){
		delete _log_tool;
	}
	printf("DataSource_realtime destructor\n");
}

int DataSource_realtime::getSensorCombinedPull(pollevent_t *revents){
	return getPullData("SensorCombined", &_sensor_combined_fds, 1000, revents);
}

int DataSource_realtime::getVehicleAttitudePull(pollevent_t *revents){
	return getPullData("VehicleAttitude", &_vehicle_attitude_fds, 20, revents);
}

int DataSource_realtime::getPullData(const char * topic_name, px4_pollfd_struct_t *fds, int max_time, pollevent_t *revents){
	int ret = px4_poll(fds, 1, max_time);
	*revents = fds->revents;
	if(_log_tool){
		_log_tool->logPull(topic_name, revents, ret);
	}
	return ret;
}

hrt_abstime DataSource_realtime::getAbsoluteTime(){
	hrt_abstime t = hrt_absolute_time();
	if(_log_tool){
		_log_tool->logTime(t);
	}
	return t;
}

void DataSource_realtime::getParameter(bool *is_updated, struct parameter_update_s * data){
	getData("Parameter", _parameter_update_sub, ORB_ID(parameter_update), is_updated, data, _log_tool, DataSerializer::serializeParameter);
}

void DataSource_realtime::getSensorCombined(bool *is_updated, struct sensor_combined_s * data){
	getData("SensorCombined", _sensor_combined_sub, ORB_ID(sensor_combined), is_updated, data, _log_tool, DataSerializer::serializeSensorCombined);
}

void DataSource_realtime::getVehicleAttitude(bool *is_updated, struct vehicle_attitude_s * data){
	getData("VehicleAttitude", _vehicle_attitude_sub, ORB_ID(vehicle_attitude), is_updated, data, _log_tool, DataSerializer::serializeVehicleAttitude);
}

void DataSource_realtime::getActuatorControls(bool *is_updated, struct actuator_controls_s * data){
	getData("ActuatorControls", _actuator_sub, ORB_ID_VEHICLE_ATTITUDE_CONTROLS, is_updated, data, _log_tool, DataSerializer::serializeActuatorControls);
}

void DataSource_realtime::getActuatorArmed(bool *is_updated, struct actuator_armed_s * data){
	getData("ActuatorArmed", _armed_sub, ORB_ID(actuator_armed), is_updated, data, _log_tool, DataSerializer::serializeActuatorArmed);
}

void DataSource_realtime::getOpticalFlow(bool *is_updated, struct optical_flow_s * data){
	getData("OpticalFlow", _optical_flow_sub, ORB_ID(optical_flow), is_updated, data, _log_tool, DataSerializer::serializeOpticalFlow);
}

void DataSource_realtime::getHomePosition(bool *is_updated, struct home_position_s * data){
	getData("HomePosition", _home_position_sub, ORB_ID(home_position), is_updated, data, _log_tool, DataSerializer::serializeHomePosition);
}

void DataSource_realtime::getVisionPositionEstimate(bool *is_updated, struct vision_position_estimate_s * data){
	getData("VisionPositionEstimate", _vision_position_estimate_sub, ORB_ID(vision_position_estimate), is_updated, data, _log_tool, DataSerializer::serializeVisionPositionEstimate);
}

void DataSource_realtime::getAttPosMocap(bool *is_updated, struct att_pos_mocap_s * data){
	getData("AttPosMocap", _att_pos_mocap_sub, ORB_ID(att_pos_mocap), is_updated, data, _log_tool, DataSerializer::serializeAttPosMocap);
}

void DataSource_realtime::getVehicleGpsPosition(bool *is_updated, struct vehicle_gps_position_s * data){
	getData("VehicleGpsPosition", _vehicle_gps_position_sub, ORB_ID(vehicle_gps_position), is_updated, data, _log_tool, DataSerializer::serializeVehicleGpsPosition);
}

void DataSource_realtime::pubVehicleGlobalPosition(struct vehicle_global_position_s *global_pos){
	pubData("VehicleGlobalPosition", _vehicle_global_position_pub, ORB_ID(vehicle_global_position), global_pos, _log_tool, DataSerializer::serializeVehicleGlobalPosition);
}

void DataSource_realtime::pubVehicleLocalPosition(struct vehicle_local_position_s *local_pos){
	pubData("VehicleLocalPosition", _vehicle_local_position_pub, ORB_ID(vehicle_local_position), local_pos, _log_tool, DataSerializer::serializeVehicleLocalPosition);
}