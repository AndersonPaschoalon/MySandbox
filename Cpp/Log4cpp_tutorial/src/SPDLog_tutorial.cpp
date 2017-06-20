//============================================================================
// Name        : SPDLog_tutorial.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PropertyConfigurator.hh>

#define LOG_PROPERTIES_FILE "log4cpp-config.properties"

#define GLOBAL_LOG_LEVEL ERROR

#define MESSER_LOG_INIT(priority_console) log4cpp::PropertyConfigurator::configure(LOG_PROPERTIES_FILE); \
	log4cpp::Category& console__ = log4cpp::Category::getInstance("console"); \
	log4cpp::Category& logfile__ = log4cpp::Category::getInstance("logfile");\
	logfile__.setPriority(log4cpp::Priority::DEBUG); \
	console__.setPriority(log4cpp::Priority::priority_console);\

#define MESSER_LOG_START() MESSER_LOG_INIT(GLOBAL_LOG_LEVEL);

#define MESSER_LOG_END() log4cpp::Category::shutdown();

#define MESSER_NOTSET(fmt, args...) logfile__.notset(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_DEBUG(fmt, args...) logfile__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_INFO(fmt, args...) logfile__.info(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_NOTICE(fmt, args...) logfile__.notice(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_WARN(fmt, args...) logfile__.warn(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_ERROR(fmt, args...) logfile__.error(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_CRIT(fmt, args...) logfile__.crit(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_ALERT(fmt, args...) logfile__.alert(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_FATAL(fmt, args...) logfile__.fatal(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\

#define MESSER_EMERG(fmt, args...) logfile__.emerg(fmt, __PRETTY_FUNCTION__ ,##args);\
	console__.debug(fmt, __PRETTY_FUNCTION__ ,##args);\


//#define MESSER_WARN(...)  logfile.warn("%s Storm is coming ", __PRETTY_FUNCTION__);

/**
 enum  	PriorityLevel {
 EMERG = 0, FATAL = 0, ALERT = 100, CRIT = 200,
 ERROR = 300, WARN = 400, NOTICE = 500, INFO = 600,
 DEBUG = 700, NOTSET = 800
 }
 */

// FATAL -> the program cant run
// ALERT -> A serious bug
// CRIT -> It should not happen
// ERROR -> a predictable error, execution program is interrupted
// WARN -> an error, but it can run correctelly
// NOTICE -> crictical execution information
// INFO -> important execution information
// DEBUG -> trivial execution information
void log4cpp_webExampel() {

	//Create a console logger
	log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console",
			&std::cout);
	appender1->setLayout(new log4cpp::BasicLayout());

	log4cpp::Appender *appender2 = new log4cpp::FileAppender("default",
			"program.log");
	appender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::WARN);
	root.addAppender(appender1);

	log4cpp::Category& sub1 = log4cpp::Category::getInstance(
			std::string("sub1"));
	sub1.addAppender(appender2);

	// use of functions for logging messages
	//
	// DEBUG < INFO < NOTICE < WARN < ERROR < CRIT < ALERT < FATAL = EMERG
	root.debug("debg");
	root.error("root error");
	root.info("root info");
	sub1.error("sub1 error");
	sub1.warn("sub1 warn");

	// printf-style for logging variables
	root.warn("%d + %d == %s ?", 1, 1, "two");

	// use of streams for logging messages
	root << log4cpp::Priority::ERROR << "Streamed root error";
	root << log4cpp::Priority::INFO << "Streamed root info";
	sub1 << log4cpp::Priority::ERROR << "Streamed sub1 error";
	sub1 << log4cpp::Priority::WARN << "Streamed sub1 warn";

	// or this way:
	root.errorStream() << "Another streamed error";

}

void log4cpp_example() {
	log4cpp::PropertyConfigurator::configure(LOG_PROPERTIES_FILE);
	log4cpp::Category& logfile = log4cpp::Category::getRoot();
	log4cpp::Category& console = log4cpp::Category::getInstance("console");
	logfile.setPriority(log4cpp::Priority::ERROR);
	console.setPriority(log4cpp::Priority::INFO);

	logfile.warn("Storm is coming %s", __PRETTY_FUNCTION__);
	logfile.debug("Received storm warning");
	logfile.info("Closing all hatches");
	logfile.debug("Hiding solar panels");
	logfile.error("Solar panels are blocked");
	logfile.debug("Applying protective shield");
	logfile.warn("Unfolding protective shield");
	logfile.info("Solar panels are shielded");
	logfile.info("All hatches closed");
	logfile.info("Ready for storm.");
	console.info("console->Ready for storm.");

	log4cpp::Category::shutdown();

}

void log4cpp_macrotest() {
	MESSER_LOG_INIT(INFO);
	/*
	 logfile.warn("Storm is coming %s", __PRETTY_FUNCTION__);
	 logfile.debug("Received storm warning");
	 logfile.info("Closing all hatches");
	 logfile.debug("Hiding solar panels");
	 logfile.error("Solar panels are blocked");
	 logfile.debug("Applying protective shield");
	 logfile.warn("Unfolding protective shield");
	 logfile.info("Solar panels are shielded");
	 logfile.info("All hatches closed");
	 logfile.info("Ready for storm.");
	 console.info("console->Ready for storm.");

	 logfile.warn("%s> Storm is coming ", __PRETTY_FUNCTION__);
	 logfile.debug("Received storm warning");
	 logfile.info("Closing all hatches");
	 logfile.debug("Hiding solar panels");
	 logfile.error("Solar panels are blocked");
	 logfile.debug("Applying protective shield");
	 logfile.warn("Unfolding protective shield");
	 logfile.info("Solar panels are shielded");
	 logfile.info("All hatches closed");
	 logfile.info("Ready for storm.");
	 console.info("console->Ready for storm.");
	 */

	MESSER_DEBUG("<%s> Macro functiona %s top %d", "??", 10);

	//MESSER_CONSOLE_DEBUG("Macro functiona %s top %d", "??", 10);
	//MESSER_CONSOLE_ALERT("a macro %d", 11223);
	//MESSER_LOGFILE_ALERT("%s> a log here %s %d", "kkk", 12);

	MESSER_LOG_END();
}

int main(int argc, char** argv) {

	bool t1 = false;
	bool t2 = false;
	bool t3 = true;

	if (t1)
		log4cpp_webExampel();
	if (t2)
		log4cpp_example();
	if (t3)
		log4cpp_macrotest();

	return 0;
}
