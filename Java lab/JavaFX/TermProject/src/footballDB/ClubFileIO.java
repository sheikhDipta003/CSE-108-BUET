package footballDB;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class ClubFileIO extends FileIO implements Serializable {
    private String clubName;
    private List<String> clubPlayersList = new ArrayList<>();

    synchronized public void setClubName(String clubName) {
        this.clubName = clubName;
        for(int i = 0 ; i < getPlayersList().size() ; i++){
            if(getPlayersList().get(i).getClub().equals(clubName)){
                clubPlayersList.add(getLines().get(i));
            }
        }
        /*for(Player player : getPlayersList()){
            if(player.getClub().equals(clubName)){
                clubPlayersList.add(player);
            }
        }*/
    }

    public List<String> getClubPlayersList() {
        return clubPlayersList;
    }

    //For debugging
    public String getClubName() {
        return clubName;
    }
}
