using System;
using System.Data;
using System.Data.Odbc;


class MyOdbcConnection
{
    public static void Main()
    {
        string myConnection = "DSN=bcitOra;uid=system;pwd=oracle1";
        OdbcConnection myConn = new OdbcConnection(myConnection);
       

        OdbcCommand myOdbcCommand = new OdbcCommand("{call insertStudent }",myConn);
        myOdbcCommand.Connection = myConn;
        myConn.Open();
        myOdbcCommand.ExecuteNonQuery();
        myOdbcCommand.Connection.Close();
        
        Console.ReadKey();
    }
}
