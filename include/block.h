#pragma once
#include "SFML/Graphics.hpp"
#include"resources_manager.h"


enum class BlockColor : std::uint8_t {
	orange = 0 ,red = 1, green = 2, blue = 3, 
	pink = 4, cyan = 5, yellow = 6, magenta = 7
};

class Block : public sf::Drawable {
private:
	sf::RectangleShape body{};
	sf::Texture texture{};
public:
	static constexpr float width = 48.0f;
	static constexpr float height = 24.0f;
	
	Block(Resources_Manager& resources, BlockColor color,const sf::Vector2f init);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::FloatRect getGlobBounds() const;


};