//============================================================================
// Name        : TimeScale.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TimeScale.h"
using namespace std;

int main() {

	cout << TimeScale::scaleFactor(seconds) << endl;
	cout << TimeScale::scaleFactor(milliseconds) << endl;
	cout << TimeScale::scaleFactor("seconds") << endl;
	cout << TimeScale::scaleFactor("milliseconds") << endl;
	return 0;
}
