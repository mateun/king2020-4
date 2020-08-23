#pragma once
#include "gamestate.h"
#include "textfield.h"
#include <vector>

class SDL_Renderer;
class DefaultGame;

class SplashGamestate : public Gamestate {

public:
	SplashGamestate(DefaultGame& game) : Gamestate(game) {}
	void init() override;
	void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	void render(SDL_Renderer* renderer) override;
	void teardown() override;


private:
	int frame = 0;
	Textfield* _textfield = nullptr;
};