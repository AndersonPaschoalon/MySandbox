using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AsyncAwait1
{
    class Toast
    {
        public bool hasButter { get; private set; }
        public bool hasJam { get; private set; }
        public bool isToasted { get; private set; }

        public Toast()
        {
            hasButter = false;
            hasJam = false;
            isToasted = false;

        }

        public int MakeToast(int n)
        {
            int nn = n / 2;
            Thread.Sleep(500 * nn);
            isToasted = true; ;
            Console.WriteLine("toasts are ready");
            return n;
        }

        void applyJam()
        {
            Thread.Sleep(500);
            hasJam = true;
        }

        void applyButter()
        {
            Thread.Sleep(500);
            hasButter = true; ;
        }

        void showToast()
        {
            Console.WriteLine("Is Toasted:" + this.isToasted);
            Console.WriteLine("Has Jam:" + this.hasJam);
            Console.WriteLine("Has Butter:" + this.hasButter);
        }

    }
}
