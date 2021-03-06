//============================================================================
// Name        : Tutorial_plog.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>

#include "PlogMacros.h"

using namespace std;

int t_test_log() {
	plog::RollingFileAppender<plog::CsvFormatter> fileAppender(
			"MultiAppender.csv", 8000, 3);
	plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoleAppender;
	plog::init(plog::debug, &colorConsoleAppender).addAppender(&fileAppender);

	LOG_ERROR << "@ t_test_log " << __PRETTY_FUNCTION__;

	return 0;
}

int test_messer() {
	PLOG_INIT();

	PLOG_FATAL << "fatalllllll";

	return 0;
}

void test_plog_default() {
	PLOG_INIT(debug);

	PLOG_FATAL << "fatal";
	PLOG_ERROR << "error";
	PLOG_INFO << "info";
	PLOG_WARN << "warn";
	PLOG_VERBOSE << "verbose";
	PLOG_DEBUG << "debug";

}

void basic_test() {
	plog::RollingFileAppender<plog::CsvFormatter> fileAppender(
			"MultiAppender.csv", 8000, 3); // Create the 1st appender.
	//static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender; // Create the 2nd appender.
	plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoleAppender; // Create the 2nd appender.

	//plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); // Initialize the logger with the both appenders.
	//plog::init(plog::debug, &fileAppender).addAppender(&colorConsoleAppender);
	plog::init(plog::debug, &colorConsoleAppender).addAppender(&fileAppender);

	// A bunch of log lines that goes to the both appenders: to the file and to the console.
	int i = 0;
	for (i = 0; i < 100; ++i) {
		LOG_WARNING << "i: " << i << __PRETTY_FUNCTION__;
	}

}
int main() {

	//basic_test();
	//t_test_log();
	//test_messer();
	test_plog_default();

	return 0;
}
