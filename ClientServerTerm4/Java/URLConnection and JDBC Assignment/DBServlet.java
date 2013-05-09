import javax.servlet.http.*;
import javax.servlet.*;
import java.sql.*;
import java.io.*;

public class DBServlet extends HttpServlet {
  private int mCount;
  
  public void doGet(HttpServletRequest request,
      HttpServletResponse response)
      throws ServletException, IOException {
		Connection con = null;
		String sqlStatement = request.getParameter("sql");
		try { 
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		}
		catch(java.lang.ClassNotFoundException e) { 
			System.err.print("ClassNotFoundException: "); 
			System.err.println(e.getMessage()); 
		} 
		try {
			con = DriverManager.getConnection("jdbc:odbc:myAccess","", "");
			Statement stmt = con.createStatement();
			con.setAutoCommit(false);
			stmt.executeUpdate(sqlStatement);
			//stmt.executeUpdate("INSERT INTO student (nam, address) VALUES ('cggccc','surrey')");
			//stmt.executeUpdate("INSERT INTO student (nam, address) VALUES ('eeee','surrey')");
			con.commit();
			stmt.close();
		 
			

			///////////////////////////////////////////
            /*Statement stmt2 = con.createStatement();
            ResultSet rs = stmt2.executeQuery("SELECT nam, address FROM student");

			//using result set meta data print the names of the columns of your query result
			response.setContentType("text/plain");
			PrintWriter out = response.getWriter();
			ResultSetMetaData rsmd = rs.getMetaData();
     			int numberOfColumns = rsmd.getColumnCount();
				String msg1 = "";
				//out.println("hello world");
			for (int i = 1; i <= numberOfColumns; i++){ 
				msg1 += rsmd.getColumnName(i);
				msg1 += " ";
			}
			//response.setContentLength(msg1.length());
			//out.println(msg1 + "\n");
			msg1 += "\n";
			while (rs.next()) {
	            msg1 += rs.getString("nam");
				msg1 += " ";
	            msg1 += rs.getString("address");
				msg1 +="\n";
	        }
                response.setContentLength(msg1.length());
				out.println(msg1 + "\n");*/	
			con.close();
		}		catch(SQLException ex) { 
				System.out.println("\n--- SQLException caught ---\n"); 
				while (ex != null) { 
					System.out.println("Message: " + ex.getMessage ()); 
					System.out.println("SQLState: " + ex.getSQLState ()); 
					System.out.println("ErrorCode: " + ex.getErrorCode ()); 
					ex = ex.getNextException(); 
					System.out.println("");
				} 
		}
			


  }
}
