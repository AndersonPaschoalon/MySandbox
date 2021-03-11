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
    public partial class FormReportViewer : Form
    {
        public FormReportViewer()
        {
            InitializeComponent();
        }

        private void FormReportViewer_Load(object sender, EventArgs e)
        {
            this.reportViewer1.LocalReport.ReportPath = "RelatorioPessoa.rdlc";
            this.reportViewer1.LocalReport.DataSources.Add(new Microsoft.Reporting.WinForms.ReportDataSource("DataSetPessoa", Biblioteca.Pessoa.RetornaListaExemplo()));
            this.reportViewer1.RefreshReport();
        }
    }
}
