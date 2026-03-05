#include "include/game.h"
#include <iostream>

Game::Game() : game_state(GameState::IN_PROGRESS), window_bg(window_background_texture), ball(resources,20.0f,460.0f, 360.0f,500.0f)
,paddle(resources, { static_cast<float>(window_width), static_cast<float>(window_height) })
{
	srand((unsigned int)time(NULL));
	window.create(sf::VideoMode({window_width,window_height})
		,"Arcanoid"
		, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60u);
	window.setMouseCursorVisible(false);
	



	//œŒƒ√–”∆¿“‹ »« ‘¿…À¿ HIGH_SCORE

}

void Game::setup() {

	font = resources.getFont("resources\\fonts\\karmatic_arcade.ttf");
	window_background_texture = resources.getTexture("resources\\textures\\background.png");
	window_background_texture.setRepeated(true);

	game_over_sound_buffer = resources.getSound("resources\\sounds\\game-lost.wav");
	game_won_sound_buffer = resources.getSound("resources\\sounds\\game-won.wav"); //   victory.wav
	game_next_level_sound_buffer = resources.getSound("resources\\sounds\\next_level.wav");

	game_over_sound.setBuffer(game_over_sound_buffer);
	game_won_sound.setBuffer(game_won_sound_buffer);
	game_next_level.setBuffer(game_next_level_sound_buffer);

	window.clear(sf::Color::Black);
	window_bg.setTextureRect({ {0,0}, {static_cast<int>(window_width), static_cast<int>(window_height)} });
	window_bg.setScale({1.5f, 1.5f});

	levels_manager.loadLevel(level);

	window.display();
}

void Game::show_splash_screen() {
	sf::Texture splash_screen_texture;
	if (!splash_screen_texture.loadFromFile("resources\\textures\\splashscreen.png") ) {
		std::cerr << "ERROR: Unable to load texture\n";
		exit(1);
	}
	sf::Sprite splash_screen(splash_screen_texture);
	window.draw(splash_screen);
	window.display();
	sf::sleep(sf::microseconds(2000000));
}


void Game::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		window.close();
	}

	if (game_state == GameState::IN_PROGRESS) {
		paddle.update();
		ball.update();
		paddlleIntersection.check_intersection();
		walItersection.check_intersection();

		if (blockIntersection.check_intersection()) {
			++score;
			high_score = (score > high_score) ? score : high_score;
		}
		scoreBoard.update(score, high_score);
	}


	if (ball.outOfBoard()) {
		gameLost();
	}
	if (levels_manager.blocks.empty()) {
		level_completed();
	}
}


void Game::draw() {
	window.clear(sf::Color::Black);
	window.draw(window_bg);
	window.draw(ball);
	window.draw(paddle);
	window.draw(scoreBoard);
	for (const auto& block : levels_manager.blocks) {
		window.draw(*block);
	}
	window.draw(messageBox);
	window.display();
}


void Game::level_completed() {

	//”¬≈À»◊»“‹ — Œ–Œ—“‹ ÿ¿–» ¿


	if (level + 1 < levels_manager.levelAmount()) {
		game_state = GameState::NEXT_LEVEL_DELAY;
		messageBox.setString("NEW LEVEL");

		if (!game_sound_played) {
			game_next_level.play();
			game_sound_played = true;
		}

		levelCompletedFreeze();
	}
	else {
		game_state = GameState::GAME_WON;
		messageBox.setString("VICTORY");

		if (!game_sound_played) {
			game_won_sound.play();
			game_sound_played = true;
		}

		//œ‡Á‰ÌË˜Ì‡ˇ ÏÛÁ˚Í‡
		//Õ‡ËÒÓ‚‡Ú¸ ÓÍÌÓ Ò ‚˚Ë„˚¯ÂÏ
		winLoseFreeze();
	}
}

void Game::gameLost() {
	game_state = GameState::GAME_OVER;

	if (!game_sound_played) {
		game_over_sound.play();
		game_sound_played = true;
	}

	//Œ·ÌÓ‚ËÚ¸Ú‡·ÎËˆÛ ÎË‰Â‡ highScore
	messageBox.setString("GAME OVER");
	winLoseFreeze();
}


void  Game::winLoseFreeze() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		score = 0;
		level = 0;
		levels_manager.loadLevel(level);
		ball.reInitiallize();
		paddle.reInitiallize();
		messageBox.setString("");

		game_won_sound.stop();
		game_over_sound.stop();
		game_sound_played = false;

		game_state = GameState::IN_PROGRESS;
	}
}


void Game::levelCompletedFreeze() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		++level;
		levels_manager.loadLevel(level);
		ball.reInitiallize();
		paddle.reInitiallize();
		messageBox.setString("");

		game_next_level.stop();
		game_sound_played = false;
		
		game_state = GameState::IN_PROGRESS;
	}
}

//«¿√–”∆¿“‹ ¬ ‘¿…À HIGH_SCORE
//—ƒ≈À¿“‹ «¬”  —“ŒÀ ÕŒ¬≈“»ﬂ ÿ¿–» ¿ »  »–œ»◊» ¿
