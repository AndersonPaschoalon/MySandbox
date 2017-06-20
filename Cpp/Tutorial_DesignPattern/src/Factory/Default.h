/*
 * Default.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef DEFAULT_H_
#define DEFAULT_H_

#include "Computer.h"

class Default: public Computer {
	public:
		Default();
		virtual ~Default();

		virtual void Run();
		virtual void Stop();
		virtual void Info();

};

#endif /* DEFAULT_H_ */
