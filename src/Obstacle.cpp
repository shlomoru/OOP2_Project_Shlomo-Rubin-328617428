#include "Obstacle.h"

Obstacle::Obstacle(float x, float y, float w, float h) {
    shape.setPosition(x, y);
    shape.setSize({ w, h });
    shape.setFillColor(sf::Color::Red);
}

void Obstacle::update(float dt) {
    // 
}

void Obstacle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}
