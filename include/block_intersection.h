#pragma once
#include <SFML\Graphics.hpp>
#include "block.h" 
#include "ball.h"
#include <vector>


class BlockIntersection {
private:
	Ball& ball;
	std::vector<std::unique_ptr<Block>>& blocks;

	bool did_bounce{ false };

public:
	BlockIntersection(Ball& ball, std::vector<std::unique_ptr<Block>>& blocks);
	bool check_intersection();

};
