/*
 * Laptop.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "Laptop.h"

Laptop::Laptop() {
	// TODO Auto-generated constructor stub
	
}

Laptop::~Laptop() {
	// TODO Auto-generated destructor stub
}

void Laptop::Run() {
	mHibernationg = false;
}

void Laptop::Stop() {
	mHibernationg = true;
}

void Laptop::Info() {
	cout << "Its is a Laptop" << endl;
}



