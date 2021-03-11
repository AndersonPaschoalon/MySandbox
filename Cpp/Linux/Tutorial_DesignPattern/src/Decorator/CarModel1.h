/*
 * CarModel1.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef CARMODEL1_H_
#define CARMODEL1_H_

#include "Car.h"

class CarModel1: public Car {
	public:
		//default constructor
		CarModel1();
		//Parameterized constructors
		CarModel1(const double cost);
		CarModel1(const string description);
		CarModel1(const double cost, const string description);
		CarModel1(const string description, const double cost);
		//destructor
		virtual ~CarModel1();
		//returns the car cost
		virtual double getCost();
	private:
};

#endif /* CARMODEL1_H_ */
