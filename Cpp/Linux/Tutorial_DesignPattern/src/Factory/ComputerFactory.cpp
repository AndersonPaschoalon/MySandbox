/*
 * ComputerFactory.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "ComputerFactory.h"

ComputerFactory::ComputerFactory() {
	// TODO Auto-generated constructor stub
	
}

ComputerFactory::~ComputerFactory() {
	// TODO Auto-generated destructor stub
}

Computer* ComputerFactory::NewComputer(const string& description) {
	if(description == "laptop"){
		return new Laptop;
	}
	if (description == "desktop"){
		return new Desktop;
	}
	return new Default;
}


