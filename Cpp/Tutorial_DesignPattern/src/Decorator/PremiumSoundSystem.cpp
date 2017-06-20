/*
 * PremiumSoundSystem.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "PremiumSoundSystem.h"

PremiumSoundSystem::PremiumSoundSystem(Car* theCar) {
	carObject = theCar;
}

PremiumSoundSystem::~PremiumSoundSystem() {
	//do nothing
}

string PremiumSoundSystem::getDescription() {
	return (carObject->getDescription()+", PremiumSoundSystem");
}

double PremiumSoundSystem::getCost() {
	return (carObject->getCost()+10.5);
}


