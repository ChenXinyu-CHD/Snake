/**
 * name : Food.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifndef FOOD_H
#define FOOD_H

#include "Position.h"

class Food
{
private:
	Position position;
public:
	Food();
	~Food();

	Position getPosition();
	Position updatePosition();
};

#endif /* FOOD_H */
