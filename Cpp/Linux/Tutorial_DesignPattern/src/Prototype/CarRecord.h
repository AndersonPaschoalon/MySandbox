/*
 * CarRecord.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef CARRECORD_H_
#define CARRECORD_H_

#include "Record.h"

class CarRecord: public Record {
	public:
		virtual ~CarRecord();
		CarRecord(string carName, int ID);
		CarRecord(const CarRecord& carRecord);
		Record* clone();
		void print();

	private:
		string mCarName;
		int mID;
};

#endif /* CARRECORD_H_ */
