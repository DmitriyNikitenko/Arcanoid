#include  "include\block.h"

Block::Block(Resources_Manager& resources, BlockColor color, const sf::Vector2f init) {
	body = sf::RectangleShape({ Block::width, Block::height });
	texture = resources.getTexture("resources\\textures\\objects.png");
	body.setOrigin({ Block::width / 2.0f, Block::height / 2 });
	body.setPosition(init);
	body.setTexture(&texture);

	switch (color) {
	case BlockColor::orange: {
		body.setTextureRect({ {0 , 0}, {64 , 32} });
		break;
	}
	case BlockColor::red: {
		body.setTextureRect({ {72 , 0}, {64 , 32} });
		break;
	}
	case BlockColor::green: {
		body.setTextureRect({ {144 , 0}, {64 , 32} });
		break;
	}
	case BlockColor::blue: {
		body.setTextureRect({ {216 , 0}, {64 , 32} });
		break;
	}
	case BlockColor::pink: {
		body.setTextureRect({ {0 , 40}, {64 , 32} });
		break;
	}
	case BlockColor::cyan: {
		body.setTextureRect({ {72 , 40}, {64 , 32} });
		break;
	}
	case BlockColor::yellow: {
		body.setTextureRect({ {144 , 40}, {64 , 32} });
		break;
	}
	case BlockColor::magenta: {
		body.setTextureRect({ {216 , 40}, {64 , 32} });
		break;
	}
	}

}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(body, states);
}

sf::FloatRect Block::getGlobBounds() const {
	return body.getGlobalBounds();
}


