#ifndef _DATA_SERIALIZER_H_
#define _DATA_SERIALIZER_H_

#include <px4_config.h>
#include <poll.h>
#include <uORB/uORB.h>
#include <uORB/uORBCommon.hpp>
#include <uORB/topics/parameter_update.h>
#include <uORB/topics/actuator_controls.h>
#include <uORB/topics/actuator_controls_0.h>
#include <uORB/topics/actuator_controls_1.h>
#include <uORB/topics/actuator_controls_2.h>
#include <uORB/topics/actuator_controls_3.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_global_position.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vision_position_estimate.h>
#include <uORB/topics/att_pos_mocap.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/optical_flow.h>

class DataSerializer{
public:
	static void serializeParameter(struct parameter_update_s * data, char * data_str);
	static void serializeSensorCombined(struct sensor_combined_s * data, char * data_str);
	static void serializeActuatorControls(struct actuator_controls_s * data, char * data_str);
	static void serializeActuatorArmed(struct actuator_armed_s * data, char * data_str);
	static void serializeVehicleAttitude(struct vehicle_attitude_s * data, char * data_str);
	static void serializeOpticalFlow(struct optical_flow_s * data, char * data_str);
	static void serializeVehicleGpsPosition(struct vehicle_gps_position_s * data, char * data_str);
	static void serializeVisionPositionEstimate(struct vision_position_estimate_s * data, char * data_str);
	static void serializeAttPosMocap(struct att_pos_mocap_s * data, char * data_str);
	static void serializeHomePosition(struct home_position_s * data, char * data_str);
	static void serializeVehicleGlobalPosition(struct vehicle_global_position_s *global_pos, char * data_str);
	static void serializeVehicleLocalPosition(struct vehicle_local_position_s *local_pos, char * data_str);

	//static void serializeSensorCombinedPull(pollevent_t *revents) = 0;
	//static void serializeVehicleAttitudePull(pollevent_t *revents) = 0;

};

#endif //_DATA_SERIALIZER_H_
