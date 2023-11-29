using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MarshallingTest
{
    using System;
    using System.Runtime.InteropServices;

    public class CppDllTestWrapper
    {
        const string DllName = "CppDllTest.dll";

        // Import functions from the C++ DLL
        [DllImport(DllName, CharSet = CharSet.Ansi, EntryPoint = "testDllPrint")]
        public static extern int testDllPrint();

        [DllImport(DllName, CharSet = CharSet.Ansi, EntryPoint = "testDllSumm")]
        public static extern int testDllSumm(int a, int b);

        [DllImport(DllName, CharSet = CharSet.Ansi, EntryPoint = "printStruct")]
        public static extern int printStruct(IntPtr stru);

        [DllImport(DllName, CharSet = CharSet.Ansi, EntryPoint = "allocStruct")]
        public static extern int allocStruct(ref IntPtr stru);

        [DllImport(DllName, CharSet = CharSet.Ansi, EntryPoint = "changeStruct")]
        public static extern int changeStruct(ref IntPtr stru);

        [DllImport(DllName, CharSet = CharSet.Ansi, EntryPoint = "freeStruct")]
        public static extern int freeStruct(ref IntPtr stru);

        public static void PrintStruct(MyStruct stru)
        {
            Console.WriteLine($"IntValue: {stru.intValue}");
            Console.WriteLine($"StringValue: {stru.str}");
            Console.WriteLine($"FloatValue: {stru.floatValue}");
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct MyStruct
    {
        public int intValue;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string str;
        public float floatValue;
    }

}
