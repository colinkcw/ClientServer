using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections.Specialized;
using System.Data.Odbc;
public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        string myQuery = Request["sqlstatement"];
        
         try
         {
             string myConnection = "DSN=myAccess";
             OdbcConnection myConn = new OdbcConnection(myConnection);
             OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
             myOdbcCommand.Connection = myConn;
             myConn.Open();
            OdbcDataReader reader = myOdbcCommand.ExecuteReader();
            int field = reader.FieldCount;
            for (int i = 0; i < field; i++)
            {
                Response.Write(reader.GetName(i));
                Response.Write("\t");
               
            }
            Response.Write("\r\n");
            while (reader.Read())
            {
                for (int i = 0; i < field; i++)
                {
                    Response.Write(reader.GetString(i));
                    Response.Write("\t");
                }
                Response.Write("\r\n");
            }

         }
         catch
         {
             Response.Write("error");
         }
  
    }
}