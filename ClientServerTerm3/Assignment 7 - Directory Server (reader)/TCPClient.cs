using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace TCPClient
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int port = 13000;

                IPAddress address = IPAddress.Parse("127.0.0.1");

                // IPAddress address = IPAddress.Parse("142.232.246.22");

                IPEndPoint ipe = new IPEndPoint(address, port);
                Socket s = new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

                s.Connect(ipe);// connects to the server

                if (s.Connected)
                {
					while(true){
						string request = Console.ReadLine();
						request += "\0";
						Byte[] bytesSent = Encoding.ASCII.GetBytes(request);
						Byte[] bytesReceived = new Byte[256];

						s.Send(bytesSent, bytesSent.Length, 0);
						if(request == "exit\0"){
							break;
						}
						int bytes = 0;

						bytes = s.Receive(bytesReceived, bytesReceived.Length, 0);
						Console.WriteLine(Encoding.ASCII.GetString(bytesReceived, 0, bytes));
					}
					Console.WriteLine("socket close");
                    s.Close();
                }
            }
            catch (ArgumentNullException e)
            {
                Console.WriteLine("Argument Null Exception: {0}", e);

            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException: {0}", e);
            }

            Console.Read();
        }


    }
}