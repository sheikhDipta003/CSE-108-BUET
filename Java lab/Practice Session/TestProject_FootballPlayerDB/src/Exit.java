import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.List;

public class Exit extends Main {

    private static final String IN_TEXT = "players.txt";

    public static void exit(List<Player> playersList){
        try{
            writeToFile(playersList);
        }catch (Exception e){
            System.out.println("An error occurred while writing to IN_TEXT");
        }
    }

    public static void writeToFile(List<Player> playersList) throws Exception{
        BufferedWriter bw = new BufferedWriter(new FileWriter(IN_TEXT));

        for(Player p : playersList){
            bw.write(p.showPlayerInfo() + "\n");
        }

        bw.close();
    }
}
