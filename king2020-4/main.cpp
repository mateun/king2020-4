#include <vector>
#include "default_game.h"
#include "splash_gamestate.h"
#include "main_menu_gamestate.h"




int main(int argc, char** args) {
	
	DefaultGame game(800, 600, false);
	game.addGameStates({ new SplashGamestate(game), new MainMenuGamestate(game) });
	game.start();
	game.stop();
	

	return 0;
}