#include <NonBlockingGame.h>
#include <iostream>

using namespace bridges::game;

struct my_game : public NonBlockingGame {

  my_game(int assID, std::string username, std::string apikey)
    : NonBlockingGame (assID, username, apikey, 3, 3) {
  }

  virtual void initialize() override {
    keyUpSetupFire(20);  // only fire every 20 frames

    // setup display
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 3; c++) {
        setBGColor(r, c, NamedColor::white);
      }
    }

    drawSymbol(0, 2, NamedSymbol::F, NamedColor::black);
  }

  virtual void gameLoop() override {
    //even with the button pressed, X will only appear every 20 frames
    if (keyUpFire())  
      drawSymbol(0, 0, NamedSymbol::X, NamedColor::black);
    else
      drawSymbol(0, 0, NamedSymbol::none, NamedColor::black);
  }
};

int main (int argc, char** argv) {
	my_game g(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

  g.start();
}
