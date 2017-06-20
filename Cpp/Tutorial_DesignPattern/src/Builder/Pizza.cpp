/*
 * Pizza.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "Pizza.h"
#include <string>
#include <iostream>
using namespace std;

Pizza::Pizza() {
	// TODO Auto-generated constructor stub
	
}

Pizza::~Pizza() {
	// TODO Auto-generated destructor stub
}

void Pizza::setDough(const string& dough) {
	m_dough = dough;
}

void Pizza::setTopping(const string& topping) {
	m_topping = topping;
}

void Pizza::setSauce(const string& sauce) {
	m_sauce = sauce;
}

void Pizza::open() const {
	cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
			<< m_topping << " topping. Mmmm." << endl;
}

