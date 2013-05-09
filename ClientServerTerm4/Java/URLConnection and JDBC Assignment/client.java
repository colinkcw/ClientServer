import java.io.*;
import java.util.*;
import java.net.*;
public class client {
    public static void main(String[] args) throws Exception {
	
		Scanner scan = new Scanner(System.in);
		String statment = scan.nextLine();
       final String sqlstate = URLEncoder.encode("sql", "UTF-8").concat("=").concat(URLEncoder.encode(statment, "UTF-8"));

        URL url = new URL("http://142.232.246.21:4020/midp/hits");
        URLConnection connection = url.openConnection();
        connection.setDoOutput(true);

        OutputStreamWriter out = new OutputStreamWriter(
                                         connection.getOutputStream());
        out.write(sqlstate);
        out.flush();

				StringBuffer answer = new StringBuffer();
				BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
				String line;
				while ((line = reader.readLine()) != null) {
					answer.append(line);
				}
				out.close();
				reader.close();
				
				//Output the response
				System.out.println(answer.toString());
    }
}