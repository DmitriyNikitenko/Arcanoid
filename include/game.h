#pragma once
#include <SFML/Graphics.hpp> //Enter your path to the library
#include <SFML/Audio.hpp>
#include "resources_manager.h"
#include "puddle.h"
#include "ball.h"
#include "paddle_intersection.h"
#include "wall_intersection.h"
#include "levels_manager.h"
#include "block_intersection.h"
#include "score_board.h"
#include "message_box.h"

enum class GameState : std::uint8_t {
	IN_PROGRESS, GAME_OVER, GAME_WON , NEXT_LEVEL_DELAY
};

class Game {
	GameState game_state;
	Resources_Manager resources;
	LevelsManager levels_manager{ resources };

	//RESOURCES
	sf::Texture window_background_texture;
	sf::Font font;

	//SPRITES
	sf::Sprite window_bg;

	Paddle paddle;
	Ball ball;

	PaddlleIntersection paddlleIntersection{ ball, paddle };
	WalItersection walItersection{ ball, *this };
	BlockIntersection blockIntersection{ball,levels_manager.blocks};
	

	ScoreBoard scoreBoard{font,window_width,window_height};
	MessageBox messageBox{ font };



	sf::SoundBuffer game_over_sound_buffer;
	sf::SoundBuffer game_won_sound_buffer;
	sf::SoundBuffer game_next_level_sound_buffer;

	sf::Sound game_over_sound{ game_over_sound_buffer };
	sf::Sound game_won_sound{ game_won_sound_buffer  };
	sf::Sound game_next_level{ game_next_level_sound_buffer };

	bool game_sound_played = false;

	unsigned int level{};
	unsigned int score{};
	unsigned int high_score{};

	void level_completed();
	void gameLost();

	void winLoseFreeze();
	void levelCompletedFreeze();


public:
	sf::RenderWindow window;
	static const unsigned int window_width = 480;
	static const unsigned int window_height = 780;

	static const unsigned int play_area_width = 480;
	static const unsigned int play_area_height = 700;

	Game();
	
	void setup();
	void show_splash_screen();
	void update();
	void draw();

};