#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "IGameState.h"

class Game {
private:
	sf::RenderWindow window;
	std::unique_ptr<IGameState> state;

public:
	Game();
	void changeState(std::unique_ptr<IGameState> newState);
	void run();
	sf::RenderWindow& getWindow();
};