/*
 * cfunctions.h
 *
 *  Created on: 25 de abr de 2017
 *      Author: anderson
 */

#ifndef CFUNCTIONS_H_
#define CFUNCTIONS_H_

#include <iostream>
#include <string.h>
#include <string>
#include <list>

#define CHAR_BUFFER 120

using std::list;
using std::string;
using std::cout;
using std::endl;

void charvet2type(const char* vetc, string& s);
void charvet2type(const char* vetc, unsigned int& v);
void charvet2type(const char* vetc, unsigned long int& v);

/**
 *
 */
void string2charvet(const string s, char* vetc);

/**
 *
 */
void charvet2type(const char* vetc, int& v);

/***
 *
 */
void charvet2type(const char* vetc, long int& v);

/**
 *
 */
void charvet2type(const char* vetc, double& v);

/**
 *
 */
void charvet2type(const char* vetc, list<double>& theList);

/**
 *
 */
void charvet2type(const char* vetc, list<int>& theList);

/**
 *
 */
void charvet2type(const char* vetc, list<long int>& theList);

/**
 *
 */
template<typename T>
void printList(list<T>& theList);

/**
 *
 */
bool delimiter(char c);

/**
 *
 */
bool delimiter(char c, const char& d);

/***********************/
bool test_delimiter();
bool test_charvet2type();

#endif /* CFUNCTIONS_H_ */
