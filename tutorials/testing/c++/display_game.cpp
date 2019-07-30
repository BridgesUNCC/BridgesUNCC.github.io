#include <NonBlockingGame.h>

using namespace bridges::game;

struct my_game : public NonBlockingGame {
	my_game(int assID, std::string username, std::string apikey)
		: NonBlockingGame (assID, username,  apikey) {
	}
	virtual void initialize() override {
		for (int i = 0; i < getBoardHeight(); ++i)
			for (int j = 0; j < getBoardWidth(); ++j)
				setBGColor(i, j, NamedColor::ivory);

		drawSymbol(1, 1, NamedSymbol::H, NamedColor::blue);
		drawSymbol(1, 2, NamedSymbol::E, NamedColor::yellow);
		drawSymbol(1, 3, NamedSymbol::L, NamedColor::black);
		drawSymbol(1, 4, NamedSymbol::L, NamedColor::green);
		drawSymbol(1, 5, NamedSymbol::O, NamedColor::red);

	}
	virtual void gameLoop() override {
		//This function is executed each frame of the game
	}
};

int main (int argc, char** argv) {
	my_game g(YOUR_ASSSIGNMENT_NUMBER, "YOUR_USER_ID",
		"YOUR_API_KEY");


	g.start();
}
