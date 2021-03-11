/*
 * Cook.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef COOK_H_
#define COOK_H_
#include "PizzaBuilder.h"

class Cook {
	public:

		Cook();
		virtual ~Cook();

		void setPizzaBuilder(PizzaBuilder* pb);
		Pizza* getPizza();
		void constructPizza();

	private:
		PizzaBuilder* m_pizzaBuilder;
};

#endif /* COOK_H_ */
