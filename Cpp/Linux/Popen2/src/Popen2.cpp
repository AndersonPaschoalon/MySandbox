//============================================================================
// Name        : Popen2.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : A Popen implementation that returns the PID of the process
//               Source: https://stackoverflow.com/questions/26852198/getting-the-pid-from-popen
//============================================================================

#include <iostream>
using namespace std;

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>
#include <sstream>

using namespace std;

#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <inttypes.h>

#define _POSIX_C_SOURCE 200809L

#define READ   0
#define WRITE  1

FILE * popen2(string command, string type, int & pid) {
	pid_t child_pid;
	int fd[2];
	pipe(fd);

	if ((child_pid = fork()) == -1) {
		perror("fork");
		exit(1);
	}

	/* child process */
	if (child_pid == 0) {
		if (type == "r") {
			close(fd[READ]); //Close the READ end of the pipe since the child's fd is write-only
			dup2(fd[WRITE], 1); //Redirect stdout to pipe
		} else {
			close(fd[WRITE]); //Close the WRITE end of the pipe since the child's fd is read-only
			dup2(fd[READ], 0);   //Redirect stdin to pipe
		}

		setpgid(child_pid, child_pid); //Needed so negative PIDs can kill children of /bin/sh
		execl("/bin/sh", "/bin/sh", "-c", command.c_str(), NULL);
		exit(0);
	} else {
		if (type == "r") {
			close(fd[WRITE]); //Close the WRITE end of the pipe since parent's fd is read-only
		} else {
			close(fd[READ]); //Close the READ end of the pipe since parent's fd is write-only
		}
	}

	pid = child_pid;

	if (type == "r") {
		return fdopen(fd[READ], "r");
	}

	return fdopen(fd[WRITE], "w");
}

int pclose2(FILE * fp, pid_t pid) {
	int stat;

	fclose(fp);
	while (waitpid(pid, &stat, 0) == -1) {
		if (errno != EINTR) {
			stat = -1;
			break;
		}
	}

	return stat;
}

void popen2_test1() {
	int pid;
	string command1 = "ping 8.8.8.8";
	FILE * fp = popen2(command1, "r", pid);
	char command1_out[100] = { 0 };
	stringstream output;

	//Using read() so that I have the option of using select() if I want non-blocking flow
	while (read(fileno(fp), command1_out, sizeof(command1_out) - 1) != 0) {
		output << string(command1_out);
		kill(-pid, 9);
		memset(&command1_out, 0, sizeof(command1_out));
	}

	string token;
	while (getline(output, token, '\n'))
		printf("OUT: %s\n", token.c_str());

	pclose2(fp, pid);
}

void popen2_test2() {
	int pid1;
	string command1 = "ping 8.8.8.8 -c 15";
	FILE * fp1 = popen2(command1, "r", pid1);
	char command1_out[100] = { 0 };

	int pid2;
	string command2 = "ping www.google.com -c 5";
	FILE * fp2 = popen2(command2, "r", pid2);
	char command2_out[100] = { 0 };

	//Using read() so that I have the option of using select() if I want non-blocking flow
	while ((read(fileno(fp1), command1_out, sizeof(command1_out) - 1) != 0)
			|| ((read(fileno(fp2), command2_out, sizeof(command2_out) - 1) != 0))) {
		std::cout << string(command1_out);
		std::cout << string(command2_out);

	}

	pclose2(fp1, pid1);
	pclose2(fp2, pid2);

}

int main() {
	bool test1 = false;
	bool test2 = true;

	if (test1 == true) {
		std::cout << "popen2_test1()\n";
		popen2_test1();
	}
	if (test2 == true) {
		std::cout << "popen2_test2()\n";
		popen2_test2();
	}

	return 0;
}
