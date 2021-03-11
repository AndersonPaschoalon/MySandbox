/*
 * PersonRecord.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef PERSONRECORD_H_
#define PERSONRECORD_H_

#include "Record.h"

class PersonRecord: public Record {
	public:
		virtual ~PersonRecord();
		PersonRecord(string mPersonName, int ID);
		PersonRecord(const PersonRecord& personRecord);
		Record* clone();
		void print();

	private:
		string mPersonName;
		int mAge;

};

#endif /* PERSONRECORD_H_ */
