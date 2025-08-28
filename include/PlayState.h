#pragma once
#include "IGameState.h"
#include "Player.h"

class Game;

class PlayState : public IGameState {
private:
	Game* game;
	Player player;

public:
	PlayState(Game* g);
	void onEnter() override;
	void onExit() override;
	void handleEvent(sf::Event& e) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};
