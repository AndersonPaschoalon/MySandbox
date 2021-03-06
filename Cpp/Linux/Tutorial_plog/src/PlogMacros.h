/*
 * PlogMacros.h
 *
 *  Created on: 24 de jul de 2017
 *      Author: anderson
 */

#ifndef PLOGMACROS_H_
#define PLOGMACROS_H_

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>

#define PLOG_INIT(logLevel)\
		char* _plog_logfile_env = std::getenv("SIMITAR_LOGFILE");\
		char _fileName[500];\
		if(_plog_logfile_env)\
		{ \
			strcpy(_fileName, _plog_logfile_env);\
			static plog::RollingFileAppender<plog::CsvFormatter> fileAppender(_fileName,\
					800000, 2);\
			static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;\
			plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); \
		}\
		else\
		{\
			static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;\
			plog::init(plog::debug, &consoleAppender);\
			LOG_ERROR  << "[" << __FILE__ << "] " << "Can't find env variable SIMITAR_LOGFILE";\
		}

#define PLOG_NONE LOG_NONE  << "[" << __FILE__ << "] "
#define PLOG_FATAL LOG_FATAL  << "[" << __FILE__ << "] "
#define PLOG_ERROR LOG_ERROR  << "[" << __FILE__ << "] "
#define PLOG_WARN LOG_WARNING  << "[" << __FILE__ << "] "
#define PLOG_INFO LOG_INFO  << "[" << __FILE__ << "] "
#define PLOG_DEBUG LOG_DEBUG  << "[" << __FILE__ << "] "
#define PLOG_VERBOSE LOG_VERBOSE  << "[" << __FILE__ << "] "

#endif /* PLOGMACROS_H_ */
