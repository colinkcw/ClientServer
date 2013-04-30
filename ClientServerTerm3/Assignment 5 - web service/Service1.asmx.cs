using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;
using System.Data.Odbc;
namespace A5Service
{
    /// <summary>
    /// Summary description for Service1
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class Service1 : System.Web.Services.WebService
    {

        [WebMethod]
        public string simpleMethod(String srt)
        {
            
                string myConnection = "DSN=myAccess";
                OdbcConnection myConn = new OdbcConnection(myConnection);
                string myQuery = "SELECT COUNT(*) FROM student where name='client'";

                OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
                myOdbcCommand.Connection = myConn;
                myConn.Open();

                OdbcDataReader reader = myOdbcCommand.ExecuteReader();
         
                //myOdbcCommand.Connection.Close();
                reader.Read();
                if ((int)reader.GetValue(0) == 1)
                {
                    myConn.Close();
                    return "valid";
                }
                else
                {
                    myConn.Close();
                    return "false";
                }

                
        }

        [WebMethod]
        public int anotherSimpleMethod(int firstNUm, int secondNUm)
        {
            return firstNUm * secondNUm;
        }
    }
}