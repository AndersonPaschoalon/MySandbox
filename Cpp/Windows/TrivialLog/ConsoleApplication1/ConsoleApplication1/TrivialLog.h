#pragma once

#include <stdio.h>
#include <stdarg.h>  
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TRIVIAL_LOG_STR_LEN 9999
#define STATIC_LOG_FILE  "tlog-echo.log"


class TrivialLog
{
public:
	TrivialLog(const char* logfile);
	~TrivialLog();
	void debug(const char* format, ...);
	static void echo(const char* format, ...);
private:
	char logfile[TRIVIAL_LOG_STR_LEN];
};


