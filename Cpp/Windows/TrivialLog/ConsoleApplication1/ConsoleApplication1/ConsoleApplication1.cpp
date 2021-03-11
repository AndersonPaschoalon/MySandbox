// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "TrivialLog.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	TrivialLog log = TrivialLog("sample.log");
	char str[] = "asfdasfsfasdfasdfdasfd";
	int a = 10;
	long int b = 12;
	log.debug("str:%s, a:%d, b:%ld", str, a, b);
	TrivialLog::echo("str:%s, a:%d, b:%ld", str, a, b);
	//TrivialLog::setStaticLogFile("setStaticLogFile.log");
	//TrivialLog::echo("str:%s, a:%d, b:%ld", str, a, b);
	return 0;
}

