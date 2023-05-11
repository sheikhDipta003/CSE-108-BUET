package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.util.LinkedHashSet;
import java.util.List;

public class AddController extends FileIO{
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
    public TextField textFieldInputClub;
    @FXML
    public Button addButton;
    @FXML
    public Button backToHomeBtn;

    public void getPlayerData(ActionEvent actionEvent) {
        /*addButton.setOnAction(actionEvent1 -> {

        });*/
        Player newPlayer = new Player();
        newPlayer.setName(textFieldInputName.getText());
        newPlayer.setCountry(textFieldInputCountry.getText());
        newPlayer.setAge(Integer.parseInt(textFieldInputAge.getText()));
        newPlayer.setHeight(Double.parseDouble(textFieldInputHeight.getText()));
        newPlayer.setPosition(textFieldInputPosition.getSelectionModel().getSelectedItem());
        newPlayer.setNumber(Integer.parseInt(textFieldInputNumber.getText()));
        newPlayer.setWeeklySalary(Double.parseDouble(textFieldInputSalary.getText()));
        newPlayer.setClub(textFieldInputClub.getText());
        getPlayersList().add(newPlayer);

        try {
            FileIO.writeToFile(getPlayersList());
                /*for(int i = 0 ; i < getPlayersList().size() ; i++){
                    System.out.println(getPlayersList().get(i).getName());
                }*/
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        //alert user that the collected information have been added
        Alert a = new Alert(Alert.AlertType.CONFIRMATION);
        a.setHeaderText("Adding player");
        a.setContentText("Player has been added successfully.");
        a.showAndWait();
    }


    public void backToHome(ActionEvent actionEvent) {
        /*backToHomeBtn.setOnAction(actionEvent1 -> {

        });*/
        Node source = (Node)  actionEvent.getSource();
        Stage stage  = (Stage) source.getScene().getWindow();
        //stage.getOnCloseRequest().handle(null);
        stage.close();
    }
}
