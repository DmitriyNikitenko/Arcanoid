#include "include/wall_intersection.h"
#include "include/game.h"


WalItersection::WalItersection(Ball& ball, Game& game) : ball(ball), game(game) {
}

void WalItersection::check_intersection() {
	if (ball.getLeft() < 0 || ball.getRight() > Game::play_area_width) {
		ball.bounceX();
	}

	if (ball.getUp() < 0) {
		ball.bounceY();
	}

}
