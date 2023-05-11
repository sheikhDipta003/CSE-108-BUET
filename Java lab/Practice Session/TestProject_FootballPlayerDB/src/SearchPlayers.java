import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SearchPlayers extends Main {

    public static void searchPlayers(List<Player> playersList, List<String> countryList){
        Scanner scanner = new Scanner(System.in);

        do{
            //Player Searching Options:
            //(1) By Player Name
            //(2) By Club and Country
            //(3) By Position
            //(4) By Salary Range
            //(5) Country-wise player count
            //(6) Back to Main Menu
            System.out.println("Player Searching Options:");
            System.out.println("(1) By Player Name");
            System.out.println("(2) By Club and Country");
            System.out.println("(3) By Position");
            System.out.println("(4) By Salary Range");
            System.out.println("(5) Country-wise player count");
            System.out.println("(6) Back to Main Menu");
            System.out.print(": ");

            int searchPlayerInput = Integer.parseInt(scanner.nextLine());

            if(searchPlayerInput == 1){
                System.out.print("Enter the name of the player: ");
                String searchName = scanner.nextLine();

                System.out.println(byPlayerName(playersList, searchName));

            } else if(searchPlayerInput == 2){
                System.out.print("Enter the country: ");
                String searchCountry = scanner.nextLine();

                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();

                ShowResult.show(byClubCountry(playersList, searchCountry, searchClub), "No such player with this country and club");

            } else if(searchPlayerInput == 3){
                System.out.print("Enter the Position: ");
                String searchPos = scanner.nextLine();

                ShowResult.show(byPosition(playersList, searchPos), "No such player with this position");

            } else if(searchPlayerInput == 4){
                System.out.print("Enter lower limit of salary: ");
                double salaryLower = Double.parseDouble(scanner.nextLine());

                System.out.print("Enter upper limit of salary: ");
                double salaryUpper = Double.parseDouble(scanner.nextLine());

                ShowResult.show(bySalaryRange(playersList, salaryLower, salaryUpper), "No such player with this weekly salary range");

            } else if(searchPlayerInput == 5){
                ShowResult.show(byPlayerCount(playersList, countryList));
            } else if(searchPlayerInput == 6){
                break;
            } else{
                System.out.println("Please enter an integer between 1 and 6");
            }

        }while(true);
    }

    public static String byPlayerName(List<Player> playersList, String searchName){
        for(Player p : playersList){
            if(p.getName().equalsIgnoreCase(searchName)){
                return p.showPlayerInfo();
            }
        }
        return ("No such player with this name");
    }

    public static List<Player> byClubCountry(List<Player> playersList, String searchCountry, String searchClub){
        List<Player> playersClubCountry = new ArrayList<>();

        for(Player p : playersList){
            if(p.getCountry().equalsIgnoreCase(searchCountry) && (searchClub.equalsIgnoreCase(p.getClub()) || searchClub.equalsIgnoreCase("ANY")) ){
                playersClubCountry.add(p);
            }
        }

        return playersClubCountry;
    }

    public static List<Player> byPosition(List<Player> playersList, String searchPos){
        List<Player> playersPosition = new ArrayList<>();

        for(Player p : playersList){
            if(p.getPosition().equalsIgnoreCase(searchPos)){
                playersPosition.add(p);
            }
        }

        return playersPosition;
    }

    public static List<Player> bySalaryRange(List<Player> playersList, Double salaryLower, Double salaryUpper){
        List<Player> playersSalaryRange = new ArrayList<>();

        for(Player p : playersList){
            if(p.getWeeklySalary() >= salaryLower && p.getWeeklySalary() <= salaryUpper){
                playersSalaryRange.add(p);
            }
        }

        return playersSalaryRange;
    }

    public static List<String> byPlayerCount(List<Player> playersList, List<String> countryList){
        List<String> playersCountryCount = new ArrayList<>();

        for(String c: countryList){
            int playersCount = 0;

            for(Player player : playersList){
                if(c.equalsIgnoreCase(player.getCountry())){
                    playersCount++;
                }
            }

            playersCountryCount.add(c + " - " + playersCount);
        }

        return playersCountryCount;
    }
}
