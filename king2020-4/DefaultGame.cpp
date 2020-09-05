#include "game.h"
#include "default_game.h"
#include <SDL.h>
#include <algorithm>
#include <GL/glew.h>

DefaultGame::DefaultGame( int screenWidth, int screenHeight, bool fullScreen) 
	: _screenWidth(screenWidth), _screenHeight(screenHeight), _fullScreen(fullScreen)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("error initializing SDL, quitting.");
		exit(10);
	}

	SDL_Log("SDL initialized!");

	_sdlWindow = SDL_CreateWindow("default game window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(_sdlWindow);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		SDL_Log("Error: %s\n", glewGetErrorString(err));
		exit(100);
	}
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
		_gameStates[_gameStateIndex]->render(1);

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

	SDL_GL_DeleteContext(_glContext);
	SDL_Quit();
	_running = false;
}

void DefaultGame::swap() {
	SDL_GL_SwapWindow(_sdlWindow);
}
