//============================================================================
// Name        : TimeScale.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AbsClass.h"
#include "BaseClass.h"
#include "D1Class.h"
#include "D2Class.h"
using namespace std;

int main() {

	D1Class d1;
	BaseClass b1;

	D1Class* ptr_d1 = new D1Class(222, 99.99, "STR PTR");


	// d1.config(12, 15.55, "changed val");

	std::cout << "D1Class:\n";
	d1.print();
	std::cout << "BaseClass:\n";
	b1.print();
	std::cout << "ptr D1Class:\n";
	ptr_d1->print();

	return 0;
}
