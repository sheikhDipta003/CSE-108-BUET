package com.sheikhdipta003.footballdb.data;

import java.io.Serializable;

public class ClubInfo implements Serializable {
    private String namePass;

    public ClubInfo(String name, String pass){
        namePass = name + "," + pass;
    }

    public String getClientInfo() {
        return namePass;
    }
}
