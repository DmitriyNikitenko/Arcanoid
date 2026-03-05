#include "include/puddle.h"

Paddle::Paddle(Resources_Manager& resources, const sf::Vector2f& field_limits)  {
	body = sf::RectangleShape({ body_width,body_height });
	texture = resources.getTexture("resources\\textures\\objects.png");
	body.setTexture(&texture);
	body.setTextureRect({ {184,112}, {96,24} });
	body.setOrigin({ body_width / 2, body_height / 2 });
	setLimits(field_limits);
	//default_position = { 256.0f, 688.0f };
	//body.setPosition(default_position);
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(body, states);
}

void Paddle::moveRight() {
	if (getRight() < limits.x) {
		body.move({ move_of_set, 0.0f });
	}
}

void Paddle::moveLeft() {
	if (getLeft() > 0) {
		body.move({ -move_of_set, 0.0f });
	}
}

void Paddle::update() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))) {
		moveLeft();
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))) {
		moveRight();
	}

}


void Paddle::setLimits(const sf::Vector2f& field_limits) {
	limits = field_limits;
	default_position = { limits.x / 2, limits.y - body_height - 100.0f };
	reInitiallize();
}

const sf::Vector2f& Paddle::getPosition() const {
	return body.getPosition();
}

float Paddle::getUp() {
	return body.getPosition().y + Paddle::body_height / 2;
}

float Paddle::getDown() {
	return body.getPosition().y - Paddle::body_height / 2;
}

float Paddle::getLeft() {
	return body.getPosition().x - Paddle::body_width / 2;
}

float Paddle::getRight() {
	return body.getPosition().x + Paddle::body_width / 2;
}

void Paddle::reInitiallize() {
	body.setPosition(default_position);
}



sf::FloatRect Paddle::getGlobBounds() const {
	return body.getGlobalBounds();
}