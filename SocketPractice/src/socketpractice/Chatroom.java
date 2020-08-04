package socketpractice;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Chatroom {

    public static void main(String[] args) throws IOException
    {
        final int PORT = 9090;
        ServerSocket listener = new ServerSocket(PORT);
        ArrayList<ClientHandler> clients = new ArrayList<>();
        ExecutorService pool = Executors.newFixedThreadPool(10);
        
        while (true)
        {
            System.out.println("[SERVER] Waiting for client connection...");
            Socket client = listener.accept();
            System.out.println("[SERVER] Connected to client!");
            ClientHandler clientThread = new ClientHandler(client, clients);
            clients.add(clientThread);
            pool.execute(clientThread);
        }
    }
}