using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AsyncAwait1
{
    public class Bacon
    {
        public Bacon()
        {
        }

        public int FryBacon(int n)
        {
            Thread.Sleep(2000*n);
            Console.WriteLine("eggs are ready");
            return n;

        }
    }
}
