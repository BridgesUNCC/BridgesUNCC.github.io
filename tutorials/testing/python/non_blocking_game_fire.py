from bridges import *

class ControlsTutorial(NonBlockingGame):
    def __init__(self, assid, login, apikey):
        super(ControlsTutorial, self).__init__(assid, login, apikey, 3, 3)

    def initialize(self):
        for col in range (0,3):
            for row in range (0,3):
                self.set_bg_color(col, row, NamedColor.white)

        self.draw_symbol(0, 2, NamedSymbol.F, NamedColor.black)
        self.key_up_setup_fire(20)

    def game_loop(self):
        if self.key_up_fire():
            self.draw_symbol(0, 0, NamedSymbol.X, NamedColor.black)
        else:
            self.draw_symbol(0, 0, NamedSymbol.none, NamedColor.black)
        

def main():
    game = ControlsTutorial(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    game.start()

if __name__ == '__main__':
    main()
