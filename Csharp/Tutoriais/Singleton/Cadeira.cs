using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    class Cadeira
    {
        private static Cadeira theCadeira = null;
        public int Quantidade { get; set; }

        private Cadeira() { }

        public static Cadeira getInstance()
        {
            if (Cadeira.theCadeira == null)
            {
                Cadeira.theCadeira = new Cadeira();
            }
            return Cadeira.theCadeira;

        }
    }
}
