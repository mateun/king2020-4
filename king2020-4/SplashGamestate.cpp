#include "splash_gamestate.h"
#include <SDL.h>

void SplashGamestate::init() {


}

void SplashGamestate::update(float deltaTime, std::vector<SDL_Event>& frameEvents) {
	//if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
	//	SDL_Log("Mouse Button 1 (left) is pressed.");
	//	//_game.moveToNextGamestate();
	//}
	for (auto e : frameEvents) {
		
		switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			_game.moveToNextGamestate();
			break;
		}

	}

}


void SplashGamestate::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0xab0, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void SplashGamestate::teardown() {

}

