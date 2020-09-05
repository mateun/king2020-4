#pragma once
#include "gamestate.h"
#include "textfield.h"
#include <vector>

class SDL_Renderer;
class Game;

class SplashGamestate : public Gamestate {

public:
	SplashGamestate(Game& game, SDL_Renderer* renderer) : Gamestate(game), _sdlRenderer(renderer) {}
	void init() override;
	void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	void render(float dt) override;
	void teardown() override;


private:
	int frame = 0;
	Textfield* _textfield = nullptr;
	SDL_Renderer* _sdlRenderer;
};