using System;
using System.Data;
using System.Data.Odbc;

class MyOdbcConnection
{
    public static void Main()
    {
        string myConnection = "DSN=myAccess";
        OdbcConnection myConn = new OdbcConnection(myConnection);
        myConn.Open();
        Console.WriteLine("to exit program enter quit");
        while (true)
        {
            try
            {

                Console.WriteLine("enter insert statement");
                string myQuery = Console.ReadLine();
                if (myQuery == "quit")
                {
                    break;
                }
                OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
                myOdbcCommand.Connection = myConn;
                myOdbcCommand.ExecuteNonQuery();
            }
            catch
            {
                Console.WriteLine("invalid command");
            }
            //        myOdbcCommand.Connection.Close();
        }
	myConn.Close();
    }
}
