#include "openglgame.h"
#include <SDL.h>

OpenGLGame::OpenGLGame(int screenWidth, int screenHeight, bool fullScreen)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("error initializing SDL, quitting.");
		exit(10);
	}

	SDL_Log("SDL initialized!");

	_sdlWindow = SDL_CreateWindow("default game window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

}

void OpenGLGame::start()
{
}

void OpenGLGame::stop()
{
}

void OpenGLGame::moveToNextGamestate()
{
}
