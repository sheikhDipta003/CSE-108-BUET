import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SearchClubs extends Main {

    public static void searchClubs(List<Player> playersList){
        Scanner scanner = new Scanner(System.in);

        do{
            //Club Searching Options:
            //(1) Player(s) with the maximum salary of a club
            //(2) Player(s) with the maximum age of a club
            //(3) Player(s) with the maximum height of a club
            //(4) Total yearly salary of a club
            //(5) Back to Main Menu
            System.out.println("Club Searching Options:");
            System.out.println("(1) Player(s) with the maximum salary of a club");
            System.out.println("(2) Player(s) with the maximum age of a club");
            System.out.println("(3) Player(s) with the maximum height of a club");
            System.out.println("(4) Total yearly salary of a club");
            System.out.println("(5) Back to Main Menu");
            System.out.print(": ");

            int searchClubInput = Integer.parseInt(scanner.nextLine());

            if(searchClubInput == 1){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();

                ShowResult.show(byMaxSalary(playersList, searchClub), "No such club with this name");

            } else if(searchClubInput == 2){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();

                ShowResult.show(byMaxAge(playersList, searchClub), "No such club with this name");

            } else if(searchClubInput == 3){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();

                ShowResult.show(byMaxHeight(playersList, searchClub), "No such club with this name");

            } else if(searchClubInput == 4){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();

                ShowResult.show(byTotalYearlySalary(playersList, searchClub), "No such club with this name");

            } else if(searchClubInput == 5){
                break;
            } else{
                System.out.println("Please enter an integer between 1 and 5");
            }

        }while(true);
    }

    public static List<Player> byMaxSalary(List<Player> playersList, String searchClub){
        double maxWeeklySalary = -1;
        List<Player> playersMexSalary = new ArrayList<>();

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                if(p.getWeeklySalary() > maxWeeklySalary){
                    maxWeeklySalary = p.getWeeklySalary();
                }
            }
        }

        for(Player p : playersList){
            if(p.getWeeklySalary() == maxWeeklySalary){
                playersMexSalary.add(p);
            }
        }

        return playersMexSalary;
    }

    public static List<Player> byMaxAge(List<Player> playersList, String searchClub){
        int maxAge = -1;
        List<Player> playersMaxAge = new ArrayList<>();

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                if(p.getAge() > maxAge){
                    maxAge = p.getAge();
                }
            }
        }

        for(Player p : playersList){
            if(p.getAge() == maxAge){
                playersMaxAge.add(p);
            }
        }

        return playersMaxAge;
    }

    public static List<Player> byMaxHeight(List<Player> playersList, String searchClub){
        double maxHeight = -1;
        List<Player> playersMaxHeight = new ArrayList<>();

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                if(p.getHeight() > maxHeight){
                    maxHeight = p.getHeight();
                }
            }
        }

        for(Player p : playersList){
            if(p.getHeight() == maxHeight){
                playersMaxHeight.add(p);
            }
        }

        return playersMaxHeight;
    }

    public static Double byTotalYearlySalary(List<Player> playersList, String searchClub){
        double totalYearlySalary = -1;

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                totalYearlySalary += 52 * p.getWeeklySalary();
            }
        }

        return totalYearlySalary;
    }

}
