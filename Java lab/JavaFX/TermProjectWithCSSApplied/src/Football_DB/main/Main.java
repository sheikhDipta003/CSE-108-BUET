package Football_DB.main;

import Football_DB.club.Club;
import Football_DB.club.ReadThreadClient;
import Football_DB.controller.*;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

import java.io.IOException;
import java.util.ArrayList;

public class Main extends Application {
    private Stage stage;
    private String headerText;
    public String auctionedPlayer;
    private Club club;
    private boolean isBuyPlayerBtnClicked = false;

    public Club getClub() {
        return club;
    }

    public void setClub(Club club) {
        this.club = club;
    }

    public void setBuyPlayerBtnClicked(boolean buyPlayerBtnClicked) {
        isBuyPlayerBtnClicked = buyPlayerBtnClicked;
    }

    public void setAuctionedPlayer(String auctionedPlayer) {
        this.auctionedPlayer = auctionedPlayer;

        try {
            club.getNetworkUtil().write(auctionedPlayer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getAuctionedPlayer() {
        if(auctionedPlayer == null)   return "";
        else    return auctionedPlayer;
    }

    public void setHeaderText(String headerText) {
        this.headerText = headerText;
    }

    public String getHeaderText() {
        return headerText;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        stage = primaryStage;
        ReadThreadClient.auctionedPlayersInClub = new ArrayList<>();
        ReadThreadClient.auctionedPlayersInThisClub = new ArrayList<>();
        showLogin();
    }

    public static void main(String[] args) {
        launch(args);
    }

    public void showLogin() throws IOException {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("/Football_DB/club_fxml/login.fxml"));
        Parent root = loader.load();

        LoginController loginController = loader.getController();
        loginController.setMain(this);

        stage.setTitle("Term Project");
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add("Football_DB/club_css/login.css");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showHome() throws IOException {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("/Football_DB/club_fxml/home.fxml"));
        Parent root = loader.load();

        isBuyPlayerBtnClicked = false;

        HomeController homeController = loader.getController();
        homeController.setMain(this);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add("Football_DB/club_css/home.css");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showPlayersInfo(boolean isAllPlayersClicked) throws IOException {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("/Football_DB/club_fxml/showPlayerInfo.fxml"));
        Parent root = loader.load();

        ShowPlayersController showPlayersController = loader.getController();
        showPlayersController.setMain(this);
        showPlayersController.setAllPlayersClicked(isAllPlayersClicked);
        showPlayersController.refreshBtn.setVisible(isBuyPlayerBtnClicked);
        showPlayersController.confirmBuyBtn.setVisible(isBuyPlayerBtnClicked);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add("Football_DB/club_css/showPlayerInfo.css");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showCountryWiseCount() throws Exception{
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("/Football_DB/club_fxml/countryWisePlayerCount.fxml"));
        Parent root = loader.load();

        CountryWisePlayerCount countryWisePlayerCount = loader.getController();
        countryWisePlayerCount.setMain(this);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add("Football_DB/club_css/showPlayerInfo.css");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showAddPlayer() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("/Football_DB/club_fxml/addPlayers.fxml"));
        Parent root = loader.load();

        AddController addController = loader.getController();
        addController.setMain(this);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add("Football_DB/club_css/addPlayers.css");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void closeAllThreads(Stage stage){
        stage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent e) {
                Platform.exit();
                System.exit(0);
            }
        });
    }
}
