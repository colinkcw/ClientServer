import java.io.*;
import java.net.*;
import java.util.*;

public class multiClient {

    public static void main(String[] args) throws IOException {

        MulticastSocket socket = new MulticastSocket(4200);
        InetAddress address = InetAddress.getByName("230.0.0.1");
	socket.joinGroup(address);

        DatagramPacket packet;
    
            // get a few quotes
		while(true){

	    byte[] buf = new byte[256];
            packet = new DatagramPacket(buf, buf.length);
            socket.receive(packet);

            String received = new String(packet.getData(), 0, packet.getLength());
            System.out.println(received);
			
			if(received == "exit")
				break;
	}

	socket.leaveGroup(address);
	socket.close();
    }

}