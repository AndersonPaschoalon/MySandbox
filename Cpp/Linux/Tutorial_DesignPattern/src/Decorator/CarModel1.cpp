/*
 * CarModel1.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "CarModel1.h"

CarModel1::CarModel1()
	:Car(){
	carCost = 31000.50;
}

CarModel1::CarModel1(const double cost)
	:Car(){
	CarModel1();
	carCost = cost;
}

CarModel1::CarModel1(const string description)
	:Car(){
	CarModel1();
	strDescriptor = description;
}

CarModel1::CarModel1(const double cost, const string description)
{
	carCost = cost;
	strDescriptor = description;
	//do nothing
}

CarModel1::CarModel1(const string description, const double cost){
	CarModel1(cost, description);
}

CarModel1::~CarModel1() {
}

double CarModel1::getCost() {
	return getCost();
}
