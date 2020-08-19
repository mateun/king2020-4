#pragma once
#include "game.h"
#include "gamestate.h"
#include <SDL.h>

class DefaultGame : public Game {
public:

	DefaultGame(std::vector<Gamestate*> gameStates, int screenWidth, int screenHeight, bool fullScreen);

	void start() override;
	void stop() override;


private:
	int _screenWidth;
	int _screenHeight;
	bool _fullScreen;
	bool _running;
	SDL_Renderer* _sdlRenderer;
	SDL_Window* _sdlWindow;
};
