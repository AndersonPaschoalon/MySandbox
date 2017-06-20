/*
 * SpicyPizzaBuilder.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "SpicyPizzaBuilder.h"

SpicyPizzaBuilder::SpicyPizzaBuilder() {
	// TODO Auto-generated constructor stub
	
}

SpicyPizzaBuilder::~SpicyPizzaBuilder() {
	// TODO Auto-generated destructor stub
}

void SpicyPizzaBuilder::buildDough() {
	m_pizza->setDough("pan-backed");
}

void SpicyPizzaBuilder::buildSauce() {
	m_pizza->setSauce("hot");
}

void SpicyPizzaBuilder::buildTopping() {
	m_pizza->setTopping("peperoni-salami");
}


