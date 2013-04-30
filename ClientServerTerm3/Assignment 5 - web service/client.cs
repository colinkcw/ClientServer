using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using A5console.TestWeb;

namespace A5console
{
    class Program
    {
        static void Main(string[] args)
        {
            Service1 webservice = new Service1();
            string srt = webservice.simpleMethod("selec");
            Console.WriteLine(srt);
            Console.WriteLine(webservice.anotherSimpleMethod(4, 3));
            Console.ReadKey();
        }
    }
}
