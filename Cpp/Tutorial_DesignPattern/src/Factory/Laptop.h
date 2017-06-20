/*
 * Laptop.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef LAPTOP_H_
#define LAPTOP_H_

#include "Computer.h"

class Laptop: public Computer {
	public:
		Laptop();
		virtual ~Laptop();

		virtual void Run();
		virtual void Stop();
		virtual void Info();

	private:
		bool mHibernationg; //wheather or not the machine is hibernating
};

#endif /* LAPTOP_H_ */
