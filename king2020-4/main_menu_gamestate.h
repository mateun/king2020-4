#pragma once
#include "gamestate.h"

class DefaultGame;

class MainMenuGamestate : public Gamestate {

public:
	MainMenuGamestate(DefaultGame& game) : Gamestate(game) {}
	void init() override;
	void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	void render(SDL_Renderer* renderer) override;
	void teardown() override;
};