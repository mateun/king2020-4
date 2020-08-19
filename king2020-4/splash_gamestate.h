#pragma once
#include "gamestate.h"

class SDL_Renderer;


class SplashGamestate : public Gamestate {

public:
	void init() override;
	void update(float dt) override;
	void render(SDL_Renderer* renderer) override;
	void teardown() override;
};