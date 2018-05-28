#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#if defined __linux__

#include <unistd.h>
#include <termios.h>

#else
#ifdef _WIN32 || _WIN64

#include <Windows.h>

#endif /* WINDOWS */
#endif /* LINUX */

#endif /* ENVIROMENT_H */
