#pragma once
#include <vector>

class Gamestate;

class Game {
public:
	Game(std::vector<Gamestate*> gameStates) :_gameStates(gameStates) {
		
	}

	virtual void start() = 0;
	virtual void stop() = 0;

protected:
	std::vector<Gamestate*> _gameStates;

};