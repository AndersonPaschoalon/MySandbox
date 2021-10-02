#include "pch.h"

#include "CppClassLibrary.h"

void CppClassLibrary::MyClasss::test()
{
	String^ s = "Hello #2";
	Console::WriteLine(s);
	//throw gcnew System::NotImplementedException();
}
