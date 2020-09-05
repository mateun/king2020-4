#include "level_state.h"
#include <vector>
#include "default_game.h"

// Functions for buildings

class House;

static std::vector<House*> houses;
static SDL_Texture* houseTexture;
static int camX = 0, camY = 0;

struct House {
	int _worldX;
	int _worldY;
	int _hp;

	SDL_Rect screenSourceRect() {
		return { 0, 0, 64, 64 };
	}
	
	SDL_Rect screenTargetRect(int camX, int camY) {
		return { _worldX - camX, _worldY - camY, 64, 64 };
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

void getWorldCoordinates(int& wx, int& wy, int screenX, int screenY, int camX, int camY) {
	wx = screenX + camX;
	wy = screenY + camY;
}

void getScreenCoordinates(int& sx, int& sy, int worldX, int worldY, int camX, int camY) {
	sx = worldX - camX;
	sy = worldY - camY;
}


void processInputEvents(std::vector<SDL_Event>& frameEvents) {
	for (auto e : frameEvents) {
		switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			SDL_Log("mouse down in level state.");
			int screenX, screenY;
			SDL_GetMouseState(&screenX, &screenY);
			int wx, wy;
			getWorldCoordinates(wx, wy, screenX, screenY, camX, camY);
			if (isBuildingAllowed(wx, wy)) {
				createHouse(wx, wy);
			}
			break;
		}
		
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_LEFT]) {
		printf("<LEFT> is pressed.\n");
		camX -= 1;
	}
	if (state[SDL_SCANCODE_RIGHT] ) {
		printf("<RIGHT> is pressed.\n");
		camX += 1;
	}

}


void LevelState::init() {
	SDL_Log("in init of level state.");
	SDL_Surface* surface = SDL_LoadBMP("E:/Projects/C++/king2020-4/assets/textures/house1.bmp");
	houseTexture = SDL_CreateTextureFromSurface(_sdlRenderer, surface);
	SDL_FreeSurface(surface);
}

void LevelState::teardown() {
	SDL_Log("in teardown of level state.");
	SDL_DestroyTexture(houseTexture);
}

void LevelState::update(float dt, std::vector<SDL_Event>& frameEvents) {
	processInputEvents(frameEvents);

}

void LevelState::render(float dt) {
	SDL_SetRenderDrawColor(_sdlRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(_sdlRenderer);
	for (auto h : houses) {
		
		SDL_RenderCopy(_sdlRenderer, houseTexture, &h->screenSourceRect(), &h->screenTargetRect(camX, camY));
	}
	SDL_RenderPresent(_sdlRenderer);

}






