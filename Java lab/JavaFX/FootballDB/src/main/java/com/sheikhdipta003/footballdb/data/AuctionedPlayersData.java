package com.sheikhdipta003.footballdb.data;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class AuctionedPlayersData implements Serializable {
    private List<String> auctionedPlayersData;

    public AuctionedPlayersData(){
        auctionedPlayersData = new ArrayList<>();
    }

    public List<String> getAuctionedPlayersData() {
        return auctionedPlayersData;
    }

    public void setAuctionedPlayersData(List<String> auctionedPlayersData) {
        this.auctionedPlayersData = auctionedPlayersData;
    }
}
