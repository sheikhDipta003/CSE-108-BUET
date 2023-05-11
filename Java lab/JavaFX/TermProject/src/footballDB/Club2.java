package footballDB;

import myUtil.NetworkUtil;
import java.io.IOException;

public class Club2 {
    public boolean isValid = false;
    private NetworkUtil networkUtil;
    private ClubInfo clubInfo;
    private Player boughtPlayer = new Player();

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

    Club2(String serverAddress, int port){
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
