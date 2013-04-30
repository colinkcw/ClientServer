using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Security.Cryptography;
using System.IO;

namespace A2Receiver
{
    class Program
    {
        static void Main(string[] args)
        {
            ASCIIEncoding ByteConverter = new ASCIIEncoding();

            byte[] signedData;
            RSACryptoServiceProvider RSAalg = new RSACryptoServiceProvider();
            StreamReader foo = new StreamReader("foo.pfx");
            string xml = foo.ReadLine();
            string ori = foo.ReadLine();
            foo.Close();
            RSAalg.FromXmlString(xml);
            RSAParameters Key = RSAalg.ExportParameters(false);
            byte[] originalData = ByteConverter.GetBytes(ori);
            signedData = getByteArray(); 
           
                
            if (VerifySignedHash(originalData, signedData, Key))
            {
                Console.WriteLine("The data was verified.");
            }
            else
            {
                Console.WriteLine("The data does not match the signature.");
            }
                
            Console.ReadKey();
        }
        public static bool VerifySignedHash(byte[] DataToVerify, byte[] SignedData, RSAParameters Key)
        {
            try
            {
                // Create a new instance of RSACryptoServiceProvider using the  
                // key from RSAParameters.
                RSACryptoServiceProvider RSAalg = new RSACryptoServiceProvider();

                RSAalg.ImportParameters(Key);

                // Verify the data using the signature.  Pass a new instance of SHA1CryptoServiceProvider 
                // to specify the use of SHA1 for hashing. 
                return RSAalg.VerifyData(DataToVerify, new SHA1CryptoServiceProvider(), SignedData);

            }
            catch (CryptographicException e)
            {
                Console.WriteLine(e.Message);

                return false;
            }
        }
        public static byte[] getByteArray()
        {
            
            FileStream fs = File.OpenRead("signed.pfx");
            byte[] bytes = new byte[fs.Length];
            fs.Read(bytes, 0, Convert.ToInt32(fs.Length));
            fs.Close();
            return bytes;
        }

    }
}
