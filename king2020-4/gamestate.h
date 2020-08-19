#pragma once


class Gamestate {
public:
	virtual void init() = 0;
	virtual void update(float dt) = 0;
	virtual void teardown() = 0;



};