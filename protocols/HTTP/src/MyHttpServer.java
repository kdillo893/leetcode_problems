import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MyHttpServer {

  // i'm gonna listen on 8080, responses go to 80.
  public static void main(String[] args) {

    // args will be "port#"
    if (args.length < 1) {
      System.err.println("Usage: 'MyHttpServer [port#]");
      return;
    }

    // try to grab host:
    int port = Integer.parseInt(args[0]);

    try (ServerSocket myServer = new ServerSocket(port)) {
      System.out.println("Listening on port " + port);

      // above try pre-req did the "create, bind, listen" steps...

      while (true) {

        Socket clientSock = myServer.accept();

        System.out.println("Client connected");

        // parse the request from the client socket...
        // have a READER from the input stream of the socket...
        InputStream inputStream = clientSock.getInputStream();
        BufferedReader buffReader = new BufferedReader(new InputStreamReader(inputStream));
        // need to read this... have lines read one by one to get headers and other
        // info.

        // loop for the reader until reaches end of headers...
        List<String> headerLines = new ArrayList<>();
        String inputLine = buffReader.readLine();
        do {
          inputLine = buffReader.readLine();
          // troubleshoot print
          System.out.println(inputLine);
          headerLines.add(inputLine);
        } while (inputLine.length() > 0);

        // finished the headers, can parse each of them to reduce into a map of
        // headers..
        Map<String, String> headers = new HashMap<>();
        for (var myline : headerLines) {
          int firstColonIdx = myline.indexOf(':');
          if (firstColonIdx < 0)
            continue;

          String key = myline.substring(0, firstColonIdx);
          String value = myline.substring(firstColonIdx + 1).trim();

          headers.put(key, value);
        }

        System.out.println(headers);

        // headers done, get the body of text... where to store.
        StringBuilder requestBody = new StringBuilder();
        while (inputLine != null && inputLine.length() > 0) {

          inputLine = buffReader.readLine();
          // troubleshoot print
          System.out.println(inputLine);
          requestBody.append(inputLine);
        }

        System.out.println(requestBody.toString());

        // now output something to the client...
        OutputStream outputStream = clientSock.getOutputStream();
        PrintWriter writer = new PrintWriter(outputStream, true);

        writer.println("This is coming from the server!");
        // I need to write a proper response with headers and such from here...

        buffReader.close();
        // close the connection when im done writing.
        clientSock.close();

      }

    } catch (Exception ex) {
      ex.printStackTrace();
    }
  }
}
