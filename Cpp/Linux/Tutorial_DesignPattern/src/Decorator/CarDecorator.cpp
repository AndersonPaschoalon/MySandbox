/*
 * CarDecorator.cpp
 *
 *  Created on: 27/08/2015
 *      Author: anderson
 */

#include "CarDecorator.h"

CarDecorator::CarDecorator() {
	//theCar = new CarModel1();
}

CarDecorator::~CarDecorator() {
}

void CarDecorator::run() {
	string input;
	Car* aCar = NULL;

	//--------------------------------------------------------------------------
	cout << "You will want a Navigation module? [y/n] ";
	cin >> input;
	if(input == "y"){
		aCar = new Navigation(aCar);
	}
	cout << aCar->getDescription() << " will cost you $" <<
			aCar->getCost() << endl;
	delete aCar;

	//--------------------------------------------------------------------------
	cout << "You will want a PremiumSoundSystem module? [y/n] ";
	cin >> input;
	if (input == "y"){
		aCar = new PremiumSoundSystem(aCar);
	}
	cout << aCar->getDescription() << " will cost you $" <<
			aCar->getCost() << endl;
	delete aCar;

	//--------------------------------------------------------------------------
	cout << "You will want a ManualTransmission module? [y/n] ";
	cin >> input;
	if (input == "y"){
		aCar = new ManualTransmission(aCar);
	}
	cout << aCar->getDescription() << " will cost you $" <<
			aCar->getCost() << endl;
	delete aCar;
}


