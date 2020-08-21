#pragma once
#include <vector>
#include <string>

class Gamestate;

class Game {
public:

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void moveToNextGamestate() = 0;

// console stuff
public:

	virtual void activateConsole() = 0;
	virtual void deactivateConsole() = 0; 
	virtual void printToConsole(const std::string& text) = 0;
	virtual void renderConsole() = 0;


	void addGameStates(std::vector<Gamestate*>&& gameStates) {
		_gameStates = gameStates;
	}
	void addGameState(Gamestate* gamestate) {
		_gameStates.push_back(gamestate);
	}

protected:
	std::vector<Gamestate*> _gameStates;


};