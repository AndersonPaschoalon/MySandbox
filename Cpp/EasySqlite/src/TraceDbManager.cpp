/*
 * TraceDbManager.cpp
 *
 *  Created on: 28 de jul de 2017
 *      Author: anderson
 */

#include "TraceDbManager.h"

TraceDbManager::TraceDbManager()
{
}

TraceDbManager::~TraceDbManager()
{
}

int TraceDbManager::getTraceData(std::string traceName, std::string field,
		std::string data)
{
	//TODO
	return(0);
}

int TraceDbManager::getTraceData(std::string traceName, std::string field,
		int data)
{
	//TODO
	return(0);
}

int TraceDbManager::getNumberOfFlows(std::string traceName, std::string field,
		int data)
{
	//TODO
	return(0);
}

int TraceDbManager::getFlowData(std::string traceName, std::string flowID,
		std::string field, std::string& data)
{
	//TODO
	return(0);
}

int TraceDbManager::getFlowData(std::string traceName, std::string flowID,
		std::string field, int& data)
{
	//TODO
	return(0);
}

int TraceDbManager::getFlowPktData(std::string traceName, std::string flowID,
		std::string field, std::list<int>& dataList)
{
	//TODO
	return(0);
}

int TraceDbManager::getFlowPktData(std::string traceName, std::string flowID,
		std::string field, std::list<double>& dataList)
{
	//TODO
	return(0);
}

int TraceDbManager::getFlowPktData(std::string traceName, std::string flowID,
		std::string field, std::list<std::string>& dataList)
{
	//TODO
	return(0);
}