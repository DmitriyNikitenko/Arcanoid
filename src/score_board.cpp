#include "include/score_board.h"

ScoreBoard::ScoreBoard(const sf::Font& font, float window_width, float window_height) : score_txt(font), high_score_txt(font) {
	body.setSize({window_width, 80.0f});
	body.setPosition({ 0.0f,window_height - 80.0f });
	body.setFillColor(sf::Color::Black);
	body.setOutlineColor(sf::Color::White);

	score_txt.setCharacterSize(24);
	score_txt.setPosition({ body.getPosition().x + 10.0f,
		body.getPosition().y + 10.0f});
	score_txt.setFillColor(sf::Color::White);

	high_score_txt.setCharacterSize(24);
	high_score_txt.setPosition({ body.getPosition().x + body.getSize().x / 2 + 10.0f,
		body.getPosition().y + 10.0f });
	high_score_txt.setFillColor(sf::Color::White);


}

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const 
 {
	target.draw(body, states);
	target.draw(score_txt, states);
	target.draw(high_score_txt, states);
}


void ScoreBoard::update(unsigned int score, unsigned int highscore) {
	score_txt.setString("SCORE\n" + std::to_string(score));
	high_score_txt.setString("HIGH SCORE\n" + std::to_string(highscore));

}