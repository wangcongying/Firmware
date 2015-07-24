#ifndef __POSITION_ESTIMATOR_INAV_H__
#define __POSITION_ESTIMATOR_INAV_H__

#include <poll.h>
#include <uORB/uORB.h>
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

#ifdef __cplusplus
#include "IDataSource.h"
IDataSource * new_data_source(bool need_log);
#endif

#ifdef __cplusplus
extern "C"
#endif
void initIO(bool need_log);

#ifdef __cplusplus
extern "C"
#endif
void closeIO(void);

#ifdef __cplusplus
extern "C"
#endif
void get_vehicle_gps_position(bool *updated, struct vehicle_gps_position_s *data);

#ifdef __cplusplus
extern "C"
#endif
void get_vehicle_attitude(bool *updated, struct vehicle_attitude_s * data);

#ifdef __cplusplus
extern "C"
#endif
hrt_abstime get_absolute_time(void);

#ifdef __cplusplus
extern "C"
#endif
void get_parameter(bool *updated, struct parameter_update_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_sensor_combined(bool *updated, struct sensor_combined_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_actuator_controls(bool *updated, struct actuator_controls_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_actuator_armed(bool *updated, struct actuator_armed_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_optical_flow(bool *updated, struct optical_flow_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_home_position(bool *updated, struct home_position_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_vision_position_estimate(bool *updated, struct vision_position_estimate_s * data);

#ifdef __cplusplus
extern "C"
#endif
void get_att_pos_mocap(bool *updated, struct att_pos_mocap_s * data);

#ifdef __cplusplus
extern "C"
#endif
int get_sensor_combined_pull(pollevent_t *revents);

#ifdef __cplusplus
extern "C"
#endif
int get_vehicle_attitude_pull(pollevent_t *revents);

#ifdef __cplusplus
extern "C"
#endif
void pub_vehicle_local_position(struct vehicle_local_position_s * local_pos);

#ifdef __cplusplus
extern "C"
#endif
void pub_vehicle_global_position(struct vehicle_global_position_s *global_pos);

#endif