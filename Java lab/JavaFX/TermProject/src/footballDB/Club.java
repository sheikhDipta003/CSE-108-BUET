package footballDB;

import myUtil.NetworkUtil;

public class Club {
    //private Main main;
    public boolean isValid = false;
    private WriteThreadClient wtc;
    /*public void setMain(Main main) {
        this.main = main;
    }*/

    /*public Main getMain() {
        return main;
    }*/

    public WriteThreadClient getWtc() {
        return wtc;
    }

    public void setValid(boolean valid) {
        isValid = valid;
    }
    public boolean getValid(){
        return isValid;
    }

    Club(String serverAddress, int port, String name, String pass, String f_auctionedPLayer){
        try {
            //this.main = main;
            NetworkUtil networkUtil = new NetworkUtil(serverAddress, port);
            ClubInfo clubInfo = new ClubInfo(name, pass);
            networkUtil.write(clubInfo.getClientInfo());
            //new ReadThreadClient(networkUtil).setMain(this.main);
            //System.out.println("Constructor of club: " + "main = " + main);
            //new ReadThreadClient(networkUtil, this);
            wtc = new WriteThreadClient(networkUtil, clubInfo.getClientInfo().split(",")[0]);
            wtc.setAuctionedPlayer(f_auctionedPLayer);
        } catch (Exception e) {
            //System.out.println("main = " + main);
            System.out.print("In constructor of Club class: ");
            e.printStackTrace();
        }
    }
}
