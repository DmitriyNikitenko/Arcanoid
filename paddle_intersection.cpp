#include "include/paddle_intersection.h"

PaddlleIntersection::PaddlleIntersection(Ball& ball, Paddle& paddle) : ball(ball), paddle(paddle) {

}

void PaddlleIntersection::check_intersection() {
	const auto ball_box = ball.getGlobBounds();
	const auto paddle_box = paddle.getGlobBounds();
	auto result = ball_box.findIntersection(paddle_box);
	if (!did_bounce && result.has_value()) {
		ball.bounceY();
		did_bounce = true;
	}

	if (!result.has_value()) {
		did_bounce = false;
	}

}