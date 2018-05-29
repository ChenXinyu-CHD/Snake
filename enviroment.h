#ifndef ENVIROMENT_H
#define ENVIROMENT_H

void changeInputMode();				//改变输入模式；
						//关闭回显并按照字符输入；

void resetInputMode();				//重设输入模式；

#if defined __linux__

#include <unistd.h>
#include <termios.h>
#include <stdio.h>

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
#ifdef _WIN32 || _WIN64

#include <Windows.h>

HANDLE hstdin;
DWORD oldMode,newMode;

void changeInputMode()
{
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConcoleMode(hstdin,&oldMode);
	newMode = oldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConcoleMode(hstdin,newMode);
}

void resetInputMode()
{
	SetConcoleMode(hstdin,oldMode);
}

#endif /* WINDOWS */
#endif /* LINUX */

#endif /* ENVIROMENT_H */
