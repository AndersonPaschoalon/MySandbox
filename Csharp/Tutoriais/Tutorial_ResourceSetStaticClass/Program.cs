using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Resources;
using System.IO;

namespace Tutorial_ResourceSetStaticClass
{

    class Program
    {
        static void Main(string[] args)
        {
            //String en = Tutorial_ResourceSetStaticClass.Properties.Resources.bundle_en;
            //ResXResourceSet resxSet = new ResXResourceSet(en);
            //Console.WriteLine("Val:" + resxSet.GetString("btn_cancel"));

            byte[] en = Encoding.ASCII.GetBytes(Tutorial_ResourceSetStaticClass.Properties.Resources.bundle_en);
            ResXResourceSet resxSet = new ResXResourceSet(new MemoryStream(en));
            Console.WriteLine("Val:" + resxSet.GetString("btn_cancel"));
            Console.ReadKey();


            

            //Properties.Settings.
            //Properties.Settings.Default.resXResourceSet = resxSet;
        }
    }
}
