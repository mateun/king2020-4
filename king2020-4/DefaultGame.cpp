#include "game.h"
#include "default_game.h"
#include <SDL.h>

DefaultGame::DefaultGame(std::vector<Gamestate*> gameStates, int screenWidth, int screenHeight, bool fullScreen) 
	: Game(gameStates), _screenWidth(screenWidth), _screenHeight(screenHeight), _fullScreen(fullScreen)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("error initializing SDL, quitting.");
		exit(10);
	}

	SDL_Log("SDL initialized!");

	_sdlWindow = SDL_CreateWindow("default game window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);

	_sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	




}

void DefaultGame::start() {



	while (_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				_running = false;
				break;
			}

			// TODO: store SDL events in vector to be passed on to the current game state update method
		}

		SDL_SetRenderDrawColor(_sdlRenderer, 0xab0, 0x00, 0x00, 0x00);
		SDL_RenderClear(_sdlRenderer);
		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(_sdlRenderer);
	}

}

void DefaultGame::stop() {
	SDL_Quit();
}