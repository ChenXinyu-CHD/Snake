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
	static const short MAX_LENGTH = 40;
	typedef char Map[MAX_HIGHT][MAX_LENGTH];
private:
	Map map;
	Snake *snake;
	Position foodPosition;
public:
	GameMap(Snake *snake);
	void update();				//更新游戏地图（执行贪吃蛇的移动和游戏状态检查）
						//游戏每进行一帧地图更新一次
	bool hasNotGameOver();
	Snake *getSnake_ptr();
	Map &getMap();
private:
	Position createFood();
DEBUG_PERMISSION:
	static bool debug();
};

#endif /* GAME_MAP_H */
