/**
 * name : GameMap.cpp;
 * date : 2018/5/28;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

#include "GameMap.h"
#include <cstdlib>
#include <ctime>

GameMap::GameMap(Snake *snake_p):
	snake(snake_p)
{
	srand((unsigned)time(0));
	for(int i = 0;i < MAX_HIGHT;++i)
		for(int j = 0;j < MAX_LENGTH;++j)
			if
			(
				i == 0||i == MAX_HIGHT-1 ||
				j == 0||j == MAX_LENGTH-1
			)
				map[i][j] = 'X';
			else
				map[i][j] = ' ';

	foodPosition = createFood();

	Position snakeHeadPosition = snake->getHeadPosition();
	map[snakeHeadPosition.Y][snakeHeadPosition.X] = '*';
	map[foodPosition.Y][foodPosition.X] = '+';
}

void GameMap::update()
{
	if(hasNotGameOver())
	{
		Position oldSnakeTailPosition = snake->getTailPosition();

		if(snake->tryToEatFood(foodPosition))
			foodPosition = createFood();
		else
			map[oldSnakeTailPosition.Y][oldSnakeTailPosition.X] = ' ';

		Position newSnakeHeadPosition = snake->getHeadPosition();
		map[newSnakeHeadPosition.Y][newSnakeHeadPosition.X] = '*';
		map[foodPosition.Y][foodPosition.X] = '+';
	}
}

bool GameMap::hasNotGameOver()
{
	Position position = snake->getThePositionFacingTo();
	return(
		map[position.Y][position.X] == ' ' ||
		map[position.Y][position.X] == '+'
	);
}

Position GameMap::createFood()
{
	int x = 0;
	int y = 0;
	Position result;

	while(map[y][x] != ' ')
    	{
        	y = rand() % (MAX_HIGHT - 4) + 2;
        	x = rand() % (MAX_LENGTH - 4) + 2;
    	}

	result.X = x;
	result.Y = y;

	return result;
}

Snake * GameMap::getSnake_ptr()
{return snake;}

GameMap::Map &GameMap::getMap()
{return map;}
