package Football_DB.controller;

import Football_DB.club.ReadThreadClient;
import Football_DB.data.Player;
import Football_DB.main.Main;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;

import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class CountryWisePlayerCount implements Initializable {

    @FXML
    public ListView<String> listViewCountryWiseCount = new ListView<>();
    public ObservableList<String> playersCountryCount = FXCollections.observableArrayList();
    @FXML
    public Button playersCountBackBtn;
    private Main main;
    private List<Player> clubPlayers = ReadThreadClient.getClubPlayersInfo();
    private ObservableList<String> countryList = FXCollections.observableArrayList();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        for(Player player : clubPlayers) {
            if (!countryList.contains(player.getCountry())) {
                countryList.add(player.getCountry());
            }
        }

        for(String c: countryList){
            int playersCount = 0;

            for(Player player : clubPlayers){
                if(c.equalsIgnoreCase(player.getCountry())){
                    playersCount++;
                }
            }

            playersCountryCount.add(c + " - " + playersCount);
        }
        listViewCountryWiseCount.setItems(playersCountryCount);
    }

    public void setMain(Main main) {
        this.main = main;
    }

    public void backToHome(ActionEvent actionEvent) {
        try {
            main.showHome();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
