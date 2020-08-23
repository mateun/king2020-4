#pragma once
#include "gamestate.h"
#include <vector>
#include <SDL.h>

class DefaultGame;

class LevelState : public Gamestate {

public: 
	LevelState(DefaultGame& game) : Gamestate(game) {}
	virtual void init() override;
	virtual void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	virtual void render(SDL_Renderer* renderer) override;
	virtual void teardown() override;

};
