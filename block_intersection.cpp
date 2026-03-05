#include "include/block_intersection.h"

BlockIntersection::BlockIntersection(Ball& ball, std::vector<std::unique_ptr<Block>>& blocks) : 
	ball(ball), blocks(blocks)
{
}

bool BlockIntersection::check_intersection() {
	for (auto it = blocks.begin(); it != blocks.end(); ++it) {
		const auto ball_box = ball.getGlobBounds();
		const auto block_box = (*it)->getGlobBounds();
		auto result = ball_box.findIntersection(block_box);
		if (result.has_value()) {
			ball.bounceY();
			blocks.erase(it);
			return true;
		}
	}
	return false;
}