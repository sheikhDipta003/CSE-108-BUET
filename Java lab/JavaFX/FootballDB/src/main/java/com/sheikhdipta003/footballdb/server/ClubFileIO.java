package com.sheikhdipta003.footballdb.server;

import com.sheikhdipta003.footballdb.server.FileIO;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class ClubFileIO extends FileIO implements Serializable {
    private List<String> clubPlayersList = new ArrayList<>();

    public void setClubName(String clubName) {

        for(int i = 0 ; i < getPlayersList().size() ; i++){
            if(getPlayersList().get(i).getClub().equals(clubName)){
                clubPlayersList.add(getLines().get(i));
            }
        }
    }

    public List<String> getClubPlayersList() {
        return clubPlayersList;
    }
}
