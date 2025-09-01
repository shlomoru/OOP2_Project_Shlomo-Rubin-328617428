#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>

GameOverState::GameOverState(Game* g, std::string message)
    : game(g), msg(std::move(message)) {
}

void GameOverState::onEnter() {
    if (!font.loadFromFile("resources/fonts/arial.ttf"))
        std::cerr << "GameOverState: failed to load font\n";

    title.setFont(font);
    title.setString("GAME OVER");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::Red);

    info.setFont(font);
    info.setString(msg + "\nPress ENTER to Retry\nPress ESC for Menu");
    info.setCharacterSize(24);
    info.setFillColor(sf::Color::White);

    auto size = game->getWindow().getSize();
    title.setPosition(size.x / 2.f - title.getGlobalBounds().width / 2.f, size.y / 2.f - 100.f);
    info.setPosition(size.x / 2.f - info.getGlobalBounds().width / 2.f, size.y / 2.f);
}

void GameOverState::handleEvent(sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Enter) {
            game->changeState(std::make_unique<PlayState>(game));
        }
        else if (e.key.code == sf::Keyboard::Escape) {
            game->changeState(std::make_unique<MenuState>(game));
        }
    }
}

void GameOverState::draw(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(info);
}
