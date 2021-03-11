/*
 * Navigation.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "Navigation.h"

Navigation::Navigation(Car* theCar) {
	carObject = theCar;
}

string Navigation::getDescription() {
	string retVal = carObject->getDescription();
	retVal += ", Navigation" ;
	return (retVal);
}

double Navigation::getCost() {
	return (carObject->getCost() + 300.5);
}

Navigation::~Navigation() {
	//do nothing
}

