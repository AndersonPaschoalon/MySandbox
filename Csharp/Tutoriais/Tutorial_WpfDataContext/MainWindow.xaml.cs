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

namespace Tutorial_WpfDataContext
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Employee P = new Employee("(M)Hello World");
            P.State = "(M)MD";
            AnotherClass c = new AnotherClass();
            c.EmployeeNameTest = P;
            c.AnotherField = "(M)Another Value";
            this.DataContext = c;
            Employee gridEm = new Employee("(G)GridContext");
            gridEm.State = "(G)gridEm.State";
            this.MainGrid.DataContext = gridEm;
        }
    }
}
