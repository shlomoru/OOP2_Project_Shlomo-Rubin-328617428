#include "Game.h"
#include "MenuState.h"

Game::Game() : window(sf::VideoMode(800, 600), "Level Devil") {
	state = std::make_unique<MenuState>(this);
}

/*void Game::changeState(std::unique_ptr<IGameState> newState) {
	if (state) {
		state->onExit();
	}
	state = std::move(newState);
	if (state) {
		state->onEnter();
	}
}*/

void Game::changeState(std::unique_ptr<IGameState> newState) {
	state->onExit();
	state = std::move(newState);
	state->onEnter();
}

void Game::run() {
	sf::Clock clock;
	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (state)
				state->handleEvent(event);
		}
		
		if (state)
			state->update(dt);
		window.clear(sf::Color::Black);
		if (state)
			state->draw(window);
		window.display();
	}
}

sf::RenderWindow& Game::getWindow() {
	return window;
}
