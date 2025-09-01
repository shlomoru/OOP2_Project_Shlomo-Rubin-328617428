#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

MenuState::MenuState(Game* g) : game(g) {
	if (!font.loadFromFile("resources/fonts/arialbd.ttf")) {
		std::cerr << "Failed to load font\n";
	}
	text.setFont(font);
	text.setString("Press Enter to Start");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(200.f, 250.f);
}
void MenuState::onEnter() {
	std::cout << "Entering Menu State\n";
}

void MenuState::onExit() {
	std::cout << "Exiting Menu State\n";
}
void MenuState::handleEvent(sf::Event& e) {
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
		game->changeState(std::make_unique<PlayState>(game));
	}
}

void MenuState::update(float dt) {
	// No dynamic elements to update in the menu
}

void MenuState::draw(sf::RenderWindow& window) {
	window.draw(text);
}
