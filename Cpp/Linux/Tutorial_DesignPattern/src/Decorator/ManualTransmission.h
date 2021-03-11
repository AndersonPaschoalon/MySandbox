/*
 * ManualTransmission.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef MANUALTRANSMISSION_H_
#define MANUALTRANSMISSION_H_

#include "OptionsDecorator.h"

class ManualTransmission: public OptionsDecorator {
	public:
		//constructor
		ManualTransmission(Car* theCar);
		//destructor
		virtual ~ManualTransmission();
		//returns the car description
		string getDescription();
		//returns the car cost
		double getCost();
	private:
		Car* carObject;
};

#endif /* MANUALTRANSMISSION_H_ */
