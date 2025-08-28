#include "Player.h"

Player::Player(float x, float y) : velocity(0.f, 0.f), onGround(false) {
	shape.setSize({40.f, 40.f});
	shape.setFillColor(sf::Color::Green);
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

void Player::update(float dt) {
	applyGravity(dt);
	shape.move(velocity * dt);

	// Simple ground collision
	if (shape.getPosition().y + shape.getSize().y >= 500.f) {
		shape.setPosition(shape.getPosition().x, 500.f - shape.getSize().y);
		velocity.y = 0.f;
		onGround = true;
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::FloatRect Player::getBounds() const {
	return shape.getGlobalBounds();
}