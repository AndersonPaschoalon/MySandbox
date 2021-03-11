using System;
using System.Collections.Generic;
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
using System.IO;
using System.Threading;
using System.Diagnostics;


namespace Tutorial_WpfTask
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private async void btnLerArquivos_Click(object sender, RoutedEventArgs e)
        {
            btnLerArquivos.IsEnabled = false;
            var sw = new Stopwatch();
            sw.Start();
            //lbArquivos.ItemsSource = LerArquivos();
            lbArquivos.ItemsSource = await TestProcess.AsycnLerArquivos();
            sw.Stop();
            lblmsg.Content = "Tempo Gasto (ms) : \n" + sw.ElapsedMilliseconds.ToString();
            btnLerArquivos.IsEnabled = true;
        }

        private void btnExibirDataHora_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Hora Data e Hora Atual  :\n " + DateTime.Now.ToShortDateString() + " - " +
                DateTime.Now.ToLongTimeString());
        }

        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {
            TestProcess.cancelProcess();
        }

        private async void btnLerArquivos2_Click(object sender, RoutedEventArgs e)
        {
            btnLerArquivos2.IsEnabled = false;
            var sw = new Stopwatch();
            sw.Start();
            lbArquivos.ItemsSource = await TestProcess.AsycnLerArquivos2();
            sw.Stop();
            lblmsg.Content = "Tempo Gasto (ms) : \n" + sw.ElapsedMilliseconds.ToString();
            btnLerArquivos2.IsEnabled = true;
        }

        private void btnLerArquivos_Click_1(object sender, RoutedEventArgs e)
        {

        }
    }
}
