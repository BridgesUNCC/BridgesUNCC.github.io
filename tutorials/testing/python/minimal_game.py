from bridges import *

class MinimalGame (NonBlockingGame): 
	def	 __init__(self, assid, user_id, api_key):
		# substitute your username and api key
		# create a game board of 10x10
		super().__init__(assid, user_id,  api_key, 10, 10)

	def	initialize(self):
		# this gets executed once
		pass

	def	game_loop(self): 
		# this gets executed every frame
		pass

def	main():
	game = MinimalGame(1, "BRIDGES_USER_ID", "BRIDGES_API_KEY");
	# start the game
	game.start()

if __name__ == '__main__':
	main()
