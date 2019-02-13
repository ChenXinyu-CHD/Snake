/**
 * name : Snake.cpp;
 * date : 18/5/28;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

#include "Snake.h"

Snake::Snake(Position headPosition):
	snakeBody(),
	length(1),
	direct(Direct::right)
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
	return snakeBody.getBottom();
}

Position Snake::getTailPosition()
{
	return snakeBody.getTop();
}

Position Snake::getThePositionFacingTo()
{
	Position result = getHeadPosition();
	switch (direct)
	{
		case Direct::left:
			result.X = result.X - 1;
			break;
		case Direct::right:
			result.X = result.X + 1;
			break;
		case Direct::up:
			result.Y = result.Y - 1;
			break;
		case Direct::down:
			result.Y = result.Y + 1;
	}
	return result;
}

int Snake::getLength()
{return length;}
