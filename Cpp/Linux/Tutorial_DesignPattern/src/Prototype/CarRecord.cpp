/*
 * CarRecord.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "CarRecord.h"

CarRecord::CarRecord(string carName, int ID)
	: Record(), mCarName(carName),mID(ID) {
}

CarRecord::~CarRecord() {
	// TODO Auto-generated destructor stub
}

CarRecord::CarRecord(const CarRecord& carRecord)
	:Record(carRecord)//copy constructor
{
	mCarName = carRecord.mCarName;
	mID =  carRecord.mID;
}

Record* CarRecord::clone() {
	// CarRecord(*this) <- copy constructor
	return new CarRecord(*this);
}

void CarRecord::print() {
	cout << "Car Record" << endl
			<< "Name   : " << mCarName << endl
			<< "Number : " << mID << endl << endl;
}
