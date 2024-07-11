import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class MyHttpClient {

  // i'm gonna listen on 8080, responses go to 80.
  public static void main(String[] args) {

    // args will be "port#"
    if (args.length < 2) {
      System.err.println("Usage: 'MyHttpClient [host] [port#]");
      return;
    }

    InetAddress host;
    try {
      host = InetAddress.getByName(args[0]);

    } catch (UnknownHostException uhe) {
      uhe.printStackTrace();
      return;
    }

    int port = Integer.parseInt(args[1]);

    try (Socket myClient = new Socket(host, port)) {
      System.out.println("Connecting to host " + host + " on port " + port);


      //what do i do with my connection as it goes?
      while(true) {

      }
      
    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }
}
