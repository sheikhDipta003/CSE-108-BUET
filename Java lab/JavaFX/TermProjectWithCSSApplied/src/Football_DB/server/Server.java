package Football_DB.server;

import Football_DB.data.ClubInfo;
import Football_DB.data.ClubPlayersListString;
import Football_DB.netUtil.NetworkUtil;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;

public class Server {

    private ServerSocket serverSocket;
    public HashMap<String, NetworkUtil> clientMap;

    Server() {
        clientMap = new HashMap<>();
        try {
            FileIO.readFromFile();
            FileIO.setClientInfoMap();
            serverSocket = new ServerSocket(44444);
            ReadThreadServer.auctionedPlayersInServer = new ArrayList<>();

            while (true) {
                System.out.println("Waiting for connection ...");
                Socket clientSocket = serverSocket.accept();
                System.out.println("Connected to a client!");
                serve(clientSocket);
            }
        } catch (Exception e) {
            System.out.println("Server starts:" + e);
        }
    }

    public void serve(Socket clientSocket) throws IOException, ClassNotFoundException {
        ClubFileIO clubFileIO = new ClubFileIO();
        NetworkUtil networkUtil = new NetworkUtil(clientSocket);
        ClubInfo clientInfo = (ClubInfo) networkUtil.read();
        String clientName = clientInfo.getClientInfo().split(",")[0];
        String clientPass = clientInfo.getClientInfo().split(",")[1];

        if (!(FileIO.getClientInfoMap().containsKey(clientName))) {
            networkUtil.write("false");
        } else {
            if (FileIO.getClientInfoMap().get(clientName).equals(clientPass)) {
                clubFileIO.setClubName(clientName);
                networkUtil.write("true");

                ClubPlayersListString obj = new ClubPlayersListString(clubFileIO.getClubPlayersList());
                networkUtil.write(obj);
            } else {
                networkUtil.write("false");
            }
        }
        clientMap.put(clientName, networkUtil);
        new ReadThreadServer(clientMap, networkUtil, clubFileIO);
    }

    public static void main(String args[]) {
        new Server();
    }
}
