using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClassLibrary2
{
    public class Class2
    {
        public const String CONST1 = "const 1 !!!";
        private String var1;

        public Class2()
        {
            this.var1 = "AAAAAAAAAAA";
        }

        public void printfClass1()
        {
            Console.WriteLine("Hello: " + this.var1);
        }

        public void runForm()
        {
            const string message =
                "Are you sure that you would like to close the form?";
            const string caption = "Form Closing";
            var result = MessageBox.Show(message, caption,
                                         MessageBoxButtons.YesNo,
                                         MessageBoxIcon.Question);
        }
    }
}
