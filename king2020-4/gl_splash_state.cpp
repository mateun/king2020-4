#include "gl_splash_state.h"
#include "glew/GL/glew.h"
#include "game.h"

void GSSplashGL::init()
{
}

void GSSplashGL::update(float dt, std::vector<SDL_Event>& frameEvents)
{
}

void GSSplashGL::render(float dt)
{
	glClearColor(0, 0.5, 0.5, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	this->_game.swap();
}

void GSSplashGL::teardown()
{
}
