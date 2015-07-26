#ifndef _IDATA_SOURCE_H_
#define _IDATA_SOURCE_H_

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
#include <drivers/drv_hrt.h>

class IDataSource{
public:
	virtual ~IDataSource(){};
public:
	virtual hrt_abstime getAbsoluteTime() = 0;
	virtual void getParameter(bool * is_updated, struct parameter_update_s * data) = 0;
	virtual void getSensorCombined(bool * is_updated, struct sensor_combined_s * data) = 0;
	virtual void getActuatorControls(bool * is_updated, struct actuator_controls_s * data) = 0;
	virtual void getActuatorArmed(bool * is_updated, struct actuator_armed_s * data) = 0;
	virtual void getVehicleAttitude(bool * is_updated, struct vehicle_attitude_s * data) = 0;
	virtual void getOpticalFlow(bool * is_updated, struct optical_flow_s * data) = 0;
	virtual void getVehicleGpsPosition(bool * is_updated, struct vehicle_gps_position_s * data) = 0;
	virtual void getVisionPositionEstimate(bool * is_updated, struct vision_position_estimate_s * data) = 0;
	virtual void getAttPosMocap(bool * is_updated, struct att_pos_mocap_s * data) = 0;
	virtual void getHomePosition(bool * is_updated, struct home_position_s * data) = 0;

	virtual int getSensorCombinedPull(pollevent_t *revents) = 0;
	virtual int getVehicleAttitudePull(pollevent_t *revents) = 0;

	virtual void pubVehicleGlobalPosition(struct vehicle_global_position_s *global_pos) = 0;
	virtual void pubVehicleLocalPosition(struct vehicle_local_position_s *local_pos) = 0;
};

#endif //_IDATA_SOURCE_H_
