/*
 * TraceDbManager.cpp
 *
 *  Created on: 28 de jul de 2017
 *      Author: anderson
 */

#include "TraceDbManager.h"

TraceDbManager::TraceDbManager(std::string databaseFile)
{
	m_db = DatabaseSqlite3(databaseFile);
}

TraceDbManager::~TraceDbManager()
{
}

int TraceDbManager::getTraceData(std::string traceName, std::string field,
		std::string data)
{
	return (m_db.max(field, "Traces", "", "", "", "", "traceName=" + traceName,
			data));
}

int TraceDbManager::getTraceData(std::string traceName, std::string field,
		int data)
{
	return (m_db.max(field, "Traces", "", "", "", "", "traceName=" + traceName,
			data));
}

int TraceDbManager::getNumberOfFlows(std::string traceName)
{
	int nflows;
	return (m_db.max("flowID", "Flows", "Trace", "Traces.traceID=Flows.traceID",
			"", "", "traceName=" + traceName, nflows) + 1);
}

std::string TraceDbManager::getFlowData(std::string traceName, int flowID,
		std::string field, std::string& data)
{
	return (m_db.max(field, "Flows", "Trace", "Traces.traceID=Flows.traceID",
			"", "", "traceName=" + traceName, data));
}

int TraceDbManager::getFlowData(std::string traceName, int flowID,
		std::string field, int& data)
{
	return (m_db.max(field, "Flows", "Trace", "Traces.traceID=Flows.traceID",
			"", "", "traceName=" + traceName, data));
}

int TraceDbManager::getFlowPktData(std::string traceName, int flowID,
		std::string field, std::list<int>& dataList)
{
	//TODO
	return (m_db.join(field, "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=" + std::string(flowID) + " AND Trace.traceName=\""
					+ traceName + "\" )", dataList));
}

int TraceDbManager::getFlowPktData(std::string traceName, int flowID,
		std::string field, std::list<double>& dataList)
{
	//TODO
	return (0);
}

int TraceDbManager::getFlowPktData(std::string traceName, int flowID,
		std::string field, std::list<std::string>& dataList)
{
	//TODO
	return (0);
}
