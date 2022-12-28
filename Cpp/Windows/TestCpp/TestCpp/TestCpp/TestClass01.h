#pragma once
#include "ScriptCmd.h"

// json scapes
//extern std::string escapes[1024];
//extern bool initEscapes;

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

private:
};




