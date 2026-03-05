#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class MessageBox : public sf::Drawable {
private:
	sf::Text text;
	std::string message;
public:
	MessageBox(const sf::Font& font);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setString(const std::string& message);
	void alignCenter();

	
	std::string get() {
		return message;
	}

};