using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AsyncAwait1
{

    public class Egg
    {
        public Egg()
        {
        }

        public int FryEgg(int n)
        {
            Thread.Sleep(1000*n);
            Console.WriteLine("eggs are ready");
            return n;
        }

        async Task<Egg> FryEggTask(int n)
        {
            this.FryEgg(n);
            return this;
        }
    }
}
