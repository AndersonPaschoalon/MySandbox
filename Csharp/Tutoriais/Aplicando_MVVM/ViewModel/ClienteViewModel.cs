using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using Aplicando_MVVM.Model;

namespace Aplicando_MVVM.ViewModel
{
    class ClienteViewModel
    {
        public ObservableCollection<Cliente> Clientes { get; set; }

        public void LoadClientes()
        {
            ObservableCollection<Cliente> clientes = new ObservableCollection<Cliente>();

            clientes.Add(new Cliente { Nome = "Macoratti", Email = "macoratti@yahoo.com" });
            clientes.Add(new Cliente { Nome = "Janice", Email = "janice@bol.com.br" });
            clientes.Add(new Cliente { Nome = "Jefferson", Email = "jeff@uol.com.br" });
            clientes.Add(new Cliente { Nome = "Jessica", Email = "jessica@net.com" });
            clientes.Add(new Cliente { Nome = "Miriam", Email = "mimi@uol.com.br" });

            Clientes = clientes;
        }
    }
}
