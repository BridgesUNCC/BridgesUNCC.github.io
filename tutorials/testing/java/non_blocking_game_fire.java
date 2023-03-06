import bridges.base.NamedColor;
import bridges.base.NamedSymbol;
import bridges.games.NonBlockingGame;

public class non_blocking_game_fire extends NonBlockingGame {
    
  public non_blocking_game_fire(int assid, String userName, String apiKey) {
      super(assid, userName, apiKey, 3, 3);
  }

  public void initialize() {
      for (int i=0; i<3; i++)
	  for (int j=0; j<3; j++) {
	      setBGColor(i, j, NamedColor.white);
	  }

      drawSymbol(0, 2, NamedSymbol.F, NamedColor.black);
      keyUpSetupFire(20);
  }

  public void gameLoop() {
      
    if (keyUpFire()) 
	drawSymbol(0, 0, NamedSymbol.X, NamedColor.black);
    else
	drawSymbol(0, 0, NamedSymbol.none, NamedColor.black);

  }

  public static void main(String args[]) {
    non_blocking_game_fire g = new non_blocking_game_fire(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
				      "YOUR_API_KEY");
    g.start();
  }
}
