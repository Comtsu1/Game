#include <cstdio>
#include <cstdlib>
#include <memory>

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

