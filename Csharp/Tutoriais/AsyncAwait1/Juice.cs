using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AsyncAwait1
{
    class Juice
    {
        public Juice()
        {
        }

        public int PourJuice(int ml)
        {
            Thread.Sleep(10 * ml);
            Console.WriteLine("eggs are ready");
            return ml;
        }
    }
}
