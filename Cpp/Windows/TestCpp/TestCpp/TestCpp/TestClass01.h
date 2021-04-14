#pragma once
class TestClass01
{
public: 
	static void overwriteFile(const char* content);
	static void incrementFile();
	static bool fileExists(const char* filename);

	static void test_overwriteFile();

private:
};

