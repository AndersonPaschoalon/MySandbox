/*
 * TimeScale.h
 *
 *  Created on: 26 de set de 2017
 *      Author: anderson
 */

#ifndef TIMESCALE_H_
#define TIMESCALE_H_

enum time_scale {
	milliseconds, seconds
};

class TimeScale {
public:
	TimeScale();
	virtual ~TimeScale();

	static double scaleFactor(time_scale ts);

	static double scaleFactor(std::string ts_str);

	static time_scale timeScale(std::string ts_str);

};

#endif /* TIMESCALE_H_ */
