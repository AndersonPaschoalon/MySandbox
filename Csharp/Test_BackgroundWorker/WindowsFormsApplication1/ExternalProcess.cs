using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class ExternalProcess
    {
        public struct ProcessStatus
        {
            public int p1;
            public int sleep;
            public String msg;

        }

        private int p1;
        private int sleep;
        private String msg;
        private bool killFlag;

        public ExternalProcess(int p1Val, int sleepVal)
        {
            this.killFlag = false;
            this.p1 = p1Val;
            this.sleep = sleepVal;
            this.msg = "";
        }

        public int run(String str, out ProcessStatus status)
        {
            status = new ProcessStatus();
            this.setStatus(ref status);
            this.msg = str;
            for (int i = 0; i < this.p1; i++ )
            {
                this.setStatus(ref status);
                if (this.killFlag)
                {
                    this.cancel();
                    this.setStatus(ref status);
                    break;
                }
                this.msg = "Starting Sleep...";
                Thread.Sleep(500 * this.sleep);

                this.setStatus(ref status);
                if (this.killFlag)
                {
                    this.cancel();
                    this.setStatus(ref status);
                    break;
                }
                this.msg = "Ending Sleep...";
                Thread.Sleep(500 * this.sleep);
            }
            return 0;
        }


        private void  cancel()
        {
            this.msg = "Cancell Proc...";
            Thread.Sleep(2000);
        }

        private void setStatus(ref ProcessStatus status)
        {
            //status = new ProcessStatus();
            status.msg = this.msg;
            status.p1 = this.p1;
            status.sleep = this.sleep;
        }

    }
}
