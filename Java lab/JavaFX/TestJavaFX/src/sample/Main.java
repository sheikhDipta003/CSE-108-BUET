package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    private Stage stage;

    @Override
    public void start(Stage primaryStage) throws Exception{
        stage = primaryStage;
        try{
            FileIO.readFromFile();
        } catch (Exception e){
            System.out.println("Error: " + e.getMessage());
        }
        showHome();
    }

    public void showHome() throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("home.fxml"));
        stage.setTitle("My Football-players Database");
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }

    public void showAddPlayer(String title) throws Exception {
        stage = new Stage();
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("addPlayers.fxml"));
        Parent root = loader.load();
        stage.setTitle(title);
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }

    public void showPlayersInfo(String title) throws IOException {
        stage = new Stage();
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("showPlayerInfo.fxml"));
        Parent root = loader.load();
        stage.setTitle(title);
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }

    public void showCountryWiseCount(String title) throws Exception{
        stage = new Stage();
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("countryWisePlayerCount.fxml"));
        Parent root = loader.load();
        stage.setTitle(title);
        stage.setScene(new Scene(root, 600, 400));
        stage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
