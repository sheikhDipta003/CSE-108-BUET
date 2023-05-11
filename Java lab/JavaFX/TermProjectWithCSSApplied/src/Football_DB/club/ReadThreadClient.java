package Football_DB.club;

import Football_DB.data.Player;
import Football_DB.data.AuctionedPlayersData;
import Football_DB.data.ClubPlayersListString;
import Football_DB.netUtil.NetworkUtil;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReadThreadClient implements Runnable{
    private Thread thr;
    private NetworkUtil networkUtil;
    private static List<Player> clubPLayersList;
    private final Club club;
    public static List<String> auctionedPlayersInClub;
    public static List<Player> auctionedPlayersInThisClub;

    public ReadThreadClient(NetworkUtil networkUtil, Club club) {
        this.networkUtil = networkUtil;
        this.club = club;
        clubPLayersList = new ArrayList<>();
        this.thr = new Thread(this);
        thr.start();
    }

    public static List<Player> getClubPlayersInfo() {
        return clubPLayersList;
    }

    public static void addBoughtPlayer(Player boughtPLayer){
        clubPLayersList.add(boughtPLayer);
    }

    public static void removeAuctionedPlayer(Player auctionedPLayer){
        clubPLayersList.remove(auctionedPLayer);
    }

    public void run() {
        try {
            while (true) {
                Object o = networkUtil.read();

                if(o instanceof String){
                    String feedback = (String) o;
                    club.setValid(Boolean.parseBoolean(feedback));
                }
                if(o instanceof ClubPlayersListString){
                    ClubPlayersListString obj = (ClubPlayersListString) o;
                    getPlayersFromStringsList(obj.getClubPlayersData());
                }
                if(o instanceof AuctionedPlayersData){
                    AuctionedPlayersData auctionedPlayersFromServer = (AuctionedPlayersData) o;
                    auctionedPlayersInClub.addAll(auctionedPlayersFromServer.getAuctionedPlayersData());
                    //System.out.println("ReadThreadClient: " + "AuctionedPLayers = " + auctionedPlayersInClub);
                    List<String> lastAuctionedPlayer = new ArrayList<>();
                    lastAuctionedPlayer.add(auctionedPlayersInClub.get(auctionedPlayersInClub.size() - 1));
                    if(!lastAuctionedPlayer.get(0).split(",")[0].equals(club.getBoughtPlayer().getName())) {
                        getAuctionedPlayersFromStringsList(lastAuctionedPlayer);
                    }
                }
            }
        } catch (Exception e) {
            System.out.println("ReadThreadClient: " + e.getMessage());
        } finally {
            try {
                networkUtil.closeConnection();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void getPlayersFromStringsList(List<String> a_clubPlayersList){
        for(String line : a_clubPlayersList) {
            Player player = new Player();
            String[] playerInfo = line.split(",");
            player.setName(playerInfo[0]);
            player.setCountry(playerInfo[1]);
            player.setAge(Integer.parseInt(playerInfo[2]));
            player.setHeight(Double.parseDouble(playerInfo[3]));
            player.setClub(playerInfo[4]);
            player.setPosition(playerInfo[5]);
            player.setNumber(Integer.parseInt(playerInfo[6]));
            player.setWeeklySalary(Double.parseDouble(playerInfo[7]));
            player.setPrice(Double.parseDouble(playerInfo[8]));

            clubPLayersList.add(player);
        }
    }

    public void getAuctionedPlayersFromStringsList(List<String> clubAuctionedPLayersList){
        for(String line : clubAuctionedPLayersList) {
            Player player = new Player();
            String[] playerInfo = line.split(",");
            player.setName(playerInfo[0]);
            player.setCountry(playerInfo[1]);
            player.setAge(Integer.parseInt(playerInfo[2]));
            player.setHeight(Double.parseDouble(playerInfo[3]));

            if(playerInfo[4].equals(club.getClubInfo().getClientInfo().split(",")[0])){
                continue;
            }

            player.setClub(playerInfo[4]);
            player.setPosition(playerInfo[5]);
            player.setNumber(Integer.parseInt(playerInfo[6]));
            player.setWeeklySalary(Double.parseDouble(playerInfo[7]));
            player.setPrice(Double.parseDouble(playerInfo[8]));

            auctionedPlayersInThisClub.add(player);
        }
    }
}
