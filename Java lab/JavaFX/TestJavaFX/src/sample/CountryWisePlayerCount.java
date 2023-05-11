package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ListView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.input.InputMethodTextRun;

import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.ResourceBundle;

public class CountryWisePlayerCount extends FileIO implements Initializable {

    @FXML
    public ListView<String> listViewCountryWiseCount = new ListView<>();
    public ObservableList<String> playersCountryCount = FXCollections.observableArrayList();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        System.out.println("countrylist is empty: " + getCountryList().isEmpty());
        for(String c: FileIO.getCountryList()){
            int playersCount = 0;

            for(Player player : FileIO.getPlayersList()){
                if(c.equalsIgnoreCase(player.getCountry())){
                    playersCount++;
                }
            }

            playersCountryCount.add(c + " - " + playersCount);
        }
        listViewCountryWiseCount.setItems(playersCountryCount);
    }
}
