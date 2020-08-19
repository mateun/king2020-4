#include <vector>
#include "default_game.h"
#include "splash_gamestate.h"




int main(int argc, char** args) {
	
	DefaultGame game({ new SplashGamestate() }, 800, 600, false);
	game.start();
	game.stop();
	

	return 0;
}