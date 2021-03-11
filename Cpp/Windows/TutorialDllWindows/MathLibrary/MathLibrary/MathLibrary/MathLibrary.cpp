// MathLibrary.cpp : Defines the exported functions for the DLL.
//
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <stdio.h>
#include <utility>
#include <limits.h>
#include "MathLibrary.h"
//#include "Winsock.h"
#include "Winsock2.h"


#define INFO_BUFFER_SIZE 32767


//
// VARIABLES
//

// This is an example of an exported variable
MATHLIBRARY_API int nMathLibrary=0;
// DLL internal state variables:
static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position

//
// FUNCTIONS
//


// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
void fibonacci_init(
	const unsigned long long a,
	const unsigned long long b)
{
	index_ = 0;
	current_ = a;
	previous_ = b; // see special case when initialized
}

// Produce the next value in the sequence.
// Returns true on success, false on overflow.
bool fibonacci_next()
{
	// check to see if we'd overflow result or position
	if ((ULLONG_MAX - previous_ < current_) ||
		(UINT_MAX == index_))
	{
		return false;
	}

	// Special case when index == 0, just return b value
	if (index_ > 0)
	{
		// otherwise, calculate next sequence value
		previous_ += current_;
	}
	std::swap(current_, previous_);
	++index_;
	return true;
}

// Get the current value in the sequence.
unsigned long long fibonacci_current()
{
	return current_;
}

// Get the current index position in the sequence.
unsigned fibonacci_index()
{
	return index_;
}

// This is an example of an exported function.
MATHLIBRARY_API int fnMathLibrary(void)
{
    return 0;
}

MATHLIBRARY_API void getHostNameTest(char* outStr, int outStrLen)
{
	//TCHAR  infoBuf[INFO_BUFFER_SIZE];
	//DWORD  bufCharCount = INFO_BUFFER_SIZE;
	//char name[500];
	//int  namelen = 500;
	//int gethoostret =  gethostname(name, namelen);
	//printf("> name:%s\n", name);
	//printf("> gethoostret:%d\n", gethoostret);

	TCHAR szBuffer[256];
	DWORD dwSize = 256;
	GetComputerName(szBuffer, &dwSize); //Get the computer name
	for (int i = 0; i < dwSize; i++)
	{
		if ( i > outStrLen)
		{
			break;
		}
		else
		{
			outStr[i] = szBuffer[i];
		}
	}
	printf("outStr[] = %s\n", outStr);
}


//
// CLASSES IMPLEMENTATIONS
//

// This is the constructor of a class that has been exported.
CMathLibrary::CMathLibrary()
{
    return;
}

