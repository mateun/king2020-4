#pragma once
#include "game.h"
#include "gamestate.h"
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <vector>
#include <string>

class DefaultGame : public Game {
public:

	DefaultGame(int screenWidth, int screenHeight, bool fullScreen);

	void start() override;
	void stop() override;
	void moveToNextGamestate() override;
	void activateConsole() override;
	void deactivateConsole() override;
	void printToConsole(const std::string& text) override;
	void renderConsole() override;


private:
	int _screenWidth;
	int _screenHeight;
	bool _fullScreen;
	bool _running;
	int _gameStateIndex = 0;
	bool _consoleActive;
	std::vector<std::string> _consoleLines;
	TTF_Font* _consoleFont;
	SDL_Renderer* _sdlRenderer;
	SDL_Window* _sdlWindow;
};
