import java.util.List;

public class AddPlayer extends Main {

    public static void addPlayer(List<Player> playersList){
        Player player = new Player();
        getPlayerInfo(player);
        playersList.add(player);
    }
}
