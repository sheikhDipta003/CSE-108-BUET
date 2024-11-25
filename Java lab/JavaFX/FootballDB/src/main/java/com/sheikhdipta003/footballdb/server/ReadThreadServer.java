package com.sheikhdipta003.footballdb.server;

import com.sheikhdipta003.footballdb.data.AddNewPlayer;
import com.sheikhdipta003.footballdb.data.AuctionedPlayersData;
import com.sheikhdipta003.footballdb.data.BoughtPlayerData;
import com.sheikhdipta003.footballdb.data.Player;
import com.sheikhdipta003.footballdb.netUtil.NetworkUtil;

import java.io.IOException;
import java.util.*;

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

                if (o instanceof String) {
                    String temp = (String) o;
                    auctionedPlayersInServer.add(temp);
                    AuctionedPlayersData auctionedPlayersData = new AuctionedPlayersData();

                    List<String> Temp = new ArrayList<>();
                    Temp.add(temp);
                    auctionedPlayersData.setAuctionedPlayersData(Temp);

                    List<String> keySet = new ArrayList<>(clientMap.keySet());
                    for (String key : keySet) {
                        NetworkUtil nu = clientMap.get(key);
                        if (nu != null) nu.write(auctionedPlayersData);
                        else System.out.println("ReadThreadServer: nu is null");
                    }
                }
                if(o instanceof BoughtPlayerData){
                    BoughtPlayerData boughtPlayerData = (BoughtPlayerData) o;

                    List<Player> allPlayers = FileIO.getPlayersList();

                    for(Player player : allPlayers){
                        if(player.getName().equals(boughtPlayerData.getBoughtPLayer().getName())){
                            player.setClub(boughtPlayerData.getClubName());
                        }
                    }

                    FileIO.writeToFile(allPlayers);
                }
                if(o instanceof AddNewPlayer){
                    AddNewPlayer newPlayer = (AddNewPlayer) o;
                    List<Player> allPlayers = FileIO.getPlayersList();
                    allPlayers.add(newPlayer.getPlayer());
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
