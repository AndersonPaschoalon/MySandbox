/*
 * PremiumSoundSystem.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef PREMIUMSOUNDSYSTEM_H_
#define PREMIUMSOUNDSYSTEM_H_

#include "OptionsDecorator.h"

class PremiumSoundSystem: public OptionsDecorator {
	public:
		//constructor
		PremiumSoundSystem(Car* theCar);
		//destructor
		virtual ~PremiumSoundSystem();
		//returns the description
		string getDescription();
		//returns the total car's cost
		double getCost();

	private:
		Car* carObject;
};

#endif /* PREMIUMSOUNDSYSTEM_H_ */
