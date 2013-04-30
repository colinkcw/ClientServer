using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.Odbc;
namespace lab2b
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string myQuery = textBox1.Text;
            label1.Hide();
            if (myQuery != null)
            {
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
                        dataGridView1.Columns.Add(reader.GetName(i), reader.GetName(i));

                    }
                    while (reader.Read())
                    {
                        for (int i = 0; i < field; i++)
                        {
                            dataGridView1.Rows.Add(reader.GetString(i),reader.GetString(++i));
                        }
                    }
                }
                catch
                {
                    label1.Text = "an error has occured";
                    label1.Show();
                }
            }
        }

        private void dataGridView1_CellContentClick(object sender,
            DataGridViewCellEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
