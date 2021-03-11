/*
 * RecordFactory.h
 *
 *  Created on: 26/08/2015
 *      Author: anderson
 */

#ifndef RECORDFACTORY_H_
#define RECORDFACTORY_H_
#include <map>
#include <iostream>
#include <string>

#include "RecordType.h"
#include "Record.h"

class RecordFactory {
	public:
		RecordFactory();
		virtual ~RecordFactory();
		Record* createRecord(RECOR_TYPE_en enType);

	private:
		Record* mRecordReference[END];
};

#endif /* RECORDFACTORY_H_ */
