#pragma once
#include "GameObject.h"

class Platform : public GameObject {
private:
    sf::RectangleShape shape;

public:
    Platform(float x, float y, float w, float h);

    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getBounds() const override;
};

