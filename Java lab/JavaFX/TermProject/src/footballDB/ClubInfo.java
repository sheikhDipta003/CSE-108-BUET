package footballDB;

import java.io.Serializable;

public class ClubInfo implements Serializable {
    private String namePass;

    ClubInfo(String name, String pass){
        namePass = name + "," + pass;
    }

    public void setClientInfo(String namePass) {
        this.namePass = namePass;
    }

    public String getClientInfo() {
        return namePass;
    }
}
