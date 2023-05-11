package Football_DB.data;

import java.io.Serializable;

public class AddNewPlayer implements Serializable {
    private Player player;
    public AddNewPlayer(Player p){
        this.player = p;
    }

    public Player getPlayer() {
        return player;
    }

    public void setPlayer(Player player) {
        this.player = player;
    }
}
