package Football_DB.server;

import Football_DB.data.Player;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class FileIO {
    private static final String IN_TEXT = "players.txt";
    private static final List<Player> playersList = new ArrayList<>();
    private static final List<String> clubsList = new ArrayList<>();
    private static final List<String> clubWisePlayerCount = new ArrayList<>();
    private static final List<String> countryList = new ArrayList<>();
    public static HashMap<String, String> clientInfoMap = new HashMap<>();
    private static final List<String> lines = new ArrayList<>();

    public static List<Player> getPlayersList() {
        return playersList;
    }

    public static List<String> getCountryList() {
        return countryList;
    }

    public static List<String> getLines() {
        return lines;
    }

    public static void readFromFile() throws Exception{
        BufferedReader br = new BufferedReader(new FileReader(IN_TEXT));

        while(true){
            String line = br.readLine();

            if(line == null){
                break;
            }

            lines.add(line);

            String[] playerInfo = line.split(",");

            Player player = new Player();
            player.setName(playerInfo[0]);

            player.setCountry(playerInfo[1]);

            if(!countryList.contains(player.getCountry())){
                countryList.add(player.getCountry());
            }

            player.setAge(Integer.parseInt(playerInfo[2]));
            player.setHeight(Double.parseDouble(playerInfo[3]));
            player.setClub(playerInfo[4]);

            if(!clubsList.contains(player.getClub())){
                clubsList.add(player.getClub());
            }

            player.setPosition(playerInfo[5]);
            player.setNumber(Integer.parseInt(playerInfo[6]));
            player.setWeeklySalary(Double.parseDouble(playerInfo[7]));
            player.setPrice(Double.parseDouble(playerInfo[8]));

            playersList.add(player);
        }

        for(int i = 0 ; i < clubsList.size() ; i++){
            int count = 0;

            for(Player p : playersList){
                if(p.getClub().equalsIgnoreCase(clubsList.get(i))){
                    count++;
                }
            }
            clubWisePlayerCount.add(i, String.valueOf(count));
        }

        //sort the clubsList so that passwords do not change due to different ordering of data in the file
        Collections.sort(clubsList);    //ascending order

        br.close();
    }

    public static HashMap<String, String> getClientInfoMap() {
        return clientInfoMap;
    }

    public static void writeToFile(List<Player> playersList) throws Exception{
        lines.clear();
        playersList.forEach(player -> lines.add(player.showPlayerInfo()));

        BufferedWriter bw = new BufferedWriter(new FileWriter(IN_TEXT));

        for(Player p : playersList){
            bw.write(p.showPlayerInfo() + "\n");
        }
        bw.close();
    }

    public static void setClientInfoMap() {
        for(int i = 0 ; i <  clubsList.size() ; i++){
            clientInfoMap.put(clubsList.get(i), "11" + (i+1));
        }
        //Arsenal - 111
        //Chelsea - 112
        //Liverpool - 113
        //Manchester City - 114
        //Manchester United - 115
    }
}
