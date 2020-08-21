#pragma once
#include "gamestate.h"
#include <vector>

class SDL_Renderer;

class SplashGamestate : public Gamestate {

public:
	SplashGamestate(Game& game) : Gamestate(game) {}
	void init() override;
	void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	void render(SDL_Renderer* renderer) override;
	void teardown() override;


private:
	int frame = 0;
};