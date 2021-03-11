/*
 * Pizza.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef PIZZA_H_
#define PIZZA_H_
#include <string>
#include <iostream>
using namespace std;

class Pizza {
	public:
		Pizza();
		virtual ~Pizza();

		void setDough(const string & dough);
		void setSauce(const string & sauce);
		void setTopping(const string & topping);
		void open() const;

	private:
		string m_dough;
		string m_sauce;
		string m_topping;
};

#endif /* PIZZA_H_ */
