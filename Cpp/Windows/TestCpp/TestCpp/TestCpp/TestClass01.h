#pragma once
#include "ScriptCmd.h"

class TestClass01
{
public: 

	static void overwriteFile(const char* content);

	static void incrementFile();

	static bool fileExists(const char* filename);

	static void test_overwriteFile();

	static void test_ScriptCmd();

private:
};

