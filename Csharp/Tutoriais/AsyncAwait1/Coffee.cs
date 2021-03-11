using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;


namespace AsyncAwait1
{
    public class Coffee
    {
        public Coffee()
        { 
        }

        public int PoorCoffe(int ml)
        {
            Thread.Sleep(ml*10);
            Console.WriteLine("coffee is ready");
            return ml;

        }
    }
}
