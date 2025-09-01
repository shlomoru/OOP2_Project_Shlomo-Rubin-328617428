#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderWindow & window) const = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual ~GameObject() {}
};
