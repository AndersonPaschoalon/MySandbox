using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tutorial_MyCalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            /*
            int firstNumber = 0;
            int secondNumber = 0;
            if (string.IsNullOrEmpty(this.textBox1.Text))
            {
                MessageBox.Show("Enter First Number");
            }
            else
            {
                firstNumber = Convert.ToInt32(this.textBox2.Text);
            }
            if (string.IsNullOrEmpty(this.textBox2.Text))
            {
                MessageBox.Show("Enter Second Number");
            }
            else
            {
                secondNumber = Convert.ToInt32(this.textBox2.Text);
            }
            int result = firstNumber + secondNumber;
            resultBox.Text = "Result is " + result.ToString();
            resultBox.ForeColor = (result < 0) ? System.Drawing.Color.Red : System.Drawing.Color.Blue;
            */
            resultBox.Text = "0";
            resultBox.ForeColor = System.Drawing.Color.Gray;  

        }

        private void label1_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("label1_Click");
        }

        private void label3_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("label3_Click");
        }

        private void button1_Click(object sender, EventArgs e)
        {
           int val1 = Convert.ToInt32(String.IsNullOrEmpty(this.textBox1.Text) ? "0": this.textBox1.Text);
           int val2 = Convert.ToInt32(String.IsNullOrEmpty(this.textBox2.Text) ? "0" : this.textBox2.Text);
           int result = val1 + val2;
           resultBox.Text = result.ToString();
           resultBox.ForeColor = (result < 0) ? System.Drawing.Color.Red : (  
               (result > 0) ? System.Drawing.Color.Blue: System.Drawing.Color.Gray);
           MessageBox.Show("Result is " + resultBox.Text);
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click_1(object sender, EventArgs e)
        {

        }
    }
}
