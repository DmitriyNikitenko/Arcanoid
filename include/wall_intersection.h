#pragma once
#include "ball.h"

class Game;

class WalItersection {
private:
	Ball& ball;
	Game& game;
public:
	WalItersection(Ball& ball, Game& game);
	void check_intersection();

};
