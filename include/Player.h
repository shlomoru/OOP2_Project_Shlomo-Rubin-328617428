#pragma once
#include "GameObject.h"

class Player : public GameObject {
private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	bool onGround;

public:
	Player(float x, float y);
	void move(int dir);
	void jump();
	void applyGravity(float dt);

	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getBounds() const override;
};