#include "splash_gamestate.h"
#include <SDL.h>

void SplashGamestate::init() {

}

void SplashGamestate::update(float deltaTime) {

}


void SplashGamestate::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0xab0, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void SplashGamestate::teardown() {

}

