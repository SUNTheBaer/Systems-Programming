package socketpractice;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ClientHandler implements Runnable
{
    private Socket client;
    private BufferedReader in;
    private PrintWriter out;
    private ArrayList<ClientHandler> clients;
    private String userID;
    private boolean userIDCheck = true;
    private String tempUserID;
    
    public ClientHandler (Socket clientSocket, ArrayList<ClientHandler> clients) throws IOException
    {
        this.client = clientSocket;
        this.clients = clients;
        in = new BufferedReader(new InputStreamReader(client.getInputStream()));
        out = new PrintWriter(client.getOutputStream(), true);
    }
    
    @Override
    public void run() {
        try
        {
            while (userIDCheck)
            {
                out.println("What is your name?");
                tempUserID = in.readLine();
                userIDCheck = pickUsername(tempUserID);
            }
            userID = tempUserID;
            outToAll(userID + " has joined");       
            while (true)
            {
                String request = in.readLine();
                
                if (request == null)
                    break;
                else if (request.equals("LOGOUT"))
                    break;
                else
                    outToAll(userID + ": " + request);
            }
        }
        catch (IOException e)
        {
            System.err.println("IOException in client handler");
            System.err.println(e.getStackTrace());
        }
        finally
        {
            try {
                clients.remove(this);
                outToAll(userID + " has left");
                client.close();
            } catch (IOException ex) {
                Logger.getLogger(ClientHandler.class.getName()).log(Level.SEVERE, null, ex);
            }
            out.close();
        }
    }

    private void outToAll(String msg)
    {
        for (ClientHandler aClient : clients)
        {
            aClient.out.println(msg);
        }
    }
    
    private boolean pickUsername (String ID)
    {
        String[] userIDs = new String[clients.size()];
        
        for (int i = 0; i < userIDs.length; i++)
            {
                userIDs[i] = clients.get(i).userID;
            }

        for (int i = 0; i < userIDs.length; i++)
        {
            if (ID.equals(userIDs[i]))
            {
                out.println("Username has been taken, try again");
                return true;
            }
        }
        return false; 
    }
}