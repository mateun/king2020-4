#include "splash_gamestate.h"
#include <SDL.h>
#include "default_game.h"

void SplashGamestate::init() {
	_textfield = new Textfield(50, 50, 200, 100);
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

	_textfield->addTextLine("frame: " + std::to_string(frame++));

}


void SplashGamestate::render(float dt) {
	SDL_SetRenderDrawColor(_sdlRenderer, 0xab0, 0x00, 0x00, 0x00);
	SDL_RenderClear(_sdlRenderer);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);

	_textfield->render(_sdlRenderer);
	SDL_RenderPresent(_sdlRenderer);
}

void SplashGamestate::teardown() {

}

