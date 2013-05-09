using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;
using System.Xml;
using System.Text.RegularExpressions;
using System.Net;
using System.IO;

namespace currencyConverter
{
    /// <summary>
    /// Summary description for Service1
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    class rssCurrency
    {
        public XmlTextReader getReader()
        {
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create("http://themoneyconverter.com/rss-feed/CAD/rss.xml");

            HttpWebResponse response = (HttpWebResponse)request.GetResponse();

            Stream dataStream = response.GetResponseStream();

            XmlTextReader reader = new XmlTextReader(dataStream);
            return reader;
        }
        public float getRate(XmlReader theReader, string countryCode)
        {
            XmlReader reader = theReader;
            string current = "";
            float rate = 0;
            while (reader.Read())
            {
                if (reader.Name == "title")
                {

                    current = reader.ReadString();
                }
                if (current == countryCode && reader.Name == "description")
                {
                    // Console.WriteLine("usa");
                    current = reader.ReadString();
                    current = current.Remove(0, 1);
                    // Console.WriteLine(current);
                    break;

                }
                reader.MoveToNextAttribute();
            }
            reader.Close();
            rate = getFloat(current);
            return rate;

        }
        public float getFloat(string parse)
        {

            Regex reg = new Regex("[0-9]+.[0-9]+");
            Match match = reg.Match(parse);
            float exchangeRate = float.Parse(match.Value);

            return exchangeRate;

        }
        public string getCountryCode(string code)
        {
            
            string returnCode = "";
            switch (code)
            {
                case "usa":
                    returnCode = "USD/CAD";
                    break;
                case "japan":
                    returnCode = "JPY/CAD";
                    break;
                case "india":
                    returnCode = "INR/CAD";
                    break;
                case "hongkong":
                    returnCode = "HRK/CAD";
                    break;
            }
            return returnCode;
        }
    }
    public class Service1 : System.Web.Services.WebService
    {

        [WebMethod]
        public float exchangeRate(int amount,string country)
        {
            float newValue = 0;
            rssCurrency main = new rssCurrency();
            XmlReader reader = main.getReader();
            string countryCode = main.getCountryCode(country);
            float exchangeRate = main.getRate(reader, countryCode);
            newValue = amount * exchangeRate;
            return newValue;
        }
    }
}