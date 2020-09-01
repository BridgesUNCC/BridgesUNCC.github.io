#include <NonBlockingGame.h>

using namespace bridges::game;

struct my_game : public NonBlockingGame {
	my_game(int assID, std::string username, std::string apikey)
		: NonBlockingGame (assID, username,  apikey, 10, 20) {
	}
	virtual void initialize() override {
		for (int i = 0; i < getBoardHeight(); ++i)
			for (int j = 0; j < getBoardWidth(); ++j)
				setBGColor(i, j, NamedColor::ivory);

		drawSymbol(0, 0, NamedSymbol::U, NamedColor::blue);
		drawSymbol(0, 19, NamedSymbol::N, NamedColor::red);
		drawSymbol(9, 0, NamedSymbol::C, NamedColor::black);
		drawSymbol(9, 19, NamedSymbol::C, NamedColor::green);

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
