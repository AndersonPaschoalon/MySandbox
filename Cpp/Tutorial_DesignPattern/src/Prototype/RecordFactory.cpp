/*
 * RecordFactory.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */
#include "RecordFactory.h"
#include "RecordType.h"
#include "Record.h"
	#include "CarRecord.h"
	#include "BikeRecord.h"
	#include "PersonRecord.h"

RecordFactory::RecordFactory() {
	mRecordReference[CAR] = new CarRecord("Ferrari", 5050);
	mRecordReference[BIKE] = new  BikeRecord("Yamaha", 2525);
	mRecordReference[PERSON] = new PersonRecord("Tom", 25);
}

RecordFactory::~RecordFactory() {
	delete mRecordReference[CAR];
	delete mRecordReference[BIKE];
	delete mRecordReference[PERSON];
}

Record* RecordFactory::createRecord(RECOR_TYPE_en enType) {
	return mRecordReference[enType]->clone();
}


