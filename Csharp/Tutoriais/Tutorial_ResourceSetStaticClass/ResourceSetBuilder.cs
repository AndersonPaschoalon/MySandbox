using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tutorial_ResourceSetStaticClass
{
    class ResourceSetBuilder
    {
        private static string lang;
        static ResourceSetBuilder()
        {
            ResourceSetBuilder.lang = "PT";
        }
    }
}
