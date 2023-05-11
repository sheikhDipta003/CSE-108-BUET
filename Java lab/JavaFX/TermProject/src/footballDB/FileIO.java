package footballDB;

import javafx.fxml.Initializable;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.ResourceBundle;

public class FileIO implements Initializable {
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

    public static List<String> getClubsList() {
        return clubsList;
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
            player.setPrize(Double.parseDouble(playerInfo[8]));

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

        br.close();
    }

    public static HashMap<String, String> getClientInfoMap() {
        for(int i = 0 ; i <  clubsList.size() ; i++){
            clientInfoMap.put(clubsList.get(i), "111");
        }
        return clientInfoMap;
    }

    public static void writeToFile(List<Player> playersList) throws Exception{
        BufferedWriter bw = new BufferedWriter(new FileWriter(IN_TEXT));

        for(Player p : playersList){
            bw.write(p.showPlayerInfo() + "\n");
        }

        bw.close();
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }
}
