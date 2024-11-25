package com.sheikhdipta003.footballdb.main;

import com.sheikhdipta003.footballdb.club.Club;
import com.sheikhdipta003.footballdb.club.ReadThreadClient;
import com.sheikhdipta003.footballdb.controller.*;
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
import java.util.HashMap;
import java.util.Map;

//Arsenal - 111
//Chelsea - 112
//Liverpool - 113
//Manchester City - 114
//Manchester United - 115

public class Main extends Application {
    private Stage stage;
    private String headerText;
    public String auctionedPlayer;
    private Club club;
    private boolean isBuyPlayerBtnClicked = false;

    private static Map<String, String> fxml_fileMap = new HashMap<>();
    private static Map<String, String> css_fileMap = new HashMap<>();

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
        fxml_fileMap.put("login", "/com/sheikhdipta003/footballdb/club_fxml/login.fxml");
        css_fileMap.put("login", "/com/sheikhdipta003/footballdb/club_css/login.css");

        fxml_fileMap.put("home", "/com/sheikhdipta003/footballdb/club_fxml/home.fxml");
        css_fileMap.put("home", "/com/sheikhdipta003/footballdb/club_css/home.css");

        fxml_fileMap.put("addPlayers", "/com/sheikhdipta003/footballdb/club_fxml/addPlayers.fxml");
        css_fileMap.put("addPlayers", "/com/sheikhdipta003/footballdb/club_css/addPlayers.css");

        fxml_fileMap.put("showPlayerInfo", "/com/sheikhdipta003/footballdb/club_fxml/showPlayerInfo.fxml");
        css_fileMap.put("showPlayerInfo", "/com/sheikhdipta003/footballdb/club_css/showPlayerInfo.css");

        fxml_fileMap.put("countryWisePlayerCount", "/com/sheikhdipta003/footballdb/club_fxml/countryWisePlayerCount.fxml");

        launch(args);
    }

    public void showLogin() throws IOException {
        FXMLLoader loader = new FXMLLoader();
//        System.out.println(getClass());
//        System.out.println(getClass().getResource(fxml_fileMap.get("login")));
        loader.setLocation(getClass().getResource(fxml_fileMap.get("login")));
        Parent root = loader.load();

        LoginController loginController = loader.getController();
        loginController.setMain(this);

        stage.setTitle("Term Project");
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add(css_fileMap.get("login"));
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showHome() throws IOException {
        FXMLLoader loader = new FXMLLoader();
//        System.out.println(getClass());
//        System.out.println(getClass().getResource(fxml_fileMap.get("home")));
        loader.setLocation(getClass().getResource(fxml_fileMap.get("home")));
        Parent root = loader.load();

        isBuyPlayerBtnClicked = false;

        HomeController homeController = loader.getController();
        homeController.setMain(this);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add(css_fileMap.get("home"));
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showPlayersInfo(boolean isAllPlayersClicked) throws IOException {
        FXMLLoader loader = new FXMLLoader();
//        System.out.println(getClass());
//        System.out.println(getClass().getResource(fxml_fileMap.get("showPlayerInfo")));
        loader.setLocation(getClass().getResource(fxml_fileMap.get("showPlayerInfo")));
        Parent root = loader.load();

        ShowPlayersController showPlayersController = loader.getController();
        showPlayersController.setMain(this);
        showPlayersController.setAllPlayersClicked(isAllPlayersClicked);
        showPlayersController.refreshBtn.setVisible(isBuyPlayerBtnClicked);
        showPlayersController.confirmBuyBtn.setVisible(isBuyPlayerBtnClicked);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add(css_fileMap.get("showPlayerInfo"));
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showCountryWiseCount() throws Exception{
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource(fxml_fileMap.get("countryWisePlayerCount")));
        Parent root = loader.load();

        CountryWisePlayerCount countryWisePlayerCount = loader.getController();
        countryWisePlayerCount.setMain(this);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add(css_fileMap.get("showPlayerInfo"));
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
        closeAllThreads(stage);
    }

    public void showAddPlayer() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource(fxml_fileMap.get("addPlayers")));
        Parent root = loader.load();

        AddController addController = loader.getController();
        addController.setMain(this);

        stage.setTitle("Players DB - " + getHeaderText());
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add(css_fileMap.get("addPlayers"));
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
