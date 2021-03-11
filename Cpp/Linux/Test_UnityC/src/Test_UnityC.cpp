//============================================================================
// Name        : Test_UnityC.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "unity.h"

using namespace std;

// tests
void test_test01();
void test_test02();

// aux functions
int retVal(int val);

int main() {
	cout << "UNITY C TESTS" << endl;
	UNITY_BEGIN();
	RUN_TEST(test_test01);
	RUN_TEST(test_test02);
	return UNITY_END();
}

// tests

void test_test01()
{
	TEST_ASSERT_EQUAL_INT(12, retVal(12));
}

void test_test02()
{
	TEST_ASSERT_EQUAL_INT(15, retVal(12));
}

// aux functions

int retVal(int val)
{
	return val;
}

