#include <bits/types/struct_timeval.h>
#include <cstdio>
#include <cstdlib>

#include <sys/select.h>
#include <unistd.h> // for STDIN_FILENO

#include "defines.h"

#ifdef __WIN32

void clearScreen()
{
    std::system("cls");
}

int getchr()
{
    int a = _getch();
    return a;
}
#else

int _kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}


void clearScreen()
{
    std::system("clear");
}

int getchr()
{
    struct termios olds, news;
    tcgetattr(STDIN_FILENO, &olds);

    news = olds;

    news.c_lflag &= (~ICANON & ~ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &news);

    short int answer = getc(stdin);

    tcsetattr(STDIN_FILENO, TCSANOW, &olds);

    return answer;
}

#endif // __WIN32

