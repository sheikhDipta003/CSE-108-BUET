package com.sheikhdipta003.footballdb.club;

import com.sheikhdipta003.footballdb.data.Player;
import com.sheikhdipta003.footballdb.data.AddNewPlayer;
import com.sheikhdipta003.footballdb.data.BoughtPlayerData;
import com.sheikhdipta003.footballdb.data.ClubInfo;
import com.sheikhdipta003.footballdb.netUtil.NetworkUtil;

import java.io.IOException;

public class Club {
    public boolean isValid = false;
    private NetworkUtil networkUtil;
    private ClubInfo clubInfo;
    private Player boughtPlayer = new Player();
    private Player newPlayer = new Player();

    public void addPlayerToThisClub(Player player){
        this.newPlayer = player;
        AddNewPlayer obj = new AddNewPlayer(newPlayer);
        try {
            networkUtil.write(obj);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setBoughtPlayer(Player boughtPlayer) {
        this.boughtPlayer = boughtPlayer;
        BoughtPlayerData boughtPlayerData = new BoughtPlayerData(clubInfo.getClientInfo().split(",")[0], boughtPlayer);
        try {
            networkUtil.write(boughtPlayerData);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Player getBoughtPlayer() {
        return boughtPlayer;
    }

    public void setValid(boolean valid) {
        isValid = valid;
    }
    public boolean getValid(){
        return isValid;
    }

    public NetworkUtil getNetworkUtil(){return networkUtil;}

    public Club(String serverAddress, int port){
        try {
            networkUtil = new NetworkUtil(serverAddress, port);
            new ReadThreadClient(networkUtil, this);
        } catch (Exception e) {
            System.out.print("In constructor of Club class: ");
            e.printStackTrace();
        }
    }

    public void setClubInfo(String name, String pass){
        clubInfo= new ClubInfo(name, pass);
        try {
            networkUtil.write(clubInfo);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public ClubInfo getClubInfo() {
        return clubInfo;
    }
}
