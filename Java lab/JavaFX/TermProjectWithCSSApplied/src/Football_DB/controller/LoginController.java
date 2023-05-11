package Football_DB.controller;

import Football_DB.club.Club;
import Football_DB.main.Main;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;

public class LoginController {

    @FXML
    public TextField textFieldClubName;
    @FXML
    public PasswordField passwordFieldClub;
    @FXML
    public Button submitBtnLogin;
    private String clubName;
    private String clubPassword;
    public Main main;
    private Club club;

    public void setMain(Main main) {
        this.main = main;
    }

    @FXML
    public void getClubCredentials(ActionEvent actionEvent) {
        clubName = textFieldClubName.getText();
        clubPassword = passwordFieldClub.getText();
        club = new Club("127.0.0.1", 44444);
        main.setClub(club);
        club.setClubInfo(clubName, clubPassword);

        try {
            Thread.sleep(1000);
        } catch (InterruptedException exception) {
            exception.printStackTrace();
        }

        try {
            if (club.getValid()) {
                main.setHeaderText(clubName);
                main.showHome();
            } else {
                showLoginError("Login failed", "Incorrect name or password");
                textFieldClubName.clear();
                passwordFieldClub.clear();
            }
        } catch (Exception e) {
            System.out.println("LoginController: " + e.getMessage());
        }
    }

    public static void showLoginError(String headerText, String contentText) {
        Alert a = new Alert(Alert.AlertType.ERROR);
        a.setHeaderText(headerText);
        a.setContentText(contentText);
        a.showAndWait();
    }
}
