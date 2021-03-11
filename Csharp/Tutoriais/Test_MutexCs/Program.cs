using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_MutexCs
{
    class Program
    {
        static void Main(string[] args)
        {
            int stime = 2;
            RunThread r = new RunThread(stime, 1000);
            r.runThread(stime);
            Console.ReadKey();
        }
    }
}
