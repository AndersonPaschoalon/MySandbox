/*
 * PizzaBuilder.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "PizzaBuilder.h"

PizzaBuilder::PizzaBuilder() {
	// TODO Auto-generated constructor stub
	
}

PizzaBuilder::~PizzaBuilder() {
	// TODO Auto-generated destructor stub
}

Pizza* PizzaBuilder::getPizza() {
	return m_pizza;
}

void PizzaBuilder::createNewPizza() {
	m_pizza = new Pizza;
}


