using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System;
using System.Data;
using System.Data.Odbc;


namespace Lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            textBox1.Text = "enter query";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String myQuery = textBox1.Text;
            if (myQuery != null)
            {
                try
                {
                    string myConnection = "DSN=myAccess";
                    OdbcConnection myConn = new OdbcConnection(myConnection);
                    myConn.Open();
                    OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
                    myOdbcCommand.Connection = myConn;
                    myOdbcCommand.ExecuteNonQuery();
                    myConn.Close();
                }
                catch
                {
                    label1.Text = "an error has occured";
                    label1.Show();

                }
            }
            textBox1.Clear(); 
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void label1_Click(object sender, System.EventArgs e)
        {

        }
    }
}
