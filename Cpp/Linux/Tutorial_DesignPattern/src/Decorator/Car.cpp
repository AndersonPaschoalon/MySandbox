/*
 * Car.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "Car.h"

Car::Car() {
	strDescriptor = "Unknown Car";
	carCost = 0;
}

Car::~Car() {
	//do nothing
}

string Car::getDescription() {
	return strDescriptor;
}


