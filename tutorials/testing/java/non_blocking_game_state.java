import bridges.base.NamedColor;
import bridges.base.NamedSymbol;
import bridges.games.NonBlockingGame;

public class non_blocking_game_state extends NonBlockingGame {
    
  public non_blocking_game_state(int assid, String userName, String apiKey) {
    super(assid, userName, apiKey, 5, 5);
  }

  public void initialize() {
      for (int i=0; i<5; i++)
	  for (int j=0; j<5; j++) {
	      setBGColor(i, j, NamedColor.white);
	  }


      drawSymbol(0, 2, NamedSymbol.J, NamedColor.black);
      drawSymbol(0, 3, NamedSymbol.P, NamedColor.black);
      drawSymbol(1, 2, NamedSymbol.S, NamedColor.black);
      drawSymbol(1, 3, NamedSymbol.P, NamedColor.black);
      drawSymbol(2, 2, NamedSymbol.J, NamedColor.black);
      drawSymbol(2, 3, NamedSymbol.N, NamedColor.black);
      drawSymbol(2, 4, NamedSymbol.P, NamedColor.black);
      drawSymbol(3, 2, NamedSymbol.S, NamedColor.black);
      drawSymbol(3, 3, NamedSymbol.N, NamedColor.black);
      drawSymbol(3, 4, NamedSymbol.P, NamedColor.black);

  }

  public void gameLoop() {
      
    if (keyUpJustPressed()) 
	drawSymbol(0, 0, NamedSymbol.X, NamedColor.black);
    else
	drawSymbol(0, 0, NamedSymbol.none, NamedColor.black);

    if (keyUpStillPressed()) 
	drawSymbol(1, 0, NamedSymbol.X, NamedColor.black);
    else
	drawSymbol(1, 0, NamedSymbol.none, NamedColor.black);

    if (keyUpJustNotPressed()) 
	drawSymbol(2, 0, NamedSymbol.X, NamedColor.black);
    else
	drawSymbol(2, 0, NamedSymbol.none, NamedColor.black);

    if (keyUpStillNotPressed()) 
	drawSymbol(3, 0, NamedSymbol.X, NamedColor.black);
    else
	drawSymbol(3, 0, NamedSymbol.none, NamedColor.black);
  }

  public static void main(String args[]) {
    non_blocking_game_state g = new non_blocking_game_state(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
						 "YOUR_API_KEY");
    g.start();
  }
}
