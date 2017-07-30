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

using namespace std;

int main()
{
	DatabaseSqlite3 db = DatabaseSqlite3("trace.db");

	std::string strval = "";
	int ival = 0;
	double dval= 0;
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
			"(Flows.flowID=1 AND Traces.traceName=\"arboc\" )" , str_list);
	std::cout << "seq:";
	printList(str_list);
	str_list.clear();

	db.join("pktSize", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=1 AND Traces.traceName=\"arboc\" )" , i_list);
	std::cout << "pktSize: ";
	printList(i_list);
	i_list.clear();

	db.join("arrivalTime", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=1 AND Traces.traceName=\"arboc\" )" , d_list);
	std::cout << "arrivalTime:";
	printList(d_list);
	d_list.clear();

	printf("\n\nTest Max\n");
	db.max("seq", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=0 AND Traces.traceName=\"arboc\" )" , strval);
	std::cout << "max seq: " << strval << std::endl;

	//Problema
	db.max("pktSize", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=0 AND Traces.traceName=\"arboc\" )" , ival);
	std::cout << "max pktSize=" << ival << std::endl;


	db.max("arrivalTime", "Packets", "Flows",
			"(Flows.flowID=Packets.flowID) AND (Flows.traceID=Packets.traceID)",
			"Traces", "Traces.traceID=Flows.traceID",
			"(Flows.flowID=0 AND Traces.traceName=\"arboc\" )" , dval);
	std::cout << "max arrivalTime=" << dval << std::endl;

	return 0;
}
