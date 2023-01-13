#include <NonBlockingGame.h>
#include <iostream>

using namespace bridges::game;

struct my_game : public NonBlockingGame {

  my_game(int assID, std::string username, std::string apikey)
    : NonBlockingGame (assID, username, apikey, 5, 5) {
    setTitle("My First Game!");
    setDescription("Test out your controls here");
  }

  virtual void initialize() override {
    for (int r = 0; r < 5; r++) {
      for (int c = 0; c < 5; c++) {
        setBGColor(r, c, NamedColor::white);
      }
    }

    drawSymbol(0, 2, NamedSymbol::J, NamedColor::black);
    drawSymbol(0, 3, NamedSymbol::P, NamedColor::black);
    drawSymbol(1, 2, NamedSymbol::S, NamedColor::black);
    drawSymbol(1, 3, NamedSymbol::P, NamedColor::black);
    drawSymbol(2, 2, NamedSymbol::J, NamedColor::black);
    drawSymbol(2, 3, NamedSymbol::N, NamedColor::black);
    drawSymbol(2, 4, NamedSymbol::P, NamedColor::black);
    drawSymbol(3, 2, NamedSymbol::S, NamedColor::black);
    drawSymbol(3, 3, NamedSymbol::N, NamedColor::black);
    drawSymbol(3, 4, NamedSymbol::P, NamedColor::black);
  }

  virtual void gameLoop() override {

      if (keyUpJustPressed())
	drawSymbol(0, 0, NamedSymbol::X, NamedColor::black);
      else
	drawSymbol(0, 0, NamedSymbol::none, NamedColor::black);

      if (keyUpStillPressed())
	drawSymbol(1, 0, NamedSymbol::X, NamedColor::black);
      else
	drawSymbol(1, 0, NamedSymbol::none, NamedColor::black);
      
      if (keyUpJustNotPressed()) 
	drawSymbol(2, 0, NamedSymbol::X, NamedColor::black);
      else
	drawSymbol(2, 0, NamedSymbol::none, NamedColor::black);
      
      if (keyUpStillNotPressed())
	drawSymbol(3, 0, NamedSymbol::X, NamedColor::black);
      else
	drawSymbol(3, 0, NamedSymbol::none, NamedColor::black);
  }
};

int main (int argc, char** argv) {
	my_game g(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");

  g.start();
}
