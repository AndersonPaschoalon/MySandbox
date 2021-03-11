/*
 * SpicyPizzaBuilder.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef SPICYPIZZABUILDER_H_
#define SPICYPIZZABUILDER_H_

#include "PizzaBuilder.h"

class SpicyPizzaBuilder: public PizzaBuilder {
	public:

		SpicyPizzaBuilder();
		virtual ~SpicyPizzaBuilder();

		virtual void buildDough();
		virtual void buildSauce();
		virtual void buildTopping();

	private:
};

#endif /* SPICYPIZZABUILDER_H_ */
