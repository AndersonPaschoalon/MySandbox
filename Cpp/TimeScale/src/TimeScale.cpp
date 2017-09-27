/*
 * TimeScale.cpp
 *
 *  Created on: 26 de set de 2017
 *      Author: anderson
 */

#include "TimeScale.h"

TimeScale::TimeScale() {
	// TODO Auto-generated constructor stub
}

TimeScale::~TimeScale() {
	// TODO Auto-generated destructor stub
}

double TimeScale::scaleFactor(time_scale ts) {
	if (ts == milliseconds)
		return (1000.0);
	else if (ts == seconds)
		return (1.0);
	std::cerr << "Error TimeScale::scaleFactor(): Invalid time_scale: " << ts
			<< std::endl;
	return (1.0);
}

double TimeScale::scaleFactor(std::string ts_str) {
	if (ts_str == "milliseconds")
		return (1000.0);
	else if (ts_str == "seconds")
		return (1.0);
	// default
	return (1.0);
}

time_scale TimeScale::timeScale(std::string ts_str) {
	if (ts_str == "milliseconds")
		return (milliseconds);
	else if (ts_str == "seconds")
		return (seconds);
	// default
	return (seconds);
}
