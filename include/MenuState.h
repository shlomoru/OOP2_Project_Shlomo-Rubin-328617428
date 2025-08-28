#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Game;

class MenuState : public IGameState {
private:
	Game* game;
	sf::Font font;
	sf::Text text;

public:
	MenuState(Game* g);
	void onEnter() override;
	void onExit() override;
	void handleEvent(sf::Event& e) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};
