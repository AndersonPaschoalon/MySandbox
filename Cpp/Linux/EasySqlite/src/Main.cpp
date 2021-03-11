//============================================================================
// Name        : EasySqlite.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "TraceDbManager.h"

#include "DatabaseSqlite3.h"
#include "TraceDbManager.h"

using namespace std;

void test_database();
void test_tracedbmanager();

int main()
{
	//test_database();
	test_tracedbmanager();

	return 0;
}

void test_database()
{
	DatabaseSqlite3 db = DatabaseSqlite3("trace.db", true);

	std::string strval = "";
	int ival = 0;
	double dval = 0;
	std::list<std::string> str_list;
	std::list<double> d_list;
	std::list<int> i_list;

	printf("\n\nstr\n");

	db.get("Flows", "protocolLink", str_list);
	printList(str_list);
	str_list.clear();

	db.get_where("Flows", "protocolLink", "traceID=12", str_list);
	printList(str_list);
	str_list.clear();

	printf("\n\nint\n");

	db.get("Flows", "protocolNetwork", i_list);
	printList(i_list);
	i_list.clear();

	db.get_where("Flows", "protocolNetwork", "traceID=12", i_list);
	printList(i_list);
	i_list.clear();

	printf("\n\ndouble\n");

	db.get("Flows", "portSrc", d_list);
	printList(d_list);
	d_list.clear();

	db.get_where("Flows", "portSrc", "traceID=12", d_list);
	printList(d_list);
	d_list.clear();

	printf("\n\nTest Join\n");

	db.join("seq", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=1 AND Traces.traceName=\"arboc\" )", str_list);
	std::cout << "seq:";
	printList(str_list);
	str_list.clear();

	db.join("pktSize", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=1 AND Traces.traceName=\"arboc\" )", i_list);
	std::cout << "pktSize: ";
	printList(i_list);
	i_list.clear();

	db.join("arrivalTime", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=1 AND Traces.traceName=\"arboc\" )", d_list);
	std::cout << "arrivalTime:";
	printList(d_list);
	d_list.clear();

	printf("\n\nTest Max\n");
	db.max("seq", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=0 AND Traces.traceName=\"arboc\" )", strval);
	std::cout << "max seq: " << strval << std::endl;

	//Problema
	db.max("pktSize", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=0 AND Traces.traceName=\"arboc\" )", ival);
	std::cout << "max pktSize=" << ival << std::endl;

	db.max("arrivalTime", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=0 AND Traces.traceName=\"arboc\" )", dval);
	std::cout << "max arrivalTime=" << dval << std::endl;
}

void test_tracedbmanager()
{
	std::string strval = "";
	int ival = 0;
	double dval = 0;
	std::list<std::string> str_list;
	std::list<double> d_list;
	std::list<int> i_list;

	printf("\n\nTest TraceDbManager\n");

	TraceDbManager traceDb = TraceDbManager("trace.db");

	//std::cout << "traceName: "
	//		<< traceDb.getTraceData("arbocccc", "traceName", strval) << std::endl;


	//traceDb.getFlowData("arboc", 0, "protocolNetwork", ival);
	std::cout << std::endl << "trace:arboc" << std::endl;
	std::cout << "traceName: "
			<< traceDb.getTraceData("arboc", "traceName", strval) << std::endl;
	std::cout << "traceID: " << traceDb.getTraceData("arboc", "traceID", strval)
			<< std::endl;
	std::cout << "captureDate: "
			<< traceDb.getTraceData("arboc", "captureDate", strval)
			<< std::endl;

	std::cout << std::endl << "trace:bubasauro" << std::endl;
	std::cout << "traceName: "
			<< traceDb.getTraceData("bubasauro", "traceName", strval)
			<< std::endl;
	std::cout << "traceID: "
			<< traceDb.getTraceData("bubasauro", "traceID", strval)
			<< std::endl;
	std::cout << "captureDate: "
			<< traceDb.getTraceData("bubasauro", "captureDate", strval)
			<< std::endl;

	//std::cout << std::endl << "trace:bubasauro, flow:6" << std::endl;
	//std::cout << "protocolLink: " << traceDb.getFlowData("bubasauro",6,"protocolLink", strval) << std::endl;
	//std::cout << "macDst: " << traceDb.getFlowData("bubasauro",6,"macDst", strval) << std::endl;
	//std::cout << "netSrc: " << traceDb.getFlowData("bubasauro",6,"netSrc", strval) << std::endl;

	std::cout << std::endl << "trace:bubasauro, flow:12" << std::endl;
	std::cout << "protocolLink: "
			<< traceDb.getFlowData("bubasauro", 12, "protocolLink", strval)
			<< std::endl;
	std::cout << "macDst: "
			<< traceDb.getFlowData("bubasauro", 12, "macDst", strval)
			<< std::endl;
	std::cout << "netSrc: "
			<< traceDb.getFlowData("bubasauro", 12, "netSrc", strval)
			<< std::endl;
	std::cout << "protocolTransport: "
			<< traceDb.getFlowData("bubasauro", 12, "protocolTransport", ival)
			<< std::endl;

	std::cout << std::endl << "trace:bubasauro, flow:0" << std::endl;
	std::cout << "protocolLink: "
			<< traceDb.getFlowData("bubasauro", 0, "protocolLink", strval)
			<< std::endl;
	std::cout << "macDst: "
			<< traceDb.getFlowData("bubasauro", 0, "macDst", strval)
			<< std::endl;
	std::cout << "netSrc: "
			<< traceDb.getFlowData("bubasauro", 0, "netSrc", strval)
			<< std::endl;
	std::cout << "protocolTransport: "
			<< traceDb.getFlowData("bubasauro", 0, "protocolTransport", ival)
			<< std::endl;
	//std::cout << "protocolTransport: "
	//		<< traceDb.getFlowData("essa-trace-nao-existe!", 0, "protocolTransport", ival)
	//		<< std::endl;

	printf("\n\nTest table Packets\n");

	traceDb.getFlowPktData("arboc", 0, "arrivalTime", d_list );
	std::cout << std::endl << "trace:bubasauro, flow:0, arrivalTime:" << std::endl;
	printList(d_list);

	traceDb.getFlowPktData("arboc", 9, "pktSize", i_list );
	std::cout << std::endl << "trace:bubasauro, flow:9, pktSize:" << std::endl;
	printList(i_list);

	//traceDb.getFlowPktData();



}

