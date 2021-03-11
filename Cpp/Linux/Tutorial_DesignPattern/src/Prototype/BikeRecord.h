/*
 * BikeRecord.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef BIKERECORD_H_
#define BIKERECORD_H_

#include "Record.h"

class BikeRecord: public Record {
	public:
		virtual ~BikeRecord();
		BikeRecord(string bikeName, int ID);
		BikeRecord(const BikeRecord& bikeRecord);
		Record* clone();
		void print();

	private:
		string mbikeName;
		int mID;
};

#endif /* BIKERECORD_H_ */
