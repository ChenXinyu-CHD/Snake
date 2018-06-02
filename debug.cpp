#define DEBUG_FLAG

#include "GameMap.h"
#include <iostream>

using namespace std;

bool GameMap::debug()
{
	GameMap gameMap(new Snake(Position(1,1)));
	Position position = gameMap.createFood();
	cout<<position.get_y()<<"   "<<position.get_x()<<endl;

	return true;
}

int main()
{
	GameMap::debug();

	return 0;
}
