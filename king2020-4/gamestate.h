#pragma once
class SDL_Renderer;

class Gamestate {
public:
	virtual void init() = 0;
	virtual void update(float dt) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual void teardown() = 0;



};