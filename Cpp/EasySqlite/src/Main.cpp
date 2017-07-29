//============================================================================
// Name        : EasySqlite.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "TraceDbManager.h"
#include "Database.h"

using namespace std;

int main()
{
	Database db = Database("trace.db");

	std::string arg1 = "";
	std::string arg2 = "";
	std::string arg3 = "";
	std::string arg4 = "";
	std::list<std::string> str_list;
	std::list<double> d_list;
	std::list<int> i_list;


	printf("\n\nstr\n");

	db.get("Flows", "protocolLink", str_list );
	printList(str_list);
	str_list.clear();

	db.get_where("Flows", "protocolLink", "traceID=12" ,str_list  );
	printList(str_list);
	str_list.clear();

	db.join(arg1,arg2, arg3, arg4, str_list );
	printList(str_list);
	str_list.clear();

	printf("\n\nint\n");

	db.get("Flows", "protocolNetwork", i_list );
	printList(i_list);
	i_list.clear();

	db.get_where("Flows", "protocolNetwork", "traceID=12" , i_list );
	printList(i_list);
	i_list.clear();

	db.join(arg1,arg2, arg3, arg4, i_list );
	printList(i_list);
	i_list.clear();

	printf("\n\ndouble\n");

	db.get("Flows", "portSrc" ,d_list );
	printList(d_list);
	d_list.clear();

	db.get_where("Flows", "portSrc", "traceID=12" ,d_list );
	printList(d_list);
	d_list.clear();

	db.join(arg1,arg2, arg3, arg4, d_list );
	printList(d_list);
	d_list.clear();


	return 0;
}
