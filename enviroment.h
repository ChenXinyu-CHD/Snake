#ifndef ENVIROMENT_H
#define ENVIROMENT_H

void changeInputMode();				//改变输入模式；
						//关闭回显并按照字符输入；

void resetInputMode();				//重设输入模式；

#if defined __linux__

#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <pthread.h>

#define THREAD_FUNC(func_name,args) void * func_name(void *args)

#define RETURN(i) pthread_exit(i)

typedef pthread_t Thread;

Thread createThread(void (*ThreadFunc(void *)),void *args)
{
	Thread result;
	pthread_create(&result,NULL,ThreadFunc,args);

	return result;
}

termios initialSettings,newSettings;

void changeInputMode()
{
	tcgetattr(fileno(stdin),&initialSettings);
	newSettings = initialSettings;

	newSettings.c_lflag &= ~ECHO & ~ICANON;			//关闭回显，关闭正规模式；
	newSettings.c_cc[VTIME] = 0;
	newSettings.c_cc[VMIN] = 1;				//使标准输入获取单个字符后立刻返回；

	tcsetattr(fileno(stdin),TCSANOW,&newSettings);			//更改设置;
}

void resetInputMode()
{
	tcsetattr(fileno(stdin),TCSANOW,&initialSettings);
}

#else
#if defined _WIN32 || _WIN64

#include <windows.h>

#define THREAD_FUN(func_name,args) DWORD WINAPI func_name(LPVOID args)

typedef HANDLE Thread;

Thread createThread(LPTHREAD_START_ROUTINE ThreadFunc,LPVOID args)
{
	return CreateThread(NULL,0,ThreadFunc,args,0,NULL);
}

HANDLE hstdin;
DWORD oldMode,newMode;

void changeInputMode()
{
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hstdin,&oldMode);
	newMode = oldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConsoleMode(hstdin,newMode);
}

void resetInputMode()
{
	SetConsoleMode(hstdin,oldMode);
}

#endif /* WINDOWS */
#endif /* LINUX */

#endif /* ENVIROMENT_H */
