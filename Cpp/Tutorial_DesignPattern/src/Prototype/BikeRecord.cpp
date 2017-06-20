/*
 * BikeRecord.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "BikeRecord.h"


BikeRecord::~BikeRecord() {
	// TODO Auto-generated destructor stub
}

BikeRecord::BikeRecord(string bikeName, int ID)
	: Record(), mbikeName(bikeName), mID(mID) {
}

BikeRecord::BikeRecord(const BikeRecord& bikeRecord)
	: Record(bikeRecord) {
	mbikeName = bikeRecord.mbikeName;
	mID = bikeRecord.mID;
}

Record* BikeRecord::clone() {
	return new BikeRecord(*this);
}

void BikeRecord::print() {
	cout << "Bike Record" << endl
			<< "Name   : " << mbikeName << endl
			<< "Number : " << mID << endl << endl;
}


