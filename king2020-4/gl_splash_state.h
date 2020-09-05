#pragma once

#include "gamestate.h"
#include <vector>
#include <vector>


class GSSplashGL : public Gamestate {

public:
	GSSplashGL(Game& game) : Gamestate(game) {}
	void init() override;
	void update(float dt, std::vector<SDL_Event>& frameEvents) override;
	void render(float dt) override;
	void teardown() override;


private:
	int frame = 0;

};
