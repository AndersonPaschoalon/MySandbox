//============================================================================
// Name        : FastTest.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() {

	bool tcp = true;
	std::string valval =
			(tcp == true) ?
					std::string("") + std::string("a") + std::string("b") :
					"udp";
	std::cout << "Hello: " << valval << std::endl;

	char binfile[] = "/bin/ls";
	//char command[3][1024];
	char command[] = "ls -lahn";
	char opts[] = " -lahn ";
	int status;
	char *cmd[] = { "ls -l -a -h", "", (char *)0 };

	if (fork() == 0) {
		//execl ("/bin/ls ", "ls -lahn ../", (char *)0);
		execv ("/bin/ls", cmd);
		//execl(binfile, command, "", (char *) 0);
	} else {
		wait (&status);

	}
	//std::cout << "command[0]:" << command[0] << "\ncommand[1]:" << command[1];


	double sleeptime = 9.666666;
	std::cout << "t_sec:" << int(sleeptime) << "\n";
	std::cout << "t_sec diff:" << sleeptime - double(int(sleeptime)) << "\n";
	std::cout << "t_usec:" << int((sleeptime - double(int(sleeptime)))*10e6) << std::endl;


	return 0;
}
