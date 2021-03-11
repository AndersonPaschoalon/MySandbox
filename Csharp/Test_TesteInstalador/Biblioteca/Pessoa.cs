using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Biblioteca
{
    public class Pessoa
    {
        public int Id { get; set; }
        public string Nome { get; set; }
        public string Sobrenome { get; set; }

        public static IEnumerable<Pessoa> RetornaListaExemplo()
        {
            return new List<Pessoa>()
            {
                new Pessoa() { Id = 1, Nome = "André", Sobrenome = "Lima" },
                new Pessoa() { Id = 2, Nome = "Fulano", Sobrenome = "de Tal" },
                new Pessoa() { Id = 3, Nome = "Beltrano", Sobrenome = "da Silva" },
                new Pessoa() { Id = 4, Nome = "Zé", Sobrenome = "Ninguém" },
            };
        }
    }
}
