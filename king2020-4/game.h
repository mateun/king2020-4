#pragma once
#include <vector>
#include <string>

class Gamestate;


class Game {
public:

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void moveToNextGamestate() = 0;
	virtual void swap() = 0;

	void addGameStates(std::vector<Gamestate*>&& gameStates) {
		_gameStates = gameStates;
	}
	void addGameState(Gamestate* gamestate) {
		_gameStates.push_back(gamestate);
	}

protected:
	std::vector<Gamestate*> _gameStates;

};