using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        Form2 f = null;
        TabPage tb1 = null;
        TabPage tb2 = null;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // hide tabs
            this.tabControl1.Appearance = TabAppearance.FlatButtons;
            this.tabControl1.ItemSize = new System.Drawing.Size(0, 1);
            this.tabControl1.SizeMode = TabSizeMode.Fixed;

            button1.Enabled = false;
            tabControl1.TabPages.Remove(tabPage1);
            tabControl1.TabPages.Remove(tabPage2);

            // start background worker
            button1.Enabled = true;
            button2.Enabled = false;
            backgroundWorker1.RunWorkerAsync();
            
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            
            int length = 100;
            String texto = "OI";
            for (int i = 0; i < length; i++)
            {
                if (this.backgroundWorker1.CancellationPending == true)
                {
                    if (i > 10)
                    {
                        i = 0;
                        e.Cancel = true;
                        Thread.Sleep(1000);
                        break;
                    }
                }
                Thread.Sleep(1000);
                if ((i % 10) == 0)
                {
                    texto = ">> Divisivel por 10:  " + i;

                }
                else
                {
                    texto = "<< Não divisivel por 10 " + i;

                }
                backgroundWorker1.ReportProgress(i, texto);
            }

        }

        private void backgroundWorker1_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            this.progressBar1.Value = e.ProgressPercentage;
            this.label1.Text = e.UserState.ToString();
            if ((e.ProgressPercentage % 10) == 0)
            {
                tabControl1.TabPages.Add(tabPage1);
                tabControl1.TabPages.Remove(tabPage2);
            }
            else
            {
                tabControl1.TabPages.Remove(tabPage1);
                if (!tabControl1.TabPages.Contains(tabPage2))
                {
                    tabControl1.TabPages.Add(tabPage2);
                }
            }
        }

        private void backgroundWorker1_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            MessageBox.Show("Processo finalizado com status de : " + 
                ((e.Cancelled == true) ? "CANCELADO" : "FINALIZADO COM SUCCESO"));
            if (f!=null)
            {
                f.Close();
            }

            f = null;
            button2.Enabled = true;
            button1.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.backgroundWorker1.CancelAsync();
            f = new Form2();
            f.ShowDialog();
            
            

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //button1.Enabled = true;
            //button2.Enabled = false;
            //backgroundWorker1.RunWorkerAsync();
        }
    }
}
