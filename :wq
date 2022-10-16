#pragma once

#include <cstdio>
#include <cstdlib>
#include <memory>

#include <unistd.h> // for STDIN_FILENO
#include <termios.h>

int getch()
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

