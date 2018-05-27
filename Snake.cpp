/**
 * name : Snake.cpp;
 * date : 18/5/28;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

#include "Snake.h"

Snake::Snake(Position headPosition):
	snakeBody(),
	length(0),
	direct(right)
{
	snakeBody.push(headPosition);
}

Snake::~Snake()
{ /* Nothing to do; */ }

bool Snake::tryToEatFood(Position foodPosition)
{
	bool result = false;

	Position newHeadPosition = getThePositionFacingTo();
	snakeBody.push(newHeadPosition);

	if(newHeadPosition != foodPosition)
		snakeBody.pop();
	else
	{
		result = true;
		++length;
	}

	return result;
}

Position Snake::getHeadPosition()
{
	return snakeBody.getTop();
}

Position Snake::getTailPosition()
{
	return snakeBody.getBottom();
}

Snake::Direct Snake::getDirect()
{
	return direct;
}

void Snake::setDirect(Snake::Direct direct)
{
	this->direct = direct;
}

Position Snake::getThePositionFacingTo()
{
	Position result = getHeadPosition();
	switch (direct)
	{
		case left:
			result.set_x(result.get_x() - 1);
			break;
		case right:
			result.set_x(result.get_x() + 1);
			break;
		case up:
			result.set_y(result.get_y() + 1);
			break;
		case down:
			result.set_y(result.get_y() - 1);
	}
	return result;
}

int Snake::getLength()
{return length;}
