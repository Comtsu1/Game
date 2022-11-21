#pragma once

#if __WIN32
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif


#define START_ONE 48 // ascii code for '0'
#define CONTINUE_MESSAGE "Press any key to continue..."
