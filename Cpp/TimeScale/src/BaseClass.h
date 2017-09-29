/*
 * BaseClass.h
 *
 *  Created on: 28 de set de 2017
 *      Author: anderson
 */

#ifndef BASECLASS_H_
#define BASECLASS_H_

#include "AbsClass.h"

class BaseClass: public AbsClass {
public:
	BaseClass(): val1(1), dval1(3.14), str1("a-string"){}
	virtual ~BaseClass();
	void print() {
		std::cout << "val1	:" << val1 << std::endl;
		std::cout << "dval1	:" << dval1 << std::endl;
		std::cout << "str1	:" << str1 << std::endl;
	}
protected:
	int val1;
	double dval1;
	std::string str1;

};

#endif /* BASECLASS_H_ */
