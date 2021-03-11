using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace tutorial_log4net
{
    class Program
    {
        // private static readonly log4net.ILog log =
        //     log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        private static readonly log4net.ILog log = log4net.LogManager.GetLogger("MyFileAppender");

        private static void stressLog4net()
        {
            while (true)
            {
                log.Info("Application is working ##########################################################################################################################");
            }
        }

        static void Main(string[] args)
        {
            stressLog4net();
        }
    }
}
