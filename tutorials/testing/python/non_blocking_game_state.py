from bridges import *

class ControlsTutorial(NonBlockingGame):
    def __init__(self, assid, login, apikey):
        super(ControlsTutorial, self).__init__(assid, login, apikey, 5, 5)

    def initialize(self):
        for col in range (0,5):
            for row in range (0,5):
                self.set_bg_color(col, row, NamedColor.white)


        self.draw_symbol(0, 2, NamedSymbol.J, NamedColor.black)
        self.draw_symbol(0, 3, NamedSymbol.P, NamedColor.black)
        self.draw_symbol(1, 2, NamedSymbol.S, NamedColor.black)
        self.draw_symbol(1, 3, NamedSymbol.P, NamedColor.black)
        self.draw_symbol(2, 2, NamedSymbol.J, NamedColor.black)
        self.draw_symbol(2, 3, NamedSymbol.N, NamedColor.black)
        self.draw_symbol(2, 4, NamedSymbol.P, NamedColor.black)
        self.draw_symbol(3, 2, NamedSymbol.S, NamedColor.black)
        self.draw_symbol(3, 3, NamedSymbol.N, NamedColor.black)
        self.draw_symbol(3, 4, NamedSymbol.P, NamedColor.black)

    def game_loop(self):
        if self.key_up_just_pressed():
            self.draw_symbol(0, 0, NamedSymbol.X, NamedColor.black)
        else:
            self.draw_symbol(0, 0, NamedSymbol.none, NamedColor.black)
        
        if self.key_up_still_pressed():
            self.draw_symbol(1, 0, NamedSymbol.X, NamedColor.black)
        else:
            self.draw_symbol(1, 0, NamedSymbol.none, NamedColor.black)
        
        if self.key_up_just_not_pressed():
            self.draw_symbol(2, 0, NamedSymbol.X, NamedColor.black)
        else:
            self.draw_symbol(2, 0, NamedSymbol.none, NamedColor.black)

        if self.key_up_still_not_pressed():
            self.draw_symbol(3, 0, NamedSymbol.X, NamedColor.black)
        else:
            self.draw_symbol(3, 0, NamedSymbol.none, NamedColor.black)
        

def main():
    game = ControlsTutorial(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", "YOUR_API_KEY")
    game.start()

if __name__ == '__main__':
    main()
