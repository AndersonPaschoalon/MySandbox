using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using ReactiveUI.Fody.Helpers;

namespace Form_SelectFileDialogAvalonia
{
    public class MainWindowViewModel
    {

        public MainWindowViewModel()
        {
            this.model = new MeuModel();
            this.model.meuTexto = "meu texto :D";
            this.minhaTarefa = new ExecutarTarefa(this.model);
            this.onClickButtonOi = this.minhaTarefa;
        }

        public ExecutarTarefa minhaTarefa { get; set; }

        public ICommand onClickButtonOi { get; set; }

        public MeuModel model { get; set; }

    }
}
