#include "main_menu_gamestate.h"

void MainMenuGamestate::init() {
	SDL_Log("In init method of MainMenuGameState.");
}

void MainMenuGamestate::teardown() {
	SDL_Log("in teardown of MainMenuGamestate.");
}

void MainMenuGamestate::update(float dt, std::vector<SDL_Event>& frameEvents) {
	for (auto e : frameEvents) {

		switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			SDL_Log("mouse down in main menu.");
			_game.moveToNextGamestate();
			break;
		}

	}
}

void MainMenuGamestate::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0xab0, 0xcc, 0xd0, 0x00);
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, texture, NULL, NULL);

	SDL_RenderPresent(renderer);
	
}