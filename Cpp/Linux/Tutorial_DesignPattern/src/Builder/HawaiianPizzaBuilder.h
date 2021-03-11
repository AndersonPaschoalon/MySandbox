/*
 * HawaiianPizzaBuilder.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef HAWAIIANPIZZABUILDER_H_
#define HAWAIIANPIZZABUILDER_H_
#include "PizzaBuilder.h"

//classe abstrata derivada da classe PizzaBuilder
class HawaiianPizzaBuilder : public PizzaBuilder {
	public:

		HawaiianPizzaBuilder();
		virtual ~HawaiianPizzaBuilder();

		virtual void buildDough();
		virtual void buildSauce();
		virtual void buildTopping();
	private:
};

#endif /* HAWAIIANPIZZABUILDER_H_ */
