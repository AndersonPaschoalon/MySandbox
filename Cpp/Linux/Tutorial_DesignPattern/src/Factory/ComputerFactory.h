/*
 * ComputerFactory.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef COMPUTERFACTORY_H_
#define COMPUTERFACTORY_H_
#include "Computer.h"
	#include "Laptop.h"
	#include "Desktop.h"
	#include "Default.h"
#include <string>
#include <iostream>
using namespace std;

class ComputerFactory {
	public:
		ComputerFactory();
		virtual ~ComputerFactory();

		static Computer* NewComputer (const string& description);

	private:
};

#endif /* COMPUTERFACTORY_H_ */
