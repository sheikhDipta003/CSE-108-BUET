package com.sheikhdipta003.footballdb.data;

import java.io.Serializable;

public class BoughtPlayerData implements Serializable {
    private String clubName;
    private Player boughtPLayer;

    public BoughtPlayerData(String clubName, Player boughtPLayer){
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
