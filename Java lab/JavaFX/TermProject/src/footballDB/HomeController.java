package footballDB;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class HomeController{
    @FXML
    public Button mainExitBtn;
    @FXML
    public ChoiceBox<String> searchOptions;
    @FXML
    public ComboBox<String> comboBoxSearchPosition;
    @FXML
    public Button mainSearchBtn;
    @FXML
    public TextField textFieldSearchName;
    @FXML
    public TextField textFieldSearchCountry;
    @FXML
    public TextField textFieldSearchClub;
    @FXML
    public TextField textFieldSearchSalLow;
    @FXML
    public TextField textFieldSearchSalUp;
    @FXML
    public Label labelClubName;
    @FXML
    private Button mainAddBtn;
    public Main main;
    private List<Player> clubPlayers = ReadThreadClient.getClubPlayersInfo();
    //public boolean isBuyPlayerBtnClicked = false;


    public List<Player> getClubPlayers() {
        return clubPlayers;
    }

    public void addBoughtPlayer(Player boughtPLayer){
        clubPlayers.add(boughtPLayer);
    }

    public void setMain(Main main) {
        this.main = main;
    }

    public void setHeaderText(String headerText){
        labelClubName.setText(headerText);
    }

    /*public void mainAddPlayer(ActionEvent actionEvent) {
        *//*mainAddBtn.setOnAction(actionEvent1 -> {

        });*//*
        //System.out.println("Hello..");
        //Main main = new Main();
        try {
            main.showAddPlayer("Add a new player");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
        //System.out.println("Cool! Everything is working fine :)");
    }*/


    public void mainExit(ActionEvent actionEvent) {
        /*mainExitBtn.setOnAction(actionEvent1 -> {

        });*/
        Node source = (Node) actionEvent.getSource();
        Stage stage = (Stage) source.getScene().getWindow();
        stage.close();
    }

    public void searchForPlayers(ActionEvent actionEvent) {
        if (searchOptions.getSelectionModel().getSelectedItem().equals("By player name")) {
            ShowPlayersController spc = new ShowPlayersController();
            //System.out.println(getPlayersList());
            //System.out.println(textFieldSearchName.getText());
            ObservableList<Player> searchPlayers = byPlayerName(clubPlayers, textFieldSearchName.getText());
            //System.out.println("searchPlayers is Empty: " + searchPlayers.isEmpty());
            spc.show(searchPlayers);
            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Player not found!", "No such player with this name");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("By club and country")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byClubCountry(clubPlayers, textFieldSearchCountry.getText(), textFieldSearchClub.getText());
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Player not found!", "No such player with this country and club");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("By position")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byPosition(clubPlayers, comboBoxSearchPosition.getSelectionModel().getSelectedItem());
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Player not found!", "No such player with this position");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("By salary range")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = bySalaryRange(clubPlayers, Double.parseDouble(textFieldSearchSalLow.getText()), Double.parseDouble(textFieldSearchSalUp.getText()));
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Player not found!", "No such player with this weekly salary range");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Players with max salary")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byMaxSalary(clubPlayers, textFieldSearchClub.getText());
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Players with max age")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byMaxAge(clubPlayers, textFieldSearchClub.getText());
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if(searchOptions.getSelectionModel().getSelectedItem().equals("Players with max height")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byMaxHeight(clubPlayers, textFieldSearchClub.getText());
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    //Main main = new Main();
                    main.showPlayersInfo("Searched player information", false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Country-wise player count")){
            CountryWisePlayerCount cwpc = new CountryWisePlayerCount();
            try {
                //Main main = new Main();
                main.showCountryWiseCount("Country-wise number of players");
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Total yearly salary")){
            Double totalYearlySalary = byTotalYearlySalary(clubPlayers, textFieldSearchClub.getText());

            if(totalYearlySalary != -1){
                Alert a = new Alert(Alert.AlertType.INFORMATION);
                a.setHeaderText("Yearly salary");
                a.setContentText("Total Yearly Salary of the club is : " + totalYearlySalary);
                a.showAndWait();
            } else {
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if(searchOptions.getSelectionModel().getSelectedItem().equals("All players of this club")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = FXCollections.observableArrayList();
            searchPlayers.addAll(clubPlayers);
            spc.show(searchPlayers);
            try{
                main.showPlayersInfo("All Players", true);
            } catch (Exception e){
                e.printStackTrace();
            }
        }
    }

    public static ObservableList<Player> byPlayerName(List<Player> playersList, String searchName) {
        ObservableList<Player> players = FXCollections.observableArrayList();
        for (Player p : playersList) {
            if (p.getName().equalsIgnoreCase(searchName)) {
                players.add(p);
            }
        }
        return players;
    }

    public static ObservableList<Player> byClubCountry(List<Player> playersList, String searchCountry, String searchClub){
        ObservableList<Player> players = FXCollections.observableArrayList();

        for(Player p : playersList){
            if(p.getCountry().equalsIgnoreCase(searchCountry) && (searchClub.equalsIgnoreCase(p.getClub()) || searchClub.equalsIgnoreCase("ANY")) ){
                players.add(p);
            }
        }

        return players;
    }

    public static ObservableList<Player> byPosition(List<Player> playersList, String searchPos){
        ObservableList<Player> players = FXCollections.observableArrayList();

        for(Player p : playersList){
            if(p.getPosition().equalsIgnoreCase(searchPos)){
                players.add(p);
            }
        }

        return players;
    }

    public static ObservableList<Player> bySalaryRange(List<Player> playersList, Double salaryLower, Double salaryUpper){
        ObservableList<Player> players = FXCollections.observableArrayList();

        for(Player p : playersList){
            if(p.getWeeklySalary() >= salaryLower && p.getWeeklySalary() <= salaryUpper){
                players.add(p);
            }
        }

        return players;
    }

    public static ObservableList<Player> byMaxSalary(List<Player> playersList, String searchClub){
        double maxWeeklySalary = -1;
        ObservableList<Player> players = FXCollections.observableArrayList();

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                if(p.getWeeklySalary() > maxWeeklySalary){
                    maxWeeklySalary = p.getWeeklySalary();
                }
            }
        }

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub) && p.getWeeklySalary() == maxWeeklySalary){
                players.add(p);
            }
        }

        return players;
    }

    public static ObservableList<Player> byMaxAge(List<Player> playersList, String searchClub){
        int maxAge = -1;
        ObservableList<Player> players = FXCollections.observableArrayList();

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                if(p.getAge() > maxAge){
                    maxAge = p.getAge();
                }
            }
        }

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub) && p.getAge() == maxAge){
                players.add(p);
            }
        }

        return players;
    }

    public static ObservableList<Player> byMaxHeight(List<Player> playersList, String searchClub){
        double maxHeight = -1;
        ObservableList<Player> players = FXCollections.observableArrayList();

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub)){
                if(p.getHeight() > maxHeight){
                    maxHeight = p.getHeight();
                }
            }
        }

        for(Player p : playersList){
            if(p.getClub().equalsIgnoreCase(searchClub) && p.getHeight() == maxHeight){
                players.add(p);
            }
        }

        return players;
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

    public void showErrorMessage(String headerText, String contentText){
        Alert a = new Alert(Alert.AlertType.ERROR);
        a.setHeaderText(headerText);
        a.setContentText(contentText);
        a.showAndWait();
    }

    public void showAuctionedPLayers(ActionEvent actionEvent) {
        main.setBuyPlayerBtnClicked(true);

        ShowPlayersController spc = new ShowPlayersController();
        ObservableList<Player> searchPlayers = FXCollections.observableArrayList(ReadThreadClient.auctionedPlayersInThisClub);

        spc.show(searchPlayers);

        try {
            //Main main = new Main();
            main.showPlayersInfo("Searched player information", false);
        } catch (IOException e) {
            e.printStackTrace();
        }

        /*if(!searchPlayers.isEmpty()){
            try {
                //Main main = new Main();
                main.showPlayersInfo("Searched player information", false);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else{
            showErrorMessage("Club not found!", "No such club with this name");
        }*/
    }
}
