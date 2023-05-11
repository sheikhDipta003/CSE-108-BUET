package sample;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;
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
    private static ObservableList<Player> players = FXCollections.observableArrayList();

    public void show(ObservableList<Player> a_players) {
        players = a_players;
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
        tablePlayersInfo.setItems(players);
    }
}
