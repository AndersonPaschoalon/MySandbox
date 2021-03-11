using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ObservableCollection
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private ObservableCollection<Pessoa> pessoa;
        public MainWindow()
        {
            InitializeComponent();
            pessoa = new ObservableCollection<Pessoa>()
            {
                new Pessoa(){Nome="Macoratti",Endereco="Rua Projetada 100"},
                new Pessoa(){Nome="Jefferson",Endereco="Rua Mexico, 34"},
                new Pessoa(){Nome="Miriam",Endereco="Av. Brasil, 200"}
            };
            lstNomes.ItemsSource = pessoa;
        }

        private void btnNomes_Click(object sender, RoutedEventArgs e)
        {
            pessoa.Add(new Pessoa()
            {
                Nome = txtNome.Text,
                Endereco = txtEndereco.Text
            });
            txtNome.Text = string.Empty;
            txtEndereco.Text = string.Empty;
        }
    }
}
