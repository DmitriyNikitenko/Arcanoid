#include "include/message_box.h"
#include "include/game.h"

MessageBox::MessageBox(const sf::Font& font) : text(font) {
	text.setCharacterSize(48u);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2.0f);
	text.setString("");
	alignCenter();
}

void MessageBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(text, states);
}

void MessageBox::setString(const std::string& msg) {
	this->message = msg;
	text.setString(this->message);
	alignCenter();
}

void MessageBox::alignCenter() {
	auto x_position = static_cast<float>((Game::window_width)-text.getGlobalBounds().size.x) / 2.0f;
	auto y_position = static_cast<float>((Game::window_width)-text.getGlobalBounds().size.y - 80.0f) / 2.0f;

	text.setPosition({x_position,y_position});
}

