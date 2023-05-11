package footballDB;

import javafx.fxml.Initializable;
import myUtil.NetworkUtil;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.ResourceBundle;

public class Server {

    private ServerSocket serverSocket;
    public HashMap<String, NetworkUtil> clientMap;

    Server() {
        /*try{
            FileIO.readFromFile();
        } catch (Exception e){
            System.out.println("Error: " + e.getMessage());
        }*/
        clientMap = new HashMap<>();
        try{
            FileIO.readFromFile();
            serverSocket = new ServerSocket(33333);
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
        /*System.out.println("Name of the client: " + clientName);
        System.out.println("Password: " + clientPass);
        System.out.println(FileIO.getClientInfoMap());*/
        if(!(FileIO.getClientInfoMap().containsKey(clientName))){
            networkUtil.write("false");
            //System.out.println("Inside first \"if\"");
        } else {
            if(FileIO.getClientInfoMap().get(clientName).equals(clientPass)){
                clubFileIO.setClubName(clientName);
                networkUtil.write("true");
                networkUtil.write(clubFileIO);
                //System.out.println("Inside first \"if\" of first \"else\"");
            } else {
                networkUtil.write("false");
                //System.out.println("Inside first \"else\" of first \"else\"");
            }
        }
        clientMap.put(clientName, networkUtil);
        new ReadThreadServer(clientMap, networkUtil, clubFileIO);
    }

    public static void main(String args[]) {
        Server server = new Server();
    }
}
