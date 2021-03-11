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
    public partial class FormCrystalReports : Form
    {
        public FormCrystalReports()
        {
            InitializeComponent();
            var report = new CrystalDecisions.CrystalReports.Engine.ReportDocument();
            report.Load("RelatorioPessoa.rpt");
            report.SetDataSource(Biblioteca.Pessoa.RetornaListaExemplo());
            crystalReportViewer1.ReportSource = report;
            crystalReportViewer1.Refresh();
        }
    }
}
