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

namespace Test_Tasks
{
    public partial class Form1 : Form
    {
        CancellationTokenSource cancelToken; 

        public Form1()
        {
            this.cancelToken = new CancellationTokenSource();
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            List<Fruta> frutas = new List<Fruta>();
            frutas.Add(new Fruta { nome = "Abacaxi", casaDoBobEsponja=true, cor="amarillo", quantidade=15, textura="espiñoso"});
            frutas.Add(new Fruta { nome = "Banana", casaDoBobEsponja=false, cor="amarillo", quantidade=10, textura="mollenga"});
            frutas.Add(new Fruta { nome = "Carambola", casaDoBobEsponja=false, cor="amarillo", quantidade=12, textura="duro-mole"});

            //var ppp = frutas.FirstOrDefault(xyntia => xyntia.nome == "Abacaxi");
            var ppp = frutas.FirstOrDefault(xyntia => xyntia.nome == "avocado");


            int? t = ppp?.quantidade;
            Progress<Queue<Fruta>> formProgress = new Progress<Queue<Fruta>>(x => 
            {
                var fff = x.Dequeue();
                if (fff.cor == "berde")
                {
                    this.BackColor = Color.Lime;
                }
                else
                {
                    this.BackColor = Color.Gold;
                }
                this.richTextBox1.Text += fff.nome + "\n";
            });
            //this.cancelToken.
            //this.myFirstTaskTest();
            //this.mySecondTaskTest(this.cancelToken.Token, formProgress); **ERROR
            MessageBox.Show("fim do Form1_Load");
        }

        private async void myFirstTaskTest()
        {
            await Task.Factory.StartNew(() =>
            {
                Thread.Sleep(15000);
                MessageBox.Show("Fim do sleep!!!!");
            });

            MessageBox.Show("OI!!!!");
        }

        private async void mySecondTaskTest(CancellationToken token, IProgress<Fruta> progress)
        {
            var val = await Task<int>.Factory.StartNew(() =>
            {
                int a = 2; 
                int b = 3;
                for (int i = 0; i < 10; i++)
                {
                    Fruta f = new Fruta { quantidade = i, cor= (i< 5)?"berde":"amarillo", nome="abacaxi", casaDoBobEsponja=true, textura="espiñento"};
                    progress.Report(f);
                    if (token.IsCancellationRequested)
                    {
                        return 0;
                    }
                    Thread.Sleep(5000);
                }
                
                return a + b;
            }, 
            token);

            MessageBox.Show(val.ToString());

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.cancelToken.Cancel();
        }
    }
}
