import java.io.*;
import java.net.*;
import java.util.*;
public class multiSender{
    public static void main(String[] args) throws java.io.IOException {
			DatagramSocket socket = new DatagramSocket(4200);
			while (true) {
            try {
                byte[] buf = new byte[256];

		    // send it
				
                InetAddress group = InetAddress.getByName("230.0.0.1");
				Scanner scan = new Scanner(System.in);
				String line = scan.nextLine();
				if(line == "exit")
					break;
				buf=line.getBytes();
                DatagramPacket packet = new DatagramPacket(buf, buf.length, group, 4200);
                socket.send(packet);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
		socket.close();
    }
}