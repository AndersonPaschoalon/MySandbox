/*
 * Car.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
using namespace std;

//Abstract class
class Car {
	public:
		//constructor
		Car();
		//destructor
		virtual ~Car();
		//default description
		virtual string getDescription();
		//returns the car's cost
		virtual double getCost() = 0;

	protected:
		//description of the car
		string strDescriptor;
		//car cost
		double carCost;

	private:
};

#endif /* CAR_H_ */
