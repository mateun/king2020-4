#pragma once
#include "gamestate.h"

class SDL_Renderer;
class Game;

class MainMenuGamestate : public Gamestate {

public:
	MainMenuGamestate(Game& game, SDL_Renderer* renderer) : Gamestate(game), _sdlRenderer(renderer) {}
	void init() override;
	void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	void render(float dt) override;
	void teardown() override;


private:
	SDL_Renderer* _sdlRenderer;
};