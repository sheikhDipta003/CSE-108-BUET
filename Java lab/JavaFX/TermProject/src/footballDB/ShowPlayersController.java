package footballDB;

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
    public TableColumn<Player, Double> showPrize = new TableColumn<>("Prize");
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

    public void show(ObservableList<Player> a_players) {
        players = a_players;
        //refreshBtn.setVisible(main.IsBuyPlayerBtnClicked());
        //tablePlayersInfo.getColumns().addAll(showName, showCountry, showAge, showHeight, showClub, showPosition, showNumber, showSalary);
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
        showPrize.setCellValueFactory(new PropertyValueFactory<>("Prize"));
        /*for(int i = 0 ; i < players.size() ; i++){
            tablePlayersInfo.getItems().set(i, players.get(i));
        }*/
        /*ObservableList<Player> list = FXCollections.observableArrayList();
        list.addAll(ReadThreadClient.auctionedPlayersInThisClub);*/
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
        //System.out.println(tablePlayersInfo.getSelectionModel().getSelectedItem().getName());
        //System.out.println("Showplayersinfo : " + "main = " + main);
        main.setAuctionedPlayer(tablePlayersInfo.getSelectionModel().getSelectedItem().showPlayerInfo());
    }

    @FXML
    public void refreshTableView(ActionEvent actionEvent) {
        tablePlayersInfo.getItems().clear();
        ObservableList<Player> list = FXCollections.observableArrayList();
        list.addAll(ReadThreadClient.auctionedPlayersInThisClub);
        tablePlayersInfo.setItems(list);
    }

    @FXML
    public void confirmBuyPlayer(ActionEvent actionEvent) {
        if(tablePlayersInfo.getSelectionModel().getSelectedItem()!=null) {
            Alert a = new Alert(Alert.AlertType.CONFIRMATION);
            a.setHeaderText("Confirm Buy");
            a.setContentText("Buy " + tablePlayersInfo.getSelectionModel().getSelectedItem().getName() + " with " + tablePlayersInfo.getSelectionModel().getSelectedItem().getPrize() + " dollars?");
            a.showAndWait();
            if(a.getResult().equals(ButtonType.OK)){
                Player selectedItem = tablePlayersInfo.getSelectionModel().getSelectedItem();
                main.getClub2().setBoughtPlayer(selectedItem);
                tablePlayersInfo.getItems().remove(selectedItem);
            }
        } else {
            Alert a = new Alert(Alert.AlertType.ERROR);
            a.setHeaderText("No player selected");
            a.setContentText("Select a player to buy");
            a.showAndWait();
        }
    }
}
