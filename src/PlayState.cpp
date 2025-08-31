#include <iostream>
#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* g) : game(g), player(200.f, 200.f) {}

void PlayState::onEnter() {
	std::cout << "Entering Play State\n";
}

void PlayState::onExit() {
	std::cout << "Exiting Play State\n";
}

void PlayState::handleEvent(sf::Event& e) {
	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Left) {
			player.move(-1);
		}
		else if (e.key.code == sf::Keyboard::Right) {
			player.move(1);
		}
		else if (e.key.code == sf::Keyboard::Space) {
			player.jump();
		}
	}
	else if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right) {
			player.move(0);
		}
	}
}

void PlayState::update(float dt) {
	player.update(dt);
}

void PlayState::draw(sf::RenderWindow& window) {
	player.draw(window);
}
