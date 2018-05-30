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
#include "enviroment.h"
#include <stdio.h>

THREAD_FUNC(input,args)
{
	changeInputMode();

	char a;
	a = getchar();
	printf("%d\n",a);

	resetInputMode();

	RETURN(0);
}

int main()
{
	Thread thread = createThread(input,NULL);

	waitThreadEnded(thread);

	RETURN(0);
};
