#pragma once
#include "GameObject.h"

class Player : public GameObject {
private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	bool onGround;
	sf::Vector2u windowSize;

public:
	Player(float x, float y, sf::Vector2u winSize);
	void move(int dir);
	void jump();
	void applyGravity(float dt);
	void setPosition(float x, float y);
	float getVelocityY() const;
	sf::Vector2f getPosition() const;
	void setOnGround(bool on, float groundY);

	void update(float dt) override;
	void draw(sf::RenderWindow& window) const override;
	sf::FloatRect getBounds() const override;
};

