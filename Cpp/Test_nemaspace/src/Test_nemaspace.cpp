//============================================================================
// Name        : Test_nemaspace.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "C1.h"
#include "C2.h"

using namespace std;
using namespace simitar;


int main() {
	C1 c1 = C1();
	C2 c2 = C2();

	c1.print();
	c2.print();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
