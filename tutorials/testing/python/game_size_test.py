from bridges import *
import sys

class GameSizeTest (NonBlockingGame): 
	def	 __init__(self, assid, user_id, api_key):
		# substitute your username and api key
		# create a game board of 10x10
		#self.set_title ("Game tutorial 2  - drawing symbols")
		super().__init__(assid, user_id,  api_key, 10, 20)

	def	initialize(self):
		# this gets executed once
		for i in range(10):
			for j in range(10):
				self.set_bg_color(i, j, NamedColor.ivory)

		self.draw_symbol(0, 0, NamedSymbol.H, NamedColor.red)
		self.draw_symbol(0, 19, NamedSymbol.E, NamedColor.green)
		self.draw_symbol(9, 0, NamedSymbol.L, NamedColor.blue)
		self.draw_symbol(9, 19, NamedSymbol.O, NamedColor.cyan)

	def	game_loop(self): 
		# this gets executed every frame
		pass

def	main():
	game = GameSizeTest(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")

	# start the game
	game.start()

if __name__ == "__main__":
	main()
