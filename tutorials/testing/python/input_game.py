from bridges import *
import sys

class InputGame (NonBlockingGame): 
	def	 __init__(self, assid, user_id, api_key):
		# substitute your username and api key
		# create a game board of 10x10
		super().__init__(assid, user_id,  api_key, 10, 10)

	def	initialize(self):
		# this gets executed once
		for i in range(10):
			for j in range(10):
				self.set_bg_color(i, j, NamedColor.ivory)

	def	game_loop(self): 
		# this gets executed every frame
		if self.key_up():
			self.draw_symbol(1, 1, NamedSymbol.H, NamedColor.blue)
			self.draw_symbol(1, 2, NamedSymbol.E, NamedColor.yellow)
			self.draw_symbol(1, 3, NamedSymbol.L, NamedColor.black)
			self.draw_symbol(1, 4, NamedSymbol.L, NamedColor.green)
			self.draw_symbol(1, 5, NamedSymbol.O, NamedColor.red)
		else:
			self.draw_symbol(1, 1, NamedSymbol.none, NamedColor.blue)
			self.draw_symbol(1, 2, NamedSymbol.none, NamedColor.yellow)
			self.draw_symbol(1, 3, NamedSymbol.none, NamedColor.black)
			self.draw_symbol(1, 4, NamedSymbol.none, NamedColor.green)
			self.draw_symbol(1, 5, NamedSymbol.none, NamedColor.red)

def	main():
	game = InputGame(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
	# start the game
	game.start()

if __name__ == "__main__":
	main()
