/*
 * CarDecorator.h
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#ifndef CARDECORATOR_H_
#define CARDECORATOR_H_
#include "Car.h"
#include "CarModel1.h"
	#include "OptionsDecorator.h"
		#include "Navigation.h"
		#include "PremiumSoundSystem.h"
		#include "ManualTransmission.h"
#include "CarDecorator.h"

class CarDecorator {
	public:
		CarDecorator();
		virtual ~CarDecorator();
		void run();
	private:
};

#endif /* CARDECORATOR_H_ */
