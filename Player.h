/**
 * name : Snake.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifndef PLAYER_H
#define PLAYER_H

#include "Snake.h"

class Player
{
private:
	Snake *snake;
public:
	Player(Snake *snake);
	~Player();

	void control()=0;
};

#endif /* PLAYER_H */
