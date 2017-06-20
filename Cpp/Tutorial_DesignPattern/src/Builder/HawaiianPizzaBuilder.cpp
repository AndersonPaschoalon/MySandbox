/*
 * HawaiianPizzaBuilder.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "HawaiianPizzaBuilder.h"

HawaiianPizzaBuilder::HawaiianPizzaBuilder() {
	// TODO Auto-generated constructor stub
	
}

HawaiianPizzaBuilder::~HawaiianPizzaBuilder() {
	// TODO Auto-generated destructor stub
}

void HawaiianPizzaBuilder::buildDough() {
	m_pizza->setDough("cross");
}

void HawaiianPizzaBuilder::buildSauce() {
	m_pizza->setSauce("mild");
}

void HawaiianPizzaBuilder::buildTopping() {
	m_pizza->setTopping("ham+pineapple");
}


