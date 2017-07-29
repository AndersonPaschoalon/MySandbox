/*
 * TraceDbManager.h
 *
 *  Created on: 28 de jul de 2017
 *      Author: anderson
 */

#ifndef TRACEDBMANAGER_H_
#define TRACEDBMANAGER_H_

#include <string>
#include <string.h>
#include <list>

class TraceDbManager
{
public:

	/**
	 * Constructor of the Trace database manager.
	 * It retrieve requested data form the database.
	 */
	TraceDbManager();

	/**
	 * Destructor.
	 */
	virtual ~TraceDbManager();

	/**
	 *
	 * @param traceName
	 * @param field
	 * @param data
	 * @return
	 */
	int getTraceData(std::string traceName, std::string field,
			std::string data);

	/**
	 *
	 * @param traceName
	 * @param field
	 * @param data
	 * @return
	 */
	int getTraceData(std::string traceName, std::string field, int data);

	/**
	 *
	 * @param traceName
	 * @param field
	 * @param data
	 * @return
	 */
	int getNumberOfFlows(std::string traceName, std::string field, int data);

	/**
	 *
	 * @param traceName
	 * @param flowID
	 * @param field
	 * @param data
	 * @return
	 */
	int getFlowData(std::string traceName, std::string flowID,
			std::string field, std::string& data);

	/**
	 *
	 * @param traceName
	 * @param flowID
	 * @param field
	 * @param data
	 * @return
	 */
	int getFlowData(std::string traceName, std::string flowID,
			std::string field, int& data);

	/**
	 *
	 * @param traceName
	 * @param flowID
	 * @param field
	 * @param dataList
	 * @return
	 */
	int getFlowPktData(std::string traceName, std::string flowID,
			std::string field, std::list<int>& dataList);

	/**
	 *
	 * @param traceName
	 * @param flowID
	 * @param field
	 * @param dataList
	 * @return
	 */
	int getFlowPktData(std::string traceName, std::string flowID,
			std::string field, std::list<double>& dataList);

	/**
	 *
	 * @param traceName
	 * @param flowID
	 * @param field
	 * @param dataList
	 * @return
	 */
	int getFlowPktData(std::string traceName, std::string flowID,
			std::string field, std::list<std::string>& dataList);

};

#endif /* TRACEDBMANAGER_H_ */