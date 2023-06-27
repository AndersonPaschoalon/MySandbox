// TestCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestClass01.h"

int main()
{
    bool test01 = false;
    bool test02 = false;
    bool test03 = false;
    bool test04 = false;
    bool test05 = false;
    bool test06 = false;
    bool test07 = false;
    bool test08 = false;
    bool test09 = true;

    if (test01) TestClass01::test_overwriteFile();
    if (test02) TestClass01::incrementFile();
    if (test03) TestClass01::test_ScriptCmd();
    if (test04) TestClass01::test_read_blocked_file();
    if (test05) TestClass01::test_exception();
    if (test06) TestClass01::test_scape_string();
    if (test09) TestClass01::exception_handling_test();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
