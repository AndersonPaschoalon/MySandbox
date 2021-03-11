/*
 * C1.h
 *
 *  Created on: 18 de ago de 2017
 *      Author: anderson
 */

#ifndef C1_H_
#define C1_H_

#include <iostream>

namespace simitar {

class C1 {
public:
	C1();
	virtual ~C1();
	void print()
	{
		std::cout << "C1\n";
	}
};

} /* namespace simitar */

#endif /* C1_H_ */
