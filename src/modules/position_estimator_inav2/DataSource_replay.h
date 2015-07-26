#include "IDataSource.h"
#include <sys/time.h>

class LogTool;
class DataSource_replay : public IDataSource{
public:
	DataSource_replay(const char *log_file_name, bool need_log = false);
	~DataSource_replay();

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
	void getNextRecord(const char *type_name, const char * topic_name,  char *data_str);
	int getPullData(const char * topic_name, pollevent_t *revents);

private:
	int _src_file;
	LogTool *_log_tool;
};
