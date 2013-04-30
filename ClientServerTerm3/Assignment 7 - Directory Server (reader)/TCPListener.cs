using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

	class threadlist{
		Socket cls;
		public threadlist(Socket s){
			cls  = s;
		}
		public void func(){
			string data = "";
			string current="";
			char c;
			Byte[] byteSent = new Byte[256];
			Byte[] bytesReceived = new Byte[1];
			while(true){
				while(true){
					int bytes = cls.Receive(bytesReceived, bytesReceived.Length, 0);// stuff that is recieved					
					current = System.Text.Encoding.ASCII.GetString(bytesReceived, 0, bytes);
					c = current[0];
					if(c == '\0'){
						break;
					}
					data+=c;
				}
				
				Console.WriteLine(data);
				
				if(data == "exit"){
					break;
				}
				
				//Process the data sent by the client.
				DirectoryInfo di = new DirectoryInfo(data);
				FileInfo[] fiArr = di.GetFiles();// return an array of file info
				string files = "";	
				foreach (FileInfo fri in fiArr)
				{
					files += fri.Name;
					files += "\n";
				}

				byte[] msg = System.Text.Encoding.ASCII.GetBytes(files);

				//Semd request to the server
				cls.Send(msg, msg.Length, 0);
				data="";
			}
			//cls.Close();
		}
	}
class MyTcpListener
{
	static void Main(string[] args)
	{
		try
		{
			int port = 13000;
			IPAddress address = IPAddress.Parse("127.0.0.1");
			
			// IPAddress address = IPAddress.Parse("142.232.246.23");

			IPEndPoint ipe = new IPEndPoint(address, port);//addreess and port number sam as udp
			Socket s = new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);// stream socket and tcp protocol

			s.Bind(ipe);
			s.Listen(10);//room for 10 simutalnous calls// blocking call server waits for connection
			while(true){
				Socket cls = s.Accept();// client socket is created
				threadlist lst = new threadlist(cls);
				Thread oThread = new Thread(new ThreadStart(lst.func));
				oThread.Start();			
			}
			s.Close();
		}
		catch (SocketException e)
		{
			Console.WriteLine("Socket exception: {0}", e);
		}

		Console.Read();
		
		}
}
