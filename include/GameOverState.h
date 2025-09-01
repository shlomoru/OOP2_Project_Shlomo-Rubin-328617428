#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
#include <string>

class Game;

class GameOverState : public IGameState {
    Game* game;
    sf::Font font;
    sf::Text title, info;
    std::string msg;

public:
    GameOverState(Game* g, std::string message = "You Lost!");

    void onEnter() override;
    void onExit() override {}
    void handleEvent(sf::Event& e) override;
    void update(float dt) override {}
    void draw(sf::RenderWindow& window) override;
};

