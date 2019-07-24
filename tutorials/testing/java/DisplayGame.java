import bridges.games.*;
import bridges.base.*;

class DisplayGame extends NonBlockingGame {
    public DisplayGame() {
	//substitute your username and api key
	super (1, "myuserid",  "myapikey", 10, 10);
	//this created a game board of 10x10 into assignment 1
    }

    public void initialize() {
	for (int i=0; i<getBoardHeight(); ++i)
	    for (int j=0; j<getBoardWidth(); ++j)
		setBGColor(i, j, NamedColor.ivory);
	
	drawObject(1, 1, NamedSymbol.H, NamedColor.blue);
	drawObject(1, 2, NamedSymbol.E, NamedColor.yellow);
	drawObject(1, 3, NamedSymbol.L, NamedColor.black);
	drawObject(1, 4, NamedSymbol.L, NamedColor.green);
	drawObject(1, 5, NamedSymbol.O, NamedColor.red);
    }

    public void gameLoop() {
	//This function is executed each frame of the game
    }

    public static void  main (String args[]) {
	DisplayGame g = new DisplayGame();
	g.start();
    }
}
