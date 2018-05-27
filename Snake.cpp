/**
 * name : Snake.cpp;
 * date : 18/5/28;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

#include "Snake.h"

Snake::Snake(Position headPosition):
	snakeBody(),
	direct(right)
{
	snakeBody.push(headPosition);
}

Snake::~Snake()
{ /* Nothing to do; */ }

void Snake::grow()
{
	Position newHeadPosition = getHeadPosition();
	switch (direct)
	{
		case left:
			newHeadPosition.set_x(newHeadPosition.get_x() - 1);
			break;
		case right:
			newHeadPosition.set_x(newHeadPosition.get_x() + 1);
			break;
		case up:
			newHeadPosition.set_y(newHeadPosition.get_y() + 1);
			break;
		case down:
			newHeadPosition.set_y(newHeadPosition.get_y() - 1);
	}
	snakeBody.push(newHeadPosition);
}

void Snake::move()
{
	grow();			//在头部伸长一格
	snakeBody.pop();	//在尾部缩短一格
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
