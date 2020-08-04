package socketpractice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ServerConnection implements Runnable
{
    private Socket server;
    private BufferedReader in;
    private PrintWriter out;
    
    public ServerConnection(Socket s) throws IOException
    {
        server = s;
        in = new BufferedReader(new InputStreamReader(server.getInputStream()));
    }

    @Override
    public void run()
    {
        try {
            while (true){
            String serverResponse = in.readLine();
            if (serverResponse == null) break;
            System.out.println("Server says: " + serverResponse);
            }
        } catch (IOException ex) {
            Logger.getLogger(ServerConnection.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                in.close();
            } catch (IOException ex) {
                Logger.getLogger(ServerConnection.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}