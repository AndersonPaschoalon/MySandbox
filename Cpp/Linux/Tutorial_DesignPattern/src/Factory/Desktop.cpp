/*
 * Desktop.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "Desktop.h"

Desktop::Desktop() {
	// TODO Auto-generated constructor stub
	
}

Desktop::~Desktop() {
	// TODO Auto-generated destructor stub
}

void Desktop::Run() {
	mOn = true;
}

void Desktop::Stop() {
	mOn = false;
}

void Desktop::Info() {
	cout << "It is a Desktop" << endl;
}



