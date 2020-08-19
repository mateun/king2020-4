#include "stdio.h"
#include <SDL.h>




int main(int argc, char** args) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("error initializing SDL, quitting.");
	}

	SDL_Log("SDL initialized!");


	SDL_Quit();

	return 0;
}