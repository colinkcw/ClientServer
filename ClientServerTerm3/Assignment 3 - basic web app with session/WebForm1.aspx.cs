using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Odbc;
namespace A3V2
{
    public partial class WebForm1 : System.Web.UI.Page
    {

        protected void Page_Load(object sender, EventArgs e)
        {
            Label2.Text = (string)Session["name"];
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            String myQuery = TextBox1.Text;
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
                    TextBox2.Text += reader.GetName(i);
                    TextBox2.Text += reader.GetDataTypeName(i);
                    TextBox2.Text += " ";
                    TextBox2.Text += "\t";
                }
                TextBox2.Text += "\r\n";
                while (reader.Read())
                {
                    for (int i = 0; i < field; i++)
                    {
                        TextBox2.Text += reader.GetString(i);
                        TextBox2.Text += "\t\t";
                    }
                    TextBox2.Text += "\r\n";
                }
            }
            catch
            {
                Label1.Text = "an error has happened";
                Label1.Visible = true;
            }

        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}