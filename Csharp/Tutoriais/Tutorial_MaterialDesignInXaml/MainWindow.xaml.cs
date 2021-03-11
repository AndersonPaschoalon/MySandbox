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
using System.Windows.Media.Animation;

using Tutorial_MaterialDesignInXaml.Objects;

namespace Tutorial_MaterialDesignInXaml
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private HamburgerManuState hamburger;
        public MainWindow()
        {
            this.hamburger = new HamburgerManuState();
            InitializeComponent();
        }

        private void ButtonMenu_Click(object sender, RoutedEventArgs e)
        {
            Storyboard sb;
            if (this.hamburger.isClosed)
            {
                sb = this.FindResource("OpenMenu") as Storyboard;
            }
            else
            {
                sb = this.FindResource("CloseMenu") as Storyboard;
            }
            sb.Begin();
            this.hamburger.isClosed = !this.hamburger.isClosed;
        }
    }
}
