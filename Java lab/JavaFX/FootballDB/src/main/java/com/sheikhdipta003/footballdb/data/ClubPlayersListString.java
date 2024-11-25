package com.sheikhdipta003.footballdb.data;

import java.io.Serializable;
import java.util.List;

public class ClubPlayersListString implements Serializable {
    private List<String> temp_clubPlayersList;

    public ClubPlayersListString(List<String> temp_clubPlayersList){
        this.temp_clubPlayersList = temp_clubPlayersList;
    }

    public List<String> getClubPlayersData() {
        return temp_clubPlayersList;
    }

}
