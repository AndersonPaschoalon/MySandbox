using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Collections.Specialized;

namespace Test_ConfigFile
{
    class Program
    {
        static void Main(string[] args)
        {
            String val;

            ExeConfigurationFileMap configMap = new ExeConfigurationFileMap();
            configMap.ExeConfigFilename = @"AdvantageSdkSettings.config";
            Configuration config = ConfigurationManager.OpenMappedExeConfiguration(configMap, ConfigurationUserLevel.None);

            Console.WriteLine("The value of val: " + config.AppSettings.Settings["smartsys_path"].Value);
            Console.ReadKey();
        }
    }
}
