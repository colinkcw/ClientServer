using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Security.Cryptography;
using System.IO;
namespace A2Sender
{
    class Program
    {
        static void Main()
        {
                Console.WriteLine("enter file name");
                string filename = Console.ReadLine();
                filename += ".txt";
                StreamReader reader = new StreamReader(filename);
                string line = reader.ReadLine();
                Console.WriteLine(line);
                string name = line.Substring(0, 30);
                string guid = line.Substring(30, 16);
                string mac = line.Substring(46, 12);
                string date = line.Substring(58, 14);
                reader.Close();


                // Create a UnicodeEncoder to convert between byte array and string.
                ASCIIEncoding ByteConverter = new ASCIIEncoding();

                // Create byte arrays to hold original, encrypted, and decrypted data. 
                byte[] originalData = ByteConverter.GetBytes(line);
                byte[] signedData;

                // Create a new instance of the RSACryptoServiceProvider class  
                // and automatically create a new key-pair.
                RSACryptoServiceProvider RSAalg = new RSACryptoServiceProvider();

                // Export the key information to an RSAParameters object. 
                // You must pass true to export the private key for signing. 
                // However, you do not need to export the private key 
                // for verification.
                RSAParameters Key = RSAalg.ExportParameters(true);

                // Hash and sign the data.
                signedData = HashAndSignBytes(originalData, Key);
                string xml = RSAalg.ToXmlString(false);
                StreamWriter foo = new StreamWriter("foo.pfx");
                foo.Write(xml);
                foo.WriteLine();
                foo.Write(line);
                foo.WriteLine();
                foo.Close();
                writeToFile(signedData);
                
            }
        
           
        
        public static byte[] HashAndSignBytes(byte[] DataToSign, RSAParameters Key)
        {
            try
            {
                // Create a new instance of RSACryptoServiceProvider using the  
                // key from RSAParameters.  
                RSACryptoServiceProvider RSAalg = new RSACryptoServiceProvider();

                RSAalg.ImportParameters(Key);

                // Hash and sign the data. Pass a new instance of SHA1CryptoServiceProvider 
                // to specify the use of SHA1 for hashing. 
                return RSAalg.SignData(DataToSign, new SHA1CryptoServiceProvider());
            }
            catch (CryptographicException e)
            {
                Console.WriteLine(e.Message);

                return null;
            }
        }
        public static void writeToFile(byte[] data)
        {
            using (FileStream fileStream = new FileStream("signed.pfx", FileMode.Create))
            {
                // Write the data to the file, byte by byte.
                for (int i = 0; i < data.Length; i++)
                {
                    fileStream.WriteByte(data[i]);
                }
                fileStream.Close();
            }
        }
        
    }
}
