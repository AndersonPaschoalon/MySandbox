using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    class Program
    {
        static void Main(string[] args)
        {
            // Colocando em prática
            Cadeira _cadeira1 = Cadeira.getInstance();
            _cadeira1.Quantidade = 1;

            Cadeira _cadeira2 = Cadeira.getInstance();
            _cadeira2.Quantidade = 5;

            Console.WriteLine(_cadeira1.Quantidade.ToString());
            Console.WriteLine(_cadeira2.Quantidade.ToString());
            Console.ReadLine();
        }
    }
}
