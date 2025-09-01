#pragma once
#include "GameObject.h"

class Goal : public GameObject {
    sf::RectangleShape shape;
public:
    Goal(float x, float y, float w, float h) {
        shape.setPosition(x, y);
        shape.setSize({ w, h });
        shape.setFillColor(sf::Color::Yellow);
    }
    void update(float) override {}
    void draw(sf::RenderWindow& window) const override { window.draw(shape); }
    sf::FloatRect getBounds() const override { return shape.getGlobalBounds(); }
};

