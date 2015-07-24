/****************************************************************************
 * main
 ****************************************************************************/
#include "DataSource_realtime.h"
#include "position_estimator_inav.h"

IDataSource * new_data_source(bool need_log){
	return new DataSource_realtime(need_log);
}