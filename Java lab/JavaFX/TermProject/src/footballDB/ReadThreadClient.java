package footballDB;

import myUtil.NetworkUtil;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReadThreadClient implements Runnable{
    private Thread thr;
    private NetworkUtil networkUtil;
    private static List<Player> clubPLayersList;
    private final Club2 club2;
    public static List<String> auctionedPlayersInClub;
    public static List<Player> auctionedPlayersInThisClub;

    public ReadThreadClient(NetworkUtil networkUtil, Club2 club2) {
        this.networkUtil = networkUtil;
        this.club2 = club2;
        clubPLayersList = new ArrayList<>();
        //auctionedPlayersInClub = new ArrayList<>();
        this.thr = new Thread(this);
        thr.start();
    }

    public static List<Player> getClubPlayersInfo() {
        return clubPLayersList;
    }

    public void run() {
        try {
            while (true) {
                Object o = networkUtil.read();
                /*if (o instanceof Message) {
                    Message obj = (Message) o;
                    System.out.println(obj.getFrom() + ", " + obj.getTo() + ", " + obj.getText());
                }*/
                if(o instanceof String){
                    String feedback = (String) o;
                    club2.setValid(Boolean.parseBoolean(feedback));
                }
                if(o instanceof ClubFileIO){
                    ClubFileIO clubFileIO = (ClubFileIO) o;
                    getPlayersFromStringsList(clubFileIO.getClubPlayersList());
                }
                if(o instanceof AuctionedPlayersData){
                    AuctionedPlayersData auctionedPlayersFromServer = (AuctionedPlayersData) o;
                    auctionedPlayersInClub.addAll(auctionedPlayersFromServer.getAuctionedPlayersData());
                    System.out.println("ReadThreadClient: " + "AuctionedPLayers = " + auctionedPlayersInClub);
                    List<String> lastAuctionedPlayer = new ArrayList<>();
                    lastAuctionedPlayer.add(auctionedPlayersInClub.get(auctionedPlayersInClub.size() - 1));
                    getAuctionedPlayersFromStringsList(lastAuctionedPlayer);
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
            player.setPrize(Double.parseDouble(playerInfo[8]));

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

            if(playerInfo[4].equals(club2.getClubInfo().getClientInfo().split(",")[0])){
                continue;
            }

            player.setClub(playerInfo[4]);
            player.setPosition(playerInfo[5]);
            player.setNumber(Integer.parseInt(playerInfo[6]));
            player.setWeeklySalary(Double.parseDouble(playerInfo[7]));
            player.setPrize(Double.parseDouble(playerInfo[8]));

            auctionedPlayersInThisClub.add(player);
        }
    }
}
