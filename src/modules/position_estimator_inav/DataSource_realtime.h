#include "IDataSource.h"
#include <sys/time.h>

class LogTool;
class DataSource_realtime : public IDataSource{
public:
	DataSource_realtime(bool need_log = false);
	~DataSource_realtime();

public:
	hrt_abstime getAbsoluteTime();
	void getParameter(bool * is_updated, struct parameter_update_s * data);
	void getSensorCombined(bool * is_updated, struct sensor_combined_s * data);
	void getActuatorControls(bool * is_updated, struct actuator_controls_s * data);
	void getActuatorArmed(bool * is_updated, struct actuator_armed_s * data);
	void getVehicleAttitude(bool * is_updated, struct vehicle_attitude_s * data);
	void getOpticalFlow(bool * is_updated, struct optical_flow_s * data);
	void getVehicleGpsPosition(bool * is_updated, struct vehicle_gps_position_s * data);
	void getVisionPositionEstimate(bool * is_updated, struct vision_position_estimate_s * data);
	void getAttPosMocap(bool * is_updated, struct att_pos_mocap_s * data);
	void getHomePosition(bool * is_updated, struct home_position_s * data);

	int getSensorCombinedPull(pollevent_t *revents);
	int getVehicleAttitudePull(pollevent_t *revents);
	
	void pubVehicleGlobalPosition(struct vehicle_global_position_s *global_pos);
	void pubVehicleLocalPosition(struct vehicle_local_position_s *local_pos);

private:
	int getPullData(const char * topic_name, px4_pollfd_struct_t *fds, int max_time, pollevent_t *revents);

private:
	int _parameter_update_sub;
	int _actuator_sub;
	int _armed_sub;
	int _sensor_combined_sub;
	int _vehicle_attitude_sub;
	int _optical_flow_sub;
	int _vehicle_gps_position_sub;
	int _vision_position_estimate_sub;
	int _att_pos_mocap_sub;
	int _home_position_sub;

	px4_pollfd_struct_t _sensor_combined_fds;
	px4_pollfd_struct_t _vehicle_attitude_fds;

	orb_advert_t _vehicle_global_position_pub;
	orb_advert_t _vehicle_local_position_pub;

	LogTool *_log_tool;
};