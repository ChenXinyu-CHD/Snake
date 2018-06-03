/**
 * name : main.cpp;
 * date : 2018/05/27;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

//if you use linux
//please build it with
//-lpthread;

#include "GameMap.h"
#include "Snake.h"
#include "enviroment.h"
#include "Position.h"

#include <stdio.h>

const Position FIRST_POSITION_OF_SNAKE(10,10);
const int UPDATE_TIME = 200;				//70毫秒;

THREAD_FUNC(input,args)
{
	GameMap *gameMap = (GameMap *)args;
	Snake *snake = gameMap->getSnake_ptr();
	char ch;

	changeInputMode();

	while(gameMap->hasNotGameOver())
	{
		ch = getchar();

		Snake::Direct result;
		switch(ch)
		{
			case 'W': case 'w':
				result = Snake::up;
				break;
			case 'A': case 'a':
				result = Snake::left;
				break;
			case 'S': case 's':
				result = Snake::down;
				break;
			case 'D': case 'd':
				result = Snake::right;
				break;
			default:
				result = snake->getDirect();
		}
		snake->setDirect(result);
	}

	resetInputMode();

	RETURN(0);
}

void printMap(GameMap::Map map)
{
	for(int i = 0;i < GameMap::MAX_HIGHT;++i)
	{
		for(int j = 0;j < GameMap::MAX_LENGTH;++j)
			putchar(map[i][j]);
		putchar('\n');
	}
}

THREAD_FUNC(output,args)
{
	GameMap *gameMap = (GameMap *)args;
	GameMap::Map & map = gameMap->getMap();

	while(gameMap->hasNotGameOver())
	{
		sleap_now(UPDATE_TIME);
		clearScreen();
		gameMap->update();
		printMap(map);
	}

	RETURN(0);
}

int main()
{
	Snake *snake = new Snake(FIRST_POSITION_OF_SNAKE);
	GameMap *gameMap = new GameMap(snake);

	Thread inputThread = createThread(input,(void *)gameMap);
	Thread outputThread = createThread(output,(void *)gameMap);

	waitThreadEnded(inputThread);
	waitThreadEnded(outputThread);

	delete snake;
	delete gameMap;

	RETURN(0);
};
