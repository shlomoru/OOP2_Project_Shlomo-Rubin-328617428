#pragma once
#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class LevelManager {
public:
    bool loadLevel(const std::string& filename);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
    const std::vector<std::unique_ptr<GameObject>>& objects() const { return m_objects; }

    bool hasSpawn() const { return m_hasSpawn; }
    sf::Vector2f spawn() const { return m_spawn; }

private:
    std::vector<std::unique_ptr<GameObject>> m_objects;
    bool m_hasSpawn = false;
    sf::Vector2f m_spawn{ 120.f, 200.f };
};
