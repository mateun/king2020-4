#pragma once
#include "gamestate.h"


class SplashGamestate : public Gamestate {

public:
	void init() override;
	void update(float dt) override;
	void teardown() override;
};