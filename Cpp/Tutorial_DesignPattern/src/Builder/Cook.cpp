/*
 * Cook.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "Cook.h"

Cook::Cook() {
	// TODO Auto-generated constructor stub
}

Cook::~Cook() {
	// TODO Auto-generated destructor stub
}

void Cook::setPizzaBuilder(PizzaBuilder* pb) {
	m_pizzaBuilder = pb;
}

Pizza* Cook::getPizza() {
	return m_pizzaBuilder->getPizza();
}

void Cook::constructPizza() {
	m_pizzaBuilder->createNewPizza();
	m_pizzaBuilder->buildDough();
	m_pizzaBuilder->buildSauce();
	m_pizzaBuilder->buildTopping();
}


