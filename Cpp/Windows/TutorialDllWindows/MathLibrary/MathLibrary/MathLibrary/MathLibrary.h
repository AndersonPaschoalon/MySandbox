// MathLibrary.h - Contains declarations of math functions
#pragma once

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MATHLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MATHLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

/* TUTORIAL
Quando a macro MATHLIBRARY_EXPORTS é definida, a macro MATHLIBRARY_API define o modificador 
__declspec(dllexport) nas declarações da função.Esse modificador instrui o compilador e o 
vinculador a exportar uma função ou variável da DLL para uso por outros aplicativos. 
Quando MATHLIBRARY_EXPORTS está indefinido, por exemplo, quando o arquivo de cabeçalho é 
incluído por um aplicativo cliente, MATHLIBRARY_API aplica o modificador __declspec(dllimport)
às declarações.Esse modificador otimiza a importação da função ou variáveis em aplicativos.
*/

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

///////////////////////////////////////////////////////////////////////////////
// CLASSES
///////////////////////////////////////////////////////////////////////////////

// This class is exported from the dll
class MATHLIBRARY_API CMathLibrary {
public:
	CMathLibrary(void);
	// TODO: add your methods here.
};

///////////////////////////////////////////////////////////////////////////////
// VARIABLES
///////////////////////////////////////////////////////////////////////////////

extern MATHLIBRARY_API int nMathLibrary;

///////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
///////////////////////////////////////////////////////////////////////////////

MATHLIBRARY_API int fnMathLibrary(void);


// The Fibonacci recurrence relation describes a sequence F
// where F(n) is { n = 0, a
//               { n = 1, b
//               { n > 1, F(n-2) + F(n-1)
// for some initial integral values a and b.
// If the sequence is initialized F(0) = 1, F(1) = 1,
// then this relation produces the well-known Fibonacci
// sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" MATHLIBRARY_API void fibonacci_init(
	const unsigned long long a, const unsigned long long b);

// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" MATHLIBRARY_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned fibonacci_index();

extern "C" MATHLIBRARY_API void getHostNameTest(char* outStr, int outStrLen);


