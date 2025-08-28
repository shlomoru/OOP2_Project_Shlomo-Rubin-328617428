#pragma once
#include <SFML/Graphics.hpp>

class IGameState {
public:
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual void handleEvent(sf::Event& e) = 0;
	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~IGameState() {}
};