using System;
using System.Data;
using System.Data.Odbc;

class MyOdbcConnection
{
    public static void Main()
    {
        string myConnection = "DSN=myAccess";
        OdbcConnection myConn = new OdbcConnection(myConnection);
        string myQuery = Console.ReadLine();
        
        OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
        myOdbcCommand.Connection = myConn;
        myConn.Open();

		OdbcDataReader reader = myOdbcCommand.ExecuteReader(); 
        int x = reader.FieldCount;
        for (int i = 0; i < x; i++)
        {
            Console.Write("{0}     ", reader.GetName(i));
        }
        Console.WriteLine();
        while (reader.Read())
        {
            Console.WriteLine("{0}", reader.GetString(0));
        }
        myOdbcCommand.Connection.Close();
        Console.ReadKey();
    }
}
