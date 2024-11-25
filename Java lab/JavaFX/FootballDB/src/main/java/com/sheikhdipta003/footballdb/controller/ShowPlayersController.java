package com.sheikhdipta003.footballdb.controller;

import com.sheikhdipta003.footballdb.club.ReadThreadClient;
import com.sheikhdipta003.footballdb.data.Player;
import com.sheikhdipta003.footballdb.main.Main;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;

import java.net.URL;
import java.util.ResourceBundle;

public class ShowPlayersController implements Initializable {

    @FXML
    public TableView<Player> tablePlayersInfo = new TableView<>();
    @FXML
    public TableColumn<Player, String> showName = new TableColumn<>("Name");
    @FXML
    public TableColumn<Player, String> showCountry = new TableColumn<>("Country");
    @FXML
    public TableColumn<Player, Integer> showAge = new TableColumn<>("Age");
    @FXML
    public TableColumn<Player, String> showClub = new TableColumn<>("Club");
    @FXML
    public TableColumn<Player, Double> showHeight = new TableColumn<>("Height");
    @FXML
    public TableColumn<Player, String> showPosition = new TableColumn<>("Position");
    @FXML
    public TableColumn<Player, Integer> showNumber = new TableColumn<>("Number");
    @FXML
    public TableColumn<Player, Double> showSalary = new TableColumn<>("Salary");
    @FXML
    public TableColumn<Player, Double> showPrice = new TableColumn<>("Price");
    private static ObservableList<Player> players = FXCollections.observableArrayList();
    public Main main;
    @FXML
    public Button showPlayersBackBtn;
    @FXML
    public Button auctionButton;
    @FXML
    public Button refreshBtn;
    @FXML
    public Button confirmBuyBtn;

    public void setAllPlayersClicked(boolean allPlayersClicked) {
        auctionButton.setVisible(allPlayersClicked);
    }

    public void setMain(Main main) {
        this.main = main;
    }

    synchronized public void show(ObservableList<Player> a_players) {
        players = a_players;
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        showName.setCellValueFactory(new PropertyValueFactory<>("Name"));
        showCountry.setCellValueFactory(new PropertyValueFactory<>("Country"));
        showClub.setCellValueFactory(new PropertyValueFactory<>("Club"));
        showPosition.setCellValueFactory(new PropertyValueFactory<>("Position"));
        showAge.setCellValueFactory(new PropertyValueFactory<>("Age"));
        showHeight.setCellValueFactory(new PropertyValueFactory<>("Height"));
        showSalary.setCellValueFactory(new PropertyValueFactory<>("WeeklySalary"));
        showNumber.setCellValueFactory(new PropertyValueFactory<>("Number"));
        showPrice.setCellValueFactory(new PropertyValueFactory<>("Price"));
        tablePlayersInfo.setItems(players);
    }

    @FXML
    public void backToHome(ActionEvent actionEvent) {
        try {
            main.showHome();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @FXML
    public void sendAuctionReq(ActionEvent actionEvent) {
        Player selectedItem = tablePlayersInfo.getSelectionModel().getSelectedItem();
        main.setAuctionedPlayer(selectedItem.showPlayerInfo());
        tablePlayersInfo.getItems().remove(selectedItem);
        ReadThreadClient.removeAuctionedPlayer(selectedItem);
    }

    @FXML
    public void refreshTableView(ActionEvent actionEvent) {
        tablePlayersInfo.getItems().clear();
        ObservableList<Player> list = FXCollections.observableArrayList();
        list.addAll(ReadThreadClient.auctionedPlayersInThisClub);

        //see if some player in auctionedPLayersList is already in the clubPLayersList
        for (Player p : ReadThreadClient.getClubPlayersInfo()) {
            list.removeIf(player -> player.getName().equals(p.getName()));
            list.removeIf(player -> player.getClub().equals(main.getClub().getClubInfo().getClientInfo().split(",")[0]));
        }
        tablePlayersInfo.setItems(list);
    }

    @FXML
    public void confirmBuyPlayer(ActionEvent actionEvent) {
        if (tablePlayersInfo.getSelectionModel().getSelectedItem() != null) {
            Alert a = new Alert(Alert.AlertType.CONFIRMATION);
            a.setHeaderText("Confirm Buy");
            a.setContentText("Buy " + tablePlayersInfo.getSelectionModel().getSelectedItem().getName() + " with " + tablePlayersInfo.getSelectionModel().getSelectedItem().getPrice() + " dollars?");
            a.showAndWait();

            if (a.getResult().equals(ButtonType.OK)) {
                Player selectedItem = tablePlayersInfo.getSelectionModel().getSelectedItem();

                main.getClub().setBoughtPlayer(selectedItem);
                tablePlayersInfo.getItems().remove(selectedItem);

                //add newly bought player to the buying club
                selectedItem.setClub(main.getClub().getClubInfo().getClientInfo().split(",")[0]);
                ReadThreadClient.addBoughtPlayer(selectedItem);
            }
        } else {
            Alert a = new Alert(Alert.AlertType.ERROR);
            a.setHeaderText("No player selected");
            a.setContentText("Select a player to buy");
            a.showAndWait();
        }
    }
}
