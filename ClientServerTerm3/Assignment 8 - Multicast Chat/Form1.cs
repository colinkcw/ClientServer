using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace Main_Chat
{
    public partial class Form1 : Form
    {
        private IPAddress mcastAddress1;
        private IPAddress mcastAddress2;
        private int mcastPort;
        private Socket mcastSocket1;
        private MulticastOption mcastOption;
        private IPEndPoint endPoint;
        static Socket mcastSocket2;

        public Form1()
        {
            InitializeComponent();


            mcastAddress2 = IPAddress.Parse("230.0.0.1");
            Thread chatThread = new Thread(new ThreadStart(threadFunction));
            chatThread.Start();
            try
            {

                mcastSocket2 = new Socket(AddressFamily.InterNetwork,
                            SocketType.Dgram,
                            ProtocolType.Udp);// create a socket

                //Send multicast packets to the listener.
                endPoint = new IPEndPoint(mcastAddress2, 13000);
            }
            catch (Exception v)
            {
                Console.WriteLine("\n" + v.ToString());
            }

        }
        private void threadFunction()
        {
            
            mcastAddress1 = IPAddress.Parse("230.0.0.1");
            mcastPort = 13000;
            try
            {
               
                mcastSocket1 = new Socket(AddressFamily.InterNetwork,
                                         SocketType.Dgram,
                                         ProtocolType.Udp);


                IPAddress localIP = IPAddress.Any;
                EndPoint localEP = (EndPoint)new IPEndPoint(localIP, 13000);
                mcastSocket1.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReuseAddress, 1);

                mcastSocket1.Bind(localEP);


                // Define a MulticastOption object specifying the multicast group 
                // address and the local IPAddress.
                // The multicast group address is the same as the address used by the server.
                mcastOption = new MulticastOption(mcastAddress1, localIP);

                mcastSocket1.SetSocketOption(SocketOptionLevel.IP,
                                            SocketOptionName.AddMembership,
                                            mcastOption);


                bool done = false;
                byte[] bytes = new Byte[100];
                IPEndPoint groupEP = new IPEndPoint(mcastAddress1, mcastPort);
                EndPoint remoteEP = (EndPoint)new IPEndPoint(IPAddress.Any, 0);

                while (!done)
                {

                    mcastSocket1.ReceiveFrom(bytes, ref remoteEP);

                    viewBox.Text += Encoding.ASCII.GetString(bytes, 0, bytes.Length);
                    viewBox.Text += "\n";


                }

            }
            catch (Exception e)
            {
                //viewBox.Text += "error\n";
            }

        }
        private void viewBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void button_Click(object sender, EventArgs e)
        {
            string data = textBox.Text;
            mcastSocket2.SendTo(ASCIIEncoding.ASCII.GetBytes(data), endPoint);// send message, must conver text into bytes
            textBox.Clear();
        }
    }
}
