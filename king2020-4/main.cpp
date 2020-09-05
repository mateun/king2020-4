#include <vector>
#include "gl_splash_state.h"
#include "main_menu_gamestate.h"
#include "level_state.h"
#include "default_game.h"



int main(int argc, char** args) {
	
	//DefaultGame game(800, 600, false);
	DefaultGame game(800, 600, false);
	game.addGameStates({ new GSSplashGL(game) });
	game.start();
	game.stop();
	

	return 0;
}