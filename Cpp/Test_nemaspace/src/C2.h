/*
 * C2.h
 *
 *  Created on: 18 de ago de 2017
 *      Author: anderson
 */

#ifndef C2_H_
#define C2_H_

#include <iostream>

namespace simitar {

class C2 {
public:
	C2();
	virtual ~C2();
	void print()
	{
		std::cout << "C2\n";
	}
};

} /* namespace simitar */

#endif /* C2_H_ */