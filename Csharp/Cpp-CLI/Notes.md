### What is C++/CLI

* Is a c++ version with acess to the .Net world

* this lnaguage can have c++ and .net objects

    *   new for c++ objects

    *   gcnew for .net objects


* C# can make functio calls, but has data types related issues

    * char? struct?  ref? array?

    * they have the same keyword, but are DIFFERENT THINGS. C++ things are on the OS, and C# objects are on the RUNTIME. 


* C++/CLI: Common language infrastructure

* Can access both C++ (OS) and .Net objects

    * new for C++ objects

    * gcnew for .Net objects

    * it is a C#-C++ "bridge" language


* projetos precisam ser configurados para a mesma CPU

Solution Properties > Configuration properties > Configuration > 

* ^ represetns a .net object

* ref before class indicate that the class belongs to .Net framework.

* Handle:

String^ s;
s = gcnew String("Hello World")

* Tracking reference String^**%** s 


* Class as a "value: MyClass my_class"
- Stack based value: Handle: **%**

* Conversion to value: *

* Unboxing: safe_cast<int^>(int_obj)

* Conversions

char* -> String                 gcnew String(...)
String -> char                  using System::Runtime::InteropServices;
                                Marshal::StringToHGlobalAnsi(...)
String -> wchar_t*              Marshal::StrignToHGlobalUni(...)

Native Array -> Managed Array   Marshal::Copy(...)
Managed Array -> Native Array   Marshal::FreeHGlobal(...)





