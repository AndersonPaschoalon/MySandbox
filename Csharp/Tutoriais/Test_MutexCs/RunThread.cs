using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_MutexCs
{
    public class RunThread
    {
        TestMutex tm = new TestMutex(0);
        bool isFinished = false;
        int threadSleep;
        int iter;

        public RunThread(int theThreadSleep, int n)
        {
            this.iter = n;
            this.tm = new TestMutex(n);
            this.threadSleep = theThreadSleep;
        }

        public void runThread(int sleep)
        {
            Thread threadProcess = new Thread(new ThreadStart(this.runThreadMethod));
            threadProcess.IsBackground = true;
            threadProcess.Start();
            for (int i = 0; i < this.iter + 200; i++)
            {
                Console.WriteLine("# Thread logger");
                Console.WriteLine("# tm.getA:" + this.tm.getA());
                Console.WriteLine("# tm.getB:" + this.tm.getB());
                if ((this.tm.getB() % 4) == 0)
                {
                    this.tm.setB(this.tm.getB() + 2);
                    this.tm.setA(this.tm.getA() + "cc");
                }
                if (this.isFinished)
                {
                    Console.WriteLine("# Thread has ended");
                    break;
                }
                Console.WriteLine("# sleep for " + sleep + "ms");
                Thread.Sleep(sleep);
            }
        }

        private void runThreadMethod()
        {
            this.isFinished = this.tm.run(this.threadSleep);
        }
    }

}
