#pragma once

#include <SFML\Graphics.hpp>
#include"resources_manager.h"

class Ball : public sf::Drawable {
private:

	sf::Texture texture{};
	sf::CircleShape body{};

	float init_x_velocity = 5.0f;
	float init_y_velocity = 5.0f;
	sf::Vector2f velocity{init_x_velocity,init_y_velocity};

	const float min_x , max_x, min_y,max_y;
	sf::Vector2f randomizePosition(float min_x, float max_x , float min_y , float max_y);

	bool out_of_board{ false };

public:
	Ball(Resources_Manager& resources, float min_x, float max_x, float min_y, float max_y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	const sf::Vector2f& getPosition() const;
	float getUp();
	float getDown();
	float getLeft();
	float getRight();

	void bounceX();
	void bounceY();

	sf::FloatRect getGlobBounds() const;

	bool outOfBoard() const;

	void update();
	void reInitiallize();

};