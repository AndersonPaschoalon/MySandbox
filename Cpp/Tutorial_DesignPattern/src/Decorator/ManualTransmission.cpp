/*
 * ManualTransmission.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "ManualTransmission.h"

ManualTransmission::ManualTransmission(Car* theCar) {
	carObject = theCar;
}

ManualTransmission::~ManualTransmission() {
	//do nothing
}

string ManualTransmission::getDescription() {
	return(carObject->getDescription() + ", ManualTransmission");
}

double ManualTransmission::getCost() {
	return(10.0 + carObject->getCost());
}


