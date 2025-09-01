#pragma once
#include "GameObject.h"

class Obstacle : public GameObject {
private:
    sf::RectangleShape shape;

public:
    Obstacle(float x, float y, float w, float h);

    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getBounds() const override;
};

