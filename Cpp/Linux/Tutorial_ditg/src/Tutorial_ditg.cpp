//============================================================================
// Name        : Tutorial_ditg.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ITGapi.h>
using namespace std;

int main() {

	struct timeval tv;
	tv.tv_sec = 20;
	tv.tv_usec = 1;

	char host[] = "10.1.1.48";

	char command1[] = " -a 10.1.1.95 -rp 9500 -C 100 -c 500 -t 20000";

	for (uint i = 0; i < 390; i++) {
		DITGsend(host, command1);
	}
	select(0, NULL, NULL, NULL, &tv);

	return 0;
}