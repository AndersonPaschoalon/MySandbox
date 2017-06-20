/*
 * Desktop.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef DESKTOP_H_
#define DESKTOP_H_

#include "Computer.h"

class Desktop: public Computer {

	public:
		Desktop();
		virtual ~Desktop();

	private:
		virtual void Run();
		virtual void Stop();
		virtual void Info();


	private:
		bool mOn; //Wheather or not the machine has been turned on
};

#endif /* DESKTOP_H_ */
