#include "LevelManager.h"
#include "Platform.h"
#include "Obstacle.h"
#include "Goal.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

static std::unique_ptr<GameObject> makeObject(const std::string& type,
    float x, float y, float w, float h)
{
    if (type == "PLATFORM")  return std::make_unique<Platform>(x, y, w, h);
    if (type == "OBSTACLE")  return std::make_unique<Obstacle>(x, y, w, h);
    if (type == "GOAL")      return std::make_unique<Goal>(x, y, w, h);
    throw std::runtime_error("Unknown object type: " + type);
}

bool LevelManager::loadLevel(const std::string& filename) {
    m_objects.clear();
    m_hasSpawn = false;

    std::ifstream in(filename);
    if (!in.is_open()) { std::cerr << "Failed to open " << filename << "\n"; return false; }

    std::string line; size_t ln = 0;
    while (std::getline(in, line)) {
        ++ln;
        if (line.empty() || line[0] == '#' || (line.size() >= 2 && line[0] == '/' && line[1] == '/')) continue;

        std::istringstream iss(line);
        std::string type; float x, y, w, h;

        //
        if (line.rfind("SPAWN", 0) == 0) {
            if (!(iss >> type >> x >> y)) { std::cerr << "Bad SPAWN at line " << ln << "\n"; continue; }
            m_spawn = { x, y }; m_hasSpawn = true;
            continue;
        }

        if (!(iss >> type >> x >> y >> w >> h)) {
            std::cerr << "Parse error at line " << ln << "\n"; continue;
        }

        try { m_objects.emplace_back(makeObject(type, x, y, w, h)); }
        catch (const std::exception& e) { std::cerr << e.what() << " (line " << ln << ")\n"; }
    }
    return true;
}

void LevelManager::update(float dt) { for (auto& o : m_objects) o->update(dt); }
void LevelManager::draw(sf::RenderWindow& window) const { for (auto& o : m_objects) o->draw(window); }
