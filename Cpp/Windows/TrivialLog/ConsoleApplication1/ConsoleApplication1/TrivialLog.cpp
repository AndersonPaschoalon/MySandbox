#include "stdafx.h"
#include "TrivialLog.h"


TrivialLog::TrivialLog(const char* filename)
{
	if (filename != NULL)
	{
		strcpy_s(this->logfile, TRIVIAL_LOG_STR_LEN, filename);
	}
	else
	{
		printf("Error! filename is NULL\n");
		exit(2);
	}
}

TrivialLog::~TrivialLog()
{
}

void TrivialLog::debug(const char* format, ...)
{
	// print log
	va_list functionArgs;
	va_start(functionArgs, format);

	FILE* logFile;
	char logFormatFile[TRIVIAL_LOG_STR_LEN];
	char logFormatStdout[TRIVIAL_LOG_STR_LEN];
	time_t timer;
	char buffer[TRIVIAL_LOG_STR_LEN];
	struct tm* tm_info;

	// init
	memset(logFormatFile, '\0', TRIVIAL_LOG_STR_LEN);
	memset(logFormatStdout, '\0', TRIVIAL_LOG_STR_LEN);
	memset(buffer, '\0', TRIVIAL_LOG_STR_LEN);

	// get time
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer, TRIVIAL_LOG_STR_LEN, "[%Y-%m-%d %H:%M:%S] ", tm_info);

	// log format file
	strcat(logFormatFile, buffer);
	strcat(logFormatFile, format);
	strcat(logFormatFile, "\n\0");
	// stdout
	strcat(logFormatStdout, format);
	strcat(logFormatStdout, "\n\0");

	vfprintf(stdout, logFormatStdout, functionArgs);
	logFile = fopen(this->logfile, "a");
	if (logFile == NULL)
	{
		printf("Error! Pointer to log file is null\n");
		exit(1);
	}
	vfprintf(logFile, logFormatFile, functionArgs);
	fclose(logFile);
	va_end(functionArgs);
}

void TrivialLog::echo(const char* format, ...)
{	
	// print log
	va_list functionArgs;
	va_start(functionArgs, format);
	FILE* logFile;
	char logFormatFile[TRIVIAL_LOG_STR_LEN];
	char logFormatStdout[TRIVIAL_LOG_STR_LEN];
	time_t timer;
	char buffer[TRIVIAL_LOG_STR_LEN];
	struct tm* tm_info;

	// init
	memset(logFormatFile, '\0', TRIVIAL_LOG_STR_LEN);
	memset(logFormatStdout, '\0', TRIVIAL_LOG_STR_LEN);
	memset(buffer, '\0', TRIVIAL_LOG_STR_LEN);

	// get time
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer, TRIVIAL_LOG_STR_LEN, "[%Y-%m-%d %H:%M:%S] ", tm_info);

	// log format file
	strcat(logFormatFile, buffer);
	strcat(logFormatFile, format);
	strcat(logFormatFile, "\n\0");
	// stdout
	strcat(logFormatStdout, format);
	strcat(logFormatStdout, "\n\0");
	
	vfprintf(stdout, logFormatStdout, functionArgs);
	logFile = fopen(STATIC_LOG_FILE, "a");
	if (logFile == NULL)
	{
		printf("Error! Pointer to log file is null\n");
		exit(1);
	}
	vfprintf(logFile, logFormatFile, functionArgs);
	fclose(logFile);
	va_end(functionArgs);
}

