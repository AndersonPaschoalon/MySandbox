// TestCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestClass01.h"

int main()
{
    bool test01 = false;
    bool test02 = true;
    bool test03 = true;
    bool test04 = true;
    bool test05 = true;
    bool test06 = true;
    bool test07 = true;
    bool test08 = true;

    if (test01) TestClass01::test_overwriteFile();
    if (test02) TestClass01::incrementFile();

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
