#pragma once
#include "ScriptCmd.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Exception handling test
//////////////////////////////////////////////////////////////////////////////////////////////////////////

struct test_str
{
	int a;
	int b;
};

int ex01();
int ex02();
int ex03();
int noEx();


class TestClass01
{
public: 

	static void overwriteFile(const char* content);

	static void incrementFile();

	static bool fileExists(const char* filename);

	static void test_overwriteFile();

	static void test_ScriptCmd();

	static void test_read_blocked_file();

	static void test_exception();

	static void test_scape_string();

	static std::string json_escape(const std::string& s);

	static void initJsonEscape();

	static void exception_handling_test();

	static void testFindCertificatePath();

	static std::string findCACertPath(const char* uriStr);


private:
};




