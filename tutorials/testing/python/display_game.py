from bridges import *
import sys

class DisplayGame (NonBlockingGame): 
	def	 __init__(self, assid, user_id, api_key):
		# substitute your username and api key
		# create a game board of 10x10
		#self.set_title ("Game tutorial 2  - drawing symbols")
		super().__init__(assid, user_id,  api_key, 10, 10)

	def	initialize(self):
		# this gets executed once
		for i in range(10):
			for j in range(10):
				self.set_bg_color(i, j, NamedColor.ivory)

		self.draw_symbol(1, 1, NamedSymbol.H, NamedColor.blue)
		self.draw_symbol(1, 2, NamedSymbol.E, NamedColor.yellow)
		self.draw_symbol(1, 3, NamedSymbol.L, NamedColor.black)
		self.draw_symbol(1, 4, NamedSymbol.L, NamedColor.green)
		self.draw_symbol(1, 5, NamedSymbol.O, NamedColor.red)

	def	game_loop(self): 
		# this gets executed every frame
		pass

def	main():
	game = DisplayGame(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
	# start the game
	game.start()

if __name__ == "__main__":
	main()
