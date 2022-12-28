using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Threading.Tasks;

namespace TrivialClient
{
    class Program
    {
        static async Task Main(string[] args)
        {
            bool test01 = false;
            bool test02 = true;

            Console.WriteLine("Trivial Client");

            if (test01)
            {
                using var client = new HttpClient();
                var content = await client.GetStringAsync("http://localhost:8000/");

                Console.WriteLine(content);
            }
            else if (test02)
            {

                using var client = new HttpClient();
                var values = new Dictionary<string, string>
                  {
                      { "thing1", "hello" },
                      { "thing2", "world" }
                  };

                var content = new FormUrlEncodedContent(values);

                var response = await client.PostAsync("http://localhost:8000/", content);

                var responseString = await response.Content.ReadAsStringAsync();

                Console.WriteLine(responseString);
            }

        }
    }
}
