using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace App
{
    public partial class FormPrincipal : Form
    {
        public FormPrincipal()
        {
            InitializeComponent();
        }

        private void reportViewerButton_Click(object sender, EventArgs e)
        {
            using (var frv = new FormReportViewer())
            {
                frv.ShowDialog();
            }
        }

        private void crystalReportsButton_Click(object sender, EventArgs e)
        {
            using (var fcr = new FormCrystalReports())
            {
                fcr.ShowDialog();
            }
        }
    }
}
