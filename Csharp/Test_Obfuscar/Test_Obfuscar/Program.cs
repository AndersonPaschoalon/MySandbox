using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibrary1;
using ClassLibrary2;

namespace Test_Obfuscar
{

    class Program
    {
        static void Main(string[] args)
        {
            Class1 c1 = new Class1();
            Class2 c2 = new Class2();
            c1.printfClass1();
            c1.runForm();
            c2.printfClass1();
            c2.runForm();
            Console.WriteLine("PRESS ANY KEY");
            Console.ReadKey();


        }
    }
}
