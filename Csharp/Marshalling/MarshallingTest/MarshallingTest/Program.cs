using System;
using System.Runtime.InteropServices;

namespace MarshallingTest
{
    class Program
    {
        static void Main(string[] args)
        {
            IntPtr stru = IntPtr.Zero;

            Console.WriteLine("-- testDllPrint");
            CppDllTestWrapper.testDllPrint();

            Console.WriteLine("-- testDllSumm");
            int result = CppDllTestWrapper.testDllSumm(7, 3);
            Console.WriteLine("Sum result is " + result);

            Console.WriteLine("-- allocStruct");
            CppDllTestWrapper.allocStruct(ref stru);

            Console.WriteLine("-- printStruct");
            CppDllTestWrapper.PrintStruct(Marshal.PtrToStructure<MyStruct>(stru));

            Console.WriteLine("-- changeStruct");
            CppDllTestWrapper.changeStruct(ref stru);

            Console.WriteLine("-- printStruct");
            CppDllTestWrapper.PrintStruct(Marshal.PtrToStructure<MyStruct>(stru));

            Console.WriteLine("-- freeStruct");
            CppDllTestWrapper.freeStruct(ref stru);

            Console.WriteLine("-- execution finished!");
        }
    }
}
