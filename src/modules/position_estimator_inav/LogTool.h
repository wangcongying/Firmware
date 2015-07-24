#ifndef __LOG_TOOL_H__
#define __LOG_TOOL_H__

#include <poll.h>
#include <drivers/drv_hrt.h>

enum LogType{
	LOGTYPE_SUB,
	LOGTYPE_PUB
};

class LogTool{
public:
	LogTool();
	~LogTool();

public:
	void logSub(const char* topic_name, bool is_updated, const char* data_str);
	void logPub(const char* topic_name, const char* data_str);
	void logPull(const char* topic_name, const pollevent_t *revents, int ret);
	void logTime(const hrt_abstime &t);

private:
	int _log_file;
};

#endif