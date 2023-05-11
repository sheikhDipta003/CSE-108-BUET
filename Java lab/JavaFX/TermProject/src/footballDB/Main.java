package footballDB;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main extends Application {
    private Stage stage;
    private String headerText;
    public String auctionedPlayer;
    private Club2 club2;
    private boolean isBuyPlayerBtnClicked = false;

    public boolean IsBuyPlayerBtnClicked() {
        return isBuyPlayerBtnClicked;
    }

    public Club2 getClub2() {
        return club2;
    }

    public void setClub2(Club2 club2) {
        this.club2 = club2;
    }

    public void setBuyPlayerBtnClicked(boolean buyPlayerBtnClicked) {
        isBuyPlayerBtnClicked = buyPlayerBtnClicked;
    }

    public void setAuctionedPlayer(String auctionedPlayer) {
        this.auctionedPlayer = auctionedPlayer;
        System.out.println("Main: " + "Auctionedplayer = " + auctionedPlayer);
        try {
            club2.getNetworkUtil().write(auctionedPlayer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getAuctionedPlayer() {
        return auctionedPlayer;
    }

    public void setHeaderText(String headerText) {
        this.headerText = headerText;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        stage = primaryStage;
        ReadThreadClient.auctionedPlayersInClub = new ArrayList<>();
        ReadThreadClient.auctionedPlayersInThisClub = new ArrayList<>();
        //club2 = new Club2("127.0.0.1", 33333);
        /*try{
            FileIO.readFromFile();
        } catch (Exception e){
            System.out.println("Error: " + e.getMessage());
        }*/
        showLogin();
    }

    public static void main(String[] args) {
        launch(args);
    }

    public void showLogin() throws IOException {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("login.fxml"));
        Parent root = loader.load();

        LoginController loginController = loader.getController();
        loginController.setMain(this);
        //loginController.setClub2(club2);

        stage.setTitle("Hello World");
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }

    public void showHome() throws IOException {
        //stage = new Stage();
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("home.fxml"));
        Parent root = loader.load();

        isBuyPlayerBtnClicked = false;

        HomeController homeController = loader.getController();
        homeController.setMain(this);
        homeController.setHeaderText(headerText);

        stage.setTitle("My Football-players Database");
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }

    public void showPlayersInfo(String title, boolean isAllPlayersClicked) throws IOException {
        //stage = new Stage();
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("showPlayerInfo.fxml"));
        Parent root = loader.load();

        ShowPlayersController showPlayersController = loader.getController();
        showPlayersController.setMain(this);
        showPlayersController.setAllPlayersClicked(isAllPlayersClicked);
        showPlayersController.refreshBtn.setVisible(isBuyPlayerBtnClicked);
        showPlayersController.confirmBuyBtn.setVisible(isBuyPlayerBtnClicked);

        stage.setTitle(title);
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }

    public void showCountryWiseCount(String title) throws Exception{
        //stage = new Stage();
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("countryWisePlayerCount.fxml"));
        Parent root = loader.load();

        CountryWisePlayerCount countryWisePlayerCount = loader.getController();
        countryWisePlayerCount.setMain(this);

        stage.setTitle(title);
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }
}
