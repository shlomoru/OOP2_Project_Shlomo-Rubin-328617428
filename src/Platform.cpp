#include "Platform.h"

Platform::Platform(float x, float y, float w, float h) {
    shape.setPosition(x, y);
    shape.setSize({ w, h });
    shape.setFillColor(sf::Color::Green);
}

void Platform::update(float dt) {
    //
}

void Platform::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Platform::getBounds() const {
    return shape.getGlobalBounds();
}
