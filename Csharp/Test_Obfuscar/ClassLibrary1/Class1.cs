using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClassLibrary1
{
    public class Class1
    {
        public const String CONST1 = "ABACATE";
        private String var1;

        public Class1()
        {
            this.var1 = "BANANA";
        }

        public void printfClass1()
        {
            Console.WriteLine("FRUTA: " + this.var1);
        }

        public void runForm()
        {
            const string message =
                "CARAMBOLA";
            const string caption = "DAMASCO";
            var result = MessageBox.Show(message, caption,
                                         MessageBoxButtons.YesNo,
                                         MessageBoxIcon.Question);
        }
    }
}
