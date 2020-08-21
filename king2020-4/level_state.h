#pragma once
#include "gamestate.h"
#include <vector>

class LevelState : public Gamestate {

public: 
	virtual void init() override;
	virtual void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	virtual void render(SDL_Renderer* renderer) override;
	virtual void teardown() override;

};
