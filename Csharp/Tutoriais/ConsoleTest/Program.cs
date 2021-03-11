using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleTest
{
    class Program
    {
        private static IEnumerable<string> LerArquivos()
        {
            var arquivos = from arquivo in Directory.GetFiles(@".") select arquivo;
            Thread.Sleep(5000);
            return arquivos;
        }

        static void Main(string[] args)
        {
            var items = LerArquivos();
            foreach (var item in items)
            {
                Console.WriteLine("- " + item);
            }
            Console.ReadKey();
        }
    }
}
