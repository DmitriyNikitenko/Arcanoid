#pragma once
#include <SFML/Graphics.hpp>

class ScoreBoard : public sf::Drawable {
private:
	sf::RectangleShape body{};
	sf::Text score_txt;
	sf::Text high_score_txt;
public:

	ScoreBoard(const sf::Font& font,float window_width, float height);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(unsigned int score, unsigned int high_score);

};