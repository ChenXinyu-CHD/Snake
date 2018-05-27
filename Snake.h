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
	enum Direct
	{left,right,up,down};
private:
	Queue<Position> snakeBody;
	Direct direct;
public:
	Snake(Position headPosition);
	~Snake();

	void move();
	void grow();

	Position getHeadPosition();
	Position getTailPosition();

	Direct getDirect();
	void setDirect(Direct direct);
};

#endif /* SNAKE_H */
