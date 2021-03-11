/*
 * OptionsDecorator.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef OPTIONSDECORATOR_H_
#define OPTIONSDECORATOR_H_

#include "Car.h"

class OptionsDecorator: public Car {
	public:
		//constructor
		OptionsDecorator();
		//destructor
		virtual ~OptionsDecorator();
		//return the car descrition
		virtual string getDescription() = 0;
};

#endif /* OPTIONSDECORATOR_H_ */
