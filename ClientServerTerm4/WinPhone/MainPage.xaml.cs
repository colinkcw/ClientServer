using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Net;
using System.IO;
using Microsoft.Phone.Controls;

namespace A1partA
{
    public partial class MainPage : PhoneApplicationPage
    {
        WebClient client = new WebClient();
        delegate void delegateUpdateWebBrowser(string content);
        private void updateWebBrowser(string content)
        {
            webBrowser1.NavigateToString(content);
        }
        // Constructor
        public MainPage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            string request = textBox1.Text;
            //initialize new HttpWebRequest objects
            HttpWebRequest httpReq = (HttpWebRequest)HttpWebRequest.Create(new Uri("http://localhost/a4/default.aspx?sqlstatement="+request));
            //Begins an asynchronous request to an Internet resource
            httpReq.BeginGetResponse(HTTPWebRequestCallBack, httpReq);
        }
        private void HTTPWebRequestCallBack(IAsyncResult result)
        {
            //initialize new HttpWebRequest objects
            HttpWebRequest httpRequest = (HttpWebRequest)result.AsyncState;
            //Ends an asynchronous request to an Internet resource
            WebResponse response = httpRequest.EndGetResponse(result);
            Stream stream = response.GetResponseStream();
            StreamReader reader = new StreamReader(stream);
            this.Dispatcher.BeginInvoke(
              new delegateUpdateWebBrowser(updateWebBrowser),
              new Object[] { reader.ReadToEnd() });
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            // asynchronously connect to the Web service and call its simpleMethodAsync() method 
            ServiceReference1.Service1SoapClient ws = new ServiceReference1.Service1SoapClient();
            ws.simpleMethodCompleted += new EventHandler<ServiceReference1.simpleMethodCompletedEventArgs>(ws_DefineCompleted);
            ws.simpleMethodAsync(1,2);
 
        }
        void ws_DefineCompleted(object sender, ServiceReference1.simpleMethodCompletedEventArgs e)
        {
            string foo = e.Result.ToString();
            MessageBox.Show(foo);
        }
    }
}