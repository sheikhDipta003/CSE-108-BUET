package footballDB;

import myUtil.NetworkUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class ReadThreadServer implements Runnable {
    private Thread thr;
    private NetworkUtil networkUtil;
    private ClubFileIO clubFileIO;
    public HashMap<String, NetworkUtil> clientMap;
    public static List<String> auctionedPlayersInServer;


    public ReadThreadServer(HashMap<String, NetworkUtil> map, NetworkUtil networkUtil, ClubFileIO clubFileIO) {
        this.clientMap = map;
        this.networkUtil = networkUtil;
        this.clubFileIO = clubFileIO;
        this.thr = new Thread(this);
        thr.start();
    }

    public void run() {
        try {
            while (true) {
                Object o = networkUtil.read();
                /*if (o instanceof Message) {
                    Message obj = (Message) o;
                    String to = obj.getTo();
                    NetworkUtil nu = clientMap.get(to);
                    if (nu != null) {
                        nu.write(obj);
                    }
                }*/
                if (o instanceof String) {
                    String temp = (String) o;
                    //System.out.println("ReadThreadServer: " + "temp = " + temp);
                    auctionedPlayersInServer.add(temp);
                    System.out.println("The List(Server): " + auctionedPlayersInServer);
                    AuctionedPlayersData auctionedPlayersData = new AuctionedPlayersData();

                    List<String> Temp = new ArrayList<>();
                    Temp.add(temp);
                    auctionedPlayersData.setAuctionedPlayersData(Temp);

                    List<String> keySet = new ArrayList<>(clientMap.keySet());
                    for (String key : keySet) {
                        System.out.println("ReadThreadServer: " + "key = " + key);
                        NetworkUtil nu = clientMap.get(key);
                        if (nu != null) nu.write(auctionedPlayersData);
                        else System.out.println("ReadThreadServer: nu is null");
                    }
                }
                if(o instanceof BoughtPlayerData){
                    BoughtPlayerData boughtPlayerData = (BoughtPlayerData) o;
                    System.out.println("ReadThreadServer: " + boughtPlayerData.getClubName() + ", " + boughtPlayerData.getBoughtPLayer().getName());

                    List<Player> allPlayers = FileIO.getPlayersList();

                    for(Player player : allPlayers){
                        if(player.getName().equals(boughtPlayerData.getBoughtPLayer().getName())){
                            player.setClub(boughtPlayerData.getClubName());
                        }
                    }
                    FileIO.writeToFile(allPlayers);
                }
            }
        } catch (Exception e) {
            System.out.println("ReadThreadServer: " + e.getMessage());
        } finally {
            try {
                networkUtil.closeConnection();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
