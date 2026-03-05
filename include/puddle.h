#pragma once

#include <SFML\Graphics.hpp>
#include"resources_manager.h"


class Paddle : public sf::Drawable {
private:
	sf::Texture texture{};
	sf::RectangleShape body{};
	
	sf::Vector2f default_position;
	const float move_of_set{ 8.0f };
	sf::Vector2f limits;
	
	void moveRight();
	void moveLeft();

public:
	Paddle(Resources_Manager& resources, const sf::Vector2f& field_limits);

	static constexpr float body_width = 96.0f;
	static constexpr float body_height = 24.0f;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setLimits(const sf::Vector2f& field_limits);
	const sf::Vector2f& getPosition() const;
	float getUp();
	float getDown();
	float getLeft();
	float getRight();

	sf::FloatRect getGlobBounds() const;

	void update();
	void reInitiallize();

};