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
	map[snakeHeadPosition.get_y()][snakeHeadPosition.get_x()] = '*';
	map[foodPosition.get_y()][foodPosition.get_x()] = '+';
}

void GameMap::update()
{
	if(hasNotGameOver())
	{
		Position oldSnakeTailPosition = snake->getTailPosition();

		if(snake->tryToEatFood(foodPosition))
			foodPosition = createFood();
		else
			map[oldSnakeTailPosition.get_y()][oldSnakeTailPosition.get_x()] = ' ';

		Position newSnakeHeadPosition = snake->getHeadPosition();
		map[newSnakeHeadPosition.get_y()][newSnakeHeadPosition.get_x()] = '*';
		map[foodPosition.get_y()][foodPosition.get_x()] = '+';
	}
}

bool GameMap::hasNotGameOver()
{
	Position position = snake->getThePositionFacingTo();
	return(
		map[position.get_y()][position.get_x()] == ' ' ||
		map[position.get_y()][position.get_x()] == '+'
	);
}

Position GameMap::createFood()
{
	/*int random = rand() % ((MAX_LENGTH-2) * (MAX_HIGHT-2) - snake->getLength());
	Position result;

	int count = 0;
	int x ,y;
	for(y = 1;y < MAX_HIGHT-1;++y)
		for(x = 1;x < MAX_LENGTH-1;++x)
			if(map[y][x] == ' ' && count < random)
				++count;
			else if(count == random && map[y][x] == ' ')
				goto out;
out:
	result.set_y(y);
	result.set_x(x);*/

	int x = 0;
	int y = 0;
	Position result;

	while(map[y][x] != ' ')
    {
        y = rand() % (MAX_HIGHT - 4) + 2;
        x = rand() % (MAX_LENGTH - 4) + 2;
    }

	result.set_x(x);
	result.set_y(y);

	return result;
}

Snake * GameMap::getSnake_ptr()
{return snake;}

GameMap::Map &GameMap::getMap()
{return map;}
