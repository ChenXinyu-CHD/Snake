/**
 * name : main.cpp;
 * date : 2018/05/27;
 * g++ version : 8.1.0;
 * g++ options : -O2;
 * */

//#include "GameMap.h"
#include "enviroment.h"
#include <stdio.h>

int main()
{
	changeInputMode();

	char a;
	a = getchar();
	printf("%d\n",a);

	resetInputMode();

	return 0;
};
