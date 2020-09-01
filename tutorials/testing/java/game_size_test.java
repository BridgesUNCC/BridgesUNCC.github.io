import bridges.games.*;
import bridges.base.*;

class game_size_test extends NonBlockingGame {
	public game_size_test(int assignmentnumber, String username, String apikey) {
		super (assignmentnumber, username,  apikey, 10, 20);
	}

	public void initialize() {
		for (int i = 0; i < getBoardHeight(); ++i)
			for (int j = 0; j < getBoardWidth(); ++j)
				setBGColor(i, j, NamedColor.ivory);

		drawSymbol(0, 0, NamedSymbol.U, NamedColor.red);
		drawSymbol(0, 19, NamedSymbol.N, NamedColor.green);
		drawSymbol(9, 0, NamedSymbol.C, NamedColor.blue);
		drawSymbol(9, 19, NamedSymbol.C, NamedColor.cyan);
	}

	public void gameLoop() {
		//This function is executed each frame of the game
	}

	public static void main (String args[]) {
		game_size_test  g = new game_size_test(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
			"YOUR_API_KEY");
		g.start();
	}
}
