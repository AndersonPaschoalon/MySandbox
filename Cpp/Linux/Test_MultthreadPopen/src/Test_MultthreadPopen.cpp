//============================================================================
// Name        : Test_MultthreadPopen.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <stdio.h>
#include <stdlib.h>

std::mutex mtx;
using namespace std;


int ls(int n){
	mtx.lock();
	cout << "\n* ls(" << n << ")\n";
	mtx.unlock();
	FILE *in;
	char buff[512];

	if (!(in = popen("ls -sail", "r"))) {
		return 1;
	}

	while (fgets(buff, sizeof(buff), in) != NULL) {
		cout << buff;
	}

	pclose(in);
	//mtx.unlock();
	return 0;
}

int make1()
{
	mtx.lock();
	cout << "\n* make1()\n";
	mtx.unlock();
	FILE *in;
	char buff[512];

	if (!(in = popen("ls -lahn", "r"))) {
	//if (!(in = popen("pwd", "r"))) {
		return 1;
	}

	while (fgets(buff, sizeof(buff), in) != NULL) {
		cout << buff;
	}

	pclose(in);
	//mtx.unlock();
	return 0;
}

int make2()
{
	mtx.lock();
	cout << "\n* make2()\n";
	mtx.unlock();
	FILE *in;
	char buff[512];

	if (!(in = popen("ls -lahn", "r"))) {
		return 1;
	}

	while (fgets(buff, sizeof(buff), in) != NULL) {
		cout << buff;
	}

	pclose(in);
	//mtx.unlock();
	return 0;
}

int main() {


	std::thread th1(ls, 1);
	std::thread th2(ls, 2);
	std::thread th3(ls, 3);

	th1.join();
	th2.join();
	th3.join();

	std::thread th4(make1);
	std::thread th5(make2);

	th4.join();
	th5.join();
	return 0;

}
