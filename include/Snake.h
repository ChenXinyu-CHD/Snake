/**
 * name : Snake.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifndef SNAKE_H
#define SNAKE_H

#include <dataStructure/Queue.h>
#include <Types.h>

class Snake
{
private:
	Queue<Position> snakeBody;
	int length;
public:
	Direct direct;
public:
	Snake(Position headPosition);
	~Snake();

	bool tryToEatFood(Position foodPosition);		//尝试吃食物
								//如果可以吃到则向前增长一格,返回true
								//如果吃不到则向前移动一格，返回false

	Position getHeadPosition();
	Position getTailPosition();

	Position getThePositionFacingTo();

	int getLength();
};

#endif /* SNAKE_H */
