import bridges.games.*;
import bridges.base.*;

class MinimalGame extends NonBlockingGame {
    public MinimalGame() {
	//substitute your username and api key
	super (1, "myuserid",  "myapikey", 10, 10);
	//this created a game board of 10x10 into assignment 1
    }

    public void initialize() {
	//This function is executed once at the beginning of the game
    }

    public void gameLoop() {
	//This function is executed each frame of the game
    }

    public static void  main (String args[]) {
	MinimalGame g = new MinimalGame();
	g.start();
    }
}
