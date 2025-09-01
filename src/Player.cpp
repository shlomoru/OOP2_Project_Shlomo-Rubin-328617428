#include "Player.h"

Player::Player(float x, float y, sf::Vector2u winSize) 
	: velocity(0.f, 0.f), onGround(false), windowSize(winSize)
{
	shape.setSize({30.f, 40.f});
	shape.setFillColor(sf::Color::White);
	shape.setPosition(x, y);

}

void Player::move(int dir) {
	velocity.x = dir * 200.f; // Move speed
}

void Player::jump() {
	if (onGround) {
		velocity.y = -400.f; // Jump strength
		onGround = false;
	}
}

void Player::applyGravity(float dt) {
	velocity.y += 800.f * dt; // Gravity
}

void Player::setPosition(float x, float y) {
	shape.setPosition(x, y);
}

float Player::getVelocityY() const {
	return velocity.y;
}
sf::Vector2f Player::getPosition() const {
	return shape.getPosition();
}

void Player::setOnGround(bool on, float groundY) {
	if (on) {
		velocity.y = 0.f;
		shape.setPosition(shape.getPosition().x, groundY - shape.getSize().y);
		onGround = true;
	}
	else {
		onGround = false;
	}
}

void Player::update(float dt) {
	applyGravity(dt);
	shape.move(velocity * dt);

	// Simple ground collision
	if (shape.getPosition().y + shape.getSize().y >= 500.f) {
		shape.setPosition(shape.getPosition().x, 500.f - shape.getSize().y);
		velocity.y = 0.f;
		onGround = true;
	}

	//Top Border
	if (shape.getPosition().y < 0.f) {
		shape.setPosition(shape.getPosition().x, 0.f);
		velocity.y = 0;
	}

	//Left Border
	if (shape.getPosition().x < 0.f) {
		shape.setPosition(0.f, shape.getPosition().y);
	}

	//Right Border
	if (shape.getPosition().x + shape.getSize().x > windowSize.x) {
		shape.setPosition(windowSize.x - shape.getSize().x, shape.getPosition().y);
	}
}

void Player::draw(sf::RenderWindow& window) const {
	window.draw(shape);
}

sf::FloatRect Player::getBounds() const {
	return shape.getGlobalBounds();
}