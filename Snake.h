/**
 * name : Snake.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifndef SNAKE_H
#define SNAKE_H

#include "dataStructure/Queue.h"
#include "Position.h"

class Snake
{
public:
	typedef short Direct;
	static const int left = -1;
	static const int right = ~left;
	static const int up = 2;
	static const int down = ~up;
private:
	Queue<Position> snakeBody;
	int length;
	Direct direct;
public:
	Snake(Position headPosition);
	~Snake();

	bool tryToEatFood(Position foodPosition);		//尝试吃食物
								//如果可以吃到则向前增长一格,返回true
								//如果吃不到则向前移动一格，返回false

	Position getHeadPosition();
	Position getTailPosition();

	Direct getDirect();
	void setDirect(Direct direct);

	Position getThePositionFacingTo();

	int getLength();
};

#endif /* SNAKE_H */
