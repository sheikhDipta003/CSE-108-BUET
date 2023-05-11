package Football_DB.controller;

import Football_DB.club.ReadThreadClient;
import Football_DB.data.Player;
import Football_DB.main.Main;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

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
    public TextField textFieldSearchSalLow;
    @FXML
    public TextField textFieldSearchSalUp;
    @FXML
    public Button addNewPlayerBtn;
    public Main main;
    private List<Player> clubPlayers = ReadThreadClient.getClubPlayersInfo();
    private String thisClubName;

    public void setMain(Main main) {
        this.main = main;
    }

    public void mainExit(ActionEvent actionEvent) {
        try {
            main.getClub().getNetworkUtil().closeConnection();
            main.showLogin();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void searchForPlayers(ActionEvent actionEvent) {
        thisClubName = main.getClub().getClubInfo().getClientInfo().split(",")[0];

        if (searchOptions.getSelectionModel().getSelectedItem().equals("By player name")) {
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byPlayerName(clubPlayers, textFieldSearchName.getText());
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    main.showPlayersInfo(false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Player not found!", "No such player with this name");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("By club and country")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byClubCountry(clubPlayers, textFieldSearchCountry.getText(), thisClubName);
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    main.showPlayersInfo(false);
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
                    main.showPlayersInfo(false);
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
                    main.showPlayersInfo(false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Player not found!", "No such player with this weekly salary range");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Players with max salary")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byMaxSalary(clubPlayers, thisClubName);
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    main.showPlayersInfo(false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Players with max age")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byMaxAge(clubPlayers, thisClubName);
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    main.showPlayersInfo(false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if(searchOptions.getSelectionModel().getSelectedItem().equals("Players with max height")){
            ShowPlayersController spc = new ShowPlayersController();
            ObservableList<Player> searchPlayers = byMaxHeight(clubPlayers, thisClubName);
            spc.show(searchPlayers);

            if(!searchPlayers.isEmpty()){
                try {
                    main.showPlayersInfo(false);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else{
                showErrorMessage("Club not found!", "No such club with this name");
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Country-wise player count")){
            CountryWisePlayerCount cwpc = new CountryWisePlayerCount();
            try {
                main.showCountryWiseCount();
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else if (searchOptions.getSelectionModel().getSelectedItem().equals("Total yearly salary")){
            Double totalYearlySalary = byTotalYearlySalary(clubPlayers, thisClubName);

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
            searchPlayers.removeIf(player -> player.getName().equals(main.getAuctionedPlayer().split(",")[0]));
            searchPlayers.forEach(player -> {
                if(!player.getClub().equals(thisClubName)){
                    player.setClub(thisClubName);
                }
            });
            spc.show(searchPlayers);

            try{
                main.showPlayersInfo(true);
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
        for(Player p : ReadThreadClient.getClubPlayersInfo()){
            searchPlayers.removeIf(player -> player.getName().equals(p.getName()));
            searchPlayers.removeIf(player -> player.getClub().equals(main.getClub().getClubInfo().getClientInfo().split(",")[0]));
        }
        ObservableList<Player> searchPlayersDistinct = FXCollections.observableArrayList(searchPlayers.stream().distinct().collect(Collectors.toList()));
        spc.show(searchPlayersDistinct);

        try {
            main.showPlayersInfo(false);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @FXML
    public void addPlayerToAClub(ActionEvent actionEvent) {
        try{
            main.showAddPlayer();
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
