/*
 * Navigation.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef NAVIGATION_H_
#define NAVIGATION_H_

#include "OptionsDecorator.h"

class Navigation: public OptionsDecorator {
	public:
		//default constructor
		Navigation(Car* theCar);
		//returns the car description
		string getDescription();
		//returns the car cost
		double getCost();
		//defaulot destructor
		virtual ~Navigation();

	private:
		Car* carObject;
};

#endif /* NAVIGATION_H_ */
