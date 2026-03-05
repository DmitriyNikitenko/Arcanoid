#include "include\ball.h"
#include "include\game.h"
#include "include\puddle.h"
#include <random>

Ball::Ball(Resources_Manager& resources, float min_x, float max_x, float min_y, float max_y) : min_x(min_x) , max_x(max_x) , min_y(min_y), max_y(max_y) {
	texture = resources.getTexture("resources\\textures\\objects.png");
	body = sf::CircleShape(12.0f);
	body.setTexture(&texture);
	body.setTextureRect({ {0, 80} , {24,24} });
	body.setOrigin( { 12.0f, 12.0f } );
	body.setPosition(randomizePosition(min_x, max_x, min_y, max_y));
}

void  Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(body, states);
}

const sf::Vector2f& Ball::getPosition() const {
	return body.getPosition();
}

float Ball::getUp() {
	return  body.getPosition().y - body.getRadius();
}

float Ball::getDown() {
	return  body.getPosition().y + body.getRadius();
}

float Ball::getLeft() {
	return  body.getPosition().x - body.getRadius();
}

float Ball::getRight() {
	return  body.getPosition().x + body.getRadius();
}

bool Ball::outOfBoard() const {
	return out_of_board;
}

void Ball::update() {
	body.move(velocity);
	if (getDown() > Game::play_area_height - Paddle::body_height) {
		out_of_board = true;
		velocity = { 0.0f,0.0f };
	}
}

void Ball::reInitiallize() {
	body.setPosition(randomizePosition(min_x, max_x, min_y, max_y));
	velocity = { init_x_velocity,init_y_velocity };
	out_of_board = false;
}

sf::Vector2f Ball::randomizePosition(float min_x, float max_x, float min_y, float max_y) {
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> destrb_x(min_x, max_x);
	std::uniform_real_distribution<float> destrb_y(min_y, max_y);

	return sf::Vector2f(destrb_x(mt), destrb_y(mt));
}


void Ball::bounceX() {
	velocity.x *= -1.0;
}

void Ball::bounceY() {
	velocity.y *= -1.0;
}


sf::FloatRect Ball::getGlobBounds() const {
	return body.getGlobalBounds();
}

