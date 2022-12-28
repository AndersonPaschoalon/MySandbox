using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ReactiveUI;
using ReactiveUI.Fody.Helpers;

namespace Form_SelectFileDialogAvalonia
{
    public class MeuModel: ReactiveObject
    {

        [Reactive]
        public string meuTexto { get; set; }


    }
}
