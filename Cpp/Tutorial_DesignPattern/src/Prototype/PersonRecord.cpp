/*
 * PersonRecord.cpp
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#include "PersonRecord.h"


PersonRecord::~PersonRecord() {
	// TODO Auto-generated destructor stub
}

PersonRecord::PersonRecord(string personName, int age)
	: Record(), mPersonName(personName), mAge(age) {
}


Record* PersonRecord::clone() {
	return new PersonRecord(*this);
}

PersonRecord::PersonRecord(const PersonRecord& personRecord) {
	mPersonName = personRecord.mPersonName;
	mAge = personRecord.mAge;
}

void PersonRecord::print() {
	cout << "Person Record" << endl
			<< "Name : " << mPersonName << endl
			<< "Age : " << mAge << endl << endl;
}


