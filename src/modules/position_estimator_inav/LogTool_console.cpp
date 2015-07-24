#include "LogTool.h"
#include <uORB/uORB.h>
#include <uORB/uORBCommon.hpp>


LogTool::LogTool()
{
}

LogTool::~LogTool(){
}

void LogTool::logSub(const char* topic_name, bool is_updated, int data_size, const char* data_str){
	printf("[SUB]	%s	%d	%s\n", topic_name, is_updated, data_str);
}

void LogTool::logPub(const char*  topic_name, int data_size, const char* data_str){
	printf("[PUB]	%s	%s\n", topic_name, data_str);
}

void LogTool::logPull(const char* topic_name, const pollevent_t *revents, int ret){
	printf("[PULL]	%s	%d	%d\n", topic_name, *revents, ret);
}

void LogTool::logTime(const hrt_abstime &t){
	printf("[TIME]	%llu\n", t);
}

