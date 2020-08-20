#pragma once
#include <SDL.h>
#include <vector>
#include "game.h"

class Gamestate {
public:
	Gamestate(Game& game) : _game(game) {}
	virtual void init() = 0;
	virtual void update(float dt, std::vector<SDL_Event>& frameEvents) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual void teardown() = 0;

protected: 
	Game& _game;

};