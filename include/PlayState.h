#pragma once
#include "IGameState.h"
#include "Player.h"
#include "LevelManager.h"
#include "Platform.h"
#include "Obstacle.h"
#include "Goal.h"
#include <string>
#include <vector>

class Game;

class PlayState : public IGameState {
private:
    Game* game;
    Player player;
    LevelManager levelMgr;

    std::vector<std::string> levelPaths{
        "resources/levels/level1.txt",
        "resources/levels/level2.txt"
    };
    std::size_t levelIndex = 0;

    int maxLives = 3;
    int lives = 3;

    // SPAWN
    sf::Vector2f spawnPoint{ 120.f, 200.f };

    // HUD
    sf::Font font;
    sf::Text hud;

    void handleCollisions();
    void loadLevelByIndex(std::size_t idx);
    void nextLevel();
    void loseLife();

public:
    explicit PlayState(Game* g);
    void onEnter() override;
    void onExit() override {}
    void handleEvent(sf::Event& e) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
};



/*#pragma once
#include "IGameState.h"
#include "Player.h"
#include "LevelManager.h"
#include "Platform.h"
#include "Obstacle.h"
#include <string>

class Game;

class PlayState : public IGameState {
private:
    Game* game;
    Player player;
    LevelManager levelMgr;

    std::string currentLevelPath = "resources/levels/level1.txt";
    sf::Vector2f spawnPoint{ 120.f, 200.f };

    void handleCollisions();

public:
    explicit PlayState(Game* g);

    void onEnter() override;
    void onExit() override {}
    void handleEvent(sf::Event& e) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
};
*/


/*#pragma once
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
*/