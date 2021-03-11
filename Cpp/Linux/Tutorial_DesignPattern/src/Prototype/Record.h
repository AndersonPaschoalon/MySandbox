/*
 * Record.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef RECORD_H_
#define RECORD_H_
#include "RecordType.h"
#include <string>
#include <iostream>
using namespace std;

class Record {
	public:
		Record();
		virtual ~Record();

		virtual Record* clone() = 0;
		virtual void print() = 0;
};

#endif /* RECORD_H_ */
