using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Form_SelectFileDialogAvalonia
{
    public class ExecutarTarefa : ICommand
    {
        public ExecutarTarefa(MeuModel customText)
        {
            this.model = customText;
        }

        public event EventHandler? CanExecuteChanged;
        public MeuModel model { get; set; }

        public bool CanExecute(object? parameter)
        {
            return true;
        }

        public void Execute(object? parameter)
        {
            Random r = new Random();
            int num = r.Next(4);
            this.model.meuTexto = num.ToString();
            Console.WriteLine("SUCESSO!");
        }
    }
}
