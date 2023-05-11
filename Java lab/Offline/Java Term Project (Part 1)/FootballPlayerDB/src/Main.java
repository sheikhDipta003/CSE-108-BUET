import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static int MAX_PLAYER_COUNT_PER_CLUB = 7;
    private static int mainInput;
    private static int searchPlayerInput;
    private static int searchClubInput;
    private static final String IN_TEXT = "players.txt";
    private static String[] positions = {"Goalkeeper", "Defender", "Midfielder", "Forward"};
    private static List<Player> playersList = new ArrayList<>();
    private static List<String> clubsList = new ArrayList<>();
    private static List<String> clubWisePlayerCount = new ArrayList<>();
    private static List<String> countryList = new ArrayList<>();

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

    public static void writeToFile() throws Exception{
        BufferedWriter bw = new BufferedWriter(new FileWriter(IN_TEXT));

        for(Player p : playersList){
            bw.write(p.showPlayerInfo() + "\n");
        }

        bw.close();
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

    public static void searchPlayers(){

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

            searchPlayerInput = Integer.parseInt(scanner.nextLine());

            if(searchPlayerInput == 1){
                System.out.print("Enter the name of the player: ");
                String searchName = scanner.nextLine();
                boolean isFound = false;

                for(Player p : playersList){
                    if(p.getName().equalsIgnoreCase(searchName)){
                        System.out.println(p.showPlayerInfo());
                        isFound = true;
                        break;
                    }
                }

                if (!isFound){
                    System.out.println("No such player with this name");
                }

            } else if(searchPlayerInput == 2){
                System.out.print("Enter the country: ");
                String searchCountry = scanner.nextLine();

                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();

                boolean isFound = false;

                for(Player p : playersList){
                    if(p.getCountry().equalsIgnoreCase(searchCountry)){
                        if(searchClub.equalsIgnoreCase("ANY")){
                            System.out.println(p.showPlayerInfo());
                            isFound = true;
                        }
                        else{
                            if(p.getClub().equalsIgnoreCase(searchClub)){
                                System.out.println(p.showPlayerInfo());
                                isFound = true;
                                break;
                            }
                        }
                    }
                }

                if(!isFound){
                    System.out.println("No such player with this country and club");
                }

            } else if(searchPlayerInput == 3){
                System.out.print("Enter the Position: ");
                String searchPos = scanner.nextLine();
                boolean isFound = false;

                for(Player p : playersList){
                    if(p.getPosition().equalsIgnoreCase(searchPos)){
                        System.out.println(p.showPlayerInfo());
                        isFound = true;
                    }
                }

                if(!isFound){
                    System.out.println("No such player with this position");
                }

            } else if(searchPlayerInput == 4){
                System.out.print("Enter lower limit of salary: ");
                double salaryLower = Double.parseDouble(scanner.nextLine());

                System.out.print("Enter upper limit of salary: ");
                double salaryUpper = Double.parseDouble(scanner.nextLine());

                boolean isFound = false;

                for(Player p : playersList){
                    if(p.getWeeklySalary() >= salaryLower && p.getWeeklySalary() <= salaryUpper){
                        isFound = true;
                        System.out.println(p.showPlayerInfo());
                    }
                }

                if(!isFound){
                    System.out.println("No such player with this weekly salary range");
                }

            } else if(searchPlayerInput == 5){

                for(String c: countryList){
                    int playersCount = 0;

                    for(Player q : playersList){
                        if(c.equalsIgnoreCase(q.getCountry())){
                            playersCount++;
                        }
                    }

                    System.out.println(c + " - " + playersCount);
                }

            } else if(searchPlayerInput == 6){
                break;
            } else{
                System.out.println("Please enter an integer between 1 and 6");
            }

        }while(true);
    }

    public static void searchClubs(){

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

            searchClubInput = Integer.parseInt(scanner.nextLine());

            if(searchClubInput == 1){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();
                double maxWeeklySalary = 0;
                boolean isClubFound = false;

                for(Player p : playersList){
                    if(p.getClub().equalsIgnoreCase(searchClub)){
                        isClubFound = true;
                        if(p.getWeeklySalary() > maxWeeklySalary){
                            maxWeeklySalary = p.getWeeklySalary();
                        }
                    }
                }

                if(isClubFound){
                    for(Player q : playersList){
                        if(q.getWeeklySalary() == maxWeeklySalary){
                            System.out.println(q.showPlayerInfo());
                        }
                    }
                } else{
                    System.out.println("No such club with this name");
                }

            } else if(searchClubInput == 2){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();
                int maxAge = 0;
                boolean isClubFound = false;


                for(Player p : playersList){
                    if(p.getClub().equalsIgnoreCase(searchClub)){
                        isClubFound = true;
                        if(p.getAge() > maxAge){
                            maxAge = p.getAge();
                        }
                    }
                }

                if(isClubFound){
                    for(Player q : playersList){
                        if(q.getAge() == maxAge){
                            System.out.println(q.showPlayerInfo());
                        }
                    }
                } else{
                    System.out.println("No such club with this name");
                }

            } else if(searchClubInput == 3){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();
                double maxHeight = 0;
                boolean isClubFound = false;

                for(Player p : playersList){
                    if(p.getClub().equalsIgnoreCase(searchClub)){
                        isClubFound = true;
                        if(p.getHeight() > maxHeight){
                            maxHeight = p.getHeight();
                        }
                    }
                }

                if(isClubFound){
                    for(Player q : playersList){
                        if(q.getHeight() == maxHeight){
                            System.out.println(q.showPlayerInfo());
                        }
                    }
                } else{
                    System.out.println("No such club with this name");
                }

            } else if(searchClubInput == 4){
                System.out.print("Enter the club: ");
                String searchClub = scanner.nextLine();
                double totalYearlySalary = 0;
                boolean isClubFound = false;

                for(Player p : playersList){
                    if(p.getClub().equalsIgnoreCase(searchClub)){
                        isClubFound = true;
                        totalYearlySalary += 52 * p.getWeeklySalary();
                    }
                }

                if(isClubFound){
                    System.out.println("Total yearly salary = " + totalYearlySalary);
                } else{
                    System.out.println("No such club with this name");
                }

            } else if(searchClubInput == 5){
                break;
            } else{
                System.out.println("Please enter an integer between 1 and 5");
            }

        }while(true);

    }

    public static void addPlayer(){
        Player player = new Player();
        getPlayerInfo(player);
        playersList.add(player);
    }

    public static void exit(){
        try{
            writeToFile();
        }catch (Exception e){
            System.out.println("An error occurred while writing to IN_TEXT");
        }
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

            mainInput = Integer.parseInt(scanner.nextLine());

            if(mainInput == 1){
                searchPlayers();
            } else if(mainInput == 2){
                searchClubs();
            } else if(mainInput == 3){
                addPlayer();
            } else if(mainInput == 4){
                exit();
                break;
            } else{
                System.out.println("Please enter an integer between 1 and 4");
            }

        }while(true);
    }
}
