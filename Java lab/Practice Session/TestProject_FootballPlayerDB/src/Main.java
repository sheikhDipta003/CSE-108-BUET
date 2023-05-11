import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final int MAX_PLAYER_COUNT_PER_CLUB = 7;
    private static final String IN_TEXT = "players.txt";
    private static final String[] positions = {"Goalkeeper", "Defender", "Midfielder", "Forward"};
    private static final List<Player> playersList = new ArrayList<>();
    private static final List<String> clubsList = new ArrayList<>();
    private static final List<String> clubWisePlayerCount = new ArrayList<>();
    private static final List<String> countryList = new ArrayList<>();

    public static void readFromFile() throws Exception{
        BufferedReader br = new BufferedReader(new FileReader(IN_TEXT));

        while(true){
            String line = br.readLine();

            if(line == null){
                break;
            }

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

    public static void getPlayerInfo(Player player){    //from console
        Scanner scanner = new Scanner(System.in);
        boolean isNamePresent = false;
        boolean isPositionPresent = false;

        do{
            System.out.print("Name: ");
            player.setName(scanner.nextLine());
            for(Player p : playersList){
                if(p.getName().equalsIgnoreCase(player.getName())){
                    isNamePresent = true;
                    System.out.println("This name already exists");
                    break;
                }
                else{
                    isNamePresent = false;
                }
            }
        }while(isNamePresent);

        System.out.print("Country: ");
        player.setCountry(scanner.nextLine());
        System.out.print("Age: ");
        player.setAge(Integer.parseInt(scanner.nextLine()));
        System.out.print("Height: ");
        player.setHeight(Double.parseDouble(scanner.nextLine()));

        do{
            System.out.print("Club: ");
            player.setClub(scanner.nextLine());

            //check if maximum player count has been crossed or not
            int clubIndex = clubsList.indexOf(player.getClub());
            if(clubIndex == -1){
                clubsList.add(player.getClub());
                clubWisePlayerCount.add("0");
                break;
            }
            else{
                int playerCount = Integer.parseInt(clubWisePlayerCount.get(clubIndex));
                if(playerCount == MAX_PLAYER_COUNT_PER_CLUB){
                    System.out.println("This club is full");
                }
                else{
                    break;
                }
            }

        }while(true);

        do{
            System.out.print("Position: ");
            String pos = scanner.nextLine().strip();

            for(String s : positions){
                if(s.equals(pos)){
                    player.setPosition(pos);
                    isPositionPresent = true;
                    break;
                }
            }

            if(!isPositionPresent){
                System.out.println("Select one among these : ");
                for(int i = 0 ; i < positions.length ; i++){
                    if(i != positions.length - 1){
                        System.out.print("\"" + positions[i] + "\", ");
                    }
                    else{
                        System.out.print("\"" + positions[i] + "\"\n");
                    }
                }
            }
            else{
                break;
            }

        } while(true);
        System.out.print("Number: ");
        player.setNumber(Integer.parseInt(scanner.nextLine()));
        System.out.print("WeeklySalary: ");
        player.setWeeklySalary(Double.parseDouble(scanner.nextLine()));
    }

    public static void main(String[] args) {

        try{
            readFromFile();
        } catch (Exception e){
            System.out.println("An error occurred while reading from IN_TXT");
        }

        do{
            //(1) Search Players
            //(2) Search Clubs
            //(3) Add Player
            //(4) Exit System
            System.out.println("Main Menu:");
            System.out.println("(1) Search Players");
            System.out.println("(2) Search Clubs");
            System.out.println("(3) Add Player");
            System.out.println("(4) Exit System");

            System.out.print(": ");
            Scanner scanner = new Scanner(System.in);

            int mainInput = Integer.parseInt(scanner.nextLine());

            if(mainInput == 1){
                SearchPlayers.searchPlayers(playersList, countryList);
            } else if(mainInput == 2){
                SearchClubs.searchClubs(playersList);
            } else if(mainInput == 3){
                AddPlayer.addPlayer(playersList);
            } else if(mainInput == 4){
                Exit.exit(playersList);
                break;
            } else{
                System.out.println("Please enter an integer between 1 and 4");
            }

        }while(true);
    }
}
