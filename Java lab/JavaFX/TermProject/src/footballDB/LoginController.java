package footballDB;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Window;
import myUtil.NetworkUtil;

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
    private Club2 club2;

    public void setClub2(Club2 club2) {
        this.club2 = club2;
    }

    public void setMain(Main main) {
        this.main = main;
    }

    @FXML
    public void getClubCredentials(ActionEvent actionEvent) {
        clubName = textFieldClubName.getText();
        clubPassword = passwordFieldClub.getText();
        club2 = new Club2("127.0.0.1", 33333);
        main.setClub2(club2);
        //Club club = new Club("127.0.0.1", 33333, clubName, clubPassword, main.getAuctionedPlayer());
        club2.setClubInfo(clubName, clubPassword);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException exception) {
            exception.printStackTrace();
        }
        //club.setMain(main);
        //System.out.println("LoginController: " + "Main = " + main);

        try {
            if (club2.getValid()) {
                //club.setMain(main);
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
