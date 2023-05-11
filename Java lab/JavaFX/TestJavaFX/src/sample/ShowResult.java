package sample;

import java.util.List;

public class ShowResult {
    public static void show(List<Player> players, String errorMessage){
        if(!players.isEmpty()){
            for(Player p : players){
                System.out.println(p.showPlayerInfo());
            }
        } else {
            System.out.println(errorMessage);
        }
    }

    public static void show(Double totalClubSalary, String errorMessage){
        if(totalClubSalary == -1){
            System.out.println(errorMessage);
        } else {
            System.out.println(totalClubSalary);
        }
    }

    public static void show(List<String> players){
        for (String player : players) {
            System.out.println(player);
        }
    }

}
