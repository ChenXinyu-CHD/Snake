/**
 * name : GameMap.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include "Snake.h"

#include "debug_permission.h"

class GameMap
{
public:
	static const short MAX_HIGHT = 20;
	static const short MAX_LENGTH = 30;
private:
	char map[MAX_HIGHT][MAX_LENGTH];
	bool gameStatus;
	Snake *snake;
	Position FoodPosition;
public:
	GameMap(Snake *snake);
	~GameMap();

	void updateGameMap();
	std::string getNextLine();
	bool hasNotGameOver();
DEBUG_PERMISSION:
	static bool debug();
};

#endif /* GAME_MAP_H */
