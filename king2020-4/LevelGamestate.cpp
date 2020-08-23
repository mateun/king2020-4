#include "level_state.h"
#include <vector>
#include "default_game.h"

// Functions for buildings

class House;

static std::vector<House*> houses;
static SDL_Texture* houseTexture;


struct House {
	int _worldX;
	int _worldY;
	int _hp;

	SDL_Rect sourceRect() {
		return { 0, 0, 64, 64 };
	}
	
	SDL_Rect worldRect() {
		return { _worldX, _worldY, 64, 64 };
	}
};

bool isBuildingAllowed(int worldX, int worldY) {
	return true;
}

void createHouse(int worldX, int worldY) {
	House* house = new House();
	house->_worldX = worldX;
	house->_worldY = worldY;
	houses.push_back(house);

	
}

void processInputEvents(std::vector<SDL_Event>& frameEvents) {
	for (auto e : frameEvents) {
		switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			SDL_Log("mouse down in level state.");
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (isBuildingAllowed(x, y)) {
				createHouse(x, y);
			}
			break;
		}
	}

}


void LevelState::init() {
	SDL_Log("in init of level state.");
	SDL_Surface* surface = SDL_LoadBMP("E:/Projects/C++/king2020-4/assets/textures/house1.bmp");
	houseTexture = SDL_CreateTextureFromSurface(_game.getRenderer(), surface);
	SDL_FreeSurface(surface);
}

void LevelState::teardown() {
	SDL_Log("in teardown of level state.");
	SDL_DestroyTexture(houseTexture);
}

void LevelState::update(float dt, std::vector<SDL_Event>& frameEvents) {
	processInputEvents(frameEvents);

}

void LevelState::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	for (auto h : houses) {
		
		SDL_RenderCopy(renderer, houseTexture, &h->sourceRect(), &h->worldRect());
	}
	SDL_RenderPresent(renderer);

}






