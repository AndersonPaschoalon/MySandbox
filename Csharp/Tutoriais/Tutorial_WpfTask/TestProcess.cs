using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.IO;

namespace Tutorial_WpfTask
{
    class TestProcess
    {
        private static CancellationTokenSource cancellationTokenSource;

        public static IEnumerable<string> LerArquivos()
        {
            var arquivos = from arquivo in Directory.GetFiles(@".") select arquivo;
            Thread.Sleep(5000);
            return arquivos;
        }

        public static Task<IEnumerable<string>> AsycnLerArquivos()
        {
            return Task.Run( () => {
                return TestProcess.LerArquivos();
            });
        }


        public static IEnumerable<string> LerArquivos2(CancellationToken cancellationToken)
        {
            bool isCanceled = false;
            var arquivos = from arquivo in Directory.GetFiles(@".") select arquivo;
            for (int i = 0; i < 10; i++)
            {
                if (cancellationToken.IsCancellationRequested)
                {
                    isCanceled = true;
                    break;
                }
                Thread.Sleep(1000);   
            }
            if (isCanceled)
            {
                Console.WriteLine("Operation was cancelled!");
                IEnumerable<string> emptyList = Enumerable.Empty<string>();
                emptyList = emptyList.Append("Cancelled!");
                return emptyList;
            }
            Console.WriteLine("Operation NOT cancelled!");
            return arquivos;
        }

        public static Task<IEnumerable<string>> AsycnLerArquivos2()
        {
            TestProcess.cancellationTokenSource = new CancellationTokenSource();
            return Task.Run(() => {
                return TestProcess.LerArquivos2(cancellationTokenSource.Token);
            });
        }

        public static void cancelProcess()
        {
            if (cancellationTokenSource != null)
            {
                cancellationTokenSource.Cancel();
            }
        }

    }
}
