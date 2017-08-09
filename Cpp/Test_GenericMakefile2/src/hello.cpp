#include <iostream>
#include "f1.h"
#include "f2.h"
#include "f3.h"
#include "f4.h"

using namespace testmake2;
int main(int argc, char* argv[])
{
	// suppress warnings
	//(void)argc; (void)argv;

	std::cout << "Hello World!" << std::endl;
	f1();
	f2();
	f3();
	f4();

	return 0;
}
