#include "LogTool.h"
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h> 


LogTool::LogTool()
{
	time_t curr_timestamp;
	time(&curr_timestamp);
	char *file_path_name = new char [255];
	sprintf(file_path_name,"/fs/microsd/log/playback/%d.sdlog", curr_timestamp);
	_log_file = open(file_path_name, O_CREAT | O_WRONLY | O_DSYNC, 0x0777);
	delete file_path_name;
}

LogTool::~LogTool(){
	if(_log_file){
		close(_log_file);
		_log_file = 0;
		printf("close file\n");
	}
}

void LogTool::logSub(const char* topic_name, bool is_updated, const char* data_str){
	dprintf(_log_file, "[SUB]	%s	%d	%s\n", topic_name, is_updated, data_str);
	fsync(_log_file);
}

void LogTool::logPub(const char*  topic_name, const char* data_str){
	dprintf(_log_file, "[PUB]	%s	%s\n", topic_name, data_str);
	fsync(_log_file);
}

void LogTool::logPull(const char* topic_name, const pollevent_t *revents, int ret){
	dprintf(_log_file, "[PULL]	%s	%d	%d\n", topic_name, *revents, ret);
	fsync(_log_file);
}

void LogTool::logTime(const hrt_abstime &t){
	dprintf(_log_file, "[TIME]	%llu\n", t);
	fsync(_log_file);
}