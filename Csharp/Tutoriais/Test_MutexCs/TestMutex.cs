using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_MutexCs
{
    public class TestMutex
    {
        private static readonly Mutex mut = new Mutex();
        private String a;
        private int b;
        private int n;

        public TestMutex(int n)
        {
            a = "";
            b = 0;
            this.n = n;
        }

        public String getA()
        {
            String temp = "";
            TestMutex.mut.WaitOne();
            try
            {
                temp = this.a;
            }
            finally
            {
                TestMutex.mut.ReleaseMutex();
            }
            return temp;
        }

        public int getB()
        {
            int temp = 0;
            TestMutex.mut.WaitOne();
            try
            {
                temp = this.b;
            }
            finally
            {
                TestMutex.mut.ReleaseMutex();
            }
            return temp;
        }

        public void setA(String inA)
        {
            TestMutex.mut.WaitOne();
            try
            {
                this.a = inA;
            }
            finally
            {
                TestMutex.mut.ReleaseMutex();
            }

        }

        public void setB(int inB)
        {
            TestMutex.mut.WaitOne();
            try
            {
                this.b = inB;
            }
            finally
            {
                TestMutex.mut.ReleaseMutex();
            }
        }


        public bool run(int sleep)
        {
            int i = 0 ;
            for (i = 0; i < this.n; i++ )
            {
                Console.WriteLine();
                Console.WriteLine("-- iter i:" + i + " start " + "sleep:" + (int)sleep/2);
                Thread.Sleep((int) sleep/2);
                this.setA(this.getA() + "a");
                this.setB(this.getB() + 1);
                Console.WriteLine();
                Console.WriteLine("-- iter i:" + i + " end " + "sleep:" + (int)sleep/2);
                Thread.Sleep((int) sleep/2);
            }
            return true;
        }
    }
}
