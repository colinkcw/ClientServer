import java.io.*;
import java.net.*;


class DirServer
{
   public static void main(String argv[]) throws Exception
      {

         ServerSocket welcomeSocket = new ServerSocket(6789);

         while(true)
         {
            Socket connectionSocket = welcomeSocket.accept();
			serverThread othread = new serverThread(connectionSocket);
			othread.start();
         }
      }
}
class serverThread extends Thread{
	
	private Socket conSocket = null;
	public serverThread(Socket connectSocket){
		conSocket = connectSocket;
	}
	public void run(){
		         String clientSentence;
         String capitalizedSentence;
		 try{
		BufferedReader inFromClient = new BufferedReader(new InputStreamReader(conSocket.getInputStream()));
        DataOutputStream outToClient = new DataOutputStream(conSocket.getOutputStream());
        clientSentence = inFromClient.readLine();
        System.out.println("Received: " + clientSentence);
        //capitalizedSentence = clientSentence.toUpperCase() + '\n';
        //outToClient.writeBytes(capitalizedSentence);
		File dir = new File(clientSentence);
		String[] chld = dir.list();
		if(chld == null){
			System.out.println("Specified directory does not exist or is not a directory.");
			System.exit(0);
		}else{
		for(int i = 0; i < chld.length; i++){
			String fileName = chld[i];
			outToClient.writeBytes(fileName + "\t");
      }
	  outToClient.writeBytes("\n");
    }
		}catch(Exception e){}
	}

}