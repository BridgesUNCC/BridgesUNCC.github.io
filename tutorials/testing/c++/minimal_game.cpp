#include <NonBlockingGame.h>

using namespace bridges::game;

struct my_game : public NonBlockingGame {
	my_game(int assID, std::string username, std::string apikey)
		: NonBlockingGame (assID, username,  apikey) {
	}
	virtual void initialize() override {
		//This function is executed once at the beginning of the game
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
