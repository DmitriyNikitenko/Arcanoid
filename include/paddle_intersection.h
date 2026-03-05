#pragma once

#include <SFML\Graphics.hpp>
#include "ball.h"
#include "puddle.h"

class PaddlleIntersection {
private:
	Ball& ball;
	Paddle& paddle;

	bool did_bounce{ false };

public:
	PaddlleIntersection(Ball& ball, Paddle& paddle);

	void check_intersection();

};
