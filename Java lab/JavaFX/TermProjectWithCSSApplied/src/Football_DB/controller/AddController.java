package Football_DB.controller;

import Football_DB.club.ReadThreadClient;
import Football_DB.data.Player;
import Football_DB.main.Main;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class AddController{
    @FXML
    public TextField textFieldInputName;
    @FXML
    public TextField textFieldInputCountry;
    @FXML
    public TextField textFieldInputAge;
    @FXML
    public TextField textFieldInputHeight;
    @FXML
    public ComboBox<String> textFieldInputPosition;
    @FXML
    public TextField textFieldInputNumber;
    @FXML
    public TextField textFieldInputSalary;
    @FXML
    public Button addButton;
    @FXML
    public Button backToHomeBtn;
    public Main main;
    @FXML
    public TextField textFieldInputPrice;

    public void setMain(Main main) {
        this.main = main;
    }

    public void getPlayerData(ActionEvent actionEvent) {
        Player newPlayer = new Player();
        newPlayer.setName(textFieldInputName.getText());
        newPlayer.setCountry(textFieldInputCountry.getText());
        newPlayer.setAge(Integer.parseInt(textFieldInputAge.getText()));
        newPlayer.setHeight(Double.parseDouble(textFieldInputHeight.getText()));
        newPlayer.setPosition(textFieldInputPosition.getSelectionModel().getSelectedItem());
        newPlayer.setNumber(Integer.parseInt(textFieldInputNumber.getText()));
        newPlayer.setWeeklySalary(Double.parseDouble(textFieldInputSalary.getText()));
        newPlayer.setClub(main.getClub().getClubInfo().getClientInfo().split(",")[0]);
        newPlayer.setPrice(Double.parseDouble(textFieldInputPrice.getText()));

        //confirmation to add the player
        Alert a = new Alert(Alert.AlertType.CONFIRMATION);
        a.setHeaderText("Confirm addition");
        a.setContentText("Add " + newPlayer.getName() + " to " + newPlayer.getClub());
        a.showAndWait();

        if(a.getResult().equals(ButtonType.OK)){
            main.getClub().addPlayerToThisClub(newPlayer);
            ReadThreadClient.addBoughtPlayer(newPlayer);
            clearAllFields();
        }
    }

    @FXML
    public void clearAllFields() {
        textFieldInputName.clear();
        textFieldInputAge.clear();
        textFieldInputCountry.clear();
        textFieldInputHeight.clear();
        textFieldInputNumber.clear();
        textFieldInputSalary.clear();
        textFieldInputPrice.clear();
        textFieldInputPosition.getSelectionModel().clearSelection();
    }

    public void backToHome(ActionEvent actionEvent) {
        try {
            main.showHome();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
