/*
 * Computer.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_
#include <string>
#include <iostream>
using namespace std;

class Computer {

	public:
		Computer();
		virtual ~Computer();

		virtual void Run() = 0;
		virtual void Stop() = 0;
		virtual void Info() = 0;

	private:
};

#endif /* COMPUTER_H_ */
