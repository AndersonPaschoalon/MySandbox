/*
 * PizzaBuilder.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef PIZZABUILDER_H_
#define PIZZABUILDER_H_
#include "Pizza.h"

/**
 * Abstract class builder of a generic object from the class Pizza
 */
class PizzaBuilder {
	public:
		
		PizzaBuilder();
		virtual ~PizzaBuilder();
		
		//returns a pointer of the built pizza
		Pizza* getPizza();

		//create a new empty pizza
		void createNewPizza();

		//virtual abstract methods
		virtual void buildDough() = 0; //make the class abstract!
		virtual void buildSauce() = 0;
		virtual void buildTopping() = 0;

	protected:
		Pizza* m_pizza;

};

#endif /* PIZZABUILDER_H_ */
