package footballDB;

import java.io.Serializable;

public class BoughtPlayerData implements Serializable {
    private String clubName;
    private Player boughtPLayer;

    BoughtPlayerData(String clubName, Player boughtPLayer){
        this.boughtPLayer = boughtPLayer;
        this.clubName = clubName;
    }

    public String getClubName() {
        return clubName;
    }

    public Player getBoughtPLayer() {
        return boughtPLayer;
    }
}
