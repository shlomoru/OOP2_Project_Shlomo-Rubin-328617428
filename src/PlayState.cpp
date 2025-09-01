#include "PlayState.h"
#include "Game.h"
#include "GameOverState.h"
#include <iostream>

PlayState::PlayState(Game* g)
    : game(g),
    player(spawnPoint.x, spawnPoint.y, g->getWindow().getSize())
{
}

void PlayState::onEnter() {
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cerr << "HUD font load failed\n";
    }
    hud.setFont(font);
    hud.setCharacterSize(20);
    hud.setFillColor(sf::Color::White);

    loadLevelByIndex(levelIndex);
}

void PlayState::loadLevelByIndex(std::size_t idx) {
    if (idx >= levelPaths.size()) {
        //
        levelIndex = 0; lives = maxLives;
        // 
        levelMgr.loadLevel(levelPaths[levelIndex]);
    }
    else {
        levelMgr.loadLevel(levelPaths[idx]);
    }

    // spawn
    if (levelMgr.hasSpawn()) spawnPoint = levelMgr.spawn();
    player.setPosition(spawnPoint.x, spawnPoint.y);
}

void PlayState::nextLevel() {
    ++levelIndex;
    loadLevelByIndex(levelIndex);
}

void PlayState::loseLife() {
    --lives;
    if (lives <= 0) {
        game->changeState(std::make_unique<GameOverState>(game, "Out of lives"));
        return;
    }
    player.setPosition(spawnPoint.x, spawnPoint.y);
}


/*void PlayState::loseLife() {
    --lives;
    player.setPosition(spawnPoint.x, spawnPoint.y);
    if (lives <= 0) {
        // Game Over
        levelIndex = 0;
        lives = maxLives;
        loadLevelByIndex(levelIndex);
    }
}*/

void PlayState::handleEvent(sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Left)  player.move(-1);
        if (e.key.code == sf::Keyboard::Right) player.move(1);
        if (e.key.code == sf::Keyboard::Space) player.jump();
        if (e.key.code == sf::Keyboard::R)     player.setPosition(spawnPoint.x, spawnPoint.y);
    }
    if (e.type == sf::Event::KeyReleased) {
        if (e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)
            player.move(0);
    }
}

void PlayState::update(float dt) {
    player.update(dt);
    levelMgr.update(dt);
    handleCollisions();

    hud.setString("Level: " + std::to_string(levelIndex + 1) +
        "   Lives: " + std::to_string(lives));
    hud.setPosition(10.f, 10.f);
}

void PlayState::draw(sf::RenderWindow& window) {
    levelMgr.draw(window);
    player.draw(window);
    window.draw(hud);
}

void PlayState::handleCollisions() {
    const auto pb = player.getBounds();

    for (const auto& obj : levelMgr.objects()) {
        const auto ob = obj->getBounds();
        if (!pb.intersects(ob)) continue;

        if (auto p = dynamic_cast<const Platform*>(obj.get())) {
            const float platformTop = ob.top;
            const float playerTop = pb.top;
            const float playerBottom = pb.top + pb.height;

            if (player.getVelocityY() > 0.f && playerTop < platformTop && playerBottom >= platformTop) {
                player.setOnGround(true, platformTop);
            }
        }
        else if (auto o = dynamic_cast<const Obstacle*>(obj.get())) {
            (void)o;
            loseLife();
            break;
        }
        else if (auto g = dynamic_cast<const Goal*>(obj.get())) {
            (void)g;
            nextLevel();
            break;
        }
    }
}


/*
#include "PlayState.h"
#include "Game.h"
#include <iostream>

PlayState::PlayState(Game* g)
    : game(g),
    player(spawnPoint.x, spawnPoint.y, g->getWindow().getSize())
{
}

void PlayState::onEnter() {
    if (!levelMgr.loadLevel(currentLevelPath)) {
        std::cerr << "PlayState: failed to load " << currentLevelPath << "\n";
    }
}

void PlayState::handleEvent(sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Left)  player.move(-1);
        if (e.key.code == sf::Keyboard::Right) player.move(1);
        if (e.key.code == sf::Keyboard::Space) player.jump();
        if (e.key.code == sf::Keyboard::R)     player.setPosition(spawnPoint.x, spawnPoint.y);
    }
    if (e.type == sf::Event::KeyReleased) {
        if (e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)
            player.move(0);
    }
}

void PlayState::update(float dt) {
    player.update(dt);
    levelMgr.update(dt);
    handleCollisions();
}

void PlayState::draw(sf::RenderWindow& window) {
    levelMgr.draw(window);
    player.draw(window);
}

void PlayState::handleCollisions() {
    const auto pb = player.getBounds();

    for (const auto& obj : levelMgr.objects()) {
        const auto ob = obj->getBounds();
        if (!pb.intersects(ob)) continue;

        if (auto p = dynamic_cast<const Platform*>(obj.get())) {
            const float platformTop = ob.top;
            const float playerTop = pb.top;
            const float playerBottom = pb.top + pb.height;

            if (player.getVelocityY() > 0.f && playerTop < platformTop && playerBottom >= platformTop) {
                player.setOnGround(true, platformTop);
            }
        }
        else if (auto o = dynamic_cast<const Obstacle*>(obj.get())) {
            (void)o;
            player.setPosition(spawnPoint.x, spawnPoint.y);
        }
    }
}



/*
#include <iostream>
#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* g) 
	: game(g), player(200.f, 200.f, g->getWindow().getSize()) {}

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
*/