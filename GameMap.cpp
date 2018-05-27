/**
 * name : GameMap.cpp;
 * date : 2018/5/28;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

#include "GameMap.h"
#include <cstdlib>

GameMap::GameMap(Snake *snake_p):
	map({"\0"}),
	snake(snake_p),
	foodPosition(createFood())
{
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
	static unsigned int random = (unsigned)time(0);
	random = (random * 16807) % (MAX_HIGHT * MAX_LENGTH);

	Position result;

	int count = 0;
	int x,y;
	while(count < random)
		for(y = 1;y < MAX_HIGHT-1;++y)
			for(x = 1;x < MAX_LENGTH-1;++x)
				if(map[y][x] == ' ')
					++count;
	result.set_y(y);
	result.set_x(x);

	return result;
}
