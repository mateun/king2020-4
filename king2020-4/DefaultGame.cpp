#include "game.h"
#include "default_game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <algorithm>

DefaultGame::DefaultGame( int screenWidth, int screenHeight, bool fullScreen) 
	: _screenWidth(screenWidth), _screenHeight(screenHeight), _fullScreen(fullScreen)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("error initializing SDL, quitting.");
		exit(10);
	}

	SDL_Log("SDL initialized!");

	{
		if (TTF_Init() == -1) {
			SDL_Log("TTF init failed. ");
			exit(11);
		}

		_consoleFont = TTF_OpenFont("E:/Projects/C++/king2020-4/x64/Debug/SLC_.ttf", 16);

		if (!_consoleFont) {
			SDL_Log("TTF_OpenFont: %s\n", TTF_GetError());
			// handle error
		}


	}

	_sdlWindow = SDL_CreateWindow("default game window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
	_sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//deactivateConsole();

}

void DefaultGame::start() {

	std::vector<SDL_Event> frameEvents;

	_gameStates[0]->init();

	while (_running) {

		frameEvents.clear();

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				_running = false;
				break;
			}

			// TODO: store SDL events in vector to be passed on to the current game state update method
			frameEvents.push_back(event);
		}

		_gameStates[_gameStateIndex]->update(1, frameEvents);
		_gameStates[_gameStateIndex]->render(_sdlRenderer);

	}

}

void DefaultGame::renderConsole() {
	if (!_consoleActive) return;

	SDL_Color color = { 0,0,0 };
	SDL_Surface* textSurface;
	
	int line = 0;

	int offset = std::max<int>(0, _consoleLines.size() - 5);
	

	for (int i = offset ; i < _consoleLines.size(); i++) {
		
		std::string text = _consoleLines[i];
		if (!(textSurface = TTF_RenderText_Solid(_consoleFont, text.c_str(), color))) {
			//handle error here, perhaps print TTF_GetError at least
			SDL_Log(TTF_GetError());
		}
		else {
			SDL_Rect dr;
			SDL_Texture* texture = SDL_CreateTextureFromSurface(_sdlRenderer, textSurface);
			SDL_QueryTexture(texture, NULL, NULL, &dr.w, &dr.h);

			dr.x = 10;
			dr.y = line * 20;

			SDL_RenderCopy(_sdlRenderer, texture, NULL, &dr);

			SDL_DestroyTexture(texture);
			SDL_FreeSurface(textSurface);
		}
		line++;

	}

}

void DefaultGame::moveToNextGamestate() {
	_gameStates[_gameStateIndex]->teardown();

	if (_gameStateIndex == _gameStates.size()-1) {
		SDL_Log("The last gamestate was stoppped. Ending the game now.");
		stop();
		return;
	}

	_gameStateIndex++;
	_gameStates[_gameStateIndex]->init();
}

void DefaultGame::stop() {
	SDL_Log("Ending the default game.");
	SDL_Log("Stopping SDL.");

	TTF_Quit();
	SDL_Quit();
	_running = false;
}

void DefaultGame::printToConsole(const std::string& text) {
	_consoleLines.push_back(text);
}

void DefaultGame::activateConsole() {
	_consoleActive = true;
}

void DefaultGame::deactivateConsole() {
	_consoleActive = false;
}