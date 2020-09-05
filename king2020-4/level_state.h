#pragma once
#include "gamestate.h"
#include <vector>
#include <SDL.h>

class DefaultGame;

class LevelState : public Gamestate {

public: 
	LevelState(Game& game, SDL_Renderer* renderer) : Gamestate(game) {}
	virtual void init() override;
	virtual void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	virtual void render(float dt) override;
	virtual void teardown() override;



private:
	SDL_Renderer* _sdlRenderer;

};
